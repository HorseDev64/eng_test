#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vertColor;

out vec3 newColor;
out vec4 position;
void main(){
 
    gl_Position = vec4(aPos, 1.0);
    position = gl_Position;
    newColor = vertColor;
    
}
