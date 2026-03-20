#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
${symbol_pound} Libray modules
${symbol_pound}
${symbol_pound} Library ${capitalizedName} 
${symbol_pound}
from Sample import es_par, sumar
from SampleType import SampleType

__version__ = "${version}"
__all__ = ["sumar", "es_par", "SampleType"]

