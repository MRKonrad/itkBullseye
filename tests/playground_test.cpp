//
// Created by Konrad Werys on 24/03/2019.
//

#include "gtest/gtest.h"

#include "itkDummyFilter.h"
#include "itkDummyFunction.h"
#include "PipelineRunner.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkFileTools.h"

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

//TEST(playground, PipelineRunner_test) {
//
//    typedef float TYPE;
//
//    TYPE zeroValue = 10;
//    TYPE testValue = 10;
//
//    size_t nCols = 10;
//    size_t nRows = 10;
//    size_t nImages = 1;
//    std::vector<TYPE> input(nCols * nRows * nImages, zeroValue);
//    std::vector<TYPE> output(nCols * nRows * nImages, zeroValue);
//
//    input[nCols * nRows * nImages - 1] = testValue;
//
//    PipelineRunner<TYPE> pipelineRunner;
//    pipelineRunner.setNInputCols(nCols);
//    pipelineRunner.setNInputRows(nRows);
//    pipelineRunner.setNInputImages(nImages);
//    pipelineRunner.setInputVolumePointer(&input[0]);
//    pipelineRunner.setNOutputCols(nCols);
//    pipelineRunner.setNOutputRows(nRows);
//    pipelineRunner.setNOutputImages(nImages);
//    pipelineRunner.setOutputVolumePointer(&output[0]);
//
//    EXPECT_NO_THROW(pipelineRunner.run());
//    EXPECT_EQ(output[0], testValue);
//    EXPECT_EQ(output[1], zeroValue);
//
//}

TEST(playground, PipelineRunner_test) {

    std::string inputFilename = "../../tests/testData/dicom/T1Map.dcm";
    std::string outputFilename = "../../tests/testData/temp/PipelineRunner_test.dcm";
    itk::FileTools::CreateDirectory("../../tests/testData/temp");

    typedef float TYPE;

    typedef itk::Image<TYPE, 3> InputImageType;
    typedef itk::Image<int, 3> OutputImageType;

    typedef itk::ImageFileReader<InputImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName (inputFilename);
    reader->Update();

    itk::Size<3> inputSize = reader->GetOutput()->GetLargestPossibleRegion().GetSize();

    PipelineRunner<TYPE> pipelineRunner;
    pipelineRunner.setNInputCols(inputSize[0]);
    pipelineRunner.setNInputRows(inputSize[1]);
    pipelineRunner.setNInputImages(inputSize[2]);
    pipelineRunner.setInputVolumePointer(reader->GetOutput()->GetBufferPointer());
    EXPECT_NO_THROW(pipelineRunner.run());

    OutputImageType::Pointer outputImage = OutputImageType::New();

    itk::Index<3> start;
    start.Fill(0);

    itk::Size<3> outputSize;
    outputSize[0] = pipelineRunner.getNOutputCols();
    outputSize[1] = pipelineRunner.getNOutputRows();
    outputSize[2] = pipelineRunner.getNOutputImages();

    itk::ImageRegion<3> region(start, outputSize);
    outputImage->SetRegions(region);
    outputImage->Allocate();

    for (int i = 0; i < outputSize[0] * outputSize[1] * outputSize[2]; ++i){
        outputImage->GetBufferPointer()[i] = pipelineRunner.getOutputVolumePointer()[i];
    }

    typedef itk::ImageFileWriter<OutputImageType> WriterType;
    WriterType::Pointer writer = WriterType::New();
    writer->SetFileName (outputFilename);
    writer->SetInput(outputImage);
    writer->Update();

}
