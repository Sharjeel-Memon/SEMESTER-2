#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    string name;
    string patientID;
    string dateOfBirth;
    string medicalHistory;
    string currentTreatment;
    string billingInfo;

public:
    PatientRecord(const string& n, const string& id, const string& dob) {
        name = n;
        patientID = id;
        dateOfBirth = dob;
        medicalHistory = "None";
        currentTreatment = "None";
        billingInfo = "Not available";
    }

    string getPublicData() const {
        return "Name: " + name + ", ID: " + patientID + ", DOB: " + dateOfBirth;
    }

private:
    string getMedicalData() const {
        return "History: " + medicalHistory + ", Treatment: " + currentTreatment;
    }

    void updateMedicalHistory(const string& history) {
        medicalHistory = history;
    }

    void updateTreatment(const string& treatment) {
        currentTreatment = treatment;
    }

    void addBillingDetails(const string& bill) {
        billingInfo = bill;
    }

    string getBillingDetails() const {
        return billingInfo;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void viewMedicalInfo(const PatientRecord& record) {
        cout << "[Doctor View] " << record.getMedicalData() << endl;
    }

    void updateMedicalInfo(PatientRecord& record, const string& history, const string& treatment) {
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
    }
};

class Billing {
public:
    void addBill(PatientRecord& record, const string& bill) {
        record.addBillingDetails(bill);
    }

    void viewBill(const PatientRecord& record) {
        cout << "[Billing View] " << record.getBillingDetails() << endl;
    }
};

class Receptionist {
public:
    void viewBasicInfo(const PatientRecord& record) {
        cout << "[Receptionist View] " << record.getPublicData() << endl;
    }

};

int main() {
    PatientRecord patient("Ali Khan", "P001", "1990-05-20");

    Doctor doctor;
    doctor.viewMedicalInfo(patient);
    doctor.updateMedicalInfo(patient, "Allergic to penicillin", "Antihistamines");

    Billing billing;
    billing.addBill(patient, "Total: Rs. 5000");
    billing.viewBill(patient);

    Receptionist receptionist;
    receptionist.viewBasicInfo(patient);

    return 0;
}
