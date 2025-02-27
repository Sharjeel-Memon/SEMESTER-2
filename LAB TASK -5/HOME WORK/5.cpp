#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    int* engine_horsepower;
    int* seating_capacity;
    int* no_of_speakers;

    Car(int hp, int seats, int speakers) {
        engine_horsepower = new int(hp);
        seating_capacity = new int(seats);
        no_of_speakers = new int(speakers);
    }

    ~Car() {
        delete engine_horsepower;
        delete seating_capacity;
        delete no_of_speakers;
    }

    void displayCarInfo() const {
        printf("Horsepower: %d HP\n", *engine_horsepower);
        printf("Seating Capacity: %d seats\n", *seating_capacity);
        printf("Speakers: %d\n", *no_of_speakers);
    }

    void updateSpecs(int hp, int seats, int speakers) const {
        *engine_horsepower = hp;
        *seating_capacity = seats;
        *no_of_speakers = speakers;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 7) {
        printf("Invalid number of arguments!\n");
        return 1;
    }

    int hp = stoi(argv[1]);
    int seats = stoi(argv[2]);
    int speakers = stoi(argv[3]);

    int new_hp = stoi(argv[4]);
    int new_seats = stoi(argv[5]);
    int new_speakers = stoi(argv[6]);

    Car myCar(hp, seats, speakers);
    printf("Initial Car Details:\n");
    myCar.displayCarInfo();
    
    printf("\nUpdating Car Specs...\n");
    myCar.updateSpecs(new_hp, new_seats, new_speakers);
    myCar.displayCarInfo();

    return 0;
}
