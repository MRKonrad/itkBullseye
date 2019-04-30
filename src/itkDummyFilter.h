//
// Created by Konrad Werys on 29/04/2019.
//

#ifndef ITKBULLSEYE_ITKDUMMYFILTER_H
#define ITKBULLSEYE_ITKDUMMYFILTER_H

#include "itkImageToImageFilter.h"
#include "itkbullseyelib_export.h"

namespace itk
{
    template< typename TInputImage, typename TOutputImage1, typename TOutputImage2>
    class DummyFilter : public ImageToImageFilter< TInputImage, TOutputImage1 > // This doesn't actually matter, as we will be overriding the output image type in MakeOutput()
    {
    public:
        /** Standard class typedefs. */
        typedef DummyFilter Self;
        typedef ImageToImageFilter< TInputImage, TOutputImage1 > Superclass;
        typedef SmartPointer< Self > Pointer;

        /** Method for creation through the object factory. */
        itkNewMacro(Self);

        /** Run-time type information (and related methods). */
        itkTypeMacro(ImageFilterMultipleOutputsDifferentType, ImageToImageFilter);

        TOutputImage1* GetOutput1();
        TOutputImage2* GetOutput2();

    protected:
        DummyFilter();
        ~DummyFilter(){}

        /** Does the real work. */
        virtual void GenerateData() ITK_OVERRIDE;

        /**  Create the Output */
        DataObject::Pointer MakeOutput(unsigned int idx);

    private:
        DummyFilter(const Self &); //purposely not implemented
        void operator=(const Self &);  //purposely not implemented

    };
} //namespace ITK

#ifndef ITK_MANUAL_INSTANTIATION
#ifdef ITKBULLSEYELIB_EXPORT
#include "itkDummyFilter.hxx"
#endif // ITKBULLSEYELIB_EXPORT
#endif // ITK_MANUAL_INSTANTIATION

#endif //ITKBULLSEYE_ITKDUMMYFILTER_H
