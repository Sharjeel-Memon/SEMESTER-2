#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Encryptor {
    string filename;

public:
    Encryptor(const string& file) : filename(file) {}

    string encrypt(const string& text) {
        string result = text;
        for (int i = 0; i < result.length(); ++i)
            result[i] += (i + 1);
        return result;
    }

    string decrypt(const string& text) {
        string result = text;
        for (int i = 0; i < result.length(); ++i)
            result[i] -= (i + 1);
        return result;
    }

    void writeEncrypted(const string& text) {
        ofstream fout(filename);
        fout << encrypt(text);
        fout.close();
    }

    string readEncrypted() {
        ifstream fin(filename);
        string line;
        getline(fin, line);
        fin.close();
        return line;
    }

    string readDecrypted() {
        return decrypt(readEncrypted());
    }
};

int main() {
    Encryptor enc("encrypted.txt");

    enc.writeEncrypted("Hello World");

    cout << "Encrypted (from file): " << enc.readEncrypted() << endl;
    cout << "Decrypted: " << enc.readDecrypted() << endl;

    return 0;
}
