#version 330

in vec3 color;
// Output
layout(location = 0) out vec4 out_color;

uniform int is_enemy;
uniform int special_mode;
void main()
{
	if(special_mode == 1 && is_enemy == 1)
		out_color = vec4(0.804f, 0.725f, 0.490f, 1);
	else
		out_color = vec4(color, 1);

}
