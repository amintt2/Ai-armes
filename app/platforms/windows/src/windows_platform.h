#ifndef WINDOWS_PLATFORM_H
#define WINDOWS_PLATFORM_H

#include "../../../core/include/platform.h"
#include <windows.h>
#include <string>
#include <functional>
#include <memory>
#include <map>

namespace autocomplete {
namespace windows {

/**
 * Windows-specific implementation of the PlatformInterface.
 */
class WindowsPlatform : public PlatformInterface {
public:
    /**
     * Constructor.
     */
    WindowsPlatform();

    /**
     * Destructor.
     */
    ~WindowsPlatform() override;

    /**
     * Capture the current text context from the active application.
     * 
     * @return The captured text context
     */
    TextContext captureTextContext() override;

    /**
     * Inject a suggestion into the active application.
     * 
     * @param suggestion The suggestion to inject
     */
    void injectSuggestion(const Suggestion& suggestion) override;

    /**
     * Register hotkeys for autocomplete functionality.
     * 
     * @param config The hotkey configuration
     */
    void registerHotkeys(const HotkeyConfig& config) override;

    /**
     * Start monitoring text fields in active applications.
     */
    void monitorTextFields() override;

    /**
     * Stop monitoring text fields.
     */
    void stopMonitoring() override;

    /**
     * Show a notification to the user.
     * 
     * @param title The notification title
     * @param message The notification message
     */
    void showNotification(const std::string& title, const std::string& message) override;

    /**
     * Initialize the platform-specific implementation.
     * 
     * @return True if initialization was successful, false otherwise
     */
    bool initialize() override;

    /**
     * Set a callback for when text context changes.
     * 
     * @param callback The callback function
     */
    void setContextChangeCallback(std::function<void(const TextContext&)> callback) override;

    /**
     * Set a callback for when a hotkey is pressed.
     * 
     * @param callback The callback function
     */
    void setHotkeyCallback(std::function<void(int)> callback) override;

private:
    // Implementation details
    std::function<void(const TextContext&)> contextChangeCallback;
    std::function<void(int)> hotkeyCallback;
    bool isMonitoring;
    HWND hwnd;  // Window handle for message processing
    std::map<int, HotkeyConfig> registeredHotkeys;

    // Private helper methods
    HWND getActiveWindowHandle();
    std::string getActiveWindowTitle();
    std::string getActiveWindowClassName();
    bool injectKeystrokes(const std::string& text);
    void createMessageWindow();
    void destroyMessageWindow();
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
};

// Factory function implementation for Windows
std::unique_ptr<PlatformInterface> createPlatformImplementation() {
    return std::make_unique<WindowsPlatform>();
}

} // namespace windows
} // namespace autocomplete

#endif // WINDOWS_PLATFORM_H 