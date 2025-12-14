[![Language](https://img.shields.io/badge/language-C++-%2300599C.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Standard](https://img.shields.io/badge/std-C++17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
# Health Management System (HMS) 🏥

A robust, console-based Health Management System built using **C++**. This application simulates core hospital operations, including patient registration, doctor management, appointment scheduling, and automated billing. It utilizes Object-Oriented Programming (OOP) principles and file handling for data persistence.

## 🚀 Features

### 👨‍⚕️ Admin Module
* **Secure Login:** Password-protected access with a security question fallback.
* **Doctor Management:** Add, Update, Delete, and View doctor records.
* **Patient Management:** Manage patient records directly from the dashboard.
* **Record View:** View all saved bills and logs.

### 😷 Patient & Appointment Module
* **Registration:** Secure input validation for patient details.
* **Doctor Selection:** View available doctors, their specializations, and consultation fees.
* **Slot Booking:** Real-time availability check for appointment slots (e.g., 9:00 AM - 10:00 AM).
* **Medical Tests:** Option to add common medical tests (MRI, X-Ray, Blood Test, ECG) to the visit.

### 💰 Billing System
* **Automated Calculation:** Generates a final bill combining the Doctor's consultation fee and chosen medical tests.
* **Invoice Generation:** Displays a detailed invoice on the console and saves it to `bills.txt`.

### 📂 Data Persistence
* Uses file handling to store records permanently:
    * `patients.txt`
    * `doctors.txt`
    * `bills.txt`

## 🛠️ Technical Implementation

* **Language:** C++
* **Paradigms:** Object-Oriented Programming (OOP)
* **Key Concepts:**
    * **Inheritance:** `User` base class with `Doctor` and `Patient` derived classes.
    * **Encapsulation:** Private/Protected data members with public Getters/Setters.
    * **Exception Handling:** `try-catch` blocks to handle invalid data types (e.g., entering text for an ID).
    * **Input Validation:** Ensures names contain only alphabets and fees are positive numbers.
    * **File I/O:** Usage of `<fstream>` for reading and writing records.
    * **STL Containers:** Usage of `vector` for managing dynamic lists of doctors and schedule slots.

## 💻 How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/health-management-system.git](https://github.com/your-username/health-management-system.git)
    ```
2.  **Navigate to the directory:**
    ```bash
    cd health-management-system
    ```
3.  **Compile the source code:**
    ```bash
    g++ main.cpp -o hms
    ```
4.  **Run the application:**
    * On Windows: `hms.exe`
    * On Linux/Mac: `./hms`

## 📖 Usage Guide

1.  **Start the Application:** You will see the Main Menu.
2.  **Admin Access:**
    * Select option `3`.
    * Default Username: `Admin`
    * Default Password: `Admin123`
    * *Tip: If you forget the password, answer the security question!*
3.  **Book Appointment:**
    * Select option `1`.
    * Enter patient details.
    * Choose a doctor from the list.
    * Select a time slot.
    * Add medical tests if required.
    * The system will print your bill and save the data.

## 🔮 Future Improvements
* Implement full file synchronization for Update/Delete operations.
* Add a GUI using Qt or wxWidgets.
* Implement patient history tracking using unique IDs.

## 📜 License
This project is open-source and available for educational purposes.
