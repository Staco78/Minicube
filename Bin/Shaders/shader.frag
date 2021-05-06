#version 460 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D t;

void main()
{
    FragColor = texture(t, TexCoords);
}