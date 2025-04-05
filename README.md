# AI-Powered Autocomplete Application

A cross-platform, lightweight AI-powered autocomplete app that provides contextual text suggestions and synchronizes personal context across devices via a Supabase cloud backend.

## Project Structure

```
.
├── app/                  # Application source code
│   ├── core/             # Core autocomplete engine (Rust/C++)
│   └── platforms/        # Platform-specific implementations
│       ├── windows/      # Windows implementation
│       ├── macos/        # macOS implementation
│       └── linux/        # Linux implementation
├── web/                  # Next.js companion website
├── utils/                # Shared utilities and scripts
└── memory-bank/          # Project documentation
```

## Key Features

- Intelligent text suggestions based on on-screen content
- Multiple autocomplete modes (Always Suggest, Complete, Tab)
- Cross-device synchronization of personal context
- Privacy-focused with clear opt-in/opt-out controls
- Companion website for account management and downloads

## Technology Stack

- **Core Engine**: Rust/C++ for performance and minimal resource usage
- **Cloud Backend**: Supabase (PostgreSQL, Auth, Storage, Realtime)
- **Web Application**: Next.js with Tailwind CSS
- **Payment Processing**: Stripe integration

## Getting Started

### Prerequisites

- Node.js 18+ for web development
- Rust/C++ toolchain for core engine development
- Platform-specific development tools
  - Windows: Visual Studio with C++ workload
  - macOS: Xcode and Command Line Tools
  - Linux: GCC/Clang and relevant development libraries

### Development Setup

1. Clone the repository
2. Set up the Next.js web application:
   ```
   cd web
   npm install
   npm run dev
   ```
3. Set up the core engine (instructions vary by platform)

## License

[MIT License](LICENSE) 