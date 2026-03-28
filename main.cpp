#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

// Base class for Person
class Person {
private:
    string name;
    string contactNumber;
    string email;

protected:
    string id;

public:
    Person(string name, string contactNumber, string email) 
        : name(name), contactNumber(contactNumber), email(email) {}
    
    string getName() const { return name; }
    void setName(string name) { this->name = name; }
    
    string getContactNumber() const { return contactNumber; }
    void setContactNumber(string contactNumber) { this->contactNumber = contactNumber; }
    
    string getEmail() const { return email; }
    void setEmail(string email) { this->email = email; }
    
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
    }
};

// Guest class inheriting from Person
class Guest : public Person {
private:
    string passportNumber;
    
public:
    Guest(string name, string contactNumber, string email, string passportNumber)
        : Person(name, contactNumber, email), passportNumber(passportNumber) {
        id = "G" + passportNumber;
    }
    
    string getPassportNumber() const { return passportNumber; }
    
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Passport Number: " << passportNumber << endl;
    }
    
    void saveToFile() const {
        ofstream file("guests.txt", ios::app);
        file << getName() << "," << getContactNumber() << "," << getEmail() << "," << passportNumber << endl;
        file.close();
    }
};

// Room class
class Room {
private:
    int roomNumber;
    string type;
    double rate;
    bool isOccupied;

public:
    Room(int roomNumber, string type, double rate)
        : roomNumber(roomNumber), type(type), rate(rate), isOccupied(false) {}
    
    int getRoomNumber() const { return roomNumber; }
    string getType() const { return type; }
    double getRate() const { return rate; }
    bool getIsOccupied() const { return isOccupied; }
    void setOccupied(bool status) { isOccupied = status; }
    
    void displayInfo() const {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Type: " << type << endl;
        cout << "Rate: $" << rate << endl;
        cout << "Status: " << (isOccupied ? "Occupied" : "Available") << endl;
    }
    
    void saveToFile() const {
        ofstream file("rooms.txt", ios::app);
        file << roomNumber << "," << type << "," << rate << "," << isOccupied << endl;
        file.close();
    }
};

// Reservation class
class Reservation {
private:
    string reservationId;
    Guest* guest;
    Room* room;
    string checkInDate;
    string checkOutDate;
    double totalAmount;

public:
    Reservation(string reservationId, Guest* guest, Room* room, 
                string checkInDate, string checkOutDate, double totalAmount)
        : reservationId(reservationId), guest(guest), room(room), 
          checkInDate(checkInDate), checkOutDate(checkOutDate), totalAmount(totalAmount) {
        room->setOccupied(true);
    }
    
    void displayInfo() const {
        cout << "Reservation ID: " << reservationId << endl;
        cout << "Guest Details:" << endl;
        guest->displayInfo();
        cout << "Room Details:" << endl;
        room->displayInfo();
        cout << "Check-in Date: " << checkInDate << endl;
        cout << "Check-out Date: " << checkOutDate << endl;
        cout << "Total Amount: $" << totalAmount << endl;
    }
    
    void saveToFile() const {
        ofstream file("reservations.txt", ios::app);
        file << reservationId << "," << guest->getName() << "," << room->getRoomNumber() 
             << "," << checkInDate << "," << checkOutDate << "," << totalAmount << endl;
        file.close();
    }
};

// Employee class inheriting from Person
class Employee : public Person {
private:
    string position;
    double salary;

public:
    Employee(string name, string contactNumber, string email, 
             string position, double salary)
        : Person(name, contactNumber, email), position(position), salary(salary) {
        id = "E" + contactNumber;
    }
    
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
    
    void saveToFile() const {
        ofstream file("employees.txt", ios::app);
        file << getName() << "," << getContactNumber() << "," << getEmail() 
             << "," << position << "," << salary << endl;
        file.close();
    }
};

// HotelManager class to manage the entire system
class HotelManager {
private:
    vector<Guest*> guests;
    vector<Room*> rooms;
    vector<Reservation*> reservations;
    vector<Employee*> employees;

public:
    ~HotelManager() {
        for(auto guest : guests) delete guest;
        for(auto room : rooms) delete room;
        for(auto reservation : reservations) delete reservation;
        for(auto employee : employees) delete employee;
    }
    
    void addGuest(Guest* guest) {
        guests.push_back(guest);
        guest->saveToFile();
    }
    
    void addRoom(Room* room) {
        rooms.push_back(room);
        room->saveToFile();
    }
    
