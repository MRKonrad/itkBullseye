//
// Created by Konrad Werys on 24/03/2019.
//

#include "gtest/gtest.h"

#include "itkDummyFilter.h"
#include "itkDummyFunction.h"
#include "oxtfPipelineBuilder.h"
//#include "PipelineRunner.h"
//#include "KWImageUtils.h"
//
//#include "itkImageFileReader.h"
//#include "itkImageFileWriter.h"
//#include "itkCastImageFilter.h"
//#include "itkMultiplyImageFilter.h"
#include "itkFileTools.h"

//// causes "H5::DataSpaceIException"

TEST(playground, DummyFilter_test) {

    typedef itk::Image<unsigned char, 2>   InputImageType;
    typedef itk::Image<float, 2>   OutputImageType1;
    typedef itk::Image<int, 2>   OutputImageType2;
    typedef itk::DummyFilter<InputImageType, OutputImageType1, OutputImageType2>  FilterType;

    FilterType::Pointer filter = FilterType::New();

    EXPECT_NO_THROW(filter->Update());

}

TEST(playground, itkBullseyeApi_test) {
    dummyFunction();
    EXPECT_NO_THROW(dummyFunction());

}

TEST(playground, PipelineRunner_segmentation_test) {

    std::vector<std::string> inputFilenames;
    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
    std::string outputDir = "../../tests/testData/temp/PipelineRunner_segmentation_test";
    std::string modelFilePath = "../../tests/testData/models/model_ocmr7.pb";
    itk::FileTools::CreateDirectory("../../tests/testData/temp");

    typedef float PixelType;
    typedef itk::Image<PixelType, 3> ImageType;

    oxtf::PipelineBuilder pipelineBuilder;
    oxtf::GraphReader *graphReader = pipelineBuilder.graphReaderMaker(modelFilePath);
    if (!graphReader) return; // no model

    pipelineBuilder.setInputImagesGrayscalePaths(inputFilenames);
    ImageType::Pointer imageIn = pipelineBuilder.readInputImage<ImageType>();
    ImageType::SizeType size = imageIn->GetLargestPossibleRegion().GetSize();
    imageIn = pipelineBuilder.padImage<ImageType>(imageIn, graphReader->getMaxX(), graphReader->getMaxY());

    //***************************
    //*** special sauce start ***
    //***************************

    itk::Size<3> inputSize = imageIn->GetLargestPossibleRegion().GetSize();

    KWImage<PixelType> *kwInputImage = KWImageUtils::ItkImage2KWImage<ImageType, PixelType>(imageIn);

    PipelineRunner<PixelType, PixelType> pipelineRunner;
    pipelineRunner.addInputImage(kwInputImage);
    pipelineRunner.userData["model_path"] = modelFilePath;

    EXPECT_NO_THROW(pipelineRunner.run());

    ImageType::Pointer outputImage = KWImageUtils::KWImage2ItkImage<ImageType, PixelType >(pipelineRunner.getNthOutputImage(0));

    //***************************
    //*** special sauce stop  ***
    //***************************

    outputImage = pipelineBuilder.cropImage<ImageType>(outputImage, size[0], size[1]);
    outputImage = pipelineBuilder.multiplyImage<ImageType>(outputImage, 255);
    pipelineBuilder.writeImages<ImageType>(outputImage, outputDir);

}
//
//TEST(playground, PipelineRunner_moco_test) {
//
//    std::vector<std::string> inputFilenames;
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    inputFilenames.emplace_back("../../tests/testData/dicom/T1Map.dcm");
//    std::string modelFilePath = "../../tests/testData/models/MoCoAI.pb";
//    std::string outputDir = "../../tests/testData/temp/PipelineRunner_moco_test";
//    itk::FileTools::CreateDirectory("../../tests/testData/temp");
//
//    typedef float PixelType;
//    typedef itk::Image<PixelType, 3> ImageType;
//
//    oxtf::PipelineBuilder pipelineBuilder;
//    oxtf::GraphReader *graphReader = pipelineBuilder.graphReaderMaker(modelFilePath);
//    if (!graphReader) return; // no model
//
//    pipelineBuilder.setInputImagesGrayscalePaths(inputFilenames);
//    ImageType::Pointer imageIn = pipelineBuilder.readInputImage<ImageType>();
//    //imageIn = pipelineBuilder.padImage<ImageType>(imageIn, graphReader->getMaxX(), graphReader->getMaxY());
//
//    //***************************
//    //*** special sauce start ***
//    //***************************
//
//    KWImage<PixelType> *kwInputImage = KWImageUtils::ItkImage2KWImage<ImageType, PixelType>(imageIn);
//
//    PipelineRunner<PixelType, PixelType> pipelineRunner;
//    pipelineRunner.addInputImage(kwInputImage);
//    pipelineRunner.userData["model_path"] = modelFilePath;
//
//    EXPECT_NO_THROW(pipelineRunner.run());
//
//    ImageType::Pointer outputImage = KWImageUtils::KWImage2ItkImage<ImageType, PixelType >(pipelineRunner.getNthOutputImage(0));
//
//    //***************************
//    //*** special sauce stop  ***
//    //***************************
//
//    //outputImage = pipelineBuilder.multiplyImage<ImageType>(outputImage, 50);
//    pipelineBuilder.writeImages<ImageType>(outputImage, outputDir);
//
//}
