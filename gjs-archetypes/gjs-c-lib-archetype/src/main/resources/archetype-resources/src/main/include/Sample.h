#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $symbol_key_open = '{' )
#set( $symbol_key_close = '}' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $tagFile = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_SAMPLE_H")

${symbol_pound}ifndef ${tagFile}
${symbol_pound}define ${tagFile}


${symbol_pound}include <${capitalizedName}Includes.h>


// Library methods an functions
bool SmpDoSomething ();




#endif
