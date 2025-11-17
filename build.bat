@echo off
REM Build script for OFX Plugin Framework on Windows

echo ========================================
echo OFX Plugin Framework Build Script
echo ========================================
echo.

REM Check for CMake
where cmake >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: CMake is not installed
    echo Please install CMake 3.15 or higher
    exit /b 1
)

REM Display CMake version
echo CMake found:
cmake --version | findstr /C:"cmake version"
echo.

REM Create build directory
set BUILD_DIR=build
if exist "%BUILD_DIR%" (
    echo Warning: Build directory exists. Cleaning...
    rmdir /s /q "%BUILD_DIR%"
)

mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

REM Configure with Visual Studio
echo.
echo Configuring...
cmake .. -G "Visual Studio 16 2019" -A x64
if %errorlevel% neq 0 (
    echo.
    echo Configuration failed!
    echo If you don't have Visual Studio 2019, try one of these:
    echo   cmake .. -G "Visual Studio 17 2022" -A x64
    echo   cmake .. -G "Visual Studio 15 2017" -A x64
    cd ..
    exit /b 1
)

REM Build
echo.
echo Building...
cmake --build . --config Release
if %errorlevel% neq 0 (
    echo.
    echo ========================================
    echo Build failed!
    echo ========================================
    cd ..
    exit /b 1
)

echo.
echo ========================================
echo Build completed successfully!
echo ========================================
echo.
echo Plugin bundles are located in:
echo   %BUILD_DIR%\Plugins\
echo.
echo To install system-wide, run as Administrator:
echo   cmake --install . --config Release
echo.
echo Or manually copy to:
echo   C:\Program Files\Common Files\OFX\Plugins\
echo.

cd ..
