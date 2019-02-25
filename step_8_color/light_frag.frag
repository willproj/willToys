#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
	//ambient
    float ambient_strength=0.1f;
	vec3 ambient=ambient_strength*lightColor;
	//diffuse
	vec3 nor=normalize(Normal);
	vec3 lightDir=normalize(lightPos-FragPos);
	float diff=max(dot(nor,lightDir),0.0f);
	vec3 diffuse=diff*lightColor;
	
	vec3 result=(ambient+diffuse)*objectColor;

	FragColor=vec4(result,1.0f);
}