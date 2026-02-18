
#include "SistemaUsuario.h"     

#include "SistemaConfig.h"


#define REAL_ID             0           
#define EFFECTIVE_ID        1




char * SisUsrObtenerNombre (unsigned int uiId)
{
#   if (defined (UNIX) || defined (LINUX))
    static struct uids {                /*  Table of cached uids             */
        unsigned int id;
        char  *name;
    } cache [UID_CACHE_MAX];
    static int
        cache_size = 0,                 /*  Number of uiId's in cache         */
        cache_oldest = 0;               /*  Oldest entry in cache            */
    int
        cache_scan;                     /*  Scan through cache               */
    struct passwd
        *passwd_entry;

    /*  First, look for uiId in cache                                         */
    for (cache_scan = 0; cache_scan < cache_size; cache_scan++)
        if (cache [cache_scan].id == uiId)
            return (cache [cache_scan].name);

    /*  Add new name to cache: if cache was full, kick-out oldest entry      */
    if (cache_size == UID_CACHE_MAX)
      {
        cache_scan = cache_oldest++;
        cache_oldest %= UID_CACHE_MAX;
        free (cache [cache_scan].name);
      }
    else
        cache_scan = cache_size++;

    cache [cache_scan].id = uiId;
    if ((passwd_entry = getpwuid (uiId)) == NULL)
        cache [cache_scan].name = "<none>";
    else
        cache [cache_scan].name = strdup (passwd_entry-> pw_name);

    return (cache [cache_scan].name);

#   else
    return (uiId == 0? "user": "<none>");

#   endif
}



char * SisUsrObtenerNombreGrupo (unsigned int uiIdGrupo)
{
#   if (defined (UNIX) || defined (LINUX))
    static struct gids {                /*  Table of cache'd gids            */
        unsigned int id;
        char  *name;
    } cache [GID_CACHE_MAX];
    static int
        cache_size = 0,                 /*  Number of uiIdGrupo's in cache         */
        cache_oldest = 0;               /*  Oldest entry in cache            */
    int
        cache_scan;                     /*  Scan through cache               */
    struct group
        *group_entry;

    /*  First, look for uiIdGrupo in cache                                         */
    for (cache_scan = 0; cache_scan < cache_size; cache_scan++)
        if (cache [cache_scan].id == uiIdGrupo)
            return (cache [cache_scan].name);

    /*  Add new name to cache: if cache was full, kick-out oldest entry      */
    if (cache_size == GID_CACHE_MAX)
      {
        cache_scan = cache_oldest++;
        cache_oldest %= GID_CACHE_MAX;
        free (cache [cache_scan].name);
      }
    else
        cache_scan = cache_size++;

    cache [cache_scan].id = uiIdGrupo;
#   if (defined (__VMS__))
        cache [cache_scan].name = "<none>";
#   else
    if ((group_entry = getgrgid (uiIdGrupo)) == NULL)
        cache [cache_scan].name = "<none>";
    else
        cache [cache_scan].name = strdup (group_entry-> gr_name);
#   endif

    return (cache [cache_scan].name);

#   else
    return (uiIdGrupo == 0? "group": "<none>");

#   endif
}


int SisUsrDesactivarRoot ()
{
#if (defined (UNIX) || defined (LINUX))
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
    return (setuid (SisUsrObtenerUsuario (REAL_ID)));
#   elif (defined (__OS2__))            /*  OS/2 only supports one UID       */
    return ( 0 );
#   elif (defined (__VMS__))            /*  No setuid under OpenVMS          */
    return ( 0 );
#   else
    return (seteuid (SisUsrObtenerUsuario (REAL_ID)));
#   endif
#else
    return ( 0 );
#endif
}


