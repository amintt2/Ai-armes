# Core Autocomplete Engine

This directory contains the core autocomplete engine implementation, which is responsible for:

- Processing text context from platform-specific modules
- Generating intelligent text suggestions
- Managing personal context and learning
- Synchronizing with the cloud backend

## Structure

- `src/` - Core engine source code
- `include/` - Public headers/interfaces
- `tests/` - Testing suite
- `vendor/` - Third-party dependencies

## Key Components

### Text Context Processor
Analyzes captured text to understand context and meaning.

### Suggestion Generator
Uses AI models to generate relevant autocomplete suggestions.

### Context Manager
Stores and retrieves personal context data for improving suggestions.

### Cloud Sync Module
Synchronizes personal context data with Supabase backend.

### Platform Abstraction Layer
Provides interfaces for platform-specific implementations.

## Implementation Details

The core engine is implemented in Rust/C++ for optimal performance and minimal resource usage. It exposes a clean API that can be consumed by each platform-specific implementation. 