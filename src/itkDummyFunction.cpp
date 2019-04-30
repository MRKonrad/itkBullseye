//
// Created by Konrad Werys on 30/04/2019.
//

#include "itkDummyFunction.h"

void dummyFunction(){
    std::cout << "Hello Api world" << std::endl;

#ifdef ITKBULLSEYELIB_STATIC_DEFINE
    std::cout << "ITKBULLSEYELIB_STATIC_DEFINE" << std::endl;
#endif

#ifdef itkBullseyeLib_EXPORTS
    std::cout << "itkBullseyeLib_EXPORTS" << std::endl;
#endif

#ifdef ITKBULLSEYELIB_EXPORT
    std::cout << "ITKBULLSEYELIB_EXPORT" << std::endl;
#endif

}
