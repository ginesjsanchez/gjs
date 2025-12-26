import groovy.io.FileType
import java.nio.file.Path
import java.util.regex.Pattern
import org.apache.commons.io.FileUtils


println "Post generate tasks..."

def replaceTags(String text) {
	return text.replaceAll( "__shortName__", shortName ).replaceAll( "__capitalizedName__", shortName.capitalize() )
			.replaceAll( "__lan__", lan ).replaceAll( "__ext__", ext ).replaceAll( "__prefix__", prefix )
}

def copyFile(File in, File dirOut) {
	//String outName = replaceTags( in.getName() )
	String outName = in.getName()
	println "   Copy file ${outName}"
	def out = new File( dirOut, outName )
	out << in.text
}

def copyDirectory(File dirIn, File dirOut) {
	println "   Copy directory ${dirOut}"
	if (!dirOut.exists()) {
		dirOut.mkdirs()
	}
	dirIn.eachFile(FileType.FILES) { file -> copyFile( file, dirOut ) }
	dirIn.eachDir() { dir -> 	
		String outName = replaceTags( dir.getName() )
		def out = new File( dirOut, outName )
		copyDirectory( dir, out ) 
	}
}



//println "1) Adapting the artifact to the ${lan} language..."

//def dirLanIn = new File(request.getOutputDirectory(), "${artifactId}/src/main/resources/archetype-resources/src/main/_lan_")
//def dirLanOut = new File(request.getOutputDirectory(), "${artifactId}/src/main/resources/archetype-resources/src/main/${lan}")
//dirLanIn.renameTo("${dirLanOut}")

//def dirTestLanIn = new File(request.getOutputDirectory(), "${artifactId}/src/main/resources/archetype-resources/src/test/_lan_")
//def dirTestLanOut = new File(request.getOutputDirectory(), "${artifactId}/src/main/resources/archetype-resources/src/test/${lan}")
//dirTestLanIn.renameTo("${dirTestLanOut}")

println "The archetype ${artifactId} has been generated."
println "Done."