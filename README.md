# Hotel Management System

A comprehensive C++ console application for managing hotel operations including guest registration, room management, reservations, and employee records.

## Features

- **Guest Management**: Register and manage guest information with passport details
- **Room Management**: Add and track different room types with pricing
- **Reservation System**: Create and manage bookings with check-in/check-out dates
- **Employee Management**: Maintain employee records with position and salary details
- **Data Persistence**: All data is saved to text files for permanent storage

## System Components

### Classes

- **Person**: Base class for guest and employee information
- **Guest**: Manages guest details including passport numbers
- **Room**: Handles room information, types, rates, and availability
- **Reservation**: Links guests with rooms and manages booking details
- **Employee**: Stores employee information and payroll data
- **HotelManager**: Main controller class that manages all operations

## Room Types

- Standard
- Deluxe
- Suite

## Data Storage

The system stores data in the following text files:
- `guests.txt` - Guest information
- `rooms.txt` - Room details and availability
- `reservations.txt` - Booking records
- `employees.txt` - Employee records

## How to Compile and Run

### Compilation

```bash
g++ main.cpp -o main
```

### Run

```bash
./main
```

On Windows:
```bash
main.exe
```

## Menu Options

1. Add New Guest
2. Add New Room
3. Add New Employee
4. Make Reservation
5. Display All Guests
6. Display All Rooms
7. Display All Reservations
8. Exit

## Usage Example

1. Start by adding rooms to the system
2. Register guests with their passport information
3. Create reservations by linking guests to available rooms
4. Manage employee records as needed
5. View all records through the display options

## Requirements

- C++ compiler (g++, clang++, or MSVC)
- C++11 or later

## Object-Oriented Concepts Used

- Inheritance (Guest and Employee inherit from Person)
- Encapsulation (Private data members with public getters/setters)
- Polymorphism (Virtual displayInfo() method)
- File I/O for data persistence
- Memory management with dynamic allocation

## Future Enhancements

- Database integration for better data management
- Check-in/check-out functionality
- Bill generation and payment processing
- Room service management
- Advanced search and filtering options
- User authentication system
