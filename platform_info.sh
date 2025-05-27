#!/bin/bash

# Simple platform detection for Cub3D
echo "🔍 Platform Detection for Cub3D"
echo "==============================="

PLATFORM=$(uname -s)
ARCH=$(uname -m)

echo "Operating System: $PLATFORM"
echo "Architecture: $ARCH"
echo ""

case $PLATFORM in
    "Darwin")
        echo "🍎 macOS Detected"
        echo "MLX Library: mlx_macos/"
        echo "Linking: OpenGL and AppKit frameworks"
        echo "Compiler flags: -framework OpenGL -framework AppKit"
        ;;
    "Linux")
        echo "🐧 Linux Detected"
        echo "MLX Library: mlx/"
        echo "Linking: X11, Xext, math, and bsd libraries"
        echo "Compiler flags: -lXext -lX11 -lm -lbsd"
        ;;
    *)
        echo "🔧 Unix-like System Detected"
        echo "Using Linux-compatible settings"
        echo "MLX Library: mlx/"
        echo "Linking: X11, Xext, and math libraries"
        echo "Compiler flags: -lXext -lX11 -lm"
        ;;
esac

echo ""
echo "To compile: make"
echo "To clean: make clean"
echo "For bonus: make bonus"
