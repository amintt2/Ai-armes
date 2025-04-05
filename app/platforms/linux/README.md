# Linux Platform Module

This module implements the platform-specific functionality for the AI-powered autocomplete application on Linux.

## Key Features

- Screen capture and text recognition using X11/Wayland
- Text field detection and monitoring
- Suggestion injection into active applications
- Hotkey registration and handling
- System tray integration

## Implementation Details

The Linux implementation uses X11/Wayland to interact with the operating system, capture screen content, and inject text into active applications. It communicates with the core engine through the platform abstraction layer.

## Development Setup

### Prerequisites

- GCC/Clang
- X11/Wayland development libraries
- CMake
- GTK or Qt for UI elements (TBD)

### Build Instructions

Detailed build instructions will be provided as the project develops. 