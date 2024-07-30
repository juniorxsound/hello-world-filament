cmake_minimum_required(VERSION 3.1)

# @see https://github.com/google/filament/discussions/7730
if (APPLE AND NOT IOS)
    # This must be set before project() is called
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.15 CACHE STRING "")
endif()

project(HelloWorldFilament)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the Filament submodule directory
add_subdirectory(ext/filament)

# Assuming your main.cpp is in the root of your project directory
add_executable(HelloWorldFilament src/main.cpp)

# Include directories for Filament
target_include_directories(HelloWorldFilament PRIVATE
    ext/filament/include
)

# Include directories for Filament
target_include_directories(HelloWorldFilament PRIVATE
    include
)

# Link against Filament libraries
# Note: You need to specify the target names as defined in Filament's CMakeLists.txt
target_link_libraries(HelloWorldFilament
    filament
    backend
    bluegl
    filabridge
    filaflat
    utils
    gltfio
    filamentapp
    filameshio
    sample-resources
    # Anything else you need from filament goes here!
)