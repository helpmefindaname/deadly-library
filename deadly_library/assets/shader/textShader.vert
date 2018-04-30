#version 430 core

// Input vertex data, different for all executions of this shader.

in vec3 vertexPosition;
in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 uvs;

void main(){

	// Output position of the vertex, in clip space
	// map [0..800][0..600] to [-1..1][-1..1]
	vec2 vertexPosition_homoneneousspace = vertexPosition.xy - vec2(400,300); // [0..800][0..600] -> [-400..400][-300..300]
	vertexPosition_homoneneousspace /= vec2(400,300);
	gl_Position =  vec4(vertexPosition_homoneneousspace,0,1);

	uvs = vertexUV;
}

