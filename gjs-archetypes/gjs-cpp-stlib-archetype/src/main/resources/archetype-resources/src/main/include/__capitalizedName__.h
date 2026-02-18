#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set($tagLib = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_H")
${symbol_pound}ifndef ${tagLib}
${symbol_pound}define ${tagLib}

// Library includes
${symbol_pound}include <Sample.h>
${symbol_pound}include <SampleType.h>


#endif
