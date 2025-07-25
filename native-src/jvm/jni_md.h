#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

// Улучшенная поддержка Windows
#ifdef _WIN32
    #ifdef _JNI_IMPLEMENTATION_
        #define JNIEXPORT __declspec(dllexport)
    #else
        #define JNIEXPORT __declspec(dllimport)
    #endif
    #define JNIIMPORT __declspec(dllimport)
    #define JNICALL __stdcall
#else
    // Поддержка Unix-подобных систем и современных компиляторов
    #ifndef __has_attribute
        #define __has_attribute(x) 0
    #endif
    #if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2))) || __has_attribute(visibility)
        #define JNIEXPORT     __attribute__((visibility("default")))
        #define JNIIMPORT     __attribute__((visibility("default")))
    #else
        #define JNIEXPORT
        #define JNIIMPORT
    #endif
    #define JNICALL
#endif

// Стандартные типы JNI
typedef int jint;

// Улучшенная обработка 64-битных систем
#ifdef _LP64
    typedef long jlong;
#else
    typedef long long jlong;
#endif

typedef signed char jbyte;

// Добавление недостающих типов для полноценной работы
typedef unsigned char   jboolean;
typedef unsigned short  jchar;
typedef short           jshort;
typedef float           jfloat;
typedef double          jdouble;
typedef jint            jsize;

#endif /* !_JAVASOFT_JNI_MD_H_ */
