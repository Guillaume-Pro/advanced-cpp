cmake_minimum_required(VERSION 3.28)

project(CppSnippets VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
#set(CMAKE_CXX_COMPILER "/usr/lib/llvm-18/bin/clang")
#set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "/usr/lib/llvm-18/bin/clang-scan-deps")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++20") # -I /usr/include/x86_64-linux-gnu/c++/12

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/build")

#set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
#set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(CMAKE_INSTALL_PREFIX Install)

add_executable(MathModule)
target_compile_options(MathModule PRIVATE -fmodules -fcxx-modules)
target_sources(MathModule
        PUBLIC
        lessons/1-2/main.cpp
)

#add_library(math_utils_module INTERFACE lessons/1-2/print_module.ixx)
#target_compile_options(math_utils_module INTERFACE -fmodules -fcxx-modules)
#add_dependencies(MathModule math_utils_module)

target_sources(MathModule
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        lessons/1-2/math_utils.cpp
        lessons/1-2/print_module.ixx
)


#add_executable(StdOptional lessons/1-1/std_optional.cpp)
#add_executable(StdVariant lessons/1-1/std_variant.cpp)
#add_executable(Union lessons/1-1/union.cpp)
#add_executable(StdAny lessons/1-1/std_any.cpp)
#
##add_executable(MathModule lessons/1-2/math_utils.cpp lessons/1-2/main.cpp
##        lessons/1-2/print_module.ixx)
#
#add_executable(CoFibonacci lessons/1-3/co_fibonacci.cpp)
#add_executable(CoCounter lessons/1-3/co_counter.cpp)
#
#add_executable(StdStringLiterals misc/std_string_literals.cpp)
#add_executable(BytesToFloat misc/bytes_to_float.cpp)
#add_executable(DemoModule misc/modules.cpp)
#
#add_executable(Exercice_1_1_Server exercices/1_1/server.cpp)
#add_executable(Exercice_1_1_Client exercices/1_1/client.cpp)
#
#add_executable(Solutions_1_1_Server solutions/1_1/server.cpp)
##add_executable(Solutions_1_1_Client solutions/1_1/client.cpp)
