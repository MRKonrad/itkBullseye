# see https://github.com/Neargye/hello_tf_c_api

if(UNIX AND NOT APPLE)
    set(DownloadUrl "https://github.com/MRKonrad/itkTensorFlow/releases/download/v0.3/itkTensorFlowLib_v0.3_linux.zip")
    set(DownloadPath ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/itkTensorflowLib.tar.gz)
elseif(APPLE)
    set(DownloadUrl "https://github.com/MRKonrad/itkTensorFlow/releases/download/v0.3/itkTensorFlowLib_v0.3_osx.zip")
    set(DownloadPath ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/itkTensorflowLib.tar.gz)
elseif(WIN32) # confusingly this means any windows system
    set(DownloadUrl "https://github.com/MRKonrad/itkTensorFlow/releases/download/v0.3/itkTensorFlowLib_v0.3_windows_x64.zip")
    set(DownloadPath ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/itkTensorflowLib.zip)
endif()

if (NOT EXISTS ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow)
    make_directory(${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow)
endif()

if (
        NOT EXISTS ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow/libitkTensorflowLib.dylib AND
        NOT EXISTS ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow/libitkTensorflowLib.so AND
        NOT EXISTS ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow/itkTensorflowLib.dll )

    file( DOWNLOAD ${DownloadUrl} ${DownloadPath} STATUS status LOG log)

    list(GET status 0 status_code)
    list(GET status 1 status_string)
    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "error downloading itkTensorflowLib: ${status_string}" "${log}")
    endif()

    execute_process(
            COMMAND cmake -E tar xvzf ${DownloadPath}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow)
    file(REMOVE ${DownloadPath})

endif()

include_directories(${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow/include)
link_directories(${CMAKE_SOURCE_DIR}/thirdParty/itkTensorflow)

#if(WIN32) # confusingly this means any windows system
#    configure_file(thirdParty/tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/Debug/tensorflow.dll COPYONLY)
#    configure_file(thirdParty/tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tests/Debug/tensorflow.dll COPYONLY)
#    configure_file(thirdParty/tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/Release/tensorflow.dll COPYONLY)
#    configure_file(thirdParty/tensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/tests/Release/tensorflow.dll COPYONLY)
#endif()
