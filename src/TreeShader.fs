#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Color;
in vec2 TexCoords;
in vec3 currentPos;

uniform sampler2D bark;
uniform sampler2D leaves
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;
uniform int day;

void main()
{    
    if (day == 0)
    {
        float ambient = 0.2f;
        
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - currentPos);
        float diffuse = max(dot(Normal, lightDir), 0.2f);

        float specularLight = 0.5f;
        vec3 viewDir = normalize(camPos - currentPos);
        vec3 reflectionDir = reflect(-lightDir, norm);
        float specAmount = pow(max(dot(viewDir, reflectionDir), 0.0f), 8);
        float specular = specAmount * specularLight;
        
        vec4 texColor = texture(bark, TexCoords) * texture(leaves, TexCoords);
       // if(texColor.a < 0.1)
       //     discard;
        FragColor = texColor * lightColor * (diffuse + ambient + specular);
    }
    else if (day == 1)
    {
        vec4 texColor = texture(bark, TexCoords) * texture(leaves, TexCoords);
       // if(texColor.a < 0.1)
       //     discard;
        FragColor = texColor;
    }
}