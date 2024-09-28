# Because minecraft aren’t 3D enough

🌟 Because minecraft aren’t 3D enough is our cub3D project that has finish with 125/125 mark 🌟

I'm excited to share that I’ve successfully completed my raycasting project, scoring a perfect 125/125! This project provided a deep dive into the mathematical principles of computer graphics, particularly focused on raycasting using angles. Below, I’ll share the detailed breakdown of how I used angles to bring this project to life.

**Table of Contents**

    1️⃣ Player Initialization and Movement
    2️⃣ Raycasting Mechanics
            Horizontal and Vertical Intersections
            Distance Calculation and Fisheye Correction
    3️⃣ Floor and Ceiling Rendering
    4️⃣ Rendering Walls
            Wall Height and Projection
            Texture Mapping
**1) Player Initialization and Movement**

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
        North: 3π/2 radians (facing upwards).
        East: 0 radians (facing right).
        South: π/2 radians (facing downwards).
        West: π radians (facing left).
```
This rotation angle will be used when casting rays and moving the player, determining the direction they’re looking and moving.

Movement and Rotation Logic:
to update the player in the game we use the input keys from MLX function than we update (walk_direction, turn_direction, strafe_direction) depaned on what has ben pressed 
```c 
if (keydata.key == MLX_KEY_ESCAPE)
    close_handler(window);
else if (keydata.key == MLX_KEY_W)
    player_direction(keydata, &window->player.walk_direction, 1);
else if (keydata.key == MLX_KEY_S)
    player_direction(keydata, &window->player.walk_direction, -1);
else if (keydata.key == MLX_KEY_A)
    player_direction(keydata, &window->player.strafe_direction, -1);
else if (keydata.key == MLX_KEY_D)
    player_direction(keydata, &window->player.strafe_direction, 1);
else if (keydata.key == MLX_KEY_RIGHT)
    player_direction(keydata, &window->player.turn_direction, 1);
else if (keydata.key == MLX_KEY_LEFT)
    player_direction(keydata, &window->player.turn_direction, -1);
```
**a- Updating Rotation Angle**
turn_direction can be 1 (turning right) or -1 (turning left), and turn_speed determines how fast the player rotates.
The player's rotation angle is updated by adding or subtracting the product of turn_direction and turn_speed.
This ensures that every frame the player turns in the specified direction at a constant speed, making the gameplay feel smooth.
```c
window->player.rotation_angle += (window->player.turn_direction * window->player.turn_speed);
```
2. Calculating Movement Steps\
walk_direction controls forward and backward movement, where 1 moves forward and -1 moves backward. This value is multiplied by walk_speed to determine how much the player moves forward or backward per update.\
strafe_direction works similarly but controls movement sideways (strafing), where 1 moves right and -1 moves left.
```c
move_step = window->player.walk_direction * window->player.walk_speed;
strafe_step = window->player.strafe_direction * window->player.walk_speed;
```
**b- Calculating the New Position**
    Trigonometry is used to calculate the new position of the player based on their current rotation and movement inputs.\
    The cos and sin functions take the player's rotation_angle to adjust the player's movement relative to their current orientation:\
        cos(rotation_angle) * move_step moves the player forward/backward along the x-axis.\
        sin(rotation_angle) * move_step moves the player forward/backward along the y-axis.\
        Strafing involves moving sideways, so the sin(rotation_angle) component moves left/right along the x-axis, and cos(rotation_angle) moves left/right along the y-axis.\
```c
new_x = window->player.x + (cos(window->player.rotation_angle) * move_step) - (sin(window->player.rotation_angle) * strafe_step);
new_y = window->player.y + (sin(window->player.rotation_angle) * move_step) + (cos(window->player.rotation_angle) * strafe_step);
```
calculates the new position of the player (new_x and new_y) based on their current position, movement direction (walking and strafing), and rotation angle. The math here involves trigonometric functions (cosine and sine), which are used to determine how much the player's position should change in both the X and Y directions based on their orientation in the game world.
Explanation of Movement\

In 2D games with raycasting or similar mechanics, movement is typically calculated based on the player's current facing direction (their rotation angle) and how far they want to move. The player can move forward or backward (walking) and left or right (strafing), but because the player can rotate, you need to adjust the movement direction using trigonometry.\
Player Movement Directions:\

    Forward/Backward Movement (move_step):
    This represents how much the player is moving in the direction they are currently facing, whether forward or backward.

    Left/Right Strafing (strafe_step):
    Strafing refers to moving left or right relative to the player's current direction. This is different from turning and walking forward; strafing means shifting sideways.

**Mathematical concepts**

    Forward/Backward Movement (Using Cosine and Sine):
        The player's movement is dependent on the direction they are facing, which is described by rotation_angle. To calculate how much the player moves forward or backward in the X and Y directions, we use the trigonometric functions cos (cosine) and sin (sine).
        In a 2D coordinate plane:
            Cosine helps compute movement in the X direction.
            Sine helps compute movement in the Y direction.
        When the player walks forward or backward (determined by move_step), the direction of the movement is along the angle they are facing. Here's how the movement is calculated:
            X Movement (Forward/Backward):
            The player moves forward in the X direction by multiplying cos(rotation_angle) with move_step. This gives the horizontal component of the movement.
            Y Movement (Forward/Backward):
            The player moves forward in the Y direction by multiplying sin(rotation_angle) with move_step. This gives the vertical component of the movement.

    Strafing (Using Cosine and Sine):
        Strafing means moving sideways, relative to the player’s rotation. So, when the player strafes left or right (determined by strafe_step), the movement is perpendicular to their facing direction. We still use cos and sin, but in the opposite direction:
            X Movement (Strafing):
            The player moves left or right in the X direction by multiplying sin(rotation_angle) with strafe_step. Notice that this uses the sine function, but it is subtracted because strafing moves perpendicular to forward movement.
            Y Movement (Strafing):
            Similarly, the Y movement is calculated by multiplying cos(rotation_angle) with strafe_step.

**Combining the Two**

    The new position (new_x, new_y) is calculated by adding forward/backward movement and subtracting/adding strafe movement.
        new_x combines the forward/backward X movement with the left/right strafing X movement.
        new_y combines the forward/backward Y movement with the left/right strafing Y movement.

**Why Use Cosine and Sine?**

In a circular motion (or rotation), the cosine and sine functions are used to break down movement along an angle into its horizontal (X) and vertical (Y) components. By using the player's rotation angle:\

    cos(rotation_angle) gives the proportion of movement along the X-axis.
    sin(rotation_angle) gives the proportion of movement along the Y-axis.

By combining these calculations, the player can move in any direction depending on their orientation, providing realistic movement mechanics in the 2D space.\
