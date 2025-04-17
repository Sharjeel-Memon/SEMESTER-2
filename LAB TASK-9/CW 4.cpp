#include <iostream>
#include <string>
using namespace std;

class Passenger;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int totalSeats;
    int bookedSeats;

public:
    Flight(const string& fn, const string& dep, const string& arr, int capacity) {
        flightNumber = fn;
        departure = dep;
        arrival = arr;
        totalSeats = capacity;
        bookedSeats = 0;
    }

    string getFlightInfo() const {
        return "Flight " + flightNumber + " from " + departure + " to " + arrival;
    }

    bool bookSeat(const Passenger& p);
    bool cancelSeat(const Passenger& p);
    bool upgradeSeat(const Passenger& p);

private:
    bool hasAvailableSeats() const {
        return bookedSeats < totalSeats;
    }

    void increaseBooking() {
        bookedSeats++;
    }

    void decreaseBooking() {
        if (bookedSeats > 0) {
            bookedSeats--;
        }
    }

    friend class Passenger;
};

class Passenger {
private:
    string name;
    string ID;
    bool hasBooking;

public:
    Passenger(const string& n, const string& id) {
        name = n;
        ID = id;
        hasBooking = false;
    }

    void requestBooking(Flight& f) {
        if (hasBooking) {
            cout << name << " already has a booking.\n";
        } else if (f.bookSeat(*this)) {
            hasBooking = true;
            cout << name << " successfully booked " << f.getFlightInfo() << endl;
        } else {
            cout << "No available seats for " << name << " on " << f.getFlightInfo() << endl;
        }
    }

    void requestCancellation(Flight& f) {
        if (!hasBooking) {
            cout << name << " has no booking to cancel.\n";
        } else if (f.cancelSeat(*this)) {
            hasBooking = false;
            cout << name << " canceled their booking on " << f.getFlightInfo() << endl;
        } else {
            cout << "Cancellation failed for " << name << endl;
        }
    }

    void requestUpgrade(Flight& f) {
        if (!hasBooking) {
            cout << name << " has no booking to upgrade.\n";
        } else if (f.upgradeSeat(*this)) {
            cout << name << " upgraded their seat on " << f.getFlightInfo() << endl;
        } else {
            cout << "Upgrade failed for " << name << endl;
        }
    }
};

bool Flight::bookSeat(const Passenger& p) {
    if (hasAvailableSeats()) {
        increaseBooking();
        return true;
    }
    return false;
}

bool Flight::cancelSeat(const Passenger& p) {
    decreaseBooking();
    return true;
}

bool Flight::upgradeSeat(const Passenger& p) {
    return true;
}

int main() {
    Flight f1("PK101", "Karachi", "Lahore", 2);
    Flight f2("PK202", "Islamabad", "Quetta", 1);

    Passenger p1("Ayesha", "P001");
    Passenger p2("Bilal", "P002");
    Passenger p3("Fatima", "P003");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); 

    p1.requestUpgrade(f1); 
    p1.requestCancellation(f1);
    p1.requestBooking(f2); 

    return 0;
}
