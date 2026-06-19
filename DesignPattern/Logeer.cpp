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

class LogSubscriber : public Subscriber {
    std::string name;
public:
    LogSubscriber(std::string n) : name(std::move(n)) {}
    void update(const std::string& msg) override {
        std::cout << "[Subscriber " << name << "] received log: " << msg << "\n";
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
// Example Usage
// -----------------------------
int main() {
    // Get singleton logger
    Logger& logger = Logger::getInstance();

    // Set logging strategy (console)
    logger.setStrategy(std::make_unique<ConsoleLogStrategy>());

    // Attach subscribers
    LogSubscriber sub1("Rajesh");
    LogSubscriber sub2("MonitoringSystem");
    logger.attach(&sub1);
    logger.attach(&sub2);

    // Log messages
    logger.log("Application started");
    logger.log("User logged in");

    // Switch strategy to file logging
    logger.setStrategy(std::make_unique<FileLogStrategy>("app.log"));
    logger.log("This log goes to file and subscribers");

    std::cout << "Logging system demo complete.\n";
    return 0;
}