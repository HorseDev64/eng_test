#version 330 core

in vec3 newColor;
out vec4 Frag_color;

void main(){

    Frag_color = vec4(newColor, 0.0f);

    
}
