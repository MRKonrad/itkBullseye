//
// Created by Konrad Werys on 24/03/2019.
//

#include "gtest/gtest.h"

#include "itkDummyFilter.h"
#include "itkDummyFunction.h"
#include "PipelineRunner.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
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

TEST(playground, PipelineRunner_test) {

    std::string inputFilename = "../../tests/testData/dicom/T1Map.dcm";
    std::string outputFilename = "../../tests/testData/temp/PipelineRunner_test.dcm";
    itk::FileTools::CreateDirectory("../../tests/testData/temp");

    typedef float InputPixelType;
    typedef int OutputPixelType;

    typedef itk::Image<InputPixelType, 3> InputImageType;
    typedef itk::Image<OutputPixelType, 3> OutputImageType;

    typedef itk::ImageFileReader<InputImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName (inputFilename);
    reader->Update();

    itk::Size<3> inputSize = reader->GetOutput()->GetLargestPossibleRegion().GetSize();

    PipelineRunner<InputPixelType, InputPixelType> pipelineRunner;
    KWImage<InputPixelType> *kwInputImage = new KWImage<InputPixelType>;
    std::vector<size_t> kwImputImageDims(3);
    kwImputImageDims[0] = inputSize[0];
    kwImputImageDims[1] = inputSize[1];
    kwImputImageDims[2] = inputSize[2];
    kwInputImage->setDims(kwImputImageDims);
    kwInputImage->setBuffer(reader->GetOutput()->GetBufferPointer());
    pipelineRunner.addInputImage(kwInputImage);

    EXPECT_NO_THROW(pipelineRunner.run());

    InputImageType::Pointer outputImage = InputImageType::New();

    itk::Index<3> start;
    start.Fill(0);

    itk::Size<3> outputSize;
    outputSize[0] = pipelineRunner.getNthOutputImage(0)->getDims()[0];
    outputSize[1] = pipelineRunner.getNthOutputImage(0)->getDims()[1];
    outputSize[2] = pipelineRunner.getNthOutputImage(0)->getDims()[2];

    itk::ImageRegion<3> region(start, outputSize);
    outputImage->SetRegions(region);
    outputImage->Allocate();

    pipelineRunner.getNthOutputImage(0)->copyToBuffer(outputImage->GetBufferPointer());

    typedef itk::CastImageFilter<InputImageType, OutputImageType> CasterType;
    CasterType::Pointer caster = CasterType::New();
    caster->SetInput(outputImage);

    typedef itk::ImageFileWriter<OutputImageType> WriterType;
    WriterType::Pointer writer = WriterType::New();
    writer->SetFileName (outputFilename);
    writer->SetInput(caster->GetOutput());
    writer->Update();

}
