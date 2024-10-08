# Cub3D - Raycaster Engine

## Writing a 3D game without a game engine

This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It enabled us to explore ray-casting. Our goal was to make a dynamic view inside a maze, in which the player will have to find their way. 

Using a window management API called [minilibx](https://github.com/42Paris/minilibx-linux). We were able to create an amazing videogame where you equip close and long-range weapons, collect power-up items and defeat different enemies. There are 3 bosses to defeat, one for each level, and 4 different enemies.

## Raycasting

An old and revolutionary method to create the impression of a 3D environment.
The gif below should be self explanatory, but we can resume it by casting a ray to the position of the pixel of a wall.
This creates the impression of space between the player and the wall.

Then you just cast more rays, one next to the other, you now have a field of view!
And then the pixel you hit with your ray you extend it to a line, the further the smaller and reciprocally.
You add difficult math about angles and there you have it!

![raycasting](https://i.imgur.com/n7XHYzq.gif)

## Gameplay 🎮
https://github.com/user-attachments/assets/02ef991c-a752-455b-995a-b284cd62b761


## Installation

That will allow you to play the game as we designed, with three levels.

```bash
make && ./cub3d
```

You can also modify a map file ending in .cub and pass it as an argument to the program.

```bash
./cub3d my_map.cub
```

## Grade 🏆
![Cub3D Score](https://i.imgur.com/BVdCiaq.png)
