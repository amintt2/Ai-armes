# System Patterns

## Architecture Overview

```mermaid
flowchart TD
    User[User Device] <--> Client[Autocomplete Client]
    Client <--> API[Cloud API]
    API <--> DB[Supabase Database]
    Web[Next.js Website] <--> API
    User <--> Web
```

## Core Components

### Autocomplete Client Architecture
```mermaid
flowchart TD
    subgraph Client[Client Application]
        CE[Core Engine] <--> PS[Platform-Specific Module]
        CE <--> AI[AI Integration]
        CE <--> Sync[Cloud Sync Module]
    end
    PS <--> OS[Operating System]
    Sync <--> Cloud[Supabase Cloud]
```

### Cloud Backend Architecture
```mermaid
flowchart TD
    subgraph Supabase[Supabase Backend]
        Auth[Authentication]
        DB[PostgreSQL Database]
        Storage[File Storage]
        Realtime[Realtime Updates]
    end
    
    Client[Client App] <--> Auth
    Client <--> DB
    Client <--> Storage
    Client <--> Realtime
    
    Website[Next.js Website] <--> Auth
    Website <--> DB
    Website <--> Storage
```

## Collaboration Patterns

### Project Direction Flow
```mermaid
flowchart TD
    U[User/Project Director] -->|Selects| S[Sprint Priority]
    U -->|Makes| AD[Architecture Decisions]
    U -->|Provides| R[Requirements]
    U -->|Determines| A[Implementation Approach]
    U -->|Validates| C[Completed Work]
    U -->|Decides When| SC[Sprint is Complete]
    
    A[AI Assistant] -->|Asks Questions| U
    A -->|Presents Options| U
    A -->|Seeks Approval| U
    A -->|Implements Based on| R
    A -->|Reports Progress to| U
    A -->|Requests Validation from| U
```

### Development Communication Flow
```mermaid
sequenceDiagram
    participant U as User/Project Director
    participant A as AI Assistant
    participant C as Codebase
    
    U->>A: Request feature implementation
    A->>A: Analyze requirements
    A->>U: Ask detailed clarifying questions
    U->>A: Provide clarification
    A->>U: Present implementation options with justifications
    U->>A: Select approach
    A->>U: Ask permission to create branch
    U->>A: Grant permission
    A->>C: Create branch & implement
    A->>U: Provide progress updates
    A->>U: Present implementation for review
    U->>A: Provide feedback
    A->>C: Make adjustments
    A->>U: Request validation
    U->>A: Validate functionality
    U->>A: Decide if sprint is complete
    A->>U: Ask permission to merge
    U->>A: Grant permission
    A->>C: Merge to master
    U->>A: Select next sprint
```

### Decision-Making Framework
```mermaid
flowchart TD
    Start[Task Identified] --> Understand[Understand Requirements]
    Understand --> Clear{Requirements Clear?}
    Clear -->|No| Ask[Ask Clarifying Questions]
    Ask --> Understand
    
    Clear -->|Yes| Options[Present Implementation Options with Justifications]
    Options --> UserDecision[User Makes Decision]
    
    UserDecision --> Permission{Permission to Proceed?}
    Permission -->|No| Adjust[Adjust Approach]
    Adjust --> Options
    
    Permission -->|Yes| Implement[Implement Solution]
    Implement --> Progress[Provide Progress Updates]
    Progress --> Review[Present for Review]
    Review --> Feedback[User Provides Feedback]
    Feedback --> Changes{Changes Needed?}
    
    Changes -->|Yes| Revise[Revise Implementation]
    Revise --> Review
    
    Changes -->|No| SprintComplete{User Confirms Sprint Complete?}
    SprintComplete -->|No| Revise
    SprintComplete -->|Yes| NextSprint[User Selects Next Sprint]
```

## Development Workflow

### Sprint Lifecycle
```mermaid
stateDiagram-v2
    [*] --> SprintPlanning
    
    SprintPlanning --> UserApproval: Present options
    UserApproval --> Rejected: User rejects or modifies
    Rejected --> SprintPlanning: Adjust based on feedback
    
    UserApproval --> Implementation: User approves
    Implementation --> ProgressUpdate: Regular updates
    ProgressUpdate --> Implementation
    
    Implementation --> Review: Complete implementation
    Review --> Refinement: User feedback
    Refinement --> Review: Make adjustments
    
    Review --> UserValidation: User satisfied with changes
    UserValidation --> [*]: User confirms sprint complete
    
    UserValidation --> NextSprint: User selects next sprint
    NextSprint --> [*]
```

### Git Branching Strategy
```mermaid
gitGraph
    commit id: "initial"
    branch feature/auth-flow
    checkout feature/auth-flow
    commit id: "add auth components"
    commit id: "implement login flow"
    commit id: "add tests"
    checkout main
    merge feature/auth-flow id: "validated auth flow" tag: "v0.1.0"
    branch feature/download-page
    checkout feature/download-page
    commit id: "create download UI"
    commit id: "implement platform detection"
    checkout main
    merge feature/download-page id: "validated download page" tag: "v0.2.0"
```

### Sprint-Based Development
```mermaid
gantt
    title Project Sprints
    dateFormat  YYYY-MM-DD
    section Web App
    Authentication Flow    :active, auth, 2023-04-06, 14d
    Download Page          :download, after auth, 14d
    Pricing Page           :after download, 14d
    Dashboard              :after pricing, 14d
    section Core Engine
    Windows Text Capture   :after dashboard, 21d
    Suggestion Generation  :after windows, 21d
```

## Design Patterns

### Client-Side Patterns
- **Observer Pattern**: For monitoring text input fields and triggering suggestions
- **Strategy Pattern**: For switching between different autocomplete modes
- **Repository Pattern**: For abstracting data access and synchronization
- **Factory Pattern**: For creating platform-specific components

### Web Application Patterns
- **Component-Based Architecture**: React/Next.js components for UI
- **Container/Presenter Pattern**: Separation of data handling and presentation
- **Server-Side Rendering**: For improved performance and SEO
- **API Route Handlers**: For secure server-side operations

### Data Flow Patterns
- **Event-Sourcing**: For tracking and synchronizing user context changes
- **CQRS**: Separate query and command models for data operations
- **Optimistic Updates**: For responsive UI during cloud synchronization

## Key Interfaces

### Core Engine API
- `initialize(config: EngineConfig): void`
- `suggest(context: TextContext): Suggestion[]`
- `learn(context: TextContext, selection: Selection): void`
- `setMode(mode: AutocompleteMode): void`
- `sync(): Promise<SyncResult>`

### Platform-Specific Module Interface
- `captureTextContext(): TextContext`
- `injectSuggestion(suggestion: Suggestion): void`
- `registerHotkeys(config: HotkeyConfig): void`
- `monitorTextFields(): void`

### Cloud Sync Interface
- `pushContext(context: UserContext): Promise<SyncResult>`
- `pullContext(): Promise<UserContext>`
- `authenticate(credentials: AuthCredentials): Promise<AuthResult>`
- `syncPreferences(preferences: UserPreferences): Promise<SyncResult>` 