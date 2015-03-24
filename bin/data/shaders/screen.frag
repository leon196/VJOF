#version 120

uniform vec2 uFboResolution;
uniform sampler2DRect uTexture0;

varying vec2 vTexCoord;

void main()
{
	gl_FragColor = vec4(texture2DRect(uTexture0, vTexCoord.xy * uFboResolution.xy).rgb, 1);
}