# Because minecraft aren’t 3D enough

🌟 Because minecraft aren’t 3D enough is our cub3D project that has finish with 125/125 mark 🌟

I'm excited to share that I’ve successfully completed my raycasting project, scoring a perfect 125/125! This project provided a deep dive into the mathematical principles of computer graphics, particularly focused on raycasting using angles. Below, I’ll share the detailed breakdown of how I used angles to bring this project to life.

Table of Contents

    1️⃣ Player Initialization and Movement
    2️⃣ Raycasting Mechanics
            Horizontal and Vertical Intersections
            Distance Calculation and Fisheye Correction
    3️⃣ Floor and Ceiling Rendering
    4️⃣ Rendering Walls
            Wall Height and Projection
            Texture Mapping
1. Player Initialization and Movement

The player in the game world is represented by coordinates (x, y) starting position, movement parameters, and initial rotation based on the map and direction they’re facing.
```c
player->x = (map->player_x * TILE_SIZE) + (PLAYER_SIZE / 2);
player->y = (map->player_y * TILE_SIZE) + (PLAYER_SIZE / 2);

player->width = 10;
player->height = 10;
player->walk_direction = 0;
player->turn_direction = 0;
player->strafe_direction = 0;
player->walk_speed = 6;
player->turn_speed = 5 * (M_PI / 180);

if (map->player_dir == NORTH)
    player->rotation_angle = 3 * (M_PI / 2);
else if (map->player_dir == EAST)
    player->rotation_angle = 0;
else if (map->player_dir == SOUTH)
    player->rotation_angle = (M_PI / 2);
else if (map->player_dir == WEST)
    player->rotation_angle = M_PI;

```
The player’s initial rotation angle is set based on the direction they're facing in the map (NORTH, EAST, SOUTH, or WEST).
```
        North: 3π/23π/2 radians (facing upwards).
        East: 00 radians (facing right).
        South: π/2π/2 radians (facing downwards).
        West: ππ radians (facing left).
```
This rotation angle will be used when casting rays and moving the player, determining the direction they’re looking and moving.
