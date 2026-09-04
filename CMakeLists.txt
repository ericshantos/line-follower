# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK
include(pico_sdk_import.cmake)

project(rastro C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable
add_executable(rastro
    src/main.cpp
    src/Engine.cpp
    src/Sensor.cpp
)

# Program name and version
pico_set_program_name(rastro "rastro")
pico_set_program_version(rastro "0.2")

# Enable/disable output over UART/USB
pico_enable_stdio_uart(rastro 0)
pico_enable_stdio_usb(rastro 0)

# Link libraries
target_link_libraries(rastro
    pico_stdlib
)

# Include directories
target_include_directories(rastro PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# Generate extra outputs (.uf2, .hex, etc.)
pico_add_extra_outputs(rastro)