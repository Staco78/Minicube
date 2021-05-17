#version 460 core
out vec4 FragColor;

in vec2 TexCoords;
in flat int texIndex;

uniform sampler2DArray samplerArray;

void main()
{
    FragColor = texture(samplerArray, vec3(TexCoords, texIndex));
    //FragColor = vec4(1.0, 0.2, 0.1, 1.0);
}