import groovy.io.FileType
import java.nio.file.Path
import java.util.regex.Pattern
import org.apache.commons.io.FileUtils


println "Post generate tasks..."


def replaceTags(String text) {
	return text.replaceAll( "__shortName__", shortName ).replaceAll( "__capitalizedName__", shortName.capitalize() )
}

def processFile(File file, File dir) {
	String newName = replaceTags( in.getName() )
	File newFile = new File( dir, newName )
	file.renameTo("${newFile}")
}

def processDirectory(File dir) {
	dirIn.eachFile(FileType.FILES) { file -> processFile( file, dir ) }
	dirIn.eachDir() { subdir -> processDirectory( subdir ) }
}



println "1) Processing filenames..."
def dirSrc = new File(request.getOutputDirectory(), "${artifactId}/src")
if( dirSrc.exists() ) {
	try {
		processDirectory(dirSrc);
	} catch (IOException e) {
		e.printStackTrace();
	}
}

println "The project ${artifactId} has been generated."
println "Done."