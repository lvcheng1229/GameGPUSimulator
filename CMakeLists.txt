cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(GameGPUSimulator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GGPUSIM_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.h")
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
file(GLOB_RECURSE SOURCE_FILES_CC "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc")
file(GLOB_RECURSE SOURCE_FILES_C "${CMAKE_CURRENT_SOURCE_DIR}/source/*.c")

# include 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty) #glm
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/VulkanSDK/1.3.261.1/Include)

# libs
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/)


# find_package(Vulkan REQUIRED)


#   
#   #zstd lib
#   
#   # boost graph
#   
#   #glslang lib
#   link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/glslang/lib/glslangd.lib)
#   link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/glslang/lib/MachineIndependentd.lib)
#   link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/glslang/lib/GenericCodeGend.lib)
#   link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/glslang/lib/glslang-default-resource-limitsd.lib)
#   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glslang)
#   
#   #
#   add_definitions(-D TANGRAM_DIR=${TANGRAM_ROOT_DIR})
#   add_definitions(-D TANGRAM_INTERMEDIATE_DIR=${TANGRAM_ROOT_DIR}/intermediate/)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/Source" FILES ${HEADER_FILES} ${SOURCE_FILES} ${SOURCE_FILES_CC} ${SOURCE_FILES_C})
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${SOURCE_FILES_CC} ${SOURCE_FILES_C})