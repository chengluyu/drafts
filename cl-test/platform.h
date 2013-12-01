#ifndef PLATFORM_H
#define PLATFORM_H

namespace cl {
  namespace os {
    enum os_type {
      Unknown, Windows, Linux, Mac, Solaris
    };

#ifdef _WIN32
    const os_type type = Windows;
    const char * name = "Windows";
#elif linux
    const os_type type = Linux;
    const char * name = "Linux";
#elif __sun
    const os_type type = Solaris;
    const char * name = "Solaris";
#else
    const os_type type = Unknown;
    const char * name = "Unknown";
#endif
  }
}

#endif // PLATFORM_H
