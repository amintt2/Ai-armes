#ifndef AUTOCOMPLETE_ENGINE_H
#define AUTOCOMPLETE_ENGINE_H

#include <string>
#include <vector>
#include <memory>

namespace autocomplete {

/**
 * Configuration for the autocomplete engine.
 */
struct EngineConfig {
    bool useCloud;               // Whether to use cloud synchronization
    bool learnFromInput;         // Whether to learn from user input
    std::string userId;          // User ID for cloud synchronization
    std::string apiKey;          // API key for cloud service
    std::string supabaseUrl;     // Supabase URL
};

/**
 * Represents the context of text being analyzed.
 */
struct TextContext {
    std::string text;            // The current text
    std::string appName;         // Name of the application where text is being entered
    std::string fieldType;       // Type of field (e.g., "email", "code", "chat")
};

/**
 * Represents a text suggestion.
 */
struct Suggestion {
    std::string text;            // The suggested text
    float confidence;            // Confidence score (0.0 to 1.0)
};

/**
 * Represents the user's selection from suggestions.
 */
struct Selection {
    std::string selectedText;    // The text selected by the user
    int suggestionIndex;         // Index of the suggestion that was selected (-1 if custom)
};

/**
 * Autocomplete modes.
 */
enum class AutocompleteMode {
    ALWAYS_SUGGEST,              // Always show suggestions
    COMPLETE,                    // Complete words as user types
    TAB                          // Only show suggestions when tab is pressed
};

/**
 * Result of synchronization with the cloud.
 */
struct SyncResult {
    bool success;                // Whether synchronization was successful
    std::string message;         // Error message if synchronization failed
};

/**
 * Forward declarations
 */
class EngineImpl;

/**
 * Main autocomplete engine class.
 */
class Engine {
public:
    /**
     * Constructor.
     */
    Engine();

    /**
     * Destructor.
     */
    ~Engine();

    /**
     * Initialize the engine with the given configuration.
     * 
     * @param config The engine configuration
     */
    void initialize(const EngineConfig& config);

    /**
     * Generate suggestions based on the given context.
     * 
     * @param context The text context
     * @return A vector of suggestions
     */
    std::vector<Suggestion> suggest(const TextContext& context);

    /**
     * Learn from the user's selection.
     * 
     * @param context The text context
     * @param selection The user's selection
     */
    void learn(const TextContext& context, const Selection& selection);

    /**
     * Set the autocomplete mode.
     * 
     * @param mode The autocomplete mode
     */
    void setMode(AutocompleteMode mode);

    /**
     * Synchronize with the cloud.
     * 
     * @return The result of synchronization
     */
    SyncResult sync();

private:
    std::unique_ptr<EngineImpl> impl;  // Implementation details
};

} // namespace autocomplete

#endif // AUTOCOMPLETE_ENGINE_H 