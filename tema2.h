#pragma once

#include "components/simple_scene.h"
#include "components/transform.h"
#include "maze.h"
#include "user_camera.h"
#include "bullet.h"
#include "enemy.h"
#include "pickup.h"

// COLORS
#define VERY_PERI glm::vec3(0.400f, 0.404f, 0.671f)
#define GRANITE_GREEN glm::vec3(0.522f, 0.627f, 0.580f)
#define DRIED_MOSS glm::vec3(0.804f, 0.725f, 0.490f)
#define MUTED_CLAY glm::vec3(0.827f, 0.573f, 0.490f)
#define HAWTHRON_ROSE glm::vec3(0.537f, 0.294f, 0.365f)
#define LOTUS glm::vec3(0.890f, 0.757f, 0.745f)
#define BURNISHED_LILAC glm::vec3(0.776f, 0.667f, 0.686f)
#define PLAIN_BROWN glm::vec3(0.486f, 0.306f, 0.204f)

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
     public:
        Tema2();
        ~Tema2();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color = glm::vec3(1), int enemyIndex = -1); // last parameter is used for vertex displacement
        void Render2DMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color = glm::vec3(1));

        void RenderMap();
        void RenderPlayer(bool firstPersonMode);
        void RenderBullets();
        void RenderEnemies();
        void RenderPickups();
        void RenderHUD(float healthLevel, float timeRemaining, std::vector<std::vector<bool>>& discovered);

        void generateBullet(float size, int speed, float duration);

        bool circleAABB(float x, float y, float radius, float left, float bottom, float width, float height);
        bool sphereAABB(glm::vec3 spherePos, float radius, glm::vec3 aabbMin, glm::vec3 aabbMax);

        bool playerWallCol(float x, float z, float radius);
        bool playerEnemyCol(float x, float z, float radius);
        bool bulletWallCol(float x, float y, float z, float radius);
        bool bulletEnemyCol(float x, float y, float z, float radius);

        void printMessage(bool gameOver, bool win, int pickup = -1, float value = 0.0f);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        Maze* maze;
        float playerX, playerZ;
        float playerAngle;
        float healthLevel, healthLevelCont, initialTime, timeRemaining;
        float playerSpeed, slowedTime;

        float movementAngle, headAngle;
        bool movementDir;

        bool gameOver;
        bool healthIncreasing;
        bool specialMode, showMap;
        float pickupTime;

        user::Camera* camera;
        user::Camera* firstPersonCamera;
        user::Camera* thirdPersonCamera;
        gfxc::Camera* camera2D;

        float cameraDistance;
        bool firstPerson;

        glm::mat4 projectionMatrix;

        std::vector<Bullet> bullets;
        std::vector<Enemy> enemies;
        std::vector<Pickup> pickups;
        std::vector<std::vector<bool>> discovered;
    };
}   // namespace m1
