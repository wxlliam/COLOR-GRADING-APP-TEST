#!/bin/bash

# Build script for OFX Plugin Framework
# Supports Linux and macOS

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}OFX Plugin Framework Build Script${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""

# Check for CMake
if ! command -v cmake &> /dev/null; then
    echo -e "${RED}Error: CMake is not installed${NC}"
    echo "Please install CMake 3.15 or higher"
    exit 1
fi

# Check CMake version
CMAKE_VERSION=$(cmake --version | head -n1 | cut -d' ' -f3)
echo -e "CMake version: ${GREEN}${CMAKE_VERSION}${NC}"

# Create build directory
BUILD_DIR="build"
if [ -d "$BUILD_DIR" ]; then
    echo -e "${YELLOW}Warning: Build directory exists. Cleaning...${NC}"
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure
echo ""
echo -e "${GREEN}Configuring...${NC}"
cmake ..

# Build
echo ""
echo -e "${GREEN}Building...${NC}"
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo ""
    echo -e "${GREEN}========================================${NC}"
    echo -e "${GREEN}Build completed successfully!${NC}"
    echo -e "${GREEN}========================================${NC}"
    echo ""
    echo "Plugin bundles are located in:"
    echo -e "  ${YELLOW}${BUILD_DIR}/Plugins/${NC}"
    echo ""
    echo "To install system-wide, run:"
    if [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "  ${YELLOW}sudo make install${NC}"
        echo ""
        echo "Or manually copy to:"
        echo -e "  ${YELLOW}/Library/OFX/Plugins/${NC}"
    else
        echo -e "  ${YELLOW}sudo make install${NC}"
        echo ""
        echo "Or manually copy to:"
        echo -e "  ${YELLOW}/usr/OFX/Plugins/${NC}"
    fi
else
    echo ""
    echo -e "${RED}========================================${NC}"
    echo -e "${RED}Build failed!${NC}"
    echo -e "${RED}========================================${NC}"
    exit 1
fi
