#ifndef COMPILER_H
#define COMPILER_H

namespace cl {
  namespace compiler {
    // support of C++ 11
#if __cplusplus >= 201103L
    const bool cpp11_support = true;
#else
    const bool cpp11_support = false;
#endif

    // compiler type checking
    enum compiler_type {
      Unknown, GNUC, Microsoft, Clang, Borland, Sun
    };
#ifdef __GNUC__
    const compiler_type type = GNUC;
#elif __clang__
    const compiler_type type = Clang;
#elif __BORLANDC__
    const compiler_type type = Borland;
#elif _MSC_VER
    const compiler_type type = Microsoft;
#elif __SUNPRO_CC
    const compiler_type type = Sun;
#else
    const compiler_type type = Unknown;
#endif

    // compiler name definiton
#ifdef __GNUC__
    const char * name = "GNU C++ Compiler";
#elif __clang__
    const char * name = "Clang";
#elif __BORLANDC__
    const char * name = "Borland C++ Compiler";
#elif _MSC_VER
    const char * name = "Microsoft C++ Compiler";
#elif __SUNPRO_CC
    const char * name = "Sun C++ Compiler";
#else
    const char * name = "Unknown";
#endif
  }
}

#endif // COMPILER_H
