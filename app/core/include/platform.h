#ifndef AUTOCOMPLETE_PLATFORM_H
#define AUTOCOMPLETE_PLATFORM_H

#include "engine.h"
#include <string>
#include <functional>

namespace autocomplete {

/**
 * Configuration for hotkey registration.
 */
struct HotkeyConfig {
    int modifiers;           // Modifier keys (e.g., Ctrl, Alt, Shift)
    int key;                 // The key code
};

/**
 * Interface for platform-specific implementations.
 * Each platform must implement this interface.
 */
class PlatformInterface {
public:
    /**
     * Virtual destructor.
     */
    virtual ~PlatformInterface() = default;

    /**
     * Capture the current text context from the active application.
     * 
     * @return The captured text context
     */
    virtual TextContext captureTextContext() = 0;

    /**
     * Inject a suggestion into the active application.
     * 
     * @param suggestion The suggestion to inject
     */
    virtual void injectSuggestion(const Suggestion& suggestion) = 0;

    /**
     * Register hotkeys for autocomplete functionality.
     * 
     * @param config The hotkey configuration
     */
    virtual void registerHotkeys(const HotkeyConfig& config) = 0;

    /**
     * Start monitoring text fields in active applications.
     * This function should set up the necessary event listeners.
     */
    virtual void monitorTextFields() = 0;

    /**
     * Stop monitoring text fields.
     */
    virtual void stopMonitoring() = 0;

    /**
     * Show a notification to the user.
     * 
     * @param title The notification title
     * @param message The notification message
     */
    virtual void showNotification(const std::string& title, const std::string& message) = 0;

    /**
     * Initialize the platform-specific implementation.
     * 
     * @return True if initialization was successful, false otherwise
     */
    virtual bool initialize() = 0;

    /**
     * Set a callback for when text context changes.
     * 
     * @param callback The callback function
     */
    virtual void setContextChangeCallback(std::function<void(const TextContext&)> callback) = 0;

    /**
     * Set a callback for when a hotkey is pressed.
     * 
     * @param callback The callback function
     */
    virtual void setHotkeyCallback(std::function<void(int)> callback) = 0;
};

/**
 * Factory function to create a platform-specific implementation.
 * This function must be implemented by each platform.
 * 
 * @return A unique pointer to a platform-specific implementation
 */
std::unique_ptr<PlatformInterface> createPlatformImplementation();

} // namespace autocomplete

#endif // AUTOCOMPLETE_PLATFORM_H 