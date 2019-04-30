//
// Created by Konrad Werys on 30/04/2019.
//

#ifndef ITKBULLSEYE_PIPELINERUNNER_H
#define ITKBULLSEYE_PIPELINERUNNER_H

#include "itkbullseyelib_export.h"
#include <iostream>

template< typename InputPixelType, typename OutputPixelType = InputPixelType>
class PipelineRunner {

public:

    PipelineRunner();

    virtual ~PipelineRunner();

    int run();

    size_t getNInputRows() const;
    void setNInputRows(size_t nInputRows);

    size_t getNInputCols() const;
    void setNInputCols(size_t nInputCols);

    size_t getNInputImages() const;
    void setNInputImages(size_t nInputImages);

    size_t getNOutputRows() const;
    void setNOutputRows(size_t nOutputRows);

    size_t getNOutputCols() const;
    void setNOutputCols(size_t nOutputCols);

    size_t getNOutputImages() const;
    void setNOutputImages(size_t nOutputImages);

    InputPixelType *getInputVolumePointer() const;
    void setInputVolumePointer(InputPixelType *inputVolumePointer);

    OutputPixelType *getOutputVolumePointer() const;
    void setOutputVolumePointer(OutputPixelType *outputVolumePointer);

private:
    size_t nInputRows;
    size_t nInputCols;
    size_t nInputImages;
    size_t nOutputRows;
    size_t nOutputCols;
    size_t nOutputImages;

    InputPixelType* inputVolumePointer;
    OutputPixelType* outputVolumePointer;

};



#ifdef ITKBULLSEYELIB_EXPORT
#include "PipelineRunner.hxx"
#endif // ITKBULLSEYELIB_EXPORT

#endif //ITKBULLSEYE_PIPELINERUNNER_H
