set(SOURCES main.cpp  basic_operations.cpp calculator_class.cpp expression_solver.cpp parser.cpp plugins_usage.cpp dlfc_forWindows.cpp)

set(HEADERS basic_operations.hpp calculator_class.hpp expression_solver.hpp parser.hpp plugins_usage.hpp dlfc_forWindows.hpp )

add_executable(cpp_calculator ${SOURCES} ${HEADERS})
