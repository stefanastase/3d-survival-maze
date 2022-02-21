#pragma once
#include "utils/glm_utils.h"

class Bullet {
public:
	float size;
	float x, y, z;
	int speed;
	glm::vec3 direction;
	float duration;

	Bullet(float size = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f, int speed = 1, glm::vec3 direction = glm::vec3(1, 0, 0), float duration = 1.0f) {
		this->size = size;
		this->x = x;
		this->y = y;
		this->z = z;
		this->speed = speed;
		this->direction = direction;
		this->duration = duration;
	}

};