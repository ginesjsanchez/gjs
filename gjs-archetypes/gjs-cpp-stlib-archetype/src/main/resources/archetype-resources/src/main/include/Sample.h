#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $symbol_key_open = '{' )
#set( $symbol_key_close = '}' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $tagFile = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_SAMPLE_H")
#set( $subpackages = ${package.split("\.")})
#set($spaces = "" )
#macro( namespacesBegin $subnamespaces )
  #set($spaces = "" )
  #foreach( $subname in $subnamespaces )
${spaces}namespace ${subname} {
    #set($spaces = $spaces + "    " )
  #end
#end
#macro( namespacesEnd $subnamespaces )
  #foreach( $subname in $subnamespaces )
    #set($max = $spaces.length() - 4 )
    #if( $max > 0 )
    #set($spaces = $spaces.substring(0, $max) )
    #else
    #set($spaces = "" )
    #end
${spaces}}
  #end
#end
${symbol_pound}ifndef ${tagFile}
${symbol_pound}define ${tagFile}


${symbol_pound}include <${capitalizedName}Includes.h>


#namespacesBegin( $subpackages )

// Library methods an functions
bool SmpDoSomething ();

#namespacesEnd( $subpackages )



#endif
