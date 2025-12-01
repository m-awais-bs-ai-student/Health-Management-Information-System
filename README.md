# Health-Management-Information-System
# Overview:
This is a console-based Health Management System written in C++. It simulates the workflow of a hospital, facilitating interactions between patients, doctors, and administrators. The system relies heavily on Object-Oriented Programming (OOP) principles.

# Key Components & Logic:

# Inheritance Hierarchy:
->User (Base Class): Encapsulates common attributes like name, id, and gender.
->Patient & Doctor (Derived Classes): Inherit from User. Patient adds symptoms; Doctor adds specialization, consultation fees, and a scheduling system (appointment slots).

# Data Persistence (File Handling):
->The program uses <fstream> to store data permanently.
->patients.txt: Stores patient registration details.
->doctors.txt: Stores doctor profiles and fees.
->bills.txt: Stores generated invoices.

Note: The file handling is primarily "Append" based. While the Admin class allows deleting/updating from the runtime vector, these changes might not reflect in the text files immediately without overwriting the whole file (a potential area for future optimization).

# Exception Handling & Validation:

->The code is robust against invalid inputs. It uses try-catch blocks within while(true) loops to ensure:
->Names contain only letters.
->IDs and Fees are valid integers/doubles.
->Gender is strictly "Male" or "Female".

# Business Logic:

->Admin Panel: Protected by a hardcoded credential set (Admin/Admin123) and a security question fallback. It allows full management of doctor/patient records.
->Booking System: A patient can view a list of doctors, select one, and book a specific time slot (9-10, 10-11, etc.).
->Billing System: This is a highlight of the code. It calculates the Total Bill = Doctor's Consultation Fee + Selected Medical Tests (e.g., X-Ray, MRI).
