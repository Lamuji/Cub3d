# CUBE3D

Cub3D is a project from **École 42** aimed at creating a 3D rendering engine using the raycasting technique, similar to the one used in early first-person shooter games like Wolfenstein 3D. 

The project uses the MinilibX graphics library to create windows, handle events, and manipulate images.  

The main steps include reading the map from a file, calculating rays to determine intersections with walls, applying textures, and implementing controls to allow the player to navigate through a 3D maze.  

The ultimate goal is to create a smooth and responsive gaming experience while optimizing performance.

## 🚀 Cross-Platform Support

This implementation now supports **automatic compilation on both macOS and Linux** without manual configuration!

- **Automatic Platform Detection**: Detects your OS and uses appropriate settings
- **Platform-Specific MLX Libraries**: Uses the correct MLX version for your system  
- **Seamless Compilation**: Same commands work on both platforms

### Quick Start
```bash
# Works on both macOS and Linux
make

# Run the program
./cub3d maps/map.cub

# For bonus features
make bonus
```

### Verification
```bash
# Check if your setup is working
./verify_setup.sh

# See platform-specific information
./platform_info.sh
```

📖 **For detailed cross-platform documentation, see [CROSS_PLATFORM_README.md](CROSS_PLATFORM_README.md)**

## Demo








![Demo GIF](IMG_1857.gif)
