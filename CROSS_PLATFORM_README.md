# Cub3D - Cross-Platform Setup Guide

This Cub3D implementation now supports automatic compilation on both **macOS** and **Linux** systems without manual configuration.

## 🚀 Features

- **Automatic Platform Detection**: Detects your operating system and uses appropriate settings
- **Platform-Specific MLX Libraries**: Uses macOS MLX for Apple systems and Linux MLX for Unix-like systems
- **Seamless Compilation**: Same commands work on both platforms
- **Comprehensive Error Handling**: Clear error messages and platform-specific feedback

## 📋 System Requirements

### macOS
- Xcode Command Line Tools
- macOS 10.12 or later
- OpenGL and AppKit frameworks (included with macOS)

### Linux
- GCC compiler
- X11 development libraries
- Make utility

#### Installing Dependencies on Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install gcc make libx11-dev libxext-dev libbsd-dev
```

#### Installing Dependencies on CentOS/RHEL/Fedora:
```bash
# CentOS/RHEL
sudo yum install gcc make libX11-devel libXext-devel libbsd-devel

# Fedora
sudo dnf install gcc make libX11-devel libXext-devel libbsd-devel
```

## 🔧 Compilation

The same commands work on both platforms:

```bash
# Compile the main project
make

# Compile with bonus features
make bonus

# Clean object files
make clean

# Full clean (removes executable too)
make fclean

# Recompile everything
make re
```

## 🖥️ Platform-Specific Behavior

### Automatic Detection
The Makefile automatically detects your platform using `uname -s`:
- **Darwin**: Detected as macOS - uses macOS MLX and Apple frameworks
- **Linux**: Detected as Linux - uses Linux MLX and X11 libraries
- **Other Unix-like**: Falls back to Linux settings

### Platform Messages
During compilation, you'll see platform-specific messages:
```
Compiling for macOS
🔨 Setting up macOS MLX library...
✅ cub3d compiled successfully for Darwin
```

```
Compiling for Linux
🔨 Building Linux MLX library...
✅ cub3d compiled successfully for Linux
```

## 📁 Directory Structure

```
Cub3d/
├── mlx/                    # Linux MLX library
├── mlx_macos/             # macOS MLX library
├── mlx_macos_backup/      # Backup of original macOS MLX
├── incl/cub3d.h           # Cross-platform header file
├── srcs/                  # Main source files
├── srcs_bonus/            # Bonus source files
├── libft/                 # Custom library
├── maps/                  # Test maps
├── textures/              # Game textures
└── Makefile               # Cross-platform Makefile
```

## 🔍 Technical Details

### Compiler Flags
- **macOS**: Uses `-framework OpenGL -framework AppKit`
- **Linux**: Uses `-lXext -lX11 -lm -lbsd`

### MLX Function Differences
The code handles platform-specific MLX function signatures:
- **macOS**: `mlx_mouse_hide()` takes no parameters
- **Linux**: `mlx_mouse_hide(void *mlx_ptr, void *win_ptr)` takes two parameters

### Header Includes
Platform-specific includes are handled automatically:
```c
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>  // macOS only
#endif
```

## 🚨 Troubleshooting

### macOS Issues
1. **"command not found: make"**
   ```bash
   xcode-select --install
   ```

2. **MLX library not found**
   - Ensure `mlx_macos_backup/` directory exists
   - The Makefile will automatically set up the macOS MLX library

### Linux Issues
1. **"mlx.h: No such file or directory"**
   ```bash
   sudo apt-get install libx11-dev libxext-dev
   ```

2. **X11 linking errors**
   ```bash
   sudo apt-get install libbsd-dev
   ```

3. **Permission denied when running**
   ```bash
   chmod +x cub3d
   ```

### General Issues
1. **Segmentation fault when running**
   - This is expected in headless environments (no display)
   - The program requires a graphical environment to run properly

2. **Math function errors**
   - Ensure `-lm` flag is included (handled automatically)

## 🎮 Usage

```bash
# Basic usage
./cub3d maps/map.cub

# With bonus features (if compiled with 'make bonus')
./cub3d maps/map.cub
```

### Controls
- **W, A, S, D**: Movement
- **Arrow Keys**: Look around
- **ESC**: Exit
- **Mouse**: Look around (bonus)

## 🔄 Switching Between Platforms

If you move the project between macOS and Linux:

1. Clean previous compilation:
   ```bash
   make fclean
   ```

2. Recompile for the new platform:
   ```bash
   make
   ```

The Makefile will automatically detect the new platform and use appropriate settings.

## 📝 Development Notes

### Adding New Source Files
Add new `.c` files to the appropriate variables in the Makefile:
- `SRC` for main project files
- `SRC_BONUS` for bonus files

### Platform-Specific Code
Use preprocessor directives for platform-specific code:
```c
#ifdef __APPLE__
    // macOS-specific code
#else
    // Linux/Unix-specific code
#endif
```

## 🤝 Contributing

When contributing to this project:
1. Test on both macOS and Linux if possible
2. Use platform-agnostic code when possible
3. Document any platform-specific requirements
4. Ensure the cross-platform Makefile still works

## ✅ Verification

To verify the cross-platform setup works:

1. **Check platform detection**:
   ```bash
   make clean && make
   # Should show "Compiling for [your platform]"
   ```

2. **Verify executable creation**:
   ```bash
   ls -la cub3d
   # Should show the executable file
   ```

3. **Test basic functionality**:
   ```bash
   ./cub3d
   # Should show error message about missing file
   ```

---

**Note**: This cross-platform implementation maintains full compatibility with the original 42 School project requirements while adding seamless multi-platform support.
