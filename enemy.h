#pragma once

class Enemy {
public:
	float size;
	int row, col;
	float x, z;
	float remainingTime;
	int speed;
	bool enemyHit;

	Enemy(float size = 0.0f, int row = 0, int col = 0, int speed = 10) {
		this->size = size;
		this->row = row;
		this->col = col;
		this->x = row - 10.0f;
		this->z = col - 10.0f;
		this->speed = speed;
		this->enemyHit = 0;
		this->remainingTime = 2.5f;
	}
};
