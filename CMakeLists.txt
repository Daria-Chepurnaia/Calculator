cmake_minimum_required(VERSION 3.10)
project(SimpleCalculator)

set(CMAKE_CXX_STANDARD 17)

# ---- Main application ----

include_directories(${CMAKE_SOURCE_DIR}/nodes)
include_directories(${CMAKE_SOURCE_DIR}/parser)
include_directories(${CMAKE_SOURCE_DIR}/utils)

add_executable(calculator
    main.cpp
    nodes/Value.cpp
    nodes/Sum.cpp
    nodes/Subtract.cpp
    nodes/Divide.cpp
    nodes/Multipl.cpp
    nodes/Negate.cpp
    nodes/Variable.cpp
    parser/Tokenizer.cpp
    parser/ExpressionParser.cpp
    utils/VariableInput.cpp
  )

# ---- GoogleTest and Tests ----

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing() 

# Build test executable
add_executable(calculator_tests
    tests/TestIntegration.cpp 
    tests/TestTokenizer.cpp
    nodes/Value.cpp
    nodes/Sum.cpp
    nodes/Subtract.cpp
    nodes/Divide.cpp
    nodes/Multipl.cpp
    nodes/Negate.cpp
    nodes/Variable.cpp
    parser/Tokenizer.cpp           
    parser/ExpressionParser.cpp   
    utils/VariableInput.cpp       
)

target_include_directories(calculator_tests PRIVATE ${CMAKE_SOURCE_DIR}/nodes)
target_link_libraries(calculator_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(calculator_tests)




