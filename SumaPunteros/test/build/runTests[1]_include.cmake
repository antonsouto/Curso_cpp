if(EXISTS "/home/anton/Desktop/Proyecto/Pruebas/SumaPunteros/test/build/runTests[1]_tests.cmake")
  include("/home/anton/Desktop/Proyecto/Pruebas/SumaPunteros/test/build/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()
