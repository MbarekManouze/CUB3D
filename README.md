# cub3D

This project is inspired by the iconic Wolfenstein 3D game, introducing you to the world of ray-casting. Your objective is to create a dynamic 3D graphical representation of a maze from a first-person perspective using the miniLibX library. Get ready to immerse yourself in the world of 3D graphics and explore the fundamentals of ray-casting algorithms.

## Goals

Enhance your skills in C programming, algorithms, and graphics design.
Gain practical experience in window management, color manipulation, event handling, and shape rendering.
Develop a deep understanding of ray-casting principles and their application in creating immersive 3D environments.
Explore the playful practical applications of mathematics in computer graphics.

## Getting Started

Before diving into the project, it's recommended to familiarize yourself with the original Wolfenstein 3D game to understand its gameplay and visual style. You can play the game online here.

# Mandatory Part - cub3D

## Description

You are tasked with creating a realistic 3D graphical representation of a maze from a first-person perspective using ray-casting principles. Here are the key constraints and requirements for the project:

Utilize the miniLibX library for graphics rendering.

Display different wall textures based on the orientation (North, South, East, West) of the walls.

Set distinct floor and ceiling colors.

Implement smooth window management, allowing for seamless transitions and interactions.

Control the viewpoint using keyboard inputs (arrow keys for rotation, WASD keys for movement).

Ensure clean program termination upon pressing ESC or closing the window.

## Scene Description File (.cub)

The program must take a scene description file with the .cub extension as its first argument.

The map must consist of only 6 characters: 0 for empty space, 1 for a wall, and N/S/E/W for the player's start position and orientation.

The map must be surrounded by walls, and each element type can be separated by empty lines.

Each element in the scene description file must be preceded by a type identifier followed by specific information (e.g., texture paths, colors).
