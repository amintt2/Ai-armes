# Technical Context

## Core Technologies

### Autocomplete Engine
- **Implementation Language**: C++ or Rust (for performance and minimal resource usage)
- **AI Integration**: Gemini 2.0 Flash or similar lightweight model
- **Text Processing**: Custom parser for contextual understanding

### Platform-Specific Implementation
- **Windows**: Win32 API for screen capture and text input
- **macOS**: AppKit/Cocoa frameworks
- **Linux**: X11/Wayland integration

### Cloud Backend
- **Platform**: Supabase
- **Database**: PostgreSQL (provided by Supabase)
- **Authentication**: Supabase Auth
- **Real-time Data**: Supabase Realtime for synchronization
- **Storage**: Supabase Storage for user data

### Web Application
- **Framework**: Next.js
- **UI Components**: Tailwind CSS
- **State Management**: React Context API or Redux
- **Payment Processing**: Stripe
- **Deployment**: Vercel

## Development Environment
- **Version Control**: Git
- **Package Management**: npm/yarn for web, platform-specific package managers for native code
- **Testing**: Jest for web, platform-specific testing frameworks for native code
- **CI/CD**: GitHub Actions

## Technical Constraints
- Minimize memory and CPU usage on client devices
- Ensure text suggestions appear with < 100ms latency
- Secure all data transmission with end-to-end encryption
- Provide fallback mechanisms for offline operation 