#version 330 core

out vec4 FragColor;
in vec4 position;
in vec3 newColor;
in vec2 texCoords;

uniform sampler2D ourTex;
uniform sampler2D tex2;
uniform float alpha2;
void main(){
    FragColor = mix(texture(ourTex, texCoords), texture(tex2, texCoords), alpha2);
} 
