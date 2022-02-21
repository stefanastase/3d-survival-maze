#include "lab_m1/tema2/tema2.h"

#include <vector>
#include <string>
#include <iostream>


using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::RenderMap() {
    std::vector<std::vector<int>> maze_array = maze->getMaze();
    float offset = (maze_array.size() - 1) / 2; // Maze is centered in (0, 0, 0)

    for (int i = 0; i < maze_array.size(); ++i)
        for (int j = 0; j < maze_array[i].size(); ++j)
            if (maze_array[i][j] == 1)
            {
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(i, 2.0f + 0.01f, j));
                modelMatrix = glm::translate(modelMatrix, glm::vec3(-offset, 0, -offset)); // Center maze
                modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 4, 1));
                RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, MUTED_CLAY);
            }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(maze_array.size(), 0.01f, maze_array.size()));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, BURNISHED_LILAC);
    }
}
void Tema2::RenderPlayer(bool firstPersonMode) {

    // Player size is 0.36f x 0.94f x 0.15f
    // Move player to desired position in maze
    glm::mat4 playerMovement = glm::translate(glm::mat4(1), glm::vec3(playerX, 0.59f + 0.005f, playerZ));
    playerMovement = glm::rotate(playerMovement, playerAngle, glm::vec3(0, 1, 0));
    playerMovement = glm::rotate(playerMovement, RADIANS(-90), glm::vec3(0, 1, 0));

    // Player is rendered only in third person mode
    if (!firstPersonMode) {
        {
            // Head
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.00f, 0.27f, 0.00f));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(headAngle), glm::vec3(0, 1, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.16f, 0.16f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, LOTUS);
        }
        {
            // Neck
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.00f, 0.17f, 0.00f));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(headAngle / 2.0f), glm::vec3(0, 1, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.08f, 0.04f, 0.10f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, LOTUS);
        }
        {
            // Upper left arm
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.18f - 0.01f, -0.02f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.17f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.17f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.08f, 0.34f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, GRANITE_GREEN);
        }
        {
            // Lower left arm
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.18f - 0.01f, -0.23f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.34f + 0.04f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.34f - 0.04f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.08f, 0.08f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, LOTUS);
        }
        {
            // Upper right arm
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.18f + 0.01f, -0.02f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.17f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.17f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.08f, 0.34f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, GRANITE_GREEN);
        }
        {
            // Lower right arm
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.18f + 0.01f, -0.23f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.34f + 0.04f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.34f - 0.04f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.08f, 0.08f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, LOTUS);
        }
        {
            // Upper torso
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.28f, 0.30f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, GRANITE_GREEN);
        }
        {
            // Lower torso
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.00f, -0.19f, 0.00f));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.28f, 0.08f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, VERY_PERI);
        }
        {
            // Left leg
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.075f, -0.39f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.16f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.16f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.13f, 0.32f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, VERY_PERI);
        }
        {
            // Right leg
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.075f, -0.39f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.16f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.16f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.13f, 0.32f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, VERY_PERI);
        }
        {
            // Left shoe
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.075f, -0.57f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.32f + 0.02f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.32 - 0.02f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.13f, 0.04f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, PLAIN_BROWN);
        }
        {
            // Right shoe
            glm::mat4 modelMatrix = playerMovement;
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.075f, -0.57f, 0.00f));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.32f + 0.02f, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(movementAngle), glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.32 - 0.02f, 0));

            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.13f, 0.04f, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, PLAIN_BROWN);
        }
    }
}
void Tema2::RenderBullets() {
    for (int i = 0; i < bullets.size(); ++i) {
        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(bullets[i].x, bullets[i].y, bullets[i].z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(bullets[i].size));
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, DRIED_MOSS);
    }
}
void Tema2::RenderEnemies() {
    for (int i = 0; i < enemies.size(); ++i) {
        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(enemies[i].x, 0.5f + 0.01f, enemies[i].z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(5 * enemies[i].size));
        RenderSimpleMesh(meshes["enemy"], shaders["LabShader"], modelMatrix, HAWTHRON_ROSE, i);
    }
}
void Tema2::RenderPickups() {
    for (int i = 0; i < pickups.size(); ++i) {
        glm::vec3 color;
        if (pickups[i].type == 0) color = GRANITE_GREEN; // HEALTH
        else if (pickups[i].type == 1) color = VERY_PERI; // TIME
        else if (pickups[i].type == 2) color = DRIED_MOSS; // SPEED & HARMLESS ENEMIES
        else if (pickups[i].type == 3) color = LOTUS; // SHOW MAP

        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(pickups[i].row - 10.0f, 0.3f, pickups[i].col - 10.0f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f)); // Pickup radius is 0.2 * 0.5 = 0.1f
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, color);
    }
}
void Tema2::RenderHUD(float healthLevel, float timeRemaining, std::vector<std::vector<bool>>& discovered) {
    glm::ivec2 resolution = window->GetResolution();
    // Health bar
    {
        // Level
        {
            glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(healthLevel + 9, 29, 30));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(healthLevel, 20, 1));
            Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, healthLevel > 20.0f ? GRANITE_GREEN : HAWTHRON_ROSE);
        }
        // Background
        {
            glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(109, 29, 30));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(100, 20, 1));
            Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0.8f));
        }
        // Border
        {
            glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(109, 29, 30));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(104, 24, 1));
            Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0));
        }
    }
    
    // Time bar
    {
        // Time bar
        float relativeTimeRemaining = 100 * timeRemaining / initialTime; // Time bar should be full for regardless of initialTime

        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(resolution.x - relativeTimeRemaining - 9, 29, 30));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(relativeTimeRemaining, 20, 1));
        Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, relativeTimeRemaining > 20.0f ? glm::vec3(0.5f) : HAWTHRON_ROSE);
    }
    {
        // Time bar background
        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(resolution.x - 109, 29, 30));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(100, 20, 1));
        Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0.8f));
    }
    {
        // Time bar margin
        glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(resolution.x - 109, 29, 30));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(104, 24, 1));
        Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0));
    }

    // Minimap
    {
        std::vector <std::vector<int>> maze_array = maze->getMaze();
        int size = maze_array.size();
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                // Map shadow
                if (!showMap && !discovered[i][j]) {
                    glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(14 + 10 * i, resolution.y - 10 * j - 14, 30));
                    modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 1));
                    Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0.5f));
                }
        for (int i = 0; i < maze_array.size(); ++i)
            for (int j = 0; j < maze_array[i].size(); ++j)
                // Walls
                if (maze_array[i][j] == 1) {
                    glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(14 + 10 * i, resolution.y - 10 * j - 14, 30));
                    modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 1));
                    Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0.8f));
                }
                // Enemies
                else if (maze_array[i][j] == 2) {
                    glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(14 + 10 * i, resolution.y - 10 * j - 14, 30));
                    modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 1));
                    Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, HAWTHRON_ROSE);
                }
        // Player
        {
            int player_row = (int)round(playerX + 10.0f);
            int player_col = (int)round(playerZ + 10.0f);
            glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(14 + 10 * player_row, resolution.y - 10 * player_col - 14, 30));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 1));
            Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, GRANITE_GREEN);
        }
        // Map background
        {
            glm::mat4 modelMatrix = glm::translate(glm::mat4(1), glm::vec3(114, resolution.y - 114, 30));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(109, 109, 1));
            Render2DMesh(meshes["quad"], shaders["LabShader"], modelMatrix, glm::vec3(0));
        }
    }
}

