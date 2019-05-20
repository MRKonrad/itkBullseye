if(itkBullseye_BUILD_TESTING)

  include(${PROJECT_SOURCE_DIR}/cmake/gtest.cmake)

  enable_testing()

  # Threads are needed for testing
  find_package(Threads REQUIRED)
  target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})

  # Test executable
  file(GLOB_RECURSE TESTS_FILES ${PROJECT_SOURCE_DIR}/tests/*.c*)

  message(STATUS ${TESTS_FILES} )

  add_executable(itkBullseyeTests ${TESTS_FILES})
  target_link_libraries(itkBullseyeTests PUBLIC gtest)
  target_link_libraries(itkBullseyeTests PUBLIC tensorflow)
  target_link_libraries(itkBullseyeTests PUBLIC itkTensorFlowLib)
  target_link_libraries(itkBullseyeTests PUBLIC ${ITK_LIBRARIES})
  target_link_libraries(itkBullseyeTests PUBLIC itkBullseyeLib)

  add_test(NAME ctest_tests COMMAND itkBullseyeTests)

  install (TARGETS itkBullseyeTests DESTINATION tests)
  install (DIRECTORY ${CMAKE_SOURCE_DIR}/tests/testData DESTINATION .)

  file(COPY ${CMAKE_SOURCE_DIR}/tests/testData/ DESTINATION ${CMAKE_BINARY_DIR}/testData)

  if(WIN32)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/tensorflow.dll DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/itkTensorFlowLib.dll DESTINATION tests)
    install (FILES ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX}/lib/itkBullseyeLib.dll DESTINATION tests)
  else()
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libtensorflow.so DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libtensorflow_framework.so DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libitkTensorFlowLib${CMAKE_SHARED_LIBRARY_SUFFIX} DESTINATION tests)
    install (FILES ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX}/lib/libitkBullseyeLib${CMAKE_SHARED_LIBRARY_SUFFIX} DESTINATION tests)
  endif()

endif(itkBullseye_BUILD_TESTING)
