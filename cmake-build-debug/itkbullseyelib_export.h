
#ifndef ITKBULLSEYELIB_EXPORT_H
#define ITKBULLSEYELIB_EXPORT_H

#ifdef ITKBULLSEYELIB_STATIC_DEFINE
#  define ITKBULLSEYELIB_EXPORT
#  define ITKBULLSEYELIB_NO_EXPORT
#else
#  ifndef ITKBULLSEYELIB_EXPORT
#    ifdef itkBullseyeLib_EXPORTS
        /* We are building this library */
#      define ITKBULLSEYELIB_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ITKBULLSEYELIB_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ITKBULLSEYELIB_NO_EXPORT
#    define ITKBULLSEYELIB_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ITKBULLSEYELIB_DEPRECATED
#  define ITKBULLSEYELIB_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ITKBULLSEYELIB_DEPRECATED_EXPORT
#  define ITKBULLSEYELIB_DEPRECATED_EXPORT ITKBULLSEYELIB_EXPORT ITKBULLSEYELIB_DEPRECATED
#endif

#ifndef ITKBULLSEYELIB_DEPRECATED_NO_EXPORT
#  define ITKBULLSEYELIB_DEPRECATED_NO_EXPORT ITKBULLSEYELIB_NO_EXPORT ITKBULLSEYELIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKBULLSEYELIB_NO_DEPRECATED
#    define ITKBULLSEYELIB_NO_DEPRECATED
#  endif
#endif

#endif
