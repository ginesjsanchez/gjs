#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $tagFile = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_SAMPLETYPE_H")
#set( $subpackages = ${package.split(".")})
#set( $tagFile = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_SAMPLETYPE_H")
#set( $subpackages = ${package.split("\.")})

${symbol_pound}ifndef ${tagFile}
${symbol_pound}define ${tagFile}


${symbol_pound}include <${capitalizedName}Includes.h>



// Data type structure
typedef struct
{
}  SampleType;

 
SampleType * SmpCrear ();
void SmpDestruir ( SampleType ** p_p_smpObj );

int SmpIsValid ( SampleType * p_smpObj );




#endif