    void addReservation(Reservation* reservation) {
        reservations.push_back(reservation);
        reservation->saveToFile();
    }
    
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        employee->saveToFile();
    }
    
    void displayAllGuests() const {
        cout << "\n=== All Guests ===" << endl;
        for(const auto& guest : guests) {
            guest->displayInfo();
            cout << "---------------" << endl;
        }
    }
    
    void displayAllRooms() const {
        cout << "\n=== All Rooms ===" << endl;
        for(const auto& room : rooms) {
            room->displayInfo();
            cout << "---------------" << endl;
        }
    }
    
    void displayAllReservations() const {
        cout << "\n=== All Reservations ===" << endl;
        for(const auto& reservation : reservations) {
            reservation->displayInfo();
            cout << "---------------" << endl;
        }
    }
    
    void loadDataFromFiles() {
        // Implementation for loading data from files would go here
        // For simplicity, we're not implementing the full file loading logic
    }

    void displayMenu() {
        cout << "\n=== Hotel Management System ===" << endl;
        cout << "1. Add New Guest" << endl;
        cout << "2. Add New Room" << endl;
        cout << "3. Add New Employee" << endl;
        cout << "4. Make Reservation" << endl;
        cout << "5. Display All Guests" << endl;
        cout << "6. Display All Rooms" << endl;
        cout << "7. Display All Reservations" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void addNewGuest() {
        string name, contact, email, passport;
        
        cout << "\nEnter Guest Details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Contact Number: ";
        getline(cin, contact);
        
        cout << "Email: ";
        getline(cin, email);
        
        cout << "Passport Number: ";
        getline(cin, passport);
        
        Guest* newGuest = new Guest(name, contact, email, passport);
        addGuest(newGuest);
        cout << "\nGuest added successfully!" << endl;
    }

    void addNewRoom() {
        int roomNum;
        string type;
        double rate;
        
        cout << "\nEnter Room Details:" << endl;
        cout << "Room Number: ";
        cin >> roomNum;
        
        cout << "Room Type (Standard/Deluxe/Suite): ";
        cin.ignore();
        getline(cin, type);
        
        cout << "Rate per night: ";
        cin >> rate;
        
        Room* newRoom = new Room(roomNum, type, rate);
        addRoom(newRoom);
        cout << "\nRoom added successfully!" << endl;
    }

    void addNewEmployee() {
        string name, contact, email, position;
        double salary;
        
        cout << "\nEnter Employee Details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Contact Number: ";
        getline(cin, contact);
        
        cout << "Email: ";
        getline(cin, email);
        
        cout << "Position: ";
        getline(cin, position);
        
        cout << "Salary: ";
        cin >> salary;
        
        Employee* newEmployee = new Employee(name, contact, email, position, salary);
        addEmployee(newEmployee);
        cout << "\nEmployee added successfully!" << endl;
    }

    void makeNewReservation() {
        string guestPassport, checkIn, checkOut;
        int roomNum;
        
        cout << "\nEnter Reservation Details:" << endl;
        cout << "Guest Passport Number: ";
        cin.ignore();
        getline(cin, guestPassport);
        
        Guest* guest = nullptr;
        for(auto g : guests) {
            if(g->getPassportNumber() == guestPassport) {
                guest = g;
                break;
            }
        }
        
        if(!guest) {
            cout << "Guest not found! Please add guest first." << endl;
            return;
        }
        
        cout << "Room Number: ";
        cin >> roomNum;
        
        Room* room = nullptr;
        for(auto r : rooms) {
            if(r->getRoomNumber() == roomNum) {
                if(r->getIsOccupied()) {
                    cout << "Room is already occupied!" << endl;
                    return;
                }
                room = r;
                break;
            }
        }
        
        if(!room) {
            cout << "Room not found!" << endl;
            return;
        }
        
        cout << "Check-in Date (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, checkIn);
        
        cout << "Check-out Date (YYYY-MM-DD): ";
        getline(cin, checkOut);
        
        string reservationId = "R" + to_string(reservations.size() + 1);
        double totalAmount = room->getRate() * 5; // Assuming 5 days stay
        
        Reservation* newReservation = new Reservation(reservationId, guest, room, checkIn, checkOut, totalAmount);
        addReservation(newReservation);
        cout << "\nReservation made successfully!" << endl;
    }
};

int main() {
    HotelManager hotel;
    hotel.loadDataFromFiles();
    
    int choice;
    do {
        hotel.displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                hotel.addNewGuest();
                break;
            case 2:
                hotel.addNewRoom();
                break;
            case 3:
                hotel.addNewEmployee();
                break;
            case 4:
                hotel.makeNewReservation();
                break;
            case 5:
                hotel.displayAllGuests();
                break;
            case 6:
                hotel.displayAllRooms();
                break;
            case 7:
                hotel.displayAllReservations();
                break;
            case 8:
                cout << "\nThank you for using Hotel Management System!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while(choice != 8);
    
    return 0;
}