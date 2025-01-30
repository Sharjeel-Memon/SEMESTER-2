#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    // Variables
    string movieName;
    double adultTicketPrice, childTicketPrice;
    int numAdultTicketsSold, numChildTicketsSold;
    double donationPercentage;

    if (argc == 7) {
        // Command-line argument mode
        movieName = argv[1]; 
        adultTicketPrice = atof(argv[2]);
        childTicketPrice = atof(argv[3]);
        numAdultTicketsSold = atoi(argv[4]);
        numChildTicketsSold = atoi(argv[5]);
        donationPercentage = atof(argv[6]);
    } else if (argc > 7) {
        movieName = argv[1];
        for (int i = 2; i < argc - 5; ++i) {
            movieName += " " + string(argv[i]);
        }
        adultTicketPrice = atof(argv[argc - 5]);
        childTicketPrice = atof(argv[argc - 4]);
        numAdultTicketsSold = atoi(argv[argc - 3]);
        numChildTicketsSold = atoi(argv[argc - 2]);
        donationPercentage = atof(argv[argc - 1]);
    } else {
        // Interactive input mode
        cout << "Enter Movie Name: ";
        getline(cin, movieName);
        cout << "Enter Adult Ticket Price: ";
        cin >> adultTicketPrice;
        cout << "Enter Child Ticket Price: ";
        cin >> childTicketPrice;
        cout << "Enter Number of Adult Tickets Sold: ";
        cin >> numAdultTicketsSold;
        cout << "Enter Number of Child Tickets Sold: ";
        cin >> numChildTicketsSold;
        cout << "Enter Percentage of Gross Amount to Donate: ";
        cin >> donationPercentage;
    }

    // Calculations
    int totalTicketsSold = numAdultTicketsSold + numChildTicketsSold;
    double grossAmount = (adultTicketPrice * numAdultTicketsSold) + (childTicketPrice * numChildTicketsSold);
    double amountDonated = (grossAmount * donationPercentage) / 100;
    double netSale = grossAmount - amountDonated;

    // Output
    cout <<endl<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << left << setw(30) << "Movie Name:" << setw(30) << movieName << endl;
    cout << left << setw(30) << "Number of Tickets Sold:" << setw(20) << totalTicketsSold << endl;
    cout << left << setw(30) << "Gross Amount:" << "$" << right << setw(15) << fixed << setprecision(2) << grossAmount << endl;
    cout << left << setw(30) << "Percentage of Gross Amount Donated:" << right << setw(15) << fixed << setprecision(2) << donationPercentage << "%" << endl;
    cout << left << setw(30) << "Amount Donated:" << "$" << right << setw(15) << fixed << setprecision(2) << amountDonated << endl;
    cout << left << setw(30) << "Net Sale:" << "$" << right << setw(15) << fixed << setprecision(2) << netSale << endl;

    return 0;
}