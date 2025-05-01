#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class EmployeeManager {
    string filename;

public:
    EmployeeManager(const string& file) : filename(file) {}

    void filterManagers(const string& output) {
        ifstream fin(filename);
        ofstream fout(output);
        string line;
        while (getline(fin, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            string designation = line.substr(pos2 + 1, pos3 - pos2 - 1);
            int years = stoi(line.substr(pos3 + 1));
            if (designation == "Manager" && years >= 2)
                fout << line << endl;
        }
        fin.close();
        fout.close();
    }

    void overwriteFromFiltered(const string& filteredFile) {
        ifstream fin(filteredFile);
        ofstream fout(filename);
        string line;
        while (getline(fin, line))
            fout << line << endl;
        fin.close();
        fout.close();
    }

    void rewriteWithIncrement(const string& filteredFile) {
        ifstream fin(filteredFile);
        ofstream fout(filename);
        string line;
        int id = 1;
        while (getline(fin, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string desig = line.substr(pos2 + 1, pos3 - pos2 - 1);
            int years = stoi(line.substr(pos3 + 1)) + 1;
            fout << id++ << "," << name << "," << desig << "," << years << endl;
        }
        fin.close();
        fout.close();
    }
};

int main() {
	
	ofstream fout("employees.txt");
fout << "1,Ali,Manager,2\n";
fout << "2,Ahmed,Technician,1\n";
fout << "3,Ayesha,Manager,4\n";
fout << "4,Sara,Clerk,3\n";
fout.close();


    EmployeeManager emp("employees.txt");

    cout << "Filtering Managers with >=2 years of service...\n";
    emp.filterManagers("filtered.txt");

    cout << "Overwriting original file with filtered data...\n";
    emp.overwriteFromFiltered("filtered.txt");

    cout << "Rewriting original file with incremented IDs and years...\n";
    emp.rewriteWithIncrement("filtered.txt");


    ifstream fin("employees.txt");
    string line;
    cout << "\nUpdated Employee Data:\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}