#include <iostream>

using namespace std;

#ifdef __GNUC__
const char * compiler = "GNU C++ Compiler";
#endif

#ifdef __BORLANDC__
const char * compiler = "Borland C++ Compiler";
#endif

#ifdef _MSC_VER
const char * compiler = "Microsoft C++ Compiler";
#endif

#ifdef __SUNPRO_CC
const char * compiler = "Sun C++ Compiler";
#endif

#ifdef WIN32
const char * platform = "Windows";
#endif

#ifdef linux
const char * platform = "Linux";
#endif

#ifdef __sun
const char * platform = "Solaris";
#endif

int main() {
  cout << "Compiler: " << compiler << "\nPlatform: " << platform;
  return 0;
}