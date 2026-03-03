#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $includeConfig = "${capitalizedName}Config.h")

${symbol_pound}include "${includeConfig}"
${symbol_pound}include "Sample.h"





// Methods and functions implementation here
bool SmpDoSomething () {
    return true;
}





