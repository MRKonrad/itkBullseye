//
// Created by Konrad Werys on 06/05/2019.
//

#ifndef ITKBULLSEYE_KWIMAGE_H
#define ITKBULLSEYE_KWIMAGE_H

#include "itkbullseyelib_export.h"
#include <iostream>
#include <vector>

template< typename PixelType>
class KWImage {

public:
    KWImage();

    virtual ~KWImage();

    int allocateBuffer();

    int copyToBuffer(PixelType* buffer);

    int copyFromBuffer(PixelType* buffer);

    size_t getNumberOfPixels();

    PixelType *getBuffer() const;

    void setBuffer(PixelType *buffer);

    const std::vector<size_t> &getDims() const;

    void setDims(const std::vector<size_t> &dims);

    bool getManagesBufferMemory() const;

    void setManagesBufferMemory(bool managesBufferMemory);

private:

    PixelType* buffer;
    std::vector<size_t> dims;
    bool managesBufferMemory;
};


#ifdef ITKBULLSEYELIB_COMPILATION
#include "KWImage.hxx"
#endif // ITKBULLSEYELIB_COMPILATION

#endif //ITKBULLSEYE_KWIMAGE_H
