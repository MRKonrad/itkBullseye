//
// Created by Konrad Werys on 20/05/2019.
// based on https://stackoverflow.com/questions/1505582/determining-32-vs-64-bit-in-c
//

#ifndef ITKBULLSEYE_SYSTEM32OR64_H
#define ITKBULLSEYE_SYSTEM32OR64_H

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#endif //ITKBULLSEYE_SYSTEM32OR64_H
