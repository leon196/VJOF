#version 120

// Uniforms
uniform vec2 uResolution;
uniform vec2 uTextureResolution;
uniform vec2 uFboResolution;
uniform sampler2DRect uTexture0;

void main()
{
	gl_FragColor = vec4(texture2DRect(uTexture0, gl_FragCoord.xy * uFboResolution.xy / uResolution.xy).rgb, 1);
}