# Project Brief: AI-Powered Autocomplete App

## Core Objective
Develop a cross-platform, lightweight AI-powered autocomplete app that suggests text contextually and synchronizes personalized context across devices via a cloud backend. A companion website will provide product downloads, account creation, and subscription management.

## Key Components

### Core Autocomplete Engine
- Provides intelligent text suggestions based on on-screen content
- Supports multiple modes (Always Suggest, Complete, Tab)
- Lightweight implementation (C++ or Rust) for minimal resource usage
- AI integration (e.g., Gemini 2.0 Flash) for smart suggestions

### Cross-Platform Support
- Separate native implementations for Windows, macOS, and Linux
- Screen capture and text input detection modules for each platform

### Cloud Storage & Sync (Supabase)
- Store user profiles, subscription details, and context data
- Secure API endpoints for data synchronization
- Support both opt-in (personalized context) and opt-out (local autocomplete) scenarios

### Companion Website (Next.js)
- Account creation and login functionality
- Subscription management with payment integration (Stripe)
- OS-specific download portal
- Dashboard for managing stored context and preferences

## Target Outcomes
- Seamless cross-device experience with personalized suggestions
- Minimal resource footprint on user devices
- Privacy-focused with clear opt-in/opt-out controls
- Sustainable business model through subscription tiers

## Success Metrics
- Accuracy of autocomplete suggestions
- Resource usage (CPU, RAM, battery impact)
- Cross-device synchronization reliability
- User retention and subscription conversion rates 