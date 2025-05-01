#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger {
    string baseFile;
    int fileIndex;

    long getFileSize(const string& file) {
        ifstream in(file, ios::binary | ios::ate);
        return in.tellg();
    }

public:
    Logger(const string& file) : baseFile(file), fileIndex(1) {}

    void log(const string& message) {
        if (getFileSize(baseFile) >= 1024 * 1024) {
            string newName = "log" + to_string(fileIndex++) + ".txt";
            rename(baseFile.c_str(), newName.c_str());
        }
        ofstream fout(baseFile, ios::app);
        fout << message << endl;
    }
};

int main() {
    Logger logger("log.txt");

    logger.log("Application started");
    logger.log("Loading configuration");
    logger.log("Connecting to database");
    logger.log("Database connection established");
    logger.log("Processing user request #1");
    logger.log("Processing user request #2");
    logger.log("Processing user request #3");
    logger.log("An error occurred: invalid input");
    logger.log("Error handled, continuing");
    logger.log("Application shutting down");

    cout << "10 log entries have been written to log.txt (rotating if >1MB)." << endl;
    return 0;
}
