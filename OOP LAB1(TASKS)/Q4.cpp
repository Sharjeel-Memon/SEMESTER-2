#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    double weightinkg = 0;

    //for Command-line argument mode
    if (argc >= 2) {
        weightinkg = stod(argv[1]);
    }
    //for Interactive input mode
    else {
        cout << "Enter your Weight in Kg: ";
        cin >> weightinkg;
    }

    //Validating weight
    if (weightinkg <= 0) {
        printf("Please input a valid positive weight!\n");
        return 1;
    }

    double ConversionFactor = 2.20462;
    double weightinpound = weightinkg * ConversionFactor;

    //Output upto 2 decimal places
    printf("The weight %.2f kg is equivalent to %.2f lbs.\n", weightinkg, weightinpound);

    return 0;
}