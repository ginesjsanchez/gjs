#set( $capitalizedPrefix = $prefix.substring(0,1).toUpperCase() + $prefix.substring(1))
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
${symbol_pound} ${capitalizedPrefix} ${capitalizedName} Archetype

Project Archetype in ${lan} language.


${symbol_pound}${symbol_pound} Description

Archetype to generate the basic structure of a project in ${lan} language.


${symbol_pound}${symbol_pound} Requirements

* Maven 3.9.x


    
${symbol_pound}${symbol_pound} Generating a project from the archetype

    mvn archetype:generate \
		-DarchetypeGroupId=${groupId} \
		-DarchetypeArtifactId=${artifactId} \
		-DarchetypeVersion=${version} 

    mvn archetype:generate \
		-DarchetypeGroupId=${groupId} \
		-DarchetypeArtifactId=${artifactId} \
		-DarchetypeVersion=${version} \
		-DshortName=test-project \ 
		-DgroupId=org.gjs.test 
    
	Archetype Parameters:

	* shortName: Name of the project. Always lowercase. Allows two words separated by a hyphen.

	* groupId: The group of the project artifact. 

	* artifactId: The name of the project artifact. Default is ${shortName}. Not required.

	* package: The project packaging of the sourc code. Default is ${groupId}. Not required.

	* version: The project version. Default is 1.0.0-SNAPSHOT. Not required.
	
	
    
${symbol_pound}${symbol_pound} References

* [Maven Build Lifecycle](https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html)
