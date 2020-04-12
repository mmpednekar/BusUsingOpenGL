# BusUsingOpenGL
Draw 3D Bus using OpenGL

#install OpenGL library
sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

#Compile Code
g++ DRAWBUS.cpp -lGL -lGLU -lglut -lm

#Use
L: Round the Bus
O: Lights On/Off
C: Change to Line/Fill
