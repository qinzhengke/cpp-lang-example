cmake_minimum_required(VERSION 3.1)

project(cpp-lang-example)

add_executable(vector
    src/container/vector.cc)

add_executable(map
    src/container/map.cc)

add_executable(shared_ptr
    src/memory/shared_ptr.cc)

add_executable(thread
    src/thread/thread.cc)
