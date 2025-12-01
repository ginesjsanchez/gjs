#set($tagIncludes = _${package.replaceAll(".","_").toUpperCase()}_${shortName.toUpperCase()}_INCLUDES_H)
#set($tagFile = _${package.replaceAll(".","_").toUpperCase()}_${shortName.toUpperCase()}_SAMPLETYPE_H)
#ifndef ${tagFile}
#define ${tagFile}

#include <${tagIncludes}>

// Data type structure
typedef struct
{
	const char *	p_cName;
} SampleType;



// Data type constructors
SampleType * SmpTypCrear ( const char * p_cName );

// Data type destructors
void SmpTypDestruir ( SampleType ** p_p_smptypObj );

// Data type getters and setters
const char * SmpTypGetName ( SampleType * p_smptypObj );
void SmpTypSetName ( SampleType * p_smptypObj, const char * p_cName );

// Data type methods ans functions

#endif
