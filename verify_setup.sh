#!/bin/bash

# Cross-Platform Cub3D Setup Verification Script
# This script verifies that the cross-platform setup is working correctly

echo "🔍 Cub3D Cross-Platform Setup Verification"
echo "=========================================="

# Detect platform
PLATFORM=$(uname -s)
echo "📱 Detected Platform: $PLATFORM"

# Check if required directories exist
echo ""
echo "📁 Checking Directory Structure..."

if [ -d "mlx" ]; then
    echo "✅ Linux MLX directory found"
else
    echo "❌ Linux MLX directory missing"
fi

if [ -d "mlx_macos" ] || [ -d "mlx_macos_backup" ]; then
    echo "✅ macOS MLX directory found"
else
    echo "⚠️  macOS MLX directory missing (only needed on macOS)"
fi

if [ -d "libft" ]; then
    echo "✅ libft directory found"
else
    echo "❌ libft directory missing"
fi

if [ -d "srcs" ]; then
    echo "✅ srcs directory found"
else
    echo "❌ srcs directory missing"
fi

# Check for required files
echo ""
echo "📄 Checking Required Files..."

if [ -f "Makefile" ]; then
    echo "✅ Makefile found"
    
    # Check if Makefile has cross-platform support
    if grep -q "UNAME_S" Makefile; then
        echo "✅ Cross-platform Makefile detected"
    else
        echo "❌ Makefile does not have cross-platform support"
    fi
else
    echo "❌ Makefile missing"
fi

if [ -f "incl/cub3d.h" ]; then
    echo "✅ Header file found"
else
    echo "❌ Header file missing"
fi

# Check platform-specific dependencies
echo ""
echo "🔧 Checking Platform-Specific Dependencies..."

if [ "$PLATFORM" = "Darwin" ]; then
    echo "🍎 macOS detected - checking for Xcode tools..."
    if command -v gcc >/dev/null 2>&1; then
        echo "✅ GCC compiler found"
    else
        echo "❌ GCC compiler not found. Install Xcode Command Line Tools:"
        echo "   xcode-select --install"
    fi
    
elif [ "$PLATFORM" = "Linux" ]; then
    echo "🐧 Linux detected - checking for required libraries..."
    
    if command -v gcc >/dev/null 2>&1; then
        echo "✅ GCC compiler found"
    else
        echo "❌ GCC compiler not found"
    fi
    
    if pkg-config --exists x11 2>/dev/null; then
        echo "✅ X11 libraries found"
    else
        echo "❌ X11 libraries not found. Install with:"
        echo "   sudo apt-get install libx11-dev libxext-dev"
    fi
    
    if find /usr -name "libbsd*" 2>/dev/null | grep -q libbsd; then
        echo "✅ BSD library found"
    else
        echo "⚠️  BSD library not found. Install with:"
        echo "   sudo apt-get install libbsd-dev"
    fi
fi

# Test compilation
echo ""
echo "🔨 Testing Compilation..."

if make clean >/dev/null 2>&1; then
    echo "✅ make clean successful"
else
    echo "❌ make clean failed"
fi

echo "Attempting to compile..."
if make >/dev/null 2>&1; then
    echo "✅ Compilation successful!"
    
    if [ -f "cub3d" ]; then
        echo "✅ Executable created"
        
        # Test basic functionality
        echo ""
        echo "🧪 Testing Basic Functionality..."
        
        # Test with no arguments (should show error)
        if ./cub3d 2>&1 | grep -q "Error"; then
            echo "✅ Basic error handling works"
        else
            echo "⚠️  Unexpected output from executable"
        fi
        
    else
        echo "❌ Executable not found after compilation"
    fi
else
    echo "❌ Compilation failed"
    echo "Run 'make' manually to see detailed error messages"
fi

# Summary
echo ""
echo "📋 Summary"
echo "=========="

if [ -f "cub3d" ]; then
    echo "✅ Setup appears to be working correctly!"
    echo ""
    echo "Next steps:"
    echo "1. Try running: ./cub3d maps/map.cub"
    echo "2. For bonus features: make bonus"
    echo "3. Read CROSS_PLATFORM_README.md for detailed information"
else
    echo "❌ Setup has issues that need to be resolved"
    echo ""
    echo "Troubleshooting:"
    echo "1. Check the error messages above"
    echo "2. Ensure all dependencies are installed"
    echo "3. Read CROSS_PLATFORM_README.md for help"
fi

echo ""
echo "For detailed documentation, see: CROSS_PLATFORM_README.md"
