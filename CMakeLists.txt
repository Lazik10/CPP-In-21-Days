# Minimum CMake version
CMAKE_MINIMUM_REQUIRED (VERSION 3.2 FATAL_ERROR)

# Name of the project
PROJECT( 21Days )

# Set compiler flags and options. 
# Here it is setting the Visual Studio warning level to 4
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")

# Set the default path for built executables to the "bin" directory
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the default path for built libraries to the "lib" directory
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add subdirectory where more CMakeLists.txt exists
ADD_SUBDIRECTORY ( src )