void Tema2::generateBullet(float size, int speed, float duration) {
    bullets.push_back(Bullet(size, playerX, 0.7f, playerZ, speed, firstPersonCamera->forward, duration));
}

bool Tema2::circleAABB(float x, float y, float radius, float left, float bottom, float width, float height) {
    glm::vec2 center(x, y);
    glm::vec2 aabb_half_extents(width / 2.0f, height / 2.0f);
    glm::vec2 aabb_center(
        left + aabb_half_extents.x,
        bottom + aabb_half_extents.y
    );
    glm::vec2 difference = center - aabb_center;
    glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
    glm::vec2 closest = aabb_center + clamped;
    difference = closest - center;

    return glm::length(difference) < radius;
}
bool Tema2::sphereAABB(glm::vec3 spherePos, float radius, glm::vec3 aabbMin, glm::vec3 aabbMax) {
    float closestX = max(aabbMin.x, min(spherePos.x, aabbMax.x));
    float closestY = max(aabbMin.y, min(spherePos.y, aabbMax.y));
    float closestZ = max(aabbMin.z, min(spherePos.z, aabbMax.z));

    float distance = sqrt((closestX - spherePos.x) * (closestX - spherePos.x) +
                          (closestY - spherePos.y) * (closestY - spherePos.y) + 
                          (closestZ - spherePos.z) * (closestZ - spherePos.z));

    return distance < radius;
}

