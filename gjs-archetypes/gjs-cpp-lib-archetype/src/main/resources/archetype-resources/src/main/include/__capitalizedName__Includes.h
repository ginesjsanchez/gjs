#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set($tagIncludes = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_INCLUDES_H")
${symbol_pound}ifndef ${tagIncludes}
${symbol_pound}define ${tagIncludes}

// External includes


#endif
