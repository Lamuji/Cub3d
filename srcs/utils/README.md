# Utils Directory

This directory contains utility functions organized by functionality:

## 📁 File Organization

### `utils.c`
**Core utility functions for game initialization and graphics**
- `fill_tabs()` - Fills the cub structure with map and element data
- `init_value()` - Initializes all game variables to default values  
- `rgb_to_hex()` - Converts RGB values to hexadecimal color format
- `draw()` - Draws lines using DDA algorithm
- `vision()` - Handles raycasting vision calculations

### `utils_2.c`
**Map validation and parsing utilities**
- `check_virgule()` - Validates comma count in color strings
- `ramzi()` - Checks player position validity (internal helper)
- `hole_in_map()` - Detects holes/newlines in map data
- `path()` - Extracts file paths from configuration strings
- `check_character()` - Validates characters in map array

### `ft_split_cub.c`
**Custom string manipulation for Cub3D**
- `turn_into_square()` - Converts spaces to '*' in map strings
- `ft_strdupmap()` - Custom strdup that pads maps to uniform width
- `ft_strjjoin()` - Custom string join function with memory management
- `get_tab()` - Reads and parses .cub file into string array

## 🔧 Usage

These utility functions are used throughout the project for:
- **Map parsing and validation** (`utils_2.c`, `ft_split_cub.c`)
- **Game initialization** (`utils.c`)
- **Graphics and rendering** (`utils.c`)
- **Memory management** (all files use `manager()` for leak prevention)

## 📝 Notes

- All functions follow 42 coding standards
- Memory allocation is managed through the `manager()` function
- Bonus versions (`*_b.c`) contain identical functionality with additional features
- Include path: `#include "../../incl/cub3d.h"`
