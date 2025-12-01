#set($tagIncludes = _${package.replaceAll(".","_").toUpperCase()}_${shortName.toUpperCase()}_INCLUDES_H)
#set($tagFile = _${package.replaceAll(".","_").toUpperCase()}_${shortName.toUpperCase()}_SAMPLE_H)
#ifndef ${tagFile}
#define ${tagFile}

#include <${tagIncludes}>

// Library methods an functions
void SmpDoSomething ();


#endif
