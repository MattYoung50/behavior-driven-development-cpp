#ifndef GHERKIN_PORT_H_
#define GHERKIN_PORT_H_

#ifdef _WIN32
#    ifdef GHERKIN_C_EXPORTS
#        define GHERKIN_C_API_ __declspec(dllexport)
#    else
#        define GHERKIN_C_API_ __declspec(dllimport)
#    endif
#elif __GNUC__ >= 4 || defined(__clang__)
#    define GHERKIN_C_API_ __attribute__((visibility ("default")))
#else
#    define GHERKIN_C_API_
#endif

#endif /* GHERKIN_PORT_H_ */