#ifndef CONSOLE_H
#define CONSOLE_H

#include "platform.h"

using cl::os::type;
using cl::os::os_type;

#if type == Windows
#include <windows.h>
#endif

namespace cl {
  namespace console {
    enum color {

    };

    // color setter
    void background_color(color clr) {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ));
    }

    void foreground_color(color clr);

    // color getter
    color background_color();
    color foreground_color();

    // print character and integers
    void log(char ch);
    void log(short);
    void log(int);
    void log(long);
    void log(long long);
    void log(unsigned short);
    void log(unsigned int);
    void log(unsigned long);
    void log(unsigned long long);

    // print pointers
    template <typename type>
    void log(const type * ptr);

    // specialize pointer to character - it's a string
    template<>
    void log(const char * str);
  }
}

#endif // CONSOLE_H
