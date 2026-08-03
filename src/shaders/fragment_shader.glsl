#version 330 core

out vec4 FragColor;
in vec4 position;

uniform vec4 aColor;
void main(){
    FragColor = position;
} 
