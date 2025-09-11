#include <iostream>
#include <cstring>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    char manufacturer[50];
    char model[50];
    int year;

    static int totalVehicles;

public:
    Vehicle() {
        vehicleID = 0;
        strcpy(manufacturer, "");
        strcpy(model, "");
        year = 0;
    }

    Vehicle(int id, const char* manu, const char* mod, int y) {
        vehicleID = id;
        strcpy(manufacturer, manu);
        strcpy(model, mod);
        year = y;
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    void inputVehicle() {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cin.ignore();
        cout << "Enter Manufacturer: ";
        cin.getline(manufacturer, 50);
        cout << "Enter Model: ";
        cin.getline(model, 50);
        cout << "Enter Year: ";
        cin >> year;
        cin.ignore();
        totalVehicles++;
    }

    virtual void display() {
        cout << "\nVehicle ID: " << vehicleID
             << "\nManufacturer: " << manufacturer
             << "\nModel: " << model
             << "\nYear: " << year << endl;
    }

    int getID() {
        return vehicleID;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }
};

int Vehicle::totalVehicles = 0;


// Single Inheritance =================
class Car : public Vehicle {
protected:
    char fuelType[20];

public:
    Car() : Vehicle() {
        strcpy(fuelType, "");
    }

    void inputVehicle() {
        Vehicle::inputVehicle();
        cout << "Enter Fuel Type: ";
        cin.getline(fuelType, 20);
    }

    void display() {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


//Multilevel Inheritance =================
class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
    }

    void inputVehicle() {
        Car::inputVehicle();
        cout << "Enter Battery Capacity (kWh): ";
        cin >> batteryCapacity;
        cin.ignore();
    }

    void display() {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
    }
};

class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar() : ElectricCar() {
        topSpeed = 0;
    }

    void inputVehicle() {
        ElectricCar::inputVehicle();
        cout << "Enter Top Speed (km/h): ";
        cin >> topSpeed;
        cin.ignore();
    }

    void display() {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h\n";
    }
};


//Multiple Inheritance =================
class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() {
        flightRange = 0;
    }

    void inputAircraft() {
        cout << "Enter Flight Range (km): ";
        cin >> flightRange;
        cin.ignore();
    }

    void displayAircraft() {
        cout << "Flight Range: " << flightRange << " km\n";
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    void inputVehicle() {
        Car::inputVehicle();
        inputAircraft();
    }

    void display() {
        Car::display();
        displayAircraft();
    }
};


//Hierarchical Inheritance =================
class Sedan : public Car {
public:
    void display() {
        cout << "--- Sedan ---\n";
        Car::display();
    }
};

class SUV : public Car {
public:
    void display() {
        cout << "--- SUV ---\n";
        Car::display();
    }
};


//Vehicle Registry ============
class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int total;

public:
    VehicleRegistry() {
        total = 0;
    }

    void addVehicle() {
        int choice;
        cout << "\nSelect Vehicle Type:\n";
        cout << "1. Car\n2. Electric Car\n3. Sports Car\n4. Flying Car\n5. Sedan\n6. SUV\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        Vehicle* v = nullptr;
        switch (choice) {
        case 1: v = new Car(); break;
        case 2: v = new ElectricCar(); break;
        case 3: v = new SportsCar(); break;
        case 4: v = new FlyingCar(); break;
        case 5: v = new Sedan(); break;
        case 6: v = new SUV(); break;
        default: cout << "Invalid choice!\n"; return;
        }

        v->inputVehicle();
        vehicles[total++] = v;
    }

    void displayAll() {
        if (total == 0) {
            cout << "No vehicles in registry!\n";
            return;
        }
        for (int i = 0; i < total; i++) {
            cout << "\n=== Vehicle " << i + 1 << " ===\n";
            vehicles[i]->display();
        }
    }

    void searchVehicle(int id) {
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (vehicles[i]->getID() == id) {
                cout << "\nVehicle Found:\n";
                vehicles[i]->display();
                found = true;
                break;
            }
        }
        if (!found) cout << "Vehicle with ID " << id << " not found!\n";
    }
};


int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- Vehicle Registry System ---\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registry.addVehicle();
            break;
        case 2:
            registry.displayAll();
            break;
        case 3: {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchVehicle(id);
            break;
        }
        case 4:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
