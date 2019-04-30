//
// Created by Konrad Werys on 30/04/2019.
//



template<typename InputPixelType, typename OutputPixelType>
PipelineRunner<InputPixelType, OutputPixelType>::PipelineRunner()
        : nInputCols(0)
        , nInputRows(0)
        , nInputImages(0)
        , nOutputRows(0)
        , nOutputCols(0)
        , nOutputImages(0)
        , inputVolumePointer(nullptr)
        , outputVolumePointer(nullptr) {

}

template< typename InputPixelType, typename OutputPixelType>
int
PipelineRunner<InputPixelType, OutputPixelType>
::run(){

    std::cout << "PipeRunner::run" << std::endl;

    if (!inputVolumePointer){
        std::cerr << "inputVolumePointer is null" << std::endl;
        return 1; // EXIT_FAILURE
    }

    if (!outputVolumePointer){
        std::cerr << "outputVolumePointer is null" << std::endl;
        return 1; // EXIT_FAILURE
    }


    // TODO: change it!!!
    if (nInputCols * nInputRows * nInputImages != nOutputCols * nOutputRows * nOutputImages){
        std::cerr << "nInputCols * nInputRows * nInputImages != nOutputCols * nOutputRows * nOutputImages" << std::endl;
        return 1; // EXIT_FAILURE
    }

    for (size_t i = 0; i < nInputCols * nInputRows * nInputImages; ++i){
        outputVolumePointer[nInputCols * nInputRows * nInputImages - 1 - i] = static_cast<OutputPixelType>(inputVolumePointer[i]);
    }

    return 0; // EXIT_SUCCESS
}

// ---------------------------
// --- getters and setters ---
// ---------------------------

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNInputRows() const {
    return nInputRows;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNInputRows(size_t nInputRows) {
    PipelineRunner::nInputRows = nInputRows;
}

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNInputCols() const {
    return nInputCols;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNInputCols(size_t nInputCols) {
    PipelineRunner::nInputCols = nInputCols;
}

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNInputImages() const {
    return nInputImages;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNInputImages(size_t nInputImages) {
    PipelineRunner::nInputImages = nInputImages;
}

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNOutputRows() const {
    return nOutputRows;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNOutputRows(size_t nOutputRows) {
    PipelineRunner::nOutputRows = nOutputRows;
}

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNOutputCols() const {
    return nOutputCols;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNOutputCols(size_t nOutputCols) {
    PipelineRunner::nOutputCols = nOutputCols;
}

template<typename InputPixelType, typename OutputPixelType>
size_t PipelineRunner<InputPixelType, OutputPixelType>::getNOutputImages() const {
    return nOutputImages;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setNOutputImages(size_t nOutputImages) {
    PipelineRunner::nOutputImages = nOutputImages;
}

template<typename InputPixelType, typename OutputPixelType>
InputPixelType *PipelineRunner<InputPixelType, OutputPixelType>::getInputVolumePointer() const {
    return inputVolumePointer;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setInputVolumePointer(InputPixelType *inputVolumePointer) {
    PipelineRunner::inputVolumePointer = inputVolumePointer;
}

template<typename InputPixelType, typename OutputPixelType>
OutputPixelType *PipelineRunner<InputPixelType, OutputPixelType>::getOutputVolumePointer() const {
    return outputVolumePointer;
}

template<typename InputPixelType, typename OutputPixelType>
void PipelineRunner<InputPixelType, OutputPixelType>::setOutputVolumePointer(OutputPixelType *outputVolumePointer) {
    PipelineRunner::outputVolumePointer = outputVolumePointer;
}

template<typename InputPixelType, typename OutputPixelType>
PipelineRunner<InputPixelType, OutputPixelType>::~PipelineRunner() {

}
