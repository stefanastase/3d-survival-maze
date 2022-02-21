#pragma once

class Pickup {
public:
	int row, col;
	int type;
	float value;
	
	Pickup(int row, int col, int type, float value) {
		this->row = row;
		this->col = col;
		this->type = type;
		this->value = value;
	}
};