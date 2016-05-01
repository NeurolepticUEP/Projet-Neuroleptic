#version 330 core

out vec4 color;

in vec4 position_vertex;
in vec3 color_vertex;
in vec4 normal_vertex;

uniform vec3 light_position;
uniform vec3 camera_position;

vec3 getColor() {
    return color_vertex;
}

void main() {
    vec3 light_direction = normalize(light_position - position_vertex.xyz);
    vec3 view_direction = normalize(camera_position - position_vertex.xyz);
    vec3 reflect_direction = normalize(reflect(-light_direction, normal_vertex.xyz));

    float spec = pow(max(dot(view_direction, reflect_direction), 0.0), 8);
    float diff = max(dot(normal_vertex.xyz, light_direction), 0.0);

    color = vec4((0.2 + spec + diff) * getColor(), 1.0);;
}