bool Tema2::playerWallCol(float x, float z, float radius) {
   std::vector<std::vector<int>> maze_array = maze->getMaze();
   int offset = (maze_array.size() - 1) / 2; // Maze is centered in 0
   for (int i = 0; i < maze_array.size(); ++i)
       for (int j = 0; j < maze_array[i].size(); ++j)
           if (maze_array[i][j] == 1)
               if (circleAABB(x, z, radius, i - offset - 0.5f, j - offset - 0.5f, 1.0f, 1.0f)) return 1; // Each wall center is located at (i - offset, j - offset)
   return 0;
}
bool Tema2::playerEnemyCol(float x, float z, float radius) {
    for (int i = 0; i < enemies.size();) {
        if (!enemies[i].enemyHit && circleAABB(x, z, radius, enemies[i].x - enemies[i].size / 2.0f, enemies[i].z - enemies[i].size / 2.0f, enemies[i].size, enemies[i].size)) {
            maze->removeEnemy(enemies[i].row, enemies[i].col);
            enemies.erase(enemies.begin() + i);
            return 1;
        }
        else ++i;
    }
    return 0;
}
bool Tema2::bulletWallCol(float x, float y, float z, float radius) {
    std::vector<std::vector<int>> maze_array = maze->getMaze();
    int offset = (maze_array.size() - 1) / 2; // Maze is centered in 0
    for (int i = 0; i < maze_array.size(); ++i)
        for (int j = 0; j < maze_array[i].size(); ++j)
            if (maze_array[i][j] == 1) {
                // Each wall center is located at(i - offset, j - offset)
                // Wall size is 1
                glm::vec3 wallMin = glm::vec3(i - offset - 0.5f, 0.01f, j - offset - 0.5f);
                glm::vec3 wallMax = glm::vec3(i - offset + 0.5f, 4.0f, j - offset + 0.5f);
                if (sphereAABB(glm::vec3(x, y, z), radius, wallMin, wallMax)) return 1;
            }
    return 0;
}
bool Tema2::bulletEnemyCol(float x, float y, float z, float radius) {
    for (int i = 0; i < enemies.size(); ++i) {
        glm::vec3 enemyMin = glm::vec3(enemies[i].x - enemies[i].size / 2.0f, 0.01f, enemies[i].z - enemies[i].size / 2.0f);
        glm::vec3 enemyMax = glm::vec3(enemies[i].x + enemies[i].size / 2.0f, 4.0f, enemies[i].z + enemies[i].size / 2.0f);

        if (!enemies[i].enemyHit && sphereAABB(glm::vec3(x, y, z), radius, enemyMin, enemyMax)) {
            enemies[i].enemyHit = 1;
            return 1;
        }
    }
    return 0;
}

