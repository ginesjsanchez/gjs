#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
${symbol_pound} Libray modules
${symbol_pound}
${symbol_pound} Library ${artifactId} 
${symbol_pound}
from Sample import es_par, sumar
from SampleType import SampleType

__version__ = "${version}"
__all__ = ["sumar", "es_par", "SampleType"]

