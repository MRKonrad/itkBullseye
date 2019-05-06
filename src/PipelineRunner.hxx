//
// Created by Konrad Werys on 30/04/2019.
//

#include "itkSobelEdgeDetectionImageFilter.h"


template<typename InputPixelType, typename OutputPixelType>
PipelineRunner<InputPixelType, OutputPixelType>::PipelineRunner() {

}

template<typename InputPixelType, typename OutputPixelType>
PipelineRunner<InputPixelType, OutputPixelType>::~PipelineRunner() {

    for (int i = 0; i < inputImages.size(); i++){
        delete inputImages[i];
    }

    for (int i = 0; i < outputImages.size(); i++){
        delete outputImages[i];
    }
}

template< typename InputPixelType, typename OutputPixelType>
int
PipelineRunner<InputPixelType, OutputPixelType>
::run(){

    std::cout << "PipeRunner::run" << std::endl;

    for (int i = 0; i < inputImages.size(); i++) {
        KWImage<InputPixelType> *kwInputImage = inputImages[i];

        if (!kwInputImage->getBuffer()) {
            std::cerr << "inputVolumePointer is null" << std::endl;
            continue;
        }

        typedef itk::Image<InputPixelType, 3> InputImageType;
        typedef itk::Image<OutputPixelType, 3> OutputImageType;

        typename InputImageType::Pointer itkInputImage = InputImageType::New();
        itk::Index<3> start;
        start.Fill(0);

        itk::Size<3> inputSize;
        inputSize[0] = kwInputImage->getDims()[0];
        inputSize[1] = kwInputImage->getDims()[1];
        inputSize[2] = kwInputImage->getDims()[2];

        itk::ImageRegion<3> region(start, inputSize);
        itkInputImage->SetRegions(region);
        itkInputImage->Allocate();

        kwInputImage->copyToBuffer(itkInputImage->GetBufferPointer());

        typedef itk::SobelEdgeDetectionImageFilter<InputImageType, OutputImageType> SobelEdgeDetectionImageFilterType;
        typename SobelEdgeDetectionImageFilterType::Pointer sobelFilter = SobelEdgeDetectionImageFilterType::New();
        sobelFilter->SetInput(itkInputImage);
        sobelFilter->Update();

        typename OutputImageType::Pointer outputImage = sobelFilter->GetOutput();
        itk::Size<3> itkOutputSize = outputImage->GetLargestPossibleRegion().GetSize();

        std::vector<size_t> vectorOutputSize(3);
        vectorOutputSize[0] = itkOutputSize[0];
        vectorOutputSize[1] = itkOutputSize[1];
        vectorOutputSize[2] = itkOutputSize[2];

        KWImage<OutputPixelType> *kwOutputImage = new KWImage<OutputPixelType>();
        kwOutputImage->setDims(vectorOutputSize);
        kwOutputImage->allocateBuffer();
        kwOutputImage->copyFromBuffer(outputImage->GetBufferPointer());

        outputImages.push_back(kwOutputImage);
    }

    return 0; // EXIT_SUCCESS
}

template<typename InputPixelType, typename OutputPixelType>
int
PipelineRunner<InputPixelType, OutputPixelType>
::addInputImage(KWImage<InputPixelType> *image){
    inputImages.push_back(image);
    return 0; // EXIT_SUCCESS
}

template<typename InputPixelType, typename OutputPixelType>
int
PipelineRunner<InputPixelType, OutputPixelType>
::addOutputImage(KWImage<OutputPixelType> *image){
    outputImages.push_back(image);
    return 0; // EXIT_SUCCESS
}

template<typename InputPixelType, typename OutputPixelType>
KWImage<InputPixelType> *
PipelineRunner<InputPixelType, OutputPixelType>
::getNthInputImage(size_t n) {
    return inputImages[n];
}

template<typename InputPixelType, typename OutputPixelType>
KWImage<OutputPixelType> *
PipelineRunner<InputPixelType, OutputPixelType>
::getNthOutputImage(size_t n) {
    return outputImages[n];
}




