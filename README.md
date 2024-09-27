# Because minecraft aren’t 3D enough

🌟 Because minecraft aren’t 3D enough is our cub3D project that has finish with 125/125 mark 🌟

I'm excited to share that I’ve successfully completed my raycasting project, scoring a perfect 125/125! This project provided a deep dive into the mathematical principles of computer graphics, particularly focused on raycasting using angles. Below, I’ll share the detailed breakdown of how I used angles to bring this project to life.

🔍 What is Raycasting?

At its core, raycasting is a technique for rendering 3D environments in 2D games. By casting rays from the player’s position and calculating where those rays hit objects (like walls), you can project a 3D-like view from a first-person perspective.

The challenge? Precisely calculating the angle of each ray and using that information to determine distances, intersections, and render walls correctly.

1️⃣ How Angles Drive Raycasting

In my implementation, the key to simulating 3D environments is calculating the angles between the player’s viewing direction and the rays that are cast outward. These rays span a Field of View (FOV), with each ray representing a different angle. The idea is to cast hundreds of rays, one for each column of pixels on the screen.

    Field of View: In my project, the player has a set FOV (typically 60° or 90° in most raycasting engines), which defines how wide the player’s view is. I divided this FOV into small angular increments, each increment corresponding to one ray.

    Ray Angles: For each ray, I calculated its angle relative to the player's viewing direction. Using trigonometric functions (sine and cosine), I determined how far the ray travels along the X and Y axes, allowing me to track where it hits a wall.

Mathematical Formula:

    For each ray, I calculated its X and Y step distances using:
        X-Step = cos(θ) × step size
        Y-Step = sin(θ) × step size Where θ is the angle of the ray relative to the player’s direction.

This use of angles allowed me to precisely control the trajectory of each ray, ensuring accurate wall detection in all directions.

2️⃣ Implementing the Raycasting Algorithm with Angles

Once the ray's angle is determined, the next step is calculating where that ray intersects with a wall. This process involves moving along the ray’s path, stepping through the grid (which represents the game world) and checking for collisions.

    DDA Algorithm with Angle-Based Steps:

        Using the DDA (Digital Differential Analyzer) algorithm, I calculated how far the ray needs to move in both the X and Y directions for each step based on its angle.

        The key here is angle-based stepping—by using trigonometric functions, I calculated how far each ray moves horizontally and vertically until it hits a wall. For example:
            When casting a ray directly forward (0°), the X component is dominant (cosine), and the Y component is minimal (sine = 0).
            At an angle of 45°, both the X and Y components contribute equally, leading the ray to move diagonally.

3️⃣ Correcting for Fish-Eye Distortion:

One issue with raycasting using angles is fish-eye distortion. As rays are cast outward from the center, they appear to hit walls farther away than those cast directly ahead. This distortion occurs because rays at different angles traverse different distances.

To fix this:

    Perpendicular Distance Correction: I adjusted the distance calculation by applying a cosine correction for each ray’s angle. This ensured that the distance used to determine wall height was the perpendicular distance from the player to the wall, not the raw distance traveled by the ray itself.

Formula:

    Corrected Distance = Distance × cos(ray angle)

This adjustment allowed me to avoid the fish-eye effect and maintain consistent, realistic rendering of the walls.

4️⃣ Wall Projection and Rendering Based on Angles:

Once each ray intersects a wall, I needed to project that information onto the screen. The height of each wall strip is determined by how far the ray travels before hitting the wall—closer walls appear taller, and distant walls shorter.

    Angle-Based Height Calculation: The height of each wall is inversely proportional to the perpendicular distance between the player and the wall. The shorter the distance, the taller the wall appears. This calculation is essential for creating the illusion of depth in a 3D environment.

    Texture Mapping: After calculating the intersection point, I determined which part of the wall texture to display. This involved calculating the exact position on the texture based on the ray’s angle and where it hit the wall, ensuring that textures line up properly across the entire wall surface.

5️⃣ Optimizing Raycasting with Angles:

Using angles in raycasting can lead to performance issues if not handled efficiently. To optimize:

    Reduced Floating-Point Calculations: Instead of recalculating trigonometric functions (cosine and sine) for every step, I precomputed values for each ray angle, which greatly improved performance.

    Efficient Grid Traversal: The DDA algorithm allowed me to efficiently step through the grid, using the precomputed X and Y step sizes based on each ray’s angle. This minimized unnecessary computations and ensured smooth performance, even with complex environments.

6️⃣ Applications of Angle-Based Raycasting:

Raycasting using angles isn’t just limited to retro game development. The underlying principles are still widely used in various fields:

    First-Person Games: The raycasting engine I built is perfect for classic FPS-style games, where simulating 3D environments in 2D space is essential.

    Robotics & LiDAR: The same principles are applied in robotics for obstacle detection and navigation using sensors like LiDAR, which cast "rays" to detect the surroundings.

    Ray Tracing & Graphics: Raycasting is a precursor to more advanced rendering techniques like ray tracing, where light rays are simulated for realistic shadows, reflections, and refractions.

This project was a deep dive into the intersection of geometry, trigonometry, and programming. It challenged me to think critically about how to efficiently render 3D-like environments,
