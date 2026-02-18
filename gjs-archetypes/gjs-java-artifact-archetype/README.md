# GJS Java artifact Archetype

Project Archetype in java language.


## Description

Archetype to generate the basic structure of a basic project in java language.


## Requirements

* Maven 3.9.x


    
## Generación de un proyecto a partir del arquetipo

    mvn -B archetype:generate \
							-DarchetypeGroupId=org.gjs.maven.archetypes \
							-DarchetypeArtifactId=gjs-java-artifact-archetype \
							-DarchetypeVersion=1.0.0-SNAPSHOT 

    mvn -B archetype:generate \
							-DarchetypeGroupId=org.gjs.maven.archetypes \
							-DarchetypeArtifactId=gjs-java-artifact-archetype \
							-DarchetypeVersion=1.0.0-SNAPSHOT \
							-Dname=test \ 
							-DgroupId=org.gjs.test 
    
	Archetype Parameters:

	* name: Name of the project. Always lowercase. Allows two words separated by a hyphen.

	* groupId: The group of the project artifact. 

	* artifactId: The name of the project artifact. Default is java-module. Not required.

	* package: The project packaging of the sourc code. Default is org.gjs.maven.archetypes. Not required.

	* version: The project version. Default is 1.0.0-SNAPSHOT. Not required.
	
	
    
## References

* [Maven Build Lifecycle](https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html)
