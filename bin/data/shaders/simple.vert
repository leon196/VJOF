#version 120

#define PI 3.141592653589

// Uniforms
uniform sampler2DRect uTexture0;
uniform vec2 uTextureResolution;
uniform float uDisplacementHeight;
uniform float uTime;

// Varyings
varying vec2 vTexCoord;
varying float vLuminance;

void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	vTexCoord = gl_TexCoord[0].st;

	vec2 uv1 = mod(abs(vTexCoord + uTime * 0.05), 1.);
	vec2 uv2 = mod(abs(vTexCoord - vec2(0, uTime * 0.05)), 1.);
	vec3 color = texture2DRect(uTexture0, uv1 * uTextureResolution).rgb;
	color += 1.0 - texture2DRect(uTexture0, uv2 * uTextureResolution).rgb;
	color /= 2.0;
	vLuminance = (color.r + color.g + color.b) / 3.0;

	vec4 pos = gl_Vertex;
	pos.xyz += normalize(pos.xyz) * uDisplacementHeight * vLuminance * sin(vTexCoord.y * PI);

	gl_Position =  gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
}
