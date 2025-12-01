# GJS Plugin Archetype

Project Archetype for maven plugins.


## Description

Archetype to generate the basic structure of a maven plugin.


## Requirements

* Maven 3.9.x


    
## Generación de un proyecto a partir del arquetipo

    mvn -B archetype:generate \
							-DarchetypeGroupId=org.gjs.maven.archetypes \
							-DarchetypeArtifactId=gjs-plugin-archetype \
							-DarchetypeVersion=1.0.0-SNAPSHOT 

    mvn -B archetype:generate \
							-DarchetypeGroupId=org.gjs.maven.archetypes \
							-DarchetypeArtifactId=gjs-plugin-archetype \
							-DarchetypeVersion=1.0.0-SNAPSHOT \
							-Dname=test -Drule=test 
    
	Archetype Parameters:

	* name: Name of the project. Always lowercase. Allows two words separated by a hyphen.

	* rule: Name of the sample rule. Always lowercase. Allows two words separated by a hyphen.

	* groupId: The group of the project artifact. 

	* artifactId: The name of the project artifact. Default is plugin. Not required.

	* package: The project packaging of the sourc code. Default is org.gjs.maven.archetypes. Not required.

	* version: The project version. Default is 1.0.0-SNAPSHOT. Not required.
	
	
    
## References

* [Maven Build Lifecycle](https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html)
