//
// Created by Konrad Werys on 30/04/2019.
//

//#include "itkSobelEdgeDetectionImageFilter.h"
#include "itkTensorFlowFilter.h"
#include "oxtfUtils.h"
#include "KWImageUtils.h"
#include "oxtfPipelineBuilder.h"

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

        typedef itk::Image<InputPixelType, 3> InputImageType;
        typedef itk::Image<OutputPixelType, 3> OutputImageType;

        if (!inputImages[i]->getBuffer()) {
            std::cerr << "inputVolumePointer is null" << std::endl;
            continue;
        }

        typename InputImageType::Pointer itkInputImage = KWImageUtils::KWImage2ItkImage<InputImageType, InputPixelType >(inputImages[i]);

        oxtf::GraphReader graphReader;
        graphReader.setGraphPath(userData["model_path"]);
        graphReader.readGraph();

        oxtf::PipelineBuilder pipelineBuilder;
        itkInputImage = pipelineBuilder.padImage<InputImageType>(itkInputImage, graphReader.getMaxX(), graphReader.getMaxY());

        typedef itk::TensorFlowImageFilter <InputImageType, OutputImageType> TensorFlowImageFilterType;
        typename TensorFlowImageFilterType::Pointer tfFilter = TensorFlowImageFilterType::New();
        tfFilter->SetInput(itkInputImage);
        tfFilter->SetGraphReader(&graphReader);
        tfFilter->Update();

        KWImage<OutputPixelType> *kwOutputImage = KWImageUtils::ItkImage2KWImage<OutputImageType, OutputPixelType>(tfFilter->GetOutput());

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




