# Computer Graphics using raylib (C)

A collection of Computer Graphics laboratory programs implemented in **C** using the **raylib** graphics library.

This repository contains classic graphics algorithms, 2D/3D transformations, clipping algorithms, polygon filling, drawing objects, and animation programs.

---

## Features

- Midpoint Circle Algorithm
- Cohen-Sutherland Line Clipping
- Sutherland-Hodgman Polygon Clipping
- Scan-Line Polygon Fill
- 2D Transformations
- 3D Parallel & Perspective Projection
- Basic Graphics Primitives
- House, Car, Fish and Man Drawings
- Moving Circle Animation
- Moving Man Animation
- Walking Man Animation
- Windmill Rotation Animation

---

## Folder Structure

The repository stores source files in the project root and build artifacts in `output/`.

```
basicgraphics.c
circleanim.c
lineclipping.c
linedrawing.c
manmove.c
manwalk.c
midpointcircle.c
Polygonclip.c
scanlinefillalgo.c
simple2d.c
transform3d.c
transformations.c
WindmillR.c
output/
README.md
```

---

## Requirements

- C Compiler (GCC / MinGW)
- raylib 5.x

---

## Compile

Linux

```bash
gcc filename.c -o output \
-lraylib -lm -lpthread -ldl -lrt -lX11
```

Windows (MinGW)

```bash
gcc filename.c -o output.exe \
-lraylib -lopengl32 -lgdi32 -lwinmm
```

---

## Programs Included

### Algorithms

- Midpoint Circle
- Cohen-Sutherland Line Clipping
- Sutherland-Hodgman Polygon Clipping
- Scan-Line Polygon Fill
- 2D Transformations
- 3D Projection

### Shapes

- Basic Shapes
- House
- Car
- Fish
- Man

### Animations

- Moving Circle
- Moving Man
- Walking Man
- Windmill Rotation

---

## Screenshots

- [output](./output/CG_OUTPUT.pdf)

```

---

## Author

Gourahari sahoo

---