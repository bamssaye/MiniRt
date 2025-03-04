# miniRT - RayTracer with miniLibX
<center>
<img src="https://github.com/bamssaye/MiniRt/blob/main/img/img4.png?raw=true" width="300" alt="Ray traced sphere">
<img src="https://github.com/bamssaye/MiniRt/blob/main/img/img6.png?raw=true" width="300" alt="Ray traced sphere">
<img src="https://github.com/bamssaye/MiniRt/blob/main/img/img5.png?raw=true" width="300" alt="Ray traced sphere">
<img src="https://github.com/bamssaye/MiniRt/blob/main/img/img2.png?raw=true" width="300" alt="Ray traced sphere">
<img src="https://github.com/bamssaye/MiniRt/blob/main/img/img1.png?raw=true" width="300" alt="Ray traced sphere">
</center>

## About
miniRT is an introduction to the beautiful world of Ray Tracing. This project involves creating a simple ray tracer that can render basic 3D scenes composed of simple geometric objects with lighting effects.

## Table of Contents
- [Features](#features)
- [Installation and Usage](#installation-and-usage)
- [Scene Description](#scene-description)
- [Implementation Details](#implementation-details)
- [Examples](#examples)
- [Bonus Features](#bonus-features)

## Features
- Rendering of 3D scenes using ray tracing technique
- Support for basic geometric objects:
  - Spheres
  - Planes
  - Cylinders
  - Cone
- Lighting features:
  - Ambient lighting
  - Diffuse lighting
  - Shadows
- Camera positioning and orientation
- Scene description via configuration files
- Flexible window management

## Installation and Usage

### Requirements
- C compiler
- miniLibX library

### Compilation
```bash
make
```

### Running the program
```bash
./miniRT <scene/scene_file.rt>
```

### Controls
- **ESC:** Exit the program
- **Red cross:** Close the window

## Scene Description
The program uses scene description files with the `.rt` extension. These files define all elements of the scene:

### File Format
Elements can be separated by one or more line breaks, and information within elements can be separated by one or more spaces. Elements can be defined in any order, though elements with capital letter identifiers can only be declared once per scene.

### Elements

#### Ambient Lighting
```
A 0.2 255,255,255
```
- Identifier: `A`
- Ambient lighting ratio [0.0-1.0]: `0.2`
- RGB colors [0-255]: `255,255,255`

#### Camera
```
C -50.0,0,20 0,0,1 70
```
- Identifier: `C`
- Position (x,y,z): `-50.0,0,20`
- Orientation vector [-1,1] per axis: `0,0,1`
- FOV [0-180] degrees: `70`

#### Light
```
L -40.0,50.0,0.0 0.6 10,0,255
```
- Identifier: `L`
- Position (x,y,z): `-40.0,50.0,0.0`
- Brightness ratio [0.0-1.0]: `0.6`
- RGB colors [0-255]: `10,0,255` (unused in mandatory part)

#### Sphere
```
sp 0.0,0.0,20.6 12.6 10,0,255
```
- Identifier: `sp`
- Center position (x,y,z): `0.0,0.0,20.6`
- Diameter: `12.6`
- RGB colors [0-255]: `10,0,255`

#### Plane
```
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
```
- Identifier: `pl`
- Position (x,y,z): `0.0,0.0,-10.0`
- Normal vector [-1,1] per axis: `0.0,1.0,0.0`
- RGB colors [0-255]: `0,0,225`

#### Cylinder
```
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```
- Identifier: `cy`
- Center position (x,y,z): `50.0,0.0,20.6`
- Axis vector [-1,1] per axis: `0.0,0.0,1.0`
- Diameter: `14.2`
- Height: `21.42`
- RGB colors [0-255]: `10,0,255`

#### Cone
```
co 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```
- Identifier: `co`
- Center position (x,y,z): `50.0,0.0,20.6`
- Axis vector [-1,1] per axis: `0.0,0.0,1.0`
- Diameter: `14.2`
- Height: `21.42`
- RGB colors [0-255]: `10,0,255`

### Checkborad / Color / {Texture, normal map}
```
co <x,y,z> <Xaxis, Yaxis, Zaxis> <Diameter> <Height> <{255,0,0, checkborad, texture:earth.xpm}>

```
## Implementation Details

### Ray Tracing Algorithm
The basic ray tracing algorithm implemented in this project:
1. For each pixel in the image:
   - Generate a ray from the camera through the pixel
   - Find the closest intersection with an object in the scene
   - Calculate lighting (ambient and diffuse) at intersection point
   - Handle shadows by checking if light rays are blocked
   - Determine the final color of the pixel

### Mathematical Formulas
Key mathematical concepts used in this implementation:
- Vector operations (dot product, cross product, normalization)
- Ray-object intersection formulas:
  - Ray-sphere intersection
  - Ray-plane intersection
  - Ray-cylinder intersection
- Lighting calculations (diffuse reflection, ambient light)

## License
This project is licensed under the MIT License - see the LICENSE file for details.
