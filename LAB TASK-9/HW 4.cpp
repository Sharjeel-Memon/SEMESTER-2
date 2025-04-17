#include <iostream>
#include <string>
using namespace std;

enum class StudentStatus { Undergraduate, Graduate, Doctoral };

class Student {
public:
    virtual double getTuition(StudentStatus status, int creditHours) const = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(StudentStatus status, int creditHours) const override {
        double rate = 0;
        switch (status) {
            case StudentStatus::Undergraduate: rate = 200; break;
            case StudentStatus::Graduate: rate = 300; break;
            case StudentStatus::Doctoral: rate = 400; break;
        }
        return rate * creditHours;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Machine Learning Applications");

    StudentStatus status = StudentStatus::Graduate;
    int creditHours = 12;

    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition for " << creditHours << " credit hours: $"
         << gs.getTuition(status, creditHours) << endl;

    return 0;
}