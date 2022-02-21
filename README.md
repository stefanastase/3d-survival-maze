# 3d-survival-maze
3D Survival Maze implemented in C++, using the GFX Framework.

## Installation
1. Download GFX Framework from GitHub (https://github.com/UPB-Graphics/gfx-framework)
2. Follow the instructions to build the project
3. Download this repository.
4. Create a new folder inside src/lab_m1 named tema2
5. Copy the contents of this repository inside the new folder
6. Add the following line inside the src/lab_m1/lab_list.h file: ```#include "lab_m1/tema2/tema2.h"```
7. Update line 47 in src/main.cpp from ```World *world = new gfxc::SimpleScene();``` to ```World *world = new m1::Tema2();```
8. Have fun! :)

## Controls
W, A, S, D - Movement
CTRL - Comute from third person to first person
SPACE/MOUSE LEFT - Shoot bullets (works only in first person mode)
