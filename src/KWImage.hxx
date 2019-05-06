//
// Created by Konrad Werys on 06/05/2019.
//

#ifndef ITKBULLSEYE_KWIMAGE_HXX
#define ITKBULLSEYE_KWIMAGE_HXX

#include "KWImage.h"

template<typename PixelType>
KWImage<PixelType>::KWImage() {
    managesBufferMemory = false;
}

template<typename PixelType>
KWImage<PixelType>:: ~KWImage() {
    if (managesBufferMemory){
        delete [] buffer;
    }
}

template<typename PixelType>
int
KWImage<PixelType>
::allocateBuffer(){

    buffer = new PixelType[getNumberOfPixels()];
    managesBufferMemory = true;

    return 0; //EXIT_SUCCESS
}

template<typename PixelType>
int
KWImage<PixelType>
::copyToBuffer(PixelType* buffer){

    for (int i = 0; i < this->getNumberOfPixels(); ++i) {
        buffer[i] = buffer[i];
    }
    return 0; //EXIT_SUCCESS
}

template<typename PixelType>
int
KWImage<PixelType>
::copyFromBuffer(PixelType* buffer){

    for (int i = 0; i < this->getNumberOfPixels(); ++i) {
        buffer[i] = buffer[i];
    }
    return 0; //EXIT_SUCCESS
}

template<typename PixelType>
size_t
KWImage<PixelType>
::getNumberOfPixels(){
    size_t dimsMultiplied = 1;
    for (int i = 0; i < dims.size(); i++) {
        dimsMultiplied = dimsMultiplied * dims[i];
    }
    return dimsMultiplied;
}

template<typename PixelType>
PixelType *KWImage<PixelType>::getBuffer() const {
    return buffer;
}

template<typename PixelType>
void KWImage<PixelType>::setBuffer(PixelType *buffer) {
    KWImage::buffer = buffer;
}

template<typename PixelType>
const std::vector<size_t> &KWImage<PixelType>::getDims() const {
    return dims;
}

template<typename PixelType>
void KWImage<PixelType>::setDims(const std::vector<size_t> &dims) {
    KWImage::dims = dims;
}

template<typename PixelType>
bool KWImage<PixelType>::getManagesBufferMemory() const {
    return managesBufferMemory;
}

template<typename PixelType>
void KWImage<PixelType>::setManagesBufferMemory(bool managesBufferMemory) {
    KWImage::managesBufferMemory = managesBufferMemory;
}


#endif //ITKBULLSEYE_KWIMAGE_HXX