void Tema2::printMessage(bool gameOver, bool win, int pickup, float value) {
    char sym = gameOver ? '=' : '-';
    cout << string(32, sym) << endl;
    if (gameOver) {
        cout << "GAME OVER!" << endl;
        if (win) cout << "Congratulations! You found your way out of the maze!" << endl;
        else if (timeRemaining <= 0.0f) cout << "You ran out of time!" << endl;
        else cout << "The enemies destroyed you!" << endl;
    }
    else {
        cout << "You picked ";
        if (pickup == 0) {
            cout << "HEALTH." << endl;
            cout << "Your health level increases with 20." << endl;
        }
        else if (pickup == 1) {
            cout << "TIME." << endl;
            cout << "Time remaining increases with " << value << " seconds." << endl;
        }
        else if (pickup == 2) {
            cout << "FRENZY MODE." << endl;
            cout << "Your speed increases and enemies are harmless for " << value << " seconds." << endl;
        }
        else if (pickup == 3) {
            cout << "MAP PEEK." << endl;
            cout << "Pay attention to the map, it will disappear again in " << value << " seconds." << endl;
        }
    }
    cout << string(32, sym) << endl;
}
void Tema2::Init()
{
    // Maze setup
    maze = new Maze();
    maze->generateMaze();
    maze->addEnemies(enemies, 15, 0.2f, rand() % 6 + 5);

    std::pair<int, int> start = maze->getEmptyCell();
    int start_row = start.first;
    int start_col = start.second;

    std::pair<int, int> exit = maze->getExit();
    int exit_row = exit.first;
    int exit_col = exit.second;
    
    // Pickups setup
    for (int i = 0; i < 5; ++i) {
        std::pair<int, int> cell = maze->getEmptyCell();
        pickups.push_back(Pickup(cell.first, cell.second, rand() % 4, 2.0f + (rand() % 12) / 2.0f));
    }

    // Player setup
    playerX = start_row - 10.0f;
    playerZ = start_col - 10.0f;
    playerAngle = 0.0f;
    playerSpeed = 2.0f;
    movementAngle = 0.0f;
    movementDir = 1;
    headAngle = 0.0f;

    // Discovered map setup
    int size = maze->getMaze().size();
    for (int i = 0; i < size; ++i)
        discovered.push_back(std::vector<bool>(size, 0));

    // Game logic
    gameOver = 0;
    healthLevelCont = healthLevel = 100.0f;
    float distanceToExit = sqrt((start_row - exit_row) * (start_row - exit_row) + (start_col - exit_col) * (start_col - exit_col));
    initialTime = timeRemaining = 5.0f * distanceToExit;

    slowedTime = 0.0f;
    pickupTime = 0.0f;
    healthIncreasing = 0;
    specialMode = 0;
    showMap = 0;

    // Camera setup
    glm::ivec2 resolution = window->GetResolution();
    camera2D = new gfxc::Camera();
    camera2D->SetPosition(glm::vec3(0, 0, 50));
    camera2D->SetRotation(glm::vec3(0, 0, 0));
    camera2D->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 20, 500);
    camera2D->Update();

    thirdPersonCamera = new user::Camera();
    firstPersonCamera = new user::Camera();

    firstPerson = 0;
    camera = thirdPersonCamera;

    cameraDistance = 1.5f;
    thirdPersonCamera->Set(glm::vec3(playerX - cos(playerAngle), cameraDistance, playerZ + sin(playerAngle)), glm::vec3(playerX, 1, playerZ), glm::vec3(0, 1, 0));
    projectionMatrix = glm::perspective(RADIANS(60.0f), window->props.aspectRatio, 1.0f, 200.0f);

    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("enemy");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "enemy.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("plane");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("quad");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "quad.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Shader *shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
}

