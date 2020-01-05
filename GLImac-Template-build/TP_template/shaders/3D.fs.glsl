/*
#version 330

void main() {
	vec3 color = vec3(0.8, 0.3, 0.1);
	gl_FragColor = vec4(color,1.0); 
}
*/

#version 330 core

out vec4 fragColor;

in vec3 vNormale;
in vec3 vPositionmonde;

uniform vec3 uLumieredirection;
uniform vec3 uLumierepoint;
uniform vec3 uCouleur;

void main() {
	float luminosite = max(-dot(uLumieredirection,vNormale),0.2);
	vec3 direction=normalize(vPositionmonde-uLumierepoint);
	float luminositeponctuelle=max(-dot(direction,vNormale),0.2);
	float additionluminosite = min(luminosite+luminositeponctuelle, 1);
	vec3 color = uCouleur;
	fragColor = vec4(color*additionluminosite,1.0); 
}