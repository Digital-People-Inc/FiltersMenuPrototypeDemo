4NOTES::

 you must install opencv4 and opencv4-contrib from opencv website. Steps are on the website. 

 Go to CMakeLists.txt and edit your opencv path to include the directory of install.




 A NOTE ON DEPLOYMENT::
 if this is deployed / distributed, we need to include FFMPEG binary because it's the video i/o backend https://docs.opencv.org/4.x/d0/da7/videoio_overview.html

 
 example [didn't run it, but image works, requires main.cpp in same location]:


 # Use an official lightweight Alpine image as a parent image
FROM alpine:latest

# Set the working directory in the container to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Install any needed packages specified in requirements.txt
RUN apk add cmake make g++ opencv-dev

# Make a build directory and switch to it
WORKDIR /app/build

# Generate the Makefile
RUN cmake ..

# Build the executable
RUN make 