//
// Created by Konrad Werys on 29/04/2019.
//

#ifndef ITKBULLSEYE_ITKBULLSEYEAPI_H
#define ITKBULLSEYE_ITKBULLSEYEAPI_H

#include "itkbullseyelib_export.h"
#include "PipelineRunner.h"

// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::int8_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::int16_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::int32_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::int64_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::uint8_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::uint16_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::uint32_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::uint64_t>;
// template class ITKBULLSEYELIB_EXPORT PipelineRunner<std::float_t>;

template class ITKBULLSEYELIB_EXPORT PipelineRunner<short>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<int>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<float>;
template class ITKBULLSEYELIB_EXPORT PipelineRunner<double>;

ITKBULLSEYELIB_EXPORT void dummyFunction();

#endif //ITKBULLSEYE_ITKBULLSEYEAPI_H
