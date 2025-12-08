#set($tagConfig = _${package.replaceAll(".","_").toUpperCase()}_${shortName.toUpperCase()}_CONFIG)
#ifndef ${tagConfig}
#define ${tagConfig}


// Common dependencies
#include <Base.h>



#endif
