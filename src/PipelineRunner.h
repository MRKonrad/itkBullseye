//
// Created by Konrad Werys on 30/04/2019.
//

#ifndef ITKBULLSEYE_PIPELINERUNNER_H
#define ITKBULLSEYE_PIPELINERUNNER_H

#include "itkbullseyelib_export.h"
#include <iostream>
#include <map>
#include "KWImage.h"

template< typename InputPixelType, typename OutputPixelType = InputPixelType>
class PipelineRunner {

public:

    PipelineRunner();

    virtual ~PipelineRunner();

    int run();

    int addInputImage(KWImage<InputPixelType> *image);

    int addOutputImage(KWImage<OutputPixelType> *image);

    KWImage<InputPixelType> * getNthInputImage(size_t n);

    KWImage<OutputPixelType> * getNthOutputImage(size_t n);

    std::map<std::string, std::string> userData;

private:

    std::vector < KWImage < InputPixelType > * > inputImages;
    std::vector < KWImage < OutputPixelType > * > outputImages;

};



#ifndef ITKBULLSEYELIB_API
#include "PipelineRunner.hxx"
#endif // ITKBULLSEYELIB_API

#endif //ITKBULLSEYE_PIPELINERUNNER_H
