# Utils Directory (Bonus)

This directory contains utility functions for the bonus features, organized by functionality:

## 📁 File Organization

### `utils_b.c`
**Core utility functions for game initialization and graphics (bonus)**
- `fill_tabs()` - Fills the cub structure with map and element data
- `init_value()` - Initializes all game variables to default values  
- `rgb_to_hex()` - Converts RGB values to hexadecimal color format
- `draw()` - Draws lines using DDA algorithm
- `vision()` - Handles raycasting vision calculations

### `utils_2_b.c`
**Map validation and parsing utilities (bonus)**
- `check_virgule()` - Validates comma count in color strings
- `ramzi()` - Checks player position validity (internal helper)
- `hole_in_map()` - Detects holes/newlines in map data
- `path()` - Extracts file paths from configuration strings
- `check_character()` - Validates characters in map array

### `ft_split_cub_b.c`
**Custom string manipulation for Cub3D (bonus)**
- `turn_into_square()` - Converts spaces to '*' in map strings
- `ft_strdupmap()` - Custom strdup that pads maps to uniform width
- `ft_strjjoin()` - Custom string join function with memory management
- `get_tab()` - Reads and parses .cub file into string array

## 🎯 Bonus Features

The bonus utilities include additional functionality for:
- Enhanced mouse controls
- Minimap rendering
- Extended graphics features
- Advanced user interactions

## 🔧 Usage

These utility functions support the bonus features including:
- **Enhanced map parsing** with additional validation
- **Mouse interaction** for camera control
- **Minimap functionality** 
- **Extended graphics** rendering capabilities

## 📝 Notes

- All functions follow 42 coding standards
- Memory allocation is managed through the `manager()` function
- Include path: `#include "../../incl/cub3d.h"`
- Maintains compatibility with main project utilities
