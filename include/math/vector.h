#pragma once

typedef struct {
    float x;
    float y;
}vec2;


typedef struct {
    float x;
    float y;
    float z;
}vec3;
typedef struct {
    float x;
    float y;
    float z;
    float w;
}vec4;

typedef struct {
    vec3 pos;
    vec3 color;
}vertex;


typedef struct{
    vertex vertices[3] ;

}tri_face;

