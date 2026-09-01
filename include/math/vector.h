#pragma once

typedef struct {
    float x;
    float y;
}cb_vec2;


typedef struct {
    float x;
    float y;
    float z;
}cb_vec3;
typedef struct {
    float x;
    float y;
    float z;
    float w;
}cb_vec4;

typedef struct {
    cb_vec3 pos;
    cb_vec3 color;
}cb_vertex;


typedef struct{
    cb_vertex vertices[3] ;

}tri_face;