void Tema2::FrameStart()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Update(float deltaTimeSeconds)
{
    RenderMap();
    if (!gameOver) {
        RenderHUD(healthLevelCont, timeRemaining, discovered);
        RenderEnemies();
        RenderPickups();
        RenderPlayer(firstPerson);
        RenderBullets();
        
        // Camera logic
        if (!firstPerson) firstPersonCamera->Set(glm::vec3(playerX, 0.9f, playerZ), glm::vec3(playerX + cos(playerAngle), 0.9f, playerZ - sin(playerAngle)), glm::vec3(0, 1, 0));
        projectionMatrix = firstPerson ? glm::perspective(RADIANS(90.0f), window->props.aspectRatio, 0.01f, 200.0f) : glm::perspective(RADIANS(60.0f), window->props.aspectRatio, 1.0f, 200.0f);
        camera = firstPerson ? firstPersonCamera : thirdPersonCamera;

        // Bullets logic
        for (int i = 0; i < bullets.size();) {
            bullets[i].x += bullets[i].speed * bullets[i].direction.x * deltaTimeSeconds;
            bullets[i].y += bullets[i].speed * bullets[i].direction.y * deltaTimeSeconds;
            bullets[i].z += bullets[i].speed * bullets[i].direction.z * deltaTimeSeconds;

            // Bullet is deleted after time is up
            if (bullets[i].duration < 0.0f) bullets.erase(bullets.begin() + i);
            else bullets[i].duration -= deltaTimeSeconds, ++i;
        }

        // Enemies movement
        float time = Engine::GetElapsedTime();
        for (int i = 0; i < enemies.size(); ++i) {
            enemies[i].x = enemies[i].row - 10.0f + (0.5f - enemies[i].size) * sin(enemies[i].speed * 0.5f * time);;
            enemies[i].z = enemies[i].col - 10.0f + (0.5f - enemies[i].size) * sin(enemies[i].speed * time);
        }

        // Player - Enemy Collision
        if (!specialMode) {
            if (playerEnemyCol(playerX, playerZ, 0.26f)) {
                healthLevel -= 20.0f;
                slowedTime = 2.0f;
            }
            playerSpeed = slowedTime > 0.0f ? 1.0f : 2.0f;
        }
        else {
            playerSpeed = 3.0f;
            if (pickupTime > 0.0f) pickupTime -= deltaTimeSeconds;
            else specialMode = 0, pickupTime = 0.0f;
        }
        // Player - Pickup Collision
        for (int i = 0; i < pickups.size();) {
            float pickupX = pickups[i].row - 10.0f;
            float pickupZ = pickups[i].col - 10.0f;
            float distance = sqrt((pickupX - playerX) * (pickupX - playerX) + (pickupZ - playerZ) * (pickupZ - playerZ));
            float pickupRadius = 0.1f;
            float playerRadius = 0.25f; 
            if (distance < pickupRadius + playerRadius) {
                if (pickups[i].type == 0) healthLevel = (healthLevel + 20.0f > 100.0f ? 100.0f : healthLevel + 20.0f), healthIncreasing = 1;
                else if (pickups[i].type == 1) timeRemaining = timeRemaining + pickups[i].value > initialTime ? initialTime : timeRemaining + pickups[i].value;
                else if (pickups[i].type == 2) specialMode = 1, pickupTime = pickups[i].value;
                else if (pickups[i].type == 3) showMap = 1, pickupTime = pickups[i].value;
                printMessage(0, 0, pickups[i].type, pickups[i].value);
                pickups.erase(pickups.begin() + i);
            }
            else ++i;
        }

        // Bullet - Wall Collision
        for (int i = 0; i < bullets.size();)
            if (bulletWallCol(bullets[i].x, bullets[i].y, bullets[i].z, bullets[i].size / 2.0f)) bullets.erase(bullets.begin() + i);
            else ++i;
        // Bullet - Enemy Collision
        for (int i = 0; i < bullets.size();) 
            if (bulletEnemyCol(bullets[i].x, bullets[i].y, bullets[i].z, bullets[i].size / 2.0f)) bullets.erase(bullets.begin() + i);
            else ++i;

        // GAME OVER - LOST
        if (healthLevel <= 0.0f || timeRemaining <= 0.0f) gameOver = 1, printMessage(1, 0);
        
        // GAME OVER - WON
        std::vector<std::vector<int>> maze_array = maze->getMaze();
        int size = maze_array.size();
        float offset = (size - 1) / 2.0f;
        int player_col = (int)round(playerZ + offset);
        int player_row = (int)round(playerX + offset);

        if (player_row != 0 && player_row != size && player_col != 0 && player_col != size) {
            // Map is discovered as player roams around it. A 9x9 cell square is discovered at every position.
            discovered[player_row >= 1 ? player_row - 1 : 0][player_col >= 1 ? player_col - 1 : 0] = 1;
            discovered[player_row >= 1 ? player_row - 1 : 0][player_col] = 1;
            discovered[player_row >= 1 ? player_row - 1 : 0][player_col < size - 1 ? player_col + 1 : size - 1] = 1;
            discovered[player_row][player_col >= 1 ? player_col - 1 : 0] = 1;
            discovered[player_row][player_col] = 1;
            discovered[player_row][player_col < size - 1 ? player_col + 1 : size - 1] = 1;
            discovered[player_row < size - 1 ? player_row + 1 : size - 1][player_col >= 1 ? player_col - 1 : 0] = 1;
            discovered[player_row < size - 1 ? player_row + 1 : size - 1][player_col] = 1;
            discovered[player_row < size - 1 ? player_row + 1 : size - 1][player_col < size - 1 ? player_col + 1 : size - 1] = 1;
        }
        else gameOver = 1, printMessage(1, 1);

        // Animations logic
        bool isMoving = (window->KeyHold(GLFW_KEY_W) || window->KeyHold(GLFW_KEY_UP) || window->KeyHold(GLFW_KEY_S) || window->KeyHold(GLFW_KEY_DOWN));
        bool isRotating = (window->KeyHold(GLFW_KEY_A) || window->KeyHold(GLFW_KEY_LEFT) || window->KeyHold(GLFW_KEY_D) || window->KeyHold(GLFW_KEY_RIGHT));
        if (!isMoving) {
            // Smooth animation when returning to the standing position
            if (movementAngle > 1.5f) movementAngle -= 100 * deltaTimeSeconds;
            else if (movementAngle < -1.5f) movementAngle += 100 * deltaTimeSeconds;
            else movementAngle = 0.0f;
        }
        if (!isRotating) {
            // Smooth animation when returning to the standing position
            if (headAngle > 2.0f) headAngle -= 300 * deltaTimeSeconds;
            else if (headAngle < -2.0f) headAngle += 300 * deltaTimeSeconds;
            else headAngle = 0.0f;
        }
        // Smooth animations for health decrease/increase
        if (!healthIncreasing) {
            if (healthLevelCont > healthLevel) healthLevelCont -= 80 * deltaTimeSeconds;
            else healthLevelCont = healthLevel;
        }
        else {
            if (healthLevelCont < healthLevel) healthLevelCont += 80 * deltaTimeSeconds;
            else healthLevelCont = healthLevel, healthIncreasing = 0;
        }

        // Enemy countdown after being hit
        for (int i = 0; i < enemies.size();) {
            if (enemies[i].enemyHit) enemies[i].remainingTime -= deltaTimeSeconds;
            if (enemies[i].remainingTime < 0.0f) {
                maze->removeEnemy(enemies[i].row, enemies[i].col);
                enemies.erase(enemies.begin() + i);
            }
            else ++i;
        }
        
        // Show map pickup
        if (showMap)
            if (pickupTime > 0.0f) pickupTime -= deltaTimeSeconds;
            else showMap = 0;

        if (slowedTime > 0.0f) slowedTime -= deltaTimeSeconds;
        else slowedTime = 0.0f;
        timeRemaining -= deltaTimeSeconds;
    }
}

