cmake_minimum_required(VERSION 3.10)

project(kyoupuro_library_cpp CXX)

# -std=c++17
set(CMAKE_CXX_STANDARD 17)

# for ctest
enable_testing()

# サブディレクトリを登録
add_subdirectory(src)
add_subdirectory(tests)