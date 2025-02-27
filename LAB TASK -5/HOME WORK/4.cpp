#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        Sleep(5000);
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        Sleep(5000);
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice(string process) {
        if (process == "blend") {
            blender.blendJuice();
        } else if (process == "grind") {
            grinder.grindJuice();
        } else {
            cout << "Invalid process! Use 'blend' or 'grind'." << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Invalid input! Provide 'blend' or 'grind' as an argument." << endl;
        return 1;
    }

    JuiceMaker juicer;
    string process;
    
    for (int i = 1; i < argc; i++) {
        process = argv[i];
        if (process == "exit") {
            break;
        }
        juicer.makeJuice(process);
    }
    
    return 0;
}
