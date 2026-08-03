#pragma once
#include "math/vector.h"
#include <bits/pthreadtypes.h>
#include <stdio.h>


#define CB_POSITION 1
#define CB_COLOR 2

vertex triangle[3];

vertex second_triangle[3];
vertex cube_vertices[36];

vertex two_triangles[6];

vertex square_vertices[4];

unsigned int triangle_i[6];

void add_triangle_attribute(vertex *triangle, vec3 addPosition,
                            unsigned int attribute);

#ifdef PRIMITIVES_IMPLEMENTATION

void add_triangle_attribute(vertex *triangle, vec3 addPosition,
                            unsigned int attribute)
{

    switch(attribute)
    {
    case CB_POSITION:
        goto position_for;
    case CB_COLOR:
        goto color_for;
    default:
        return;
    }

position_for:
    for(int i = 0; i < 3; i++)
    {
        triangle[i].pos.x += addPosition.x;
        triangle[i].pos.y += addPosition.y;
        triangle[i].pos.z += addPosition.z;
    }
    return;

color_for:

    for(int i = 0; i < 3; i++)
    {
        triangle[i].color.x = addPosition.x;
        triangle[i].color.y = addPosition.y;
        triangle[i].color.z = addPosition.z;
    }
    printf("succesful changed color i guess\n");
    printf("triangle fvc: %f\n", triangle[0].color.x);
    return;
}
unsigned int triangle_i[] = {0, 1, 2, 0, 3, 2};
vertex triangle[] = {{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
                     {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
                     {{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}};

vertex second_triangle[] = {{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
                            {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
                            {{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}};
;
vertex two_triangles[] = {
    // Triángulo 1
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}}, // Inferior izquierdo
    {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},  // Inferior derecho
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // Superior derecho

    // Triángulo 2
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}}, // Inferior izquierdo
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},   // Superior derecho
    {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}},  // Superior izquierdo
};

vertex square_vertices[] = {
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 0.0f}},
};
vertex cube_vertices[] = {
    // Frente (rojo)
    {{-0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},

    {{-0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},
    {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}},

    // Atrás (verde)
    {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},

    {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},

    // Izquierda (azul)
    {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},

    {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}},

    // Derecha (amarillo)
    {{0.5f, -0.5f, 0.5f}, {1.0f, 1.0f, 0.0f}},
    {{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}},

    {{0.5f, -0.5f, 0.5f}, {1.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 0.0f}},

    // Arriba (magenta)
    {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 1.0f}},
    {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 1.0f}},
    {{0.5f, 0.5f, -0.5f}, {1.0f, 0.0f, 1.0f}},

    {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 1.0f}},
    {{0.5f, 0.5f, -0.5f}, {1.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.5f}, {1.0f, 0.0f, 1.0f}},

    // Abajo (cian)
    {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 1.0f}},
    {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 1.0f}},
    {{0.5f, -0.5f, 0.5f}, {0.0f, 1.0f, 1.0f}},

    {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 1.0f}},
    {{0.5f, -0.5f, 0.5f}, {0.0f, 1.0f, 1.0f}},
    {{-0.5f, -0.5f, 0.5f}, {0.0f, 1.0f, 1.0f}}};
#endif
