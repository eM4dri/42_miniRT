# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## 2022-05-04 - Edu
### Changed
- Added grattitude & scenes to README.md
### Fixed
- Parse cylinder's orient as unit vector

## 2022-04-30 - Jorge
### Changed
- Control MAXVALUE in get_cos & rgb2int
### Fixed
- Control cylinder_lid exception between perpendicular's ray and cylinder axis
- Control border cylinder_wall now eval if cam is inside infinite cylinder
## 2022-04-30 - Edu
### Changed
- Free variables as soon as they aren't needed
### Fixed
- Fixed bonus & mandatory headers

## 2022-04-27 - Edu
### Added
- Added libft's **get_array_size**
### Fixed
- Fix leaks parser with array size

## 2022-04-27 - Jorge
- Norminette passed.
- BLACK_HOLE added.

## 2022-04-25 - Edu
### Changed
- Set mandatory or bonus **settings** with makefile **mandatory** & **bonus** rules

## 2022-04-24 - Jorge
### Added
- First version of a Phong reflection. It looks fine, but the reflection should lose intensity when the light is far away.

## 2022-04-24 - Edu
### Added
- Added **black_hole**
### Fixed
- Fix mac bug item + '\0' not parsed

## 2022-04-20 - Jorge
### Changed
- Changed the whole system to detect cylinders and find their collision point and with a ray and normal vector.
- Some "old" functions haven't been removed yet, but should serve no purpose.
- Most bugs with the cylinders' lids have been fixed with this new system. Although, there's now some minor issues with certain areas of a cylinder where random black pixels appear.

## 2022-04-19 - Jorge
### Added
- Lids of cylinders are now detected.
- The normal vector and the collision point is now retrieved properly.
- Reflection of lights over cylinders seems to work fine, including shadows formed by and cast over the cylinder.
### Bugs
- In some cases (specially when there's multiple cylinders in a single scene) the lids are not placed properly, but seems like the walls of the cylinder always work fine.

## 2022-04-17 - Jorge
### Added
- Cylinders are detected when a ray collides directly to the cylinder's body ("lids" excluded).
	Lighting and color system has been temporary disabled but can be reenabled at *./src/coloring/set_color_matrix.c* (line 46).

## 2022-04-17 - Edu
### Added
- Added **resolution.h** to handle different resolutions
### Changed
- Include malloc's error handling on **parse**
### Fixed
- Fixed init color matrix with background color
- Remove leaks

## 2022-04-16 - Edu
### Added
- Include option to allow multiple lights bonus
- Document **parser.c** & **try_parse.c**
### Changed
- Improve error handling
### Fixed
- Handle **miniLibX** properly on makefile
## 2022-04-15 - Edu
### Added
- Added **try_parse** to handle parser for mandatory items.
## 2022-04-10 - Edu
### Changed
- Document **render**

## 2022-04-09 - Edu
### Changed
- Refactor **set_color_matrix** to reduce complexity, including reduce VERT_RESOLUTION x HORIZ_RESOLUTION x 1 o 2 operations to one.
- Refactor **t_item_list->next/content** into **t_item->next** to reduce complexity

## 2022-04-01 - Jorge
- Shadows work fine, and all bugs related to collisions have been fixed.
## 2022-03-28 - Jorge
- Attempted to create shadows created by objects. It kinda works, but it's not precise as we depend on the precision of floats (check src/coloring/get_collision_point.c line 99).

## 2022-03-25 - Jorge
### Added
- **Ambient lights** now affects every figure's color. The color modification gets applied when checking which is the closest point for each ray.

## 2022-03-22 - Edu
### Added
- Added **free_array_coords** & **free_array_colors**
### Changed
- Replaced malloc by ft_calloc to simplify leaks handling

## 2022-03-22 - Jorge
### Added
- **change_color_matrix** now stores the color of the figure touched. There's a problem with collisions involving spheres (the transition isn't smooth).
## 2022-03-22 - Jorge
### Fixed
- Sphere detection now works fine. The number of times a single ray collided with an object doesn't seem to work.

## 2022-03-22 - Edu
### Added
- Added **render.c/render.h** to render pixels into mlx's screen

## 2022-03-18 - Jorge
### Added
- We can now get the spot where a ray collides with a sphere and with a plane, along with the normal vector at that point.
- New utils to make a dot product of two angles and the unit vector of a vector.
### Changed
- Spheres should not show on camera when found behind it. The system to check for spheres has been changed but **(BUG)** doesn't work yet.

## 2022-03-20 - Edu
### Added
- minilibx (2020-02-19 version) added

## 2022-03-18 - Jorge
### Added
- We can now identify collisons with spheres for each vector of the cam.
- Some new functions to work with vectors (*vctr_\*_operations.c*) and colors (*rgb2int.c*).

## 2022-03-16 - Jorge
### Added
- *Coloring* section, where we'll calculate the color of each pixel for the MiniLibX to work.
- Created *line_collision_checker.c*, where we'll check if a ray collides with a certain item. It does nothing yet.
### Changed
- Most of *main()* commands are now moved to *doingcalculation()* to make space for MiniLibX.

## 2022-03-15 - Edu
### Added
- Functions to print list_rt **lst_rt_print** and filter by type **get_items_by_type**
### Changed
- Some documentation on utils
### Fixed
- Some leaks at parsing list

## 2022-03-15 - Jorge
### Added
- Every ray's vector of the camera is now calculated and returned to the **main** function

## 2022-03-13 - Edu
### Added
- Add CHANGELOG.md, README.md, Makefile
### Changed
- Structure files in folders.