void Tema2::FrameEnd()
{
    //DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema2::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, const glm::vec3 &color, int enemyIndex)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    glUniform3f(glGetUniformLocation(shader->program, "object_color"), color.r, color.g, color.b);

    // Bind model matrix
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "Model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Bind view matrix
    glm::mat4 viewMatrix = camera->GetViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "View"), 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "Projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Send enemy information to shader
    if (!strcmp(mesh->GetMeshID(), "enemy")) {
        glUniform1i(glGetUniformLocation(shader->program, "is_enemy"), 1);
        glUniform1f(glGetUniformLocation(shader->program, "remaining_time"), enemies[enemyIndex].remainingTime);
        if(enemies[enemyIndex].enemyHit)
            glUniform1i(glGetUniformLocation(shader->program, "enemy_hit"), 1);
        else
            glUniform1i(glGetUniformLocation(shader->program, "enemy_hit"), 0);
    }
    else {
        glUniform1i(glGetUniformLocation(shader->program, "is_enemy"), 0);
        glUniform1i(glGetUniformLocation(shader->program, "enemy_hit"), 0);
        glUniform1f(glGetUniformLocation(shader->program, "elapsed_time"), 0.0f);
    }

    glUniform1i(glGetUniformLocation(shader->program, "special_mode"), (int)specialMode);
    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}
