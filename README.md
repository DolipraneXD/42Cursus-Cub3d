# Because minecraft aren’t 3D enough

🌟 Because minecraft aren’t 3D enough is our cub3D project that has finish with 125/125 mark 🌟

we are excited to share that we successfully completed our raycasting project, scoring a perfect 125/125! This project provided a deep dive into the mathematical principles of computer graphics, particularly focused on raycasting using angles. Below, we share the detailed breakdown of how we used angles to bring this project to life.


https://github.com/user-attachments/assets/3af640bc-b4d6-4d5d-8284-c40abd771bf2


# Table of Contents

- [Player Initialization and Movement](#Player-Initialization-and-Movement)
- [Raycasting Mechanics](#Raycasting-Mechanics)
  - [Horizontal and Vertical Intersections](#Horizontal-and-Vertical-Intersections)
  - [Distance Calculation and Fisheye Correction](#Distance-Calculation-and-Fisheye-Correction)
- [Floor and Ceiling Rendering](#Floor-and-Ceiling-Rendering)
- [Rendering Walls](#Rendering-Walls)
  - [Wall Height and Projection](#Wall-Height-and-Projection)
  - [Texture Mapping](#Texture-Mapping)


## Player Initialization and Movement

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
**b- Calculating Movement Steps**

walk_direction controls forward and backward movement, where 1 moves forward and -1 moves backward. This value is multiplied by walk_speed to determine how much the player moves forward or backward per update.\
strafe_direction works similarly but controls movement sideways (strafing), where 1 moves right and -1 moves left.
```c
move_step = window->player.walk_direction * window->player.walk_speed;
strafe_step = window->player.strafe_direction * window->player.walk_speed;
```
**c- Calculating the New Position**

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
Player Movement Directions:

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

In a circular motion (or rotation), the cosine and sine functions are used to break down movement along an angle into its horizontal (X) and vertical (Y) components. By using the player's rotation angle:

    cos(rotation_angle) gives the proportion of movement along the X-axis.
    sin(rotation_angle) gives the proportion of movement along the Y-axis.

By combining these calculations, the player can move in any direction depending on their orientation, providing realistic movement mechanics in the 2D space.\
## Raycasting Mechanics
**What is Raycasting?**

Raycasting is a computational technique used to simulate 3D environments in a 2D space, commonly used in early 3D games like Wolfenstein 3D or in projects like Cub3d. The basic idea behind raycasting is to "cast" rays from the player's viewpoint in the direction they are looking to detect objects (usually walls) and determine how far away they are. These rays are cast at different angles, covering the player's field of view (FOV).

```c
void	rays_casting(t_window *window)
{
	double	angle;
	int		i;

	i = 0;
	angle = normalize_angle(window->player.rotation_angle) - \
		(window->fov_angle / 2);
	while (i < WIDTH)
	{
		window->ray_list[i].ray_angle = normalize_angle(angle);
		ray_cast(&window->ray_list[i], window);
		i++;
		angle += window->fov_angle / WIDTH;
	}
}
```
This function casts rays for the entire screen (or viewport) by iterating through each column of pixels.
It loops through all rays, starting at the left edge of the screen and moving to the right. For each ray, it calculates the corresponding angle and calls ray_cast to perform the raycasting for that angle. The angle of the ray is adjusted in each iteration based on the field of view (FOV) and screen width (WIDTH).

![ray](https://github.com/user-attachments/assets/629548f0-31bd-44e0-bc13-2fe7a38e1bf0)

now we need to detect where the player is facing, that will help us in raycasting process.

![ray_facing](https://github.com/user-attachments/assets/bb94b5f7-71e9-4ad3-b4b4-91d776814769)
```c
if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
	ray->is_facing_down = true;
else
	ray->is_facing_down = false;
ray->is_facing_up = !ray->is_facing_down;
if (ray->ray_angle < 0.5 * M_PI || ray->ray_angle > 1.5 * M_PI)
	ray->is_facing_right = true;
else
	ray->is_facing_right = false;
ray->is_facing_left = !ray->is_facing_right;
```
## Horizontal and Vertical Intersections

- **Horizontal Intersections**
  
horizontal intersection refers to the point where a ray intersects with the horizontal lines (grid cells) in the map. These intersections are critical for determining where a wall is hit and thus how far the player is from that wall along the horizontal axis.

![Yfirst_intercept](https://github.com/user-attachments/assets/1149b33b-f294-467d-9fb8-cc93ed89ba5d)
  
![horizonta_imter](https://github.com/user-attachments/assets/12672581-1cef-4ee7-b85c-66dd2bb72312)

This calculation allows the ray to "step" from one horizontal line to the next, checking for intersections with walls as it moves horizontally across the grid. The combination of xinter and yinter provides the intersection points, and xstep and ystep allow the ray to advance through the map grid in the appropriate direction.

- **Vertical Intersections**
  
we apply the same process for the vertical 

![Vertical_Intersection](https://github.com/user-attachments/assets/3e2b0b52-edd2-48b1-a972-e20c1ef2274a)

## Distance Calculation and Fisheye Correction

here we will calcule the distance fom the player to the point where we hit the wall for both horizontal and verical, and select the closest one that will be our distance.

![DistancetoWall](https://github.com/user-attachments/assets/e0d40da0-7a45-488e-b649-456f636ba3ee)

```c
horz_distance = INT_MAX;
vert_distance = INT_MAX;
if (find_h_wall)
	horz_distance = calc_distance(window->player.x, window->player.y,ray->wall_hit_x, ray->wall_hit_y);
if (find_v_wall)
	vert_distance = calc_distance(window->player.x, window->player.y,ray->wall_hit_x_ver, ray->wall_hit_y_ver);
if (horz_distance >= vert_distance)
	ray->wall_hit_x = ray->wall_hit_x_ver;
if (horz_distance >= vert_distance)
	ray->wall_hit_y = ray->wall_hit_y_ver;
if (horz_distance <= vert_distance)
	ray->distance = horz_distance;
else
	ray->distance = vert_distance;
ray->was_hit_horz = (vert_distance > horz_distance);
```

- **Fisheye Correction**
  
This function adjusts the distance for each ray by compensating for the angle between the ray's direction and the player's viewpoint. This ensures that the walls are rendered at their true size and prevents visual distortions caused by the fish-eye effect.

  ```c
void	calculate_correct_distance(t_window *window, int i)
{
	window->ray_list[i].distance *= cos(window->ray_list[i].ray_angle \
		- window->player.rotation_angle);
}
  ```

## Floor and Ceiling Rendering

This function efficiently renders a simple floor and ceiling background by dividing the screen in half and filling each part with a predefined color.

```c
void	draw_floor_ceiling(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(window->img, x, y, window->floor_color);
			else
				mlx_put_pixel(window->img, x, y, window->ceiling_color);
			x++;
		}
		y++;
	}
}
```


## Rendering Walls

Wall_Height_and_Projection

In this raycasting, the wall rendering process follows a series of calculations and steps to accurately draw walls based on the player's perspective. This explanation breaks down the steps involved in rendering walls in a 3D environment:
1. Correcting the Distance for Fisheye Effect

When casting rays, the distance calculated for each ray needs to be adjusted to account for the fisheye effect. The calculate_correct_distance function multiplies the distance by the cosine of the difference between the ray’s angle and the player’s rotation angle:
```c
void calculate_correct_distance(t_window *window, int i)
{
    window->ray_list[i].distance *= cos(window->ray_list[i].ray_angle - window->player.rotation_angle);
}
```
This ensures that walls further to the sides of the player's view aren't artificially elongated, maintaining the correct perspective.

2. Calculating Wall Strip Dimensions

Each ray represents a vertical strip on the screen. The height of this strip is determined by the distance to the wall. To calculate the vertical position of the top and bottom of each wall strip, we use the following formulas:
```c
double calculate_wall_top_pixel(double wall_strip_height)
{
    return (HEIGHT / 2) - (wall_strip_height / 2);
}

double calculate_wall_bottom_pixel(double wall_strip_height)
{
    return (HEIGHT / 2) + (wall_strip_height / 2);
}
```
The calculate_wall_top_pixel function determines where the top of the wall should be drawn, based on the screen height.\
Similarly, calculate_wall_bottom_pixel determines the bottom position. This centers the wall vertically on the screen.

3. Determining Wall Direction

The texture that gets mapped onto the wall depends on the direction the wall is facing. The get_wall_direction function determines whether the wall is facing north, south, east, or west, and also checks if the wall hit is horizontal or vertical:
```c
int get_wall_direction(t_ray *ray)
{
    if (ray->is_door)
        return DOOR;
    if (ray->was_hit_horz)
    {
        if (ray->is_facing_up)
            return NORTH;
        else
            return SOUTH;
    }
    else
    {
        if (ray->is_facing_left)
            return WEST;
        else
            return EAST;
    }
}
```
This helps in selecting the correct texture for rendering based on the wall’s direction and whether it was hit horizontally or vertically.

4. Mapping Textures to Walls

To ensure the texture aligns properly with the wall, we calculate the initial X-coordinate (init_x) where the wall texture starts, and then calculate the corresponding texture pixel to draw:
```c
double get_initial_x(t_ray *ray)
{
    if (ray->was_hit_horz)
        return ((int)ray->wall_hit_x % TILE_SIZE);
    else
        return ((int)ray->wall_hit_y % TILE_SIZE);
}
```
Depending on whether the wall was hit horizontally or vertically, this function calculates the correct starting X-coordinate for the texture.

5. Rendering the Wall Strip

The render_wall_strip function takes the calculated values and draws the wall strip for each ray. It loops through each pixel on the screen from the top of the wall to the bottom, fetching the correct texture pixel and drawing it to the screen:
```c
void render_wall_strip(t_window *window, double wall_top_pixel, double wall_bottom_pixel, double wall_strip_height)
{
    double init_x = get_initial_x(&window->ray_list[window->ray_index]);
    uint32_t texture_x = init_x * (window->texture[window->direction]->width / TILE_SIZE);
    double init_y = wall_top_pixel;
    int y = (int)round(wall_top_pixel);

    while (y <= wall_bottom_pixel)
    {
        if (window->ray_index >= 0 && window->ray_index < WIDTH && y >= 0 && y < HEIGHT)
        {
            uint32_t texture_y = (uint32_t)(y - init_y) * (window->texture[window->direction]->height / wall_strip_height);
            mlx_put_pixel(window->img, round(window->ray_index), round(y), get_pixel_color(window->texture[window->direction], texture_x, texture_y));
        }
        y++;
    }
}
```
This function calculates the texture’s X and Y coordinates and maps them onto the correct screen pixels, ensuring the texture is applied smoothly across the vertical strip.

6. Main Wall Rendering Loop

The render_walls function iterates over every vertical strip (each ray cast from the player's viewpoint) and calculates the appropriate wall height, top, and bottom pixel positions, as well as the correct texture to use. It then calls render_wall_strip to draw each wall segment on the screen:
```c
void render_walls(t_window *window)
{
    int i = 0;
    window->ray_index = 0;

    while (i < WIDTH)
    {
        window->ray_index = i;
        calculate_correct_distance(window, i);
        double wall_strip_height = get_wall_height(window, i);
        double wall_top_pixel = calculate_wall_top_pixel(wall_strip_height);
        double wall_bottom_pixel = calculate_wall_bottom_pixel(wall_strip_height);
        window->direction = get_wall_direction(&window->ray_list[i]);
        render_wall_strip(window, wall_top_pixel, wall_bottom_pixel, wall_strip_height);
        i++;
    }
}
```
Iterating over Rays: For each ray cast across the screen's width, the distance to the wall is corrected, and the height of the wall strip is determined.\
Rendering: After calculating the top and bottom positions for the wall, and determining the correct texture, the strip is rendered to the screen.

This process allows the engine to render walls in a 3D space, providing a realistic first-person view.
By calculating the correct distances, wall heights, and mapping textures appropriately,\
the engine produces a smooth and accurate visual representation of the player's surroundings.
