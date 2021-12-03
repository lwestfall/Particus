cmake_minimum_required(VERSION 3.12)


# set the project name
project(Particus)

# get required packages for opengl
find_package(GLEW 2.0 REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
# find_package(OpenGL REQUIRED)

# add the executable
add_executable(Particus
                "src/accelerometer_controller.cpp"
                "src/display_controller.cpp"
                "src/particle_controller.cpp"
                "src/particle.cpp"
                "src/particus.cpp"
                "src/program_controller.cpp"
                "src/vector_2.cpp"
                )

# include directory
target_include_directories(Particus PUBLIC
                            "${PROJECT_SOURCE_DIR}/include"
                            ${OPENGL_INCLUDE_DIR}
                            )

target_link_libraries(Particus PUBLIC GLEW::GLEW)
target_link_libraries(Particus PRIVATE glfw)
target_link_libraries(Particus PRIVATE glm::glm)
# target_link_libraries(Particus PUBLIC ${OPENGL_LIBRARY})

# specify the C++ standard
# include_directories()
set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(SOURCES src/ include/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)