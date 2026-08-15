well, important things to remember

vertex - geometry - assembly - rasterization - fragmentation - depth and blending

a fragment is the full pixel

shaders compilation and buffers are totally independent processes

data is only sent to the shaders when a glDraw call is made

glPlygonMode if for defining how opengl draws, very usefull for side-culling (only draw inside or only draw lines)


for now the most optimal way of changing colors and drawing more than one object is by changing 
opengls inner states

"in" "out" keywords to pass variables between shaders
"uniforms" keyword for defining a global variable, that all shaders will share, and it cannot be changed
unless is reset or updated (by the program)

yes


***TEXTURES***

**THIS IS IMPORTANT**

so, basically, textures has their own coordinate system, texture coordinates, that goes from 0.0 to 1.0
but, you can set the range to every number you want, the behaviour of this is that it will repeat the texture
(learnopengl says the following: we basically ignore the integer part of the floating point texture coordinate, which i do not understand
yet, so whenever you learn what does it mean, WRITE IT HERE:, chatgpt, thank you so much brother, basically, ***the texture coordinates maps the image,
from 0 to 1, if its out of boundarys like 1.25, then it repeats the image and takes 25% of the copy, but, because its the same image, thats just the 
same as drawing the 25% of the original image, here is the diagram:
+----------------------+
|        CAT           |
+----------------------+

+-----+ +-----+ +-----+ +-----+
| CAT | | CAT | | CAT | | CAT |
+-----+ +-----+ +-----+ +-----+
Texture 0        Texture 1        Texture 2

0.0     1.0      2.0      3.0
|-------|--------|--------|
|  CAT  |  CAT   |  CAT   |
      ^
      1.25
);

also, remember, the first step to make a texture, is configure how the target texture is gonna behave in the axis we define
(xyz is changed for str);


PLEASE REMEMBER: SAMPLER2D is an INT, NOT a FLOAT, to set an uniform, you must set it as an INT
