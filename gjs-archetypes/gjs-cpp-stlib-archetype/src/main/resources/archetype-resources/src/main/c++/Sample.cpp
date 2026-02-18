#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $includeConfig = "${capitalizedName}Config.h")
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
${symbol_pound}include "${includeConfig}"
${symbol_pound}include "Sample.h"




#namespacesBegin( $subpackages )
using namespace std;


// Methods and functions implementation here
bool SmpDoSomething () {
    return true;
}



#namespacesEnd( $subpackages )





