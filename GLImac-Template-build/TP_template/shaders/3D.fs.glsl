#version 330 core

out vec4 fragColor;

in vec3 vNormale;
in vec3 vPosition;

uniform vec3 uLumieredirection;
uniform vec3 uLumierepoint;
uniform vec3 uCouleur;

void main() {
	float luminosite = max(-dot(uLumieredirection,vNormale),0.2);
	vec3 direction=normalize(vPosition-uLumierepoint);
	float luminositeponctuelle=max(-dot(direction,vNormale),0.2);
	float additionluminosite = min(luminosite+luminositeponctuelle, 1);
	vec3 color = uCouleur;
	fragColor = vec4(color*additionluminosite,1.0); 
}