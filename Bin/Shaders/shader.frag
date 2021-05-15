#version 460 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D t;

void main()
{
    //FragColor = texture(t, TexCoords);
    FragColor = vec4(1.0, 0.2, 0.1, 1.0);
}