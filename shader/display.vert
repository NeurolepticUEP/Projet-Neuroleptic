#version 330 core

layout (location = 0) in vec3 position_in;
layout (location = 1) in vec3 normale_in;
layout (location = 2) in vec3 color_in;
layout (location = 3) in vec2 uvcoord_in;

out vec2 uvcoord_vertex;
out vec4 position_vertex;
out vec3 color_vertex;
out vec4 normal_vertex;

uniform mat4 matrix_projection;
uniform mat4 matrix_view;
uniform mat4 matrix_model;

void main() {
    vec4 position = matrix_model * vec4(position_in, 1.0);

    gl_Position = matrix_projection * matrix_view * position;

    position_vertex = normalize(position);
    color_vertex = color_in;
    uvcoord_vertex = vec2(uvcoord_in.x, -uvcoord_in.y);
    normal_vertex = normalize(matrix_model * vec4(normale_in, 0.0));
}
