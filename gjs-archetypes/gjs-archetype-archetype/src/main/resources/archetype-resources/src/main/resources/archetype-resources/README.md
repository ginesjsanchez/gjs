#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
${symbol_pound}set( ${symbol_dollar}symbol_pound = '${symbol_pound}' )
${symbol_pound}set( ${symbol_dollar}symbol_dollar = '${symbol_dollar}' )
${symbol_pound}set( ${symbol_dollar}symbol_escape = '${symbol_escape}' )
${symbol_pound}set( ${symbol_dollar}capitalizedName = ${symbol_dollar}shortName.substring(0,1).toUpperCase() + ${symbol_dollar}shortName.substring(1))
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} ${symbol_dollar}{capitalizedName} project

Project ${symbol_dollar}{shortName}

${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Description

Project ${shortName} in ${lan} language.


${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Requirements

* Maven 3.9.x


${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Configuration


      
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Installation
    
    mvn clean install


${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Unit testing

    mvn clean test
    

${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Documentation

    mvn site
    

${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Deploy 

    mvn deploy

        
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Execution

    
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Security
    
    
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Audit

    
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} To start

    

${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Avalaible users


${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} Common mistakes


    
${symbol_dollar}{symbol_pound}${symbol_dollar}{symbol_pound} References

* [Maven Build Lifecycle](https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html)
