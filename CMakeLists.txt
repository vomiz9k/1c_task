project(task_for_1c)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_DIR ${task_for_1c_SOURCE_DIR}/source)

add_executable(
    decryptor
    main.cpp
    source/decryptor.cpp
    source/trie.cpp
)





