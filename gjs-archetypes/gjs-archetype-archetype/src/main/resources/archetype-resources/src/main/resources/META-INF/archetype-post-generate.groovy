#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
import groovy.io.FileType
import java.nio.file.Path
import java.util.regex.Pattern
import org.apache.commons.io.FileUtils


println "Post generate tasks..."

def projectArtifactId = request.properties.getProperty("artifactId")
def projectGroupId = request.properties.getProperty("groupId")
def projectVersion = request.properties.getProperty("version")

println "1) Customizing pom.xml..."
// This is due to a bug in the Maven plugin that, when there is a parent in the pom.xml template, it is lost 
// and places the Gavs of the archetype itself instead of those of the project to be generated.

def pomFile = new File(request.getOutputDirectory(), projectArtifactId + "/pom.xml")
if (pomFile.exists()) {
	def pom = pomFile.text
	def badGroup = "<groupId>${symbol_dollar}{groupId}</groupId>"
	def badArtifact = "<artifactId>${symbol_dollar}{artifactId}</artifactId>"
	def badVersion = "<version>${symbol_dollar}{version}</version>"
	def goodGroup = "<groupId>" + projectGroupId + "</groupId>"
	def goodArtifact = "<artifactId>" + projectArtifactId + "</artifactId>"
	def goodVersion = "<version>" + projectVersion + "</version>"
	pom = pom.replace( badGroup, goodGroup )
	pom = pom.replace( badArtifact, goodArtifact )
	def posEndParent = pom.indexOf( "</parent>" )
	if ( posEndParent > 0 ) {
		pom = pom.substring(0, posEndParent) + 
					pom.substring(posEndParent).replace( badVersion, goodVersion )
	}
	pomFile.text = pom
	println "pom.xml updated with groupId=" + projectGroupId + " and artifactId=" + projectArtifactId
}
else {
    println "Warn: pom.xml not found in " + request.getOutputDirectory() + "/" + projectArtifactId
}

println "The project ${symbol_dollar}{shortName} has been generated."
println "Done."