#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"


class Maze {
	public:
		Maze(int size = 10);
		void generateMaze(int seed = time(NULL));
		void addEnemies(std::vector<Enemy>& enemyList, int count, float size, int speed = 10);
		void removeEnemy(int row, int col);
		void printMaze();
		std::vector<std::vector<int>> getMaze();
		std::pair<int, int> getExit();
		std::pair<int, int> getEmptyCell();

	private:
		int size; // Size of maze before adding walls
		std::pair<int, int> exit;
		std::vector<std::vector<int>> arr;
		void recursiveBacktracking(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>>& visited, std::pair<int, int> pos, std::pair<int, int> dir = std::pair<int, int>(0, 0));
};