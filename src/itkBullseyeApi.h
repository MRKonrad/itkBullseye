//
// Created by Konrad Werys on 29/04/2019.
//

#ifndef ITKBULLSEYE_ITKBULLSEYEAPI_H
#define ITKBULLSEYE_ITKBULLSEYEAPI_H

#include "itkbullseyelib_export.h"
#include "PipelineRunner.h"

template class ITKBULLSEYELIB_EXPORT PipelineRunner<short>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<int>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<float>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<double>;

template class ITKBULLSEYELIB_EXPORT KWImage<short>;
template class ITKBULLSEYELIB_EXPORT KWImage<int>;
template class ITKBULLSEYELIB_EXPORT KWImage<float>;
template class ITKBULLSEYELIB_EXPORT KWImage<double>;

ITKBULLSEYELIB_EXPORT void dummyFunction();

#endif //ITKBULLSEYE_ITKBULLSEYEAPI_H
