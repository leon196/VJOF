#version 120

varying vec2 vTexCoord;

void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	vTexCoord = gl_TexCoord[0].st;
	
	gl_Position =  gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
