cmake_minimum_required(VERSION 3.28)
project(ECS36BTemplatedDoublyLinkedList) # make sure to update

set(CMAKE_CXX_STANDARD 23)
set(CXX_WARNINGS -Wall -Werror -Wextra)

# make sure to update
set(SRC_LIB_NAME TemplatedDoublyLinkedListLib)
set(EXE_NAME TemplatedDoublyLinkedListExe)
set(TESTING_NAME TemplatedDoublyLinkedListTests)

add_subdirectory(src)
add_subdirectory(testing)
