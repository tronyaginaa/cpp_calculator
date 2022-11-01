set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../plugins)

add_library(sin SHARED "sin.cpp")
add_library(cos SHARED "cos.cpp")
add_library(sort SHARED "sqrt.cpp")
add_library(exp SHARED "exp.cpp")
