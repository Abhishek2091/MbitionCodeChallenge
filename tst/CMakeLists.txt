add_executable(IntentRecognizer_tst IntentRecognizertest.cpp main.cpp)

target_link_libraries(IntentRecognizer_tst PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)