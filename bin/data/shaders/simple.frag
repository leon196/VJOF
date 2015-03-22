#version 120

// Varyings
varying vec2 vTexCoord;
varying float vLuminance;

//
float deepWater = .1;
float water = .4;
float ground = .5;
float grass = .6;
float moutain = .9;

// Colors
vec3 skyColor = vec3(0.05, 0, 0);
vec3 shadowColor = vec3(0.1, 0, 0);
vec3 waterColor = vec3(0.6, 0.7, .9);
vec3 groundColor = vec3(.7, .7, .6);
vec3 grassColor = vec3(.6, .65, .1);
vec3 mountainColor = vec3(.8);
vec3 cloudColor = vec3(.99);
vec3 buildingColor = vec3(.7);

void main()
{
	vec2 uv = vTexCoord.xy;
	vec3 color = skyColor;
	
    color = mix(color, waterColor, smoothstep(deepWater, water, vLuminance));
    color = mix(color, groundColor, smoothstep(water, ground, vLuminance));
    color = mix(color, grassColor, smoothstep(ground, grass, vLuminance));
    color = mix(color, mountainColor, smoothstep(grass, moutain, vLuminance));

	gl_FragColor = vec4(color, 1);
}