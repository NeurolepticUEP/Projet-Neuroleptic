#version 330 core
out vec4 color;

in vec2 uvcoord_vertex;
in vec4 position_vertex;
in vec3 color_vertex;
in vec4 normal_vertex;

uniform vec3 light_position;
uniform vec3 camera_position;

vec3 getColor() {
    return color_vertex;
}

void main() {
    color = vec4(getColor(), 1.0);;
}
