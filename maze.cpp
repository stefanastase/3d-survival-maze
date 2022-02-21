#include "maze.h"


Maze::Maze(int size) {
	this->size = size;
}


void Maze::recursiveBacktracking(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>>& visited, std::pair<int, int> pos, std::pair<int, int> dir) {
	int row = pos.first;
	int col = pos.second;
	if (visited[row][col]) return;


	visited[row][col] = 1;
	arr[1 + 2 * row + dir.first][1 + 2 * col + dir.second] = 0; // The wall denoted by the direction is deleted

	int size = (int) visited.size();

	std::vector<std::pair<int, int>> neighbours;
	// Add the neighbour above the current cell
	if (row - 1 >= 0)
		neighbours.push_back(std::pair<int, int>(row - 1, col));
	// Add the neighbour below the current cell
	if (row + 1 < size)
		neighbours.push_back(std::pair<int, int>(row + 1, col));
	// Add the left neighbour
	if (col - 1 >= 0)
		neighbours.push_back(std::pair<int, int>(row, col - 1));
	// Add the right neighbour
	if (col + 1 < size)
		neighbours.push_back(std::pair<int, int>(row, col + 1));

	while (!neighbours.empty()) {
		int i = rand() % neighbours.size(); // Randomly choose a neighbour
		std::pair<int, int> dir(pos.first - neighbours[i].first, pos.second - neighbours[i].second); // Save the direction to know which wall to delete

		recursiveBacktracking(arr, visited, neighbours[i], dir);
		neighbours.erase(neighbours.begin() + i); // Remove the visited neighbours
	}


}

void Maze::generateMaze(int seed) {
	int n = 2 * size + 1; // Size of maze including the borders and the walls between cells
	for (int i = 0; i < n; ++i)
		arr.push_back(std::vector<int>(n, 1));
	for (int i = 1; i < n; i += 2)
		for (int j = 1; j < n; j += 2)
			arr[i][j] = 0;
	
	std::vector<std::vector<int>> visited(size, std::vector<int>(size, 0));

	// Start position is set up randomly
	srand(seed);
	std::pair<int, int> start(rand() % size, rand() % size);

	recursiveBacktracking(arr, visited, start);

	// Adding an exit on one of the borders connected to an empty cell
	if (rand() % 2) {
		if (rand() % 2) {
			arr[0][1 + 2 * (rand() % size)] = 0;
			exit = std::pair<int, int>(0, 1 + 2 * (rand() % size));
		}
		else {
			arr[n - 1][1 + 2 * (rand() % size)] = 0;
			exit = std::pair<int, int>(n - 1, 1 + 2 * (rand() % size));
		}
	}
	else {
		if (rand() % 2) {
			arr[1 + 2 * (rand() % size)][0] = 0;
			exit = std::pair<int, int>(1 + 2 * (rand() % size), 0);
		}
		else {
			arr[1 + 2 * (rand() % size)][n - 1] = 0;
			exit = std::pair<int, int>(1 + 2 * (rand() % size), n - 1);
		}
	}
}
void Maze::addEnemies(std::vector<Enemy>& enemyList, int count, float size, int speed) {
	for (int i = 0; i < count; ++i) {
		int row = rand() % (int) arr.size();
		int col = rand() % (int) arr.size();
		while (arr[row][col]) {
			row = rand() % (int)arr.size();
			col = rand() % (int)arr.size();
		}
		arr[row][col] = 2;
		enemyList.push_back(Enemy(size, row, col, speed));
	}
}
void Maze::removeEnemy(int row, int col) {
	arr[row][col] = 0;
}

void Maze::printMaze() {
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}
}

std::vector<std::vector<int>> Maze::getMaze() {
	return arr;
}

std::pair<int, int> Maze::getExit() {
	return exit;
}

std::pair<int, int> Maze::getEmptyCell() {
	int row = rand() % (arr.size());
	int col = rand() % (arr.size());
	while (arr[row][col]) {
		row = rand() % (arr.size());
		col = rand() % (arr.size());
	}
	arr[row][col] = 3;
	return std::pair<int, int>(row, col);
}