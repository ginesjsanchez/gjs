#ifndef _ORG_GJS_C_CC_CPP_BASE_CONFIG
#define _ORG_GJS_C_CC_CPP_BASE_CONFIG


#include <string>
#include <list>
#include <initializer_list>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <thread>
#include <map>
#include <vector>
#include <regex>
#include <ctime>
#include <cmath>
#include <limits>
#include <cstdio>
#include <algorithm>



#define REGEX_URL 			"([a-z0-9-]+://)?(localhost|[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+|[-a-z0-9]+(\\.[-a-z0-9]+)+)(:[0-9]+)?/?"
#define REGEX_URN 			"/([-a-zA-Z0-9_%]+(/[-a-zA-Z0-9_%]+)*)?(\\.[a-zA-Z]+)?(\\?(([a-zA-Z0-9-_%]+=[a-zA-Z0-9-_%]+)(&([a-zA-Z0-9-_%]+=[a-zA-Z0-9-_%]+))*))?"
#define REGEX_URI 			"([a-z0-9-]+://)?(localhost|[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+|[-a-z0-9]+(\\.[-a-z0-9]+)+)(:[0-9]+)?(/([-a-zA-Z0-9_%]+(/[-a-zA-Z0-9_%]+)*)?(\\.[a-zA-Z]+)?)?(\\?(([a-zA-Z0-9-_%]+=[a-zA-Z0-9-_%]+)(&([a-zA-Z0-9-_%]+=[a-zA-Z0-9-_%]+))*))?"


#endif