int SisUsrActivarRoot ()
{
#if (defined (UNIX) || defined (LINUX))
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
    return (setuid (SisUsrObtenerUsuario (EFFECTIVE_ID)));
#   elif (defined (__OS2__))            /*  OS/2 only supports one UID       */
    return ( 0 );
#   elif (defined (__VMS__))            /*  No setuid under OpenVMS          */
    return ( 0 );
#   else
    return (seteuid (SisUsrObtenerUsuario (EFFECTIVE_ID)));
#   endif
#else
    return ( 0 );
#endif
}



unsigned int SisUsrObtenerUsuario (int type)
{
#if (defined (UNIX) || defined (LINUX) )
    static int
        ruid = -1,
        euid = -1;

    if (ruid == -1)
        ruid = getuid ();
    if (euid == -1)
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
        euid = getuid ();
#   else
        euid = geteuid ();
#   endif

    if (type == REAL_ID)
        return (ruid);
    else
    if (type == EFFECTIVE_ID)
        return (euid);
    else
        return (-1);
#else
	return (-1);
#endif
}



int SisUsrDesactivarGrupoRoot ()
{
#if (defined (UNIX) || defined (LINUX))
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
    return (setgid (getgid (REAL_ID)));
#   elif (defined (__OS2__))            /*  OS/2 only supports one UID       */
    return ( 0 );
#   elif (defined (__VMS__))            /*  No setgid under OpenVMS          */
    return ( 0 );
#   else
        struct group * grp = getgrgid ( REAL_ID );
        if ( ES_VALIDO ( grp ) )
        {
            return ( setegid ( grp->gr_gid ) );
        }
        else
        {
            return ( 0 );
        }
#   endif
#else
    return ( 0 );
#endif
}

int SisUsrActivarGrupoRoot ()
{
#if (defined (UNIX) || defined (LINUX))
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
    return (setgid (get_gid (EFFECTIVE_ID)));
#   elif (defined (__OS2__))            /*  OS/2 only supports one UID       */
    return ( 0 );
#   elif (defined (__VMS__))            /*  No setgid under OpenVMS          */
    return ( 0 );
#   else
    struct group * grp = getgrgid ( EFFECTIVE_ID );
    if ( ES_VALIDO ( grp ) )
    {
        return ( setegid ( grp->gr_gid ) );
    }
    else
    {
        return ( 0 );
    }
#   endif
#else
    return ( 0 );
#endif
}



unsigned int SisUsrObtenerGrupo ( int type )
{
#if (defined (UNIX) || defined (LINUX) )
    static int
        rgid = -1,
        egid = -1;

    if (rgid == -1)
        rgid = getgid ();
    if (egid == -1)
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
        egid = getgid ();
#   else
        egid = getegid ();
#   endif

    if (type == REAL_ID)
        return (rgid);
    else
    if (type == EFFECTIVE_ID)
        return (egid);
    else
        return ( 0 );
#else
	return ( 0 );
#endif
}


int SisUsrEstablecerUsuario ( const char *p_cUsuario, const char *p_cGrupo )
{
#if (defined (UNIX) || defined (LINUX))
    struct passwd
        *pwdbuf;
    struct group
        *grpbuf;

#   if (defined (__VMS__))
    return ( 0 );
#   else
    if (p_cGrupo && *p_cGrupo)
      {
        if ((grpbuf = getgrnam (p_cGrupo)) == NULL)
            return (-1);
        else
        if (setgid (grpbuf-> gr_gid) == -1)
            return (-2);
      }
    if ((pwdbuf = getpwnam (p_cUsuario)) == NULL)
        return (-1);
    else
    if (setuid (pwdbuf-> pw_uid) == -1)
        return (-2);
#   endif
#endif
    return ( 0 );
}

char * SisUsObtenerUsuarioLogin ()
{
#if (defined (WIN))
#   if (defined (WIN32))
    ULONG
        user_name_max = 255;
    static char
        user_name [256];

    if (!GetUserName (user_name, &user_name_max))
        strncpy (user_name, "unknown", sizeof (user_name));
    return (user_name);
#   else
    return ("none");
#   endif
#elif ( defined (UNIX) || defined (LINUX) )
    return (getlogin ());
#endif
}
