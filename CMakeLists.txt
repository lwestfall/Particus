cmake_minimum_required(VERSION 3.12)

# set the project name
project(Particus)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(PARENT_DIR ${PROJECT_SOURCE_DIR}/..)
set(MPU_DIR ${PARENT_DIR}/MPU)
set(CPDB_DIR ${PARENT_DIR}/CrossPlatformDataBus)
set(EXTERNAL_SRC
    ${MPU_DIR}/src/MPU.cpp
    ${MPU_DIR}/src/MPU9250_Master_I2C.cpp
    ${MPU_DIR}/src/MPU9250_Master.cpp
    ${MPU_DIR}/src/MPU9250.cpp
    ${CPDB_DIR}/extras/i2c/wiringpi/src/WiringPiI2C.cpp
)

# get required packages for opengl
find_package(GLEW 2.0 REQUIRED)
find_package(glfw3 REQUIRED)

# add the executable
add_executable(Particus
                "src/accelerometer_controller.cpp"
                "src/button_controller.cpp"
                "src/display_controller.cpp"
                "src/particle_controller.cpp"
                "src/particle.cpp"
                "src/particus.cpp"
                "src/program_controller.cpp"
                "src/vector_2.cpp"
                ${EXTERNAL_SRC}
                )

# include directory
target_include_directories(Particus PUBLIC
                            "${PROJECT_SOURCE_DIR}/include"
                            "${MPU_DIR}/src"
                            "${MPU_DIR}/extras/i2c/wiringpi/src"
                            "${MPU_DIR}/extras/common"
                            "${CPDB_DIR}/src"
                            ${pigpio_INCLUDE_DIR}
                            )

target_link_libraries(Particus PUBLIC GLEW::GLEW)
target_link_libraries(Particus PRIVATE glfw)
target_link_libraries(Particus PRIVATE pigpio)
target_link_libraries(Particus PRIVATE wiringPi)

target_compile_options(Particus PRIVATE -Wno-psabi)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
