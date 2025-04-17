#include <iostream>
#include <string>
using namespace std;

const int MAX_LOGS = 1000;

class Logger {
private:
    string logs[MAX_LOGS];
    int logCount = 0;

    string formatLog(const string& module, const string& severity, const string& message) const {
        return "[" + severity + "] [" + module + "] " + message;
    }

    void storeLog(const string& formattedLog) {
        if (logCount < MAX_LOGS) {
            logs[logCount++] = formattedLog;
        } else {
            for (int i = 1; i < MAX_LOGS; i++) {
                logs[i - 1] = logs[i];
            }
            logs[MAX_LOGS - 1] = formattedLog;
        }
    }

public:
    void log(const string& module, const string& severity, const string& message) {
        string formatted = formatLog(module, severity, message);
        storeLog(formatted);
    }

    friend class LogAuditor;
};

class LogAuditor {
private:
    bool authenticated;

public:
    LogAuditor(bool auth) {
        authenticated = auth;
    }

    void retrieveLogs(const Logger& logger) const {
        if (!authenticated) {
            cout << "Access Denied\n";
            return;
        }

        cout << "\n---- Logs ----\n";
        for (int i = 0; i < logger.logCount; i++) {
            cout << logger.logs[i] << endl;
        }
        cout << "--------------\n";
    }
};

void networkModule(Logger& logger) {
    logger.log("Network", "INFO", "Ping success");
    logger.log("Network", "WARN", "Slow connection");
}

void databaseModule(Logger& logger) {
    logger.log("Database", "INFO", "DB connected");
    logger.log("Database", "ERROR", "DB timeout");
}

void authModule(Logger& logger) {
    logger.log("Auth", "INFO", "Login ok");
    logger.log("Auth", "ERROR", "Login failed");
}

int main() {
    Logger logger;

    networkModule(logger);
    databaseModule(logger);
    authModule(logger);

    LogAuditor auditor1(false);
    auditor1.retrieveLogs(logger);

    LogAuditor auditor2(true);
    auditor2.retrieveLogs(logger);

    return 0;
}
