cmake_minimum_required(VERSION 3.10)
project(TheHub VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Set __your own__ path to your OpenCV 4 installation. Should be something like /usr/lib/x86_64-linux-gnu/cmake/opencv4
set(OpenCV_DIR "/home/raccoonhands/Programming/Libraries/opencv-4.x/cmake")



# Find the OpenCV packages
find_package(OpenCV 4 REQUIRED)

aux_source_directory(./source SOURCE_FILES)

# Add an executable target
add_executable(Hub source/main.cpp source/MainMenu.cpp)

# Link the Qt5 and OpenCV libraries to the executable
target_link_libraries(Hub ${OpenCV_LIBS})

# Include the OpenCV headers in the build
target_include_directories(Hub PUBLIC ${OpenCV_INCLUDE_DIRS} ./headers)