void Tema2::Render2DMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, const glm::vec3 &color){
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    glUniform3f(glGetUniformLocation(shader->program, "object_color"), color.r, color.g, color.b);

    // Bind model matrix
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "Model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Bind view matrix
    glm::mat4 viewMatrix = camera2D->GetViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "View"), 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glm::mat4 projectionMatrix = camera2D->GetProjectionMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader->program, "Projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Send 0 to unused uniforms
    glUniform1i(glGetUniformLocation(shader->program, "is_enemy"), 0);
    glUniform1i(glGetUniformLocation(shader->program, "enemy_hit"), 0);
    glUniform1f(glGetUniformLocation(shader->program, "elapsed_time"), 0.0f);
    glUniform1i(glGetUniformLocation(shader->program, "special_mode"), 0);
    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    firstPerson = window->KeyHold(GLFW_KEY_LEFT_CONTROL) || window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT);
    if (!firstPerson && !gameOver) {
        if (window->KeyHold(GLFW_KEY_W) || window->KeyHold(GLFW_KEY_UP)) {
            float newPlayerX = playerX + deltaTime * playerSpeed * cos(playerAngle);
            float newPlayerZ = playerZ - deltaTime * playerSpeed * sin(playerAngle);
            if (!playerWallCol(newPlayerX, newPlayerZ, 0.22f)) {
                // Movement
                thirdPersonCamera->MoveForward(deltaTime * playerSpeed);
                playerX = newPlayerX;
                playerZ = newPlayerZ;
                // Animation
                if (movementDir && movementAngle < 20.0f) movementAngle += 100 * deltaTime;
                else if (movementDir && movementAngle >= 20.0f) movementDir = 0;
                else if (!movementDir && movementAngle > -20.0f) movementAngle -= 100 * deltaTime;
                else movementDir = 1;
            }
        }
        if (window->KeyHold(GLFW_KEY_S) || window->KeyHold(GLFW_KEY_DOWN)) {
            float newPlayerX = playerX - deltaTime * playerSpeed * cos(playerAngle);
            float newPlayerZ = playerZ + deltaTime * playerSpeed * sin(playerAngle);
            if (!playerWallCol(newPlayerX, newPlayerZ, 0.22f)) {
                // Movement
                thirdPersonCamera->MoveForward(-deltaTime * playerSpeed);
                playerX = newPlayerX;
                playerZ = newPlayerZ;
                // Animation
                if (movementDir && movementAngle > -20.0f) movementAngle -= 100 * deltaTime;
                else if (movementDir && movementAngle <= -20.0f) movementDir = 0;
                else if (!movementDir && movementAngle < 20.0f) movementAngle += 100 * deltaTime;
                else movementDir = 1;
            }
        }
        if (window->KeyHold(GLFW_KEY_A) || window->KeyHold(GLFW_KEY_LEFT)) {
            // Movement
            thirdPersonCamera->RotateThirdPerson_OY(deltaTime * playerSpeed);
            playerAngle += deltaTime * playerSpeed;
            // Animation
            if (headAngle < 25.0f) headAngle += 300 * deltaTime;
            else headAngle = 25.0f;
        }
        if (window->KeyHold(GLFW_KEY_D) || window->KeyHold(GLFW_KEY_RIGHT)) {
            // Movement
            thirdPersonCamera->RotateThirdPerson_OY(-deltaTime * playerSpeed);
            playerAngle -= deltaTime * playerSpeed;
            // Animation
            if (headAngle > -25.0f) headAngle -= 300 * deltaTime;
            else headAngle = -25.0f;
        }
    }
}

void Tema2::OnKeyPress(int key, int mods)
{
    if (firstPerson && key == GLFW_KEY_SPACE) generateBullet(0.1f, 5, 1.5f);
}
void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    float sensivityOX = 0.001f;
    float sensivityOY = 0.001f;
    if (!gameOver) {
        firstPersonCamera->RotateFirstPerson_OX(-sensivityOX * deltaY);
        firstPersonCamera->RotateFirstPerson_OY(-sensivityOY * deltaX);
    }
}
void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (firstPerson && IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) generateBullet(0.1f, 5, 1.5f);
}
void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}
void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
    camera2D->SetOrthographic(0, (float)width, 0, (float)height, 20, 500);
    camera2D->Update();
}
