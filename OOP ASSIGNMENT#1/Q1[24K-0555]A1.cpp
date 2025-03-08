#include<iostream>
#include<string>
using namespace std;

class Skill {
public:
    int skillID;
    string skillName, description;
    
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}
    void showSkillDetails() {
        cout << "Skill ID: " << skillID << "\nSkill Name: " << skillName << "\nDescription: " << description << endl;
    }
    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
};

class Sport {
public:
    int sportID;
    string name, description;
    Skill** requiredSkills;
    int skillCount;
    
    Sport(int id, string n, string desc) : sportID(id), name(n), description(desc), skillCount(0) {
        requiredSkills = new Skill*[10]; // Assuming max 10 skills per sport
    }
    ~Sport() {
        delete[] requiredSkills;
    }
    void addSkill(Skill* s) {
        requiredSkills[skillCount++] = s;
    }
    void removeSkill(int skillID) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i]->skillID == skillID) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                break;
            }
        }
    }
};

class Student;

class Mentor {
public:
    int mentorID;
    string mentorName;
    string* sportsExpertise;
    int expertiseCount;
    int maxLearners;
    Student** assignedLearners;
    int learnerCount;
    
    Mentor(string name, int id, int maxL) : mentorName(name), mentorID(id), maxLearners(maxL), learnerCount(0), expertiseCount(0) {
        assignedLearners = new Student*[maxLearners];
        sportsExpertise = new string[10];
    }
    ~Mentor() {
        delete[] assignedLearners;
        delete[] sportsExpertise;
    }
    bool assignLearner(Student* s);
    void removeLearner(Student* s);
    void viewLearners();
    void provideGuidance();
    void display();
};

class Student {
public:
    string studentName;
    int studentID;
    string* sportsInterests;
    int interestCount;
    Mentor* assignedMentor;
    
    Student(string name, int id) : studentName(name), studentID(id), assignedMentor(nullptr), interestCount(0) {
        sportsInterests = new string[10];
    }
    ~Student() {
        delete[] sportsInterests;
    }
    void registerForMentorship(Mentor* mentor) {
        if (mentor->assignLearner(this)) {
            assignedMentor = mentor;
            cout << "Mentor " << mentor->mentorName << " assigned to " << studentName << endl;
        } else {
            cout << "Mentor has reached maximum capacity." << endl;
        }
    }
    void updateSportsInterest(string sport) {
        sportsInterests[interestCount++] = sport;
    }
    void viewMentorDetails() {
        if (assignedMentor) assignedMentor->display();
        else cout << "No mentor assigned." << endl;
    }
    void display();
};

bool Mentor::assignLearner(Student* s) {
    if (learnerCount < maxLearners) {
        assignedLearners[learnerCount++] = s;
        return true;
    }
    return false;
}

void Mentor::removeLearner(Student* s) {
    for (int i = 0; i < learnerCount; i++) {
        if (assignedLearners[i] == s) {
            for (int j = i; j < learnerCount - 1; j++) {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            learnerCount--;
            break;
        }
    }
}

void Mentor::viewLearners() {
    cout << "Learners under mentor " << mentorName << ":\n";
    for (int i = 0; i < learnerCount; i++) {
        cout << assignedLearners[i]->studentName << " (ID: " << assignedLearners[i]->studentID << ")\n";
    }
}

void Mentor::provideGuidance() {
    cout << "Providing guidance to assigned learners." << endl;
}

void Mentor::display() {
    cout << "Mentor Name: " << mentorName << "\nMentor ID: " << mentorID << "\nMax Learners: " << maxLearners << endl;
    viewLearners();
}

void Student::display() {
    cout << "Student Name: " << studentName << "\nStudent ID: " << studentID << "\nSports Interests: ";
    for (int i = 0; i < interestCount; i++) cout << sportsInterests[i] << " ";
    cout << endl;
    viewMentorDetails();
}

int main() {
    int choice;
    Student student("John Doe", 101);
    Mentor mentor("Dr. Smith", 202, 3);
    Sport sport(1, "Tennis", "A sport played with rackets and a ball.");
    Skill skill(1, "Backhand Stroke", "A fundamental tennis stroke.");
    sport.addSkill(&skill);
    
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Register (Student)\n";
        cout << "2. Mentor Details\n";
        cout << "3. Student Details\n";
        cout << "4. Add Sport (Student)\n";
        cout << "5. Add Learner (Mentor)\n";
        cout << "6. Remove Learner (Mentor)\n";
        cout << "7. Provide Guidance (Mentor)\n";
        cout << "8. Add Skill (Sport)\n";
        cout << "9. Exit\n";
        cin >> choice;
        
        if (choice == 9) break;
        
        switch (choice) {
            case 1:
                student.registerForMentorship(&mentor);
                break;
            case 2:
                mentor.display();
                break;
            case 3:
                student.display();
                break;
            case 4:
                {
                    string sport;
                    cout << "Enter sport: ";
                    cin >> sport;
                    student.updateSportsInterest(sport);
                }
                break;
            case 5:
                mentor.assignLearner(&student);
                break;
            case 6:
                mentor.removeLearner(&student);
                break;
            case 7:
                mentor.provideGuidance();
                break;
            case 8:
                sport.addSkill(&skill);
                cout << "Skill added to sport." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
