//
// Created by Konrad Werys on 24/03/2019.
//

#include "gtest/gtest.h"

#include "itkDummyFilter.h"
#include "itkDummyFunction.h"
#include "PipelineRunner.h"

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

    typedef float TYPE;

    TYPE zeroValue = 10;
    TYPE testValue = 10;

    size_t nCols = 10;
    size_t nRows = 10;
    size_t nImages = 1;
    std::vector<TYPE> input(nCols * nRows * nImages, zeroValue);
    std::vector<TYPE> output(nCols * nRows * nImages, zeroValue);

    input[nCols * nRows * nImages - 1] = testValue;

    PipelineRunner<TYPE> pipelineRunner;
    pipelineRunner.setNInputCols(nCols);
    pipelineRunner.setNInputRows(nRows);
    pipelineRunner.setNInputImages(nImages);
    pipelineRunner.setInputVolumePointer(&input[0]);
    pipelineRunner.setNOutputCols(nCols);
    pipelineRunner.setNOutputRows(nRows);
    pipelineRunner.setNOutputImages(nImages);
    pipelineRunner.setOutputVolumePointer(&output[0]]);

    EXPECT_NO_THROW(pipelineRunner.run());
    EXPECT_EQ(output[0], testValue);
    EXPECT_EQ(output[1], zeroValue);

}
