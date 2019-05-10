//
// Created by Konrad Werys on 09/05/2019.
//

#ifndef ITKBULLSEYE_KWIMAGEUTILS_H
#define ITKBULLSEYE_KWIMAGEUTILS_H

#include "KWImage.h"
#include "itkImage.h"

namespace KWImageUtils {

    template<typename TImage, typename PixelType>
    KWImage<PixelType> *
    ItkImage2KWImage(typename TImage::Pointer itkImage) {

        typename TImage::SizeType itkSize = itkImage->GetLargestPossibleRegion().GetSize();
        int dim = itkSize.GetSizeDimension();

        KWImage<PixelType> *kwImage = new KWImage<PixelType>;
        std::vector<size_t> kwImputImageDims(dim);
        for (int i = 0; i < dim; i++) {
            kwImputImageDims[i] = itkSize[i];
        }
        kwImage->setDims(kwImputImageDims);

        // if we want to use the itk image memory:
        // kwImage->setBuffer(itkImage->GetBufferPointer());

        // if we want to copy the memory
        kwImage->allocateBuffer();
        kwImage->copyFromBuffer(itkImage->GetBufferPointer());
        return kwImage;
    }

    template<typename TImage, typename PixelType>
    typename TImage::Pointer
    KWImage2ItkImage(KWImage<PixelType> * kwImage){

        const size_t dim = kwImage->getDims().size();

        typename TImage::Pointer itkImage = TImage::New();
        typename TImage::IndexType start;
        start.Fill(0);

        typename TImage::SizeType inputSize;
        for (size_t i = 0; i < dim; ++i){
            inputSize[i] = kwImage->getDims()[i];
        }

        typename TImage::RegionType region(start, inputSize);
        itkImage->SetRegions(region);
        itkImage->Allocate();

        kwImage->copyToBuffer(itkImage->GetBufferPointer());

        return itkImage;
    }


} // KWImageUtils

#endif //ITKBULLSEYE_KWIMAGEUTILS_H
