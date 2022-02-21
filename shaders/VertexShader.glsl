#version 330

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

uniform float remaining_time;
uniform int is_enemy;
uniform int enemy_hit;

uniform vec3 object_color;

// Output value to fragment shader
out vec3 color;

float rand(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453); // Random function
}

void main()
{
    color = object_color;
    if(is_enemy == 1 && enemy_hit == 1){
        vec3 deformed_position;
        float random = rand(v_texture_coord);
        float displacement = 0.03 * (1.25f - remaining_time / 2) * random;
        deformed_position = v_position + v_normal * displacement;
        gl_Position = Projection * View * Model * vec4(deformed_position, 1.0);
        }
    else{
        gl_Position = Projection * View * Model * vec4(v_position, 1.0);
        }
}
