/*
    magine a car’s infotainment system that needs:

    A central logger (Singleton) so all modules (navigation, media, connectivity) share one logging instance.

    Different logging strategies (Strategy) — console for debugging, file for persistent logs, network for remote diagnostics.

    Observers (Observer) — subscribers like a monitoring dashboard, driver alert system, or OEM backend that react to log events.

    A Factory to create different log strategies dynamically based on configuration (e.g., “use network logging if connected”).

    Why This Matters in Infotainment:
    Singleton → one central logger across all modules (navigation, media, connectivity).

    Strategy → flexible logging outputs (console for dev, file for diagnostics, network for remote monitoring).

    Observer → dashboards and OEM backends react instantly to log events.

    Factory → runtime selection of logging strategy based on environment (connected vs offline).

    This is exactly the kind of multi‑pattern design you’d present in a technical lead interview: showing how patterns combine to solve real system problems.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

// -----------------------------
// Observer Pattern
// -----------------------------
class Subscriber {
public:
    virtual void update(const std::string& msg) = 0;
    virtual ~Subscriber() = default;
};

class DashboardSubscriber : public Subscriber {
    std::string name;
public:
    DashboardSubscriber(std::string n) : name(std::move(n)) {}
    void update(const std::string& msg) override {
        std::cout << "[Dashboard " << name << "] Alert: " << msg << "\n";
    }
};

// -----------------------------
// Strategy Pattern
// -----------------------------
class LogStrategy {
public:
    virtual void write(const std::string& msg) = 0;
    virtual ~LogStrategy() = default;
};

class ConsoleLogStrategy : public LogStrategy {
public:
    void write(const std::string& msg) override {
        std::cout << "[Console] " << msg << "\n";
    }
};

class FileLogStrategy : public LogStrategy {
    std::ofstream file;
public:
    FileLogStrategy(const std::string& filename) {
        file.open(filename, std::ios::app);
    }
    void write(const std::string& msg) override {
        file << "[File] " << msg << "\n";
    }
};

class NetworkLogStrategy : public LogStrategy {
public:
    void write(const std::string& msg) override {
        std::cout << "[Network] Sending log to server: " << msg << "\n";
    }
};

// -----------------------------
// Factory Pattern
// -----------------------------
class LogStrategyFactory {
public:
    static std::unique_ptr<LogStrategy> createStrategy(const std::string& type) {
        if (type == "console") return std::make_unique<ConsoleLogStrategy>();
        else if (type == "file") return std::make_unique<FileLogStrategy>("infotainment.log");
        else return std::make_unique<NetworkLogStrategy>();
    }
};

// -----------------------------
// Singleton Logger
// -----------------------------
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance; // Meyers' Singleton
        return instance;
    }

    void setStrategy(std::unique_ptr<LogStrategy> s) {
        strategy = std::move(s);
    }

    void attach(Subscriber* sub) {
        subscribers.push_back(sub);
    }

    void log(const std::string& msg) {
        if (strategy) strategy->write(msg);
        for (auto* sub : subscribers) {
            sub->update(msg);
        }
    }

private:
    Logger() { std::cout << "Logger initialized\n"; }
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::unique_ptr<LogStrategy> strategy;
    std::vector<Subscriber*> subscribers;
};

// -----------------------------
// Example Usage in Infotainment
// -----------------------------
int main() {
    Logger& logger = Logger::getInstance();

    // Choose strategy dynamically (Factory)
    logger.setStrategy(LogStrategyFactory::createStrategy("console"));

    // Attach observers (dashboard, monitoring system)
    DashboardSubscriber dash1("DriverDisplay");
    DashboardSubscriber dash2("OEMBackend");
    logger.attach(&dash1);
    logger.attach(&dash2);

    // Log events from infotainment modules
    logger.log("Navigation started");
    logger.log("Music playback: Hero song");

    // Switch strategy at runtime
    logger.setStrategy(LogStrategyFactory::createStrategy("file"));
    logger.log("Bluetooth connected");

    logger.setStrategy(LogStrategyFactory::createStrategy("network"));
    logger.log("Firmware update initiated");

    std::cout << "Infotainment logging demo complete.\n";
    return 0;
}
