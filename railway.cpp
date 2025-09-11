#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);

        trainCount++;
    }

    void displayTrainDetails() {
        cout << "\nTrain Number: " << trainNumber
             << "\nTrain Name: " << trainName
             << "\nSource: " << source
             << "\nDestination: " << destination
             << "\nTrain Time: " << trainTime << "\n";
    }

    int getTrainNumber() {
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;


class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train storage full!\n";
        }
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "No train records available!\n";
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            cout << "\nTrain " << i + 1 << " details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found!\n";
        }
    }
};


int main() {
    RailwaySystem rs;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            rs.addTrain();
            break;
        case 2:
            rs.displayAllTrains();
            break;
        case 3: {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            rs.searchTrainByNumber(num);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
