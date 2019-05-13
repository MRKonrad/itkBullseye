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

  # message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
  # message(STATUS ${CMAKE_BUILD_TYPE})


  install (TARGETS itkBullseyeTests DESTINATION tests)
  install (DIRECTORY ${CMAKE_SOURCE_DIR}/tests DESTINATION testData)

  message(STATUS CMAKE_INSTALL_PREFIX  ${CMAKE_INSTALL_PREFIX})

  if(WIN32)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/tensorflow.dll DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/itkTensorFlowLib.dll DESTINATION tests)
    install (FILES ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX}/lib/itkBullseyeLib.dll DESTINATION tests)
  else()
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libtensorflow.so DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libtensorflow_frameworks.so DESTINATION tests)
    install (FILES ${CMAKE_SOURCE_DIR}/thirdParty/itkTensorFlow/lib/libitkTensorFlowLib${CMAKE_SHARED_LIBRARY} DESTINATION tests)
    install (FILES ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_PREFIX}/lib/libitkBullseyeLib${CMAKE_SHARED_LIBRARY} DESTINATION tests)
  endif()

endif(itkBullseye_BUILD_TESTING)
