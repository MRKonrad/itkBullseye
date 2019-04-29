include(${PROJECT_SOURCE_DIR}/cmake/gtest.cmake)

enable_testing()

# Threads are needed for testing
find_package(Threads REQUIRED)
target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})

# Test executable
file(GLOB_RECURSE TESTS_FILES ${PROJECT_SOURCE_DIR}/tests/*.c* ${PROJECT_SOURCE_DIR}/tests/*.h* ${PROJECT_SOURCE_DIR}/tests/*.t*)

add_executable(itkBullseyeTests ${TESTS_FILES})
target_link_libraries(itkBullseyeTests PUBLIC gtest)
target_link_libraries(itkBullseyeTests PUBLIC itkBullseyeLibStatic)

if(WIN32)
  target_link_libraries(itkBullseyeTests PUBLIC itkBullseyeLibStatic)
  target_link_libraries(itkBullseyeTests PUBLIC ${ITK_LIBRARIES})
else()
  target_link_libraries(itkBullseyeTests PUBLIC itkBullseyeLib)
endif()

#set_target_properties(itkBullseyeTests PROPERTIES COMPILE_FLAGS -DitkBullseye_EXPORTS) # to see hxx content

add_test(NAME ctest_tests COMMAND itkBullseyeTests)

if(WIN32)
  file(COPY testData DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testData/temp)
endif()
