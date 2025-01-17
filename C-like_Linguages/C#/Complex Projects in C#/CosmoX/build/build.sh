#!/bin/bash

echo "Building the project..."

# Compile C# and C++ files
csc Program.cs GameManager.cs MapRenderer.cs ResourceManager.cs EventSystem.cs
g++ -o game Main.cpp

echo "Build complete."