#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TodoManager {
    string filename;

    int nextID() {
        ifstream fin(filename);
        string line;
        int maxID = 0;
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            int id = stoi(line.substr(0, p1));
            if (id > maxID) maxID = id;
        }
        fin.close();
        return maxID + 1;
    }

public:
    TodoManager(const string& file) : filename(file) {}

    void addTask(const string& task) {
        int id = nextID();
        ofstream fout(filename, ios::app);
        fout << id << "," << task << ",false\n";
        fout.close();
    }

    void viewTasks() {
        ifstream fin(filename);
        string line;
        cout << "To-Do List:\n";
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            string id   = line.substr(0, p1);
            string desc = line.substr(p1 + 1, p2 - p1 - 1);
            string done = line.substr(p2 + 1);
            cout << id << ". " << desc << " [" << (done == "true" ? "Done" : "Pending") << "]\n";
        }
        fin.close();
    }

    void markDone(int taskID) {
        ifstream fin(filename);
        ofstream fout("temp.txt");
        string line;
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            string id   = line.substr(0, p1);
            string rest = line.substr(p1);
            if (stoi(id) == taskID) {
                size_t lastComma = rest.rfind(',');
                fout << id << rest.substr(0, lastComma) << ",true\n";
            } else {
                fout << line << "\n";
            }
        }
        fin.close();
        fout.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }
};

int main() {
    TodoManager todo("tasks.txt");

    todo.addTask("Write project report");
    todo.addTask("Review pull requests");
    todo.addTask("Prepare presentation slides");

    cout << "=== Before marking done ===\n";
    todo.viewTasks();

    todo.markDone(2);

    cout << "\n=== After marking task 2 done ===\n";
    todo.viewTasks();

    return 0;
}
