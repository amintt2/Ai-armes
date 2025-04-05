#ifndef AUTOCOMPLETE_CLOUD_SYNC_H
#define AUTOCOMPLETE_CLOUD_SYNC_H

#include <string>
#include <vector>
#include <memory>

namespace autocomplete {

/**
 * Authentication credentials for cloud services.
 */
struct AuthCredentials {
    std::string userId;      // User ID
    std::string apiKey;      // API key
    std::string supabaseUrl; // Supabase URL
};

/**
 * Result of authentication.
 */
struct AuthResult {
    bool success;            // Whether authentication was successful
    std::string message;     // Error message if authentication failed
    std::string token;       // Authentication token
};

/**
 * User context data to be synchronized with the cloud.
 */
struct UserContext {
    std::string userId;                  // User ID
    std::vector<std::string> contexts;   // List of context strings
    std::string appName;                 // Application name
    long timestamp;                      // Timestamp of the context
};

/**
 * User preferences to be synchronized with the cloud.
 */
struct UserPreferences {
    bool useCloud;                       // Whether to use cloud synchronization
    bool learnFromInput;                 // Whether to learn from user input
    std::string preferredMode;           // Preferred autocomplete mode
    std::vector<std::string> appSettings; // Application-specific settings
};

/**
 * Forward declarations
 */
class CloudSyncImpl;

/**
 * Interface for cloud synchronization.
 */
class CloudSync {
public:
    /**
     * Constructor.
     */
    CloudSync();

    /**
     * Destructor.
     */
    ~CloudSync();

    /**
     * Authenticate with the cloud service.
     * 
     * @param credentials The authentication credentials
     * @return The result of authentication
     */
    AuthResult authenticate(const AuthCredentials& credentials);

    /**
     * Push user context to the cloud.
     * 
     * @param context The user context to push
     * @return The result of synchronization
     */
    SyncResult pushContext(const UserContext& context);

    /**
     * Pull user context from the cloud.
     * 
     * @return The user context
     */
    UserContext pullContext();

    /**
     * Synchronize user preferences with the cloud.
     * 
     * @param preferences The user preferences to synchronize
     * @return The result of synchronization
     */
    SyncResult syncPreferences(const UserPreferences& preferences);

    /**
     * Check if cloud synchronization is available.
     * 
     * @return True if cloud synchronization is available, false otherwise
     */
    bool isCloudAvailable();

private:
    std::unique_ptr<CloudSyncImpl> impl; // Implementation details
};

} // namespace autocomplete

#endif // AUTOCOMPLETE_CLOUD_SYNC_H 