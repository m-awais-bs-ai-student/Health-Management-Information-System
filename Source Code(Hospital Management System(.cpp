#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<limits>
#include<stdexcept>
#include<cctype>
using namespace std;

class User 
{
    protected:
        string name;
        int id;
        string gender;

    public:
        User(string n = "", int i = 0, string g = "") : name(n), id(i), gender(g) {}
        
        void setName(string n) { name = n; }
        void setId(int i) { id = i; }
        void setGender(string g) { gender = g; }
        string getName() const { return name; }
        int getId() const { return id; }
        string getGender() const { return gender; }  
};



class Patient : public User 
{
    protected:
        string symptoms;
        bool isvalid = true;

    public:
        Patient(string n = "", int i = 0, string g = "", string s = "") 
            : User(n, i, g), symptoms(s) {}

        void Set_Patient_Data() 
        {
            while (true)
            {
                try
                {
                    cout << "Enter Patient Name: ";
                    cin.ignore();
                    getline(cin, name);

                    for(char a : name)
                    {
                        if (!isalpha(a) && a != ' ')
                        {
                            throw invalid_argument("Invalid name! Enter letters only.");
                        }
                    }

                    break;
                }
                catch(const exception& e)
                {
                    cout << e.what() << endl;
                }
            }

            while (true)
            {
                try
                {
                    cout << "Enter Appointment Id: ";
                    cin >> id;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000 , '\n');
                        throw invalid_argument("Enter valid integer value.");
                    }

                    break;
                }
                catch(const exception& e)
                {
                    cout << e.what() << endl;
                }
            }

            do 
            {
                cout << "Enter Patient's Gender: ";
                cin >> gender;

                if (gender != "Male" && gender != "male" && gender != "Female" && gender != "female") 
                {
                    cout << "Invalid input! Please enter Male or Female.\n";
                }

            } while (gender != "Male" && gender != "male" && gender != "Female" && gender != "female");

            cin.ignore();

            while (true)
            {
                try
                {
                    cout << "Enter Symptoms: ";
                    getline(cin, symptoms);

                    for(char b : symptoms)
                    {
                        if (!isalpha(b) && b != ' ')
                        {
                            throw invalid_argument("Invalid symptoms! Enter letters only.");
                        }
                    }

                    break;
                }
                catch(const exception& e)
                {
                    cout << e.what() << endl;
                }
            }
        }
        
        void saveToFile() const 
        {
            ofstream out("patients.txt", ios::app);
            out << "Name: " << name << "\nID: " << id << "\nGender: " << gender
            << "\nSymptoms: " << symptoms << "\n-----------------------------\n";
            out.close();
        }
        
        static void displaySavedPatients() 
        {
            ifstream in("patients.txt");
            string line;
            cout << "\n***** Saved Patient Records *****\n";
            while (getline(in, line)) {
                cout << line << endl;
            }
            in.close();
        }
        
        string getSymptoms() const { return symptoms; }
};

class Doctor : public User 
{
    protected:
        string specialization;
        vector<string> schedule;
        vector<bool> slotAvailable;
        bool isvalid = true;
        double consultationFee;

    public:
        Doctor(string n = "", int i = 0, string g = "", string sp = "", double fee = 0.0)
            : User(n, i, g), specialization(sp), consultationFee(fee) 
        {
            schedule.push_back("9:00 AM - 10:00 AM");
            schedule.push_back("10:00 AM - 11:00 AM");
            schedule.push_back("11:00 AM - 12:00 PM");

            slotAvailable = {true, true, true};
        }

        void Set_Doctor_Data() 
        {
            while (true)
            {
                try
                {
                    cout << "Enter Doctor Name: ";
                    cin.ignore();
                    getline(cin, name);

                    for (char c : name)
                    {
                        if (!isalpha(c) && c != ' ')
                        {
                            throw invalid_argument("Invalid name! Enter letters only.");
                        }
                    }

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
            }

            while (true)
            {
                try
                {
                    cout << "Enter Doctor's ID: ";
                    cin >> id;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw invalid_argument("Enter valid integer value.");
                    }

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
            }

            do 
            {
                cout << "Enter Doctor's Gender: ";
                cin >> gender;

                if (gender != "Male" && gender != "male" && gender != "Female" && gender != "female") 
                {
                    cout << "Invalid input! Please enter Male or Female.\n";
                }

            } while (gender != "Male" && gender != "male" && gender != "Female" && gender != "female");

            cin.ignore();

            while (true)
            {
                try
                {
                    cout << "Enter Specialization: ";
                    getline(cin, specialization);

                    for (char d : specialization)
                    {
                        if (!isalpha(d) && d != ' ')
                        {
                            throw invalid_argument("Invalid specialization! Enter letters only.");
                        }
                    }

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
            }

            while(true) {
                try {
                    cout << "Enter Consultation Fee: ";
                    cin >> consultationFee;
                    if(cin.fail() || consultationFee < 0) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw invalid_argument("Invalid fee! Enter positive number only.");
                    }
                    break;
                } catch(const exception& e) {
                    cout << e.what() << endl;
                }
            }
        }

        void displayAvailableSlots() const 
        {
            cout << "Name: " << name << "\nID: " << id << "\nGender: " << gender 
                 << "\nSpecialization: " << specialization 
                 << "\nConsultation Fee: $" << consultationFee << endl;
            cout << "Available Slots:\n";
            for (size_t i = 0; i < schedule.size(); i++) 
            {
                cout << i + 1 << ". " << schedule[i] << " - "  <<
                (slotAvailable[i] ? "Available" : "Booked") << endl;
            }
        }

        bool bookAppointment(int slotIndex) 
        {
            if (slotIndex >= 0 && slotIndex < schedule.size() && slotAvailable[slotIndex]) 
            {
                slotAvailable[slotIndex] = false;
                return true;
            }
            return false;
        }
        
        void saveToFile() const 
        {
            ofstream out("doctors.txt", ios::app);
            out << "Name: " << name << "\nID: " << id << "\nGender: " << gender
            << "\nSpecialization: " << specialization << "\nFee: $" << consultationFee << "\n-----------------------------\n";
            out.close();
        }
        
        static void displaySavedDoctors() 
        {
            ifstream in("doctors.txt");
            string line;
            cout << "\n***** Saved Doctor Records *****\n";
            while (getline(in, line)) 
            {
                cout << line << endl;
            }
            in.close();
        }
        
        string getSpecialization() const { return specialization; }
        double getConsultationFee() const { return consultationFee; }
};

class MedicalTest 
{
    public:
        string testName;
        double testFee;
        
        MedicalTest(string name = "", double fee = 0.0) 
            : testName(name), testFee(fee) {}
            
        static vector<MedicalTest> commonTests() 
        {
            return 
			{
                MedicalTest("Blood Test", 500),
                MedicalTest("X-Ray", 1200),
                MedicalTest("MRI", 5000),
                MedicalTest("ECG", 800)
            };
        }
};

class Billing {
    private:
        Patient patient;
        Doctor doctor;
        vector<MedicalTest> tests;
        double totalFee;
        
    public:
        Billing(const Patient& p, const Doctor& d) 
            : patient(p), doctor(d), totalFee(d.getConsultationFee()) {}
            
        void addTest(const MedicalTest& test) 
		{
            tests.push_back(test);
            totalFee += test.testFee;
        }
        
        void generateBill() const {
            cout << "\n********** HOSPITAL BILL **********\n";
            cout << "Patient: " << patient.getName() << " (ID: " << patient.getId() << ")\n";
            cout << "Doctor: " << doctor.getName() << " - " << doctor.getSpecialization() << "\n";
            cout << "Consultation Fee: $" << doctor.getConsultationFee() << "\n";
            
            if(!tests.empty()) {
                cout << "\nTests Conducted:\n";
                for(const auto& test : tests) {
                    cout << "- " << test.testName << ": $" << test.testFee << "\n";
                }
            }
            
            cout << "\nTOTAL AMOUNT DUE: $" << totalFee << "\n";
            cout << "***********************************\n";
        }
        
        void saveBillToFile() const {
            ofstream out("bills.txt", ios::app);
            out << "Patient: " << patient.getName() << " (ID: " << patient.getId() << ")\n";
            out << "Doctor: " << doctor.getName() << "\n";
            out << "Total Amount: $" << totalFee << "\n";
            out << "-----------------------------\n";
            out.close();
        }
        
        static void displaySavedBills() 
		{
            ifstream in("bills.txt");
            string line;
            cout << "\n***** Saved Bill Records *****\n";
            while(getline(in, line)) {
                cout << line << endl;
            }
            in.close();
        }
};

class Admin 
{
    private:
        string username;
        string password;
        string inputUsername, inputPassword, ISA;
        const string securityAnswer = "One Hundred And Eleven";

    public:
        vector<Doctor> doctors;
        vector<Patient> patients;

        Admin(string un = "Admin", string p = "Admin123") : username(un), password(p) {}

        void displayDoctors() const 
        {
            if (doctors.empty()) 
            {
                cout << "No Doctor Available" << endl;
            } 
            else 
            {
                for (const auto& doctor : doctors)
                {
                    doctor.displayAvailableSlots();
                }
            }
        }

        void Set_Admin_Credentials() 
        {
            do 
            {
                cout << "Enter your username and password:\nUsername: ";
                cin >> inputUsername;
                cout << "Password: ";
                cin >> inputPassword;

                if (inputUsername != username || inputPassword != password)
                {
                    cout << "Wrong credentials. Security question: How many beds in the hospital?\n";
                    cin.ignore();
                    getline(cin, ISA);
                    if (ISA == securityAnswer) 
                    {
                        cout << "Correct answer.\n";
                        break;
                    } 
                    else 
                    {
                        cout << "Wrong answer, try again.\n";
                    }
                }
            } while (inputUsername != username && inputPassword != password && ISA != securityAnswer);

            if((inputUsername == username && inputPassword == password) || ISA == securityAnswer)
            {
                int choice;
                do
                {
                    cout << "\n1. Add Doctor Record\n2. Update Doctor Record\n3. Delete Doctor Record\n"
                         << "4. Add Patients Record\n5. Update patients Record\n6. Remove Patiants Records\n"
                         << "7. Display Patiants Record\n8. Display Doctors Record\n9. Display Bills Record\n"
                         << "10. Exit Admin Panel\nEnter choice: ";
                    cin >> choice;
                    
                    if (choice < 1 || choice > 10) 
                    {
                        cout << "Please enter a valid choice!\n";
                    }
                } while(choice < 1 || choice > 10);

                switch (choice) 
                {
                    case 1:
                        {
                            Doctor newDoctor;
                            newDoctor.Set_Doctor_Data();
                            cout << "Doctor Added Successfully."<<endl;
                            doctors.push_back(newDoctor);
                            newDoctor.saveToFile();
                            break;
                        }
                    case 2:
                        {
                            int index;
                            cout << "Enter Doctor Number (1 to " << doctors.size() << "): ";
                            cin >> index;
                            if (index >= 1 && index <= doctors.size()) 
                            {
                                doctors[index - 1].Set_Doctor_Data();
                            } 
                            else 
                            {
                                cout << "Invalid Choice.\n";
                            }
                            break;
                        }
                    case 3:
                        {
                            int index;
                            cout << "Enter Doctor Number (1 to " << doctors.size() << "): ";
                            cin >> index;
                            if (index >= 1 && index <= doctors.size()) 
                            {
                                doctors.erase(doctors.begin() + (index - 1));
                            } 
                            else 
                            {
                                cout << "Invalid Choice.\n";
                            }
                            break;
                        }
                    case 4:
                        {
                            Patient newPatient;
                            newPatient.Set_Patient_Data();
                            cout << "Patient added successfully.";
                            patients.push_back(newPatient);
                            newPatient.saveToFile();
                            break;
                        }
                    case 5:
                        {
                            int index;
                            cout << "Enter Patient Number (1 to " << patients.size() << "): ";
                            cin >> index;
                            if (index >= 1 && index <= patients.size()) 
                            {
                                patients[index - 1].Set_Patient_Data();
                            } 
                            else 
                            {
                                cout << "Invalid Choice.\n";
                            }
                            break;
                        }
                    case 6:
                        {
                            int index;
                            cout << "Enter Patient Number (1 to " << patients.size() << "): ";
                            cin >> index;
                            if (index >= 1 && index <= patients.size()) 
                            {
                                patients.erase(patients.begin() + (index - 1));
                            } 
                            else 
                            {
                                cout << "Invalid Choice.\n";
                            }
                            break;
                        }
                    case 7:
                        {
                            Patient::displaySavedPatients();
                            break;
                        }
                    case 8:
                        {
                            Doctor::displaySavedDoctors();
                            break;
                        }
                    case 9:
                        {
                            Billing::displaySavedBills();
                            break;
                        }
                    case 10:
                        {
                            cout << "Exiting admin panel...\n";
                            break;
                        }
                    default:
                        cout << "Invalid Choice.\n";
                }
            }
        }
};

class HospitalSystem 
{
    private:
        Admin admin;
        
    public:
        void run() 
        {
            int role;
            do
            {
                cout << "\n********** Main Menu **********\n";
                cout << "1. Book An Appointment\n2. Display Available Doctors\n3. Admin\n4. Exit\n";

                do 
                {
                    cout << "Enter Your Choice (1-4): ";
                    cin >> role;
                    if (role < 1 || role > 4) 
                    {
                        cout << "Please enter a valid choice!\n";
                    }
                } while (role < 1 || role > 4);

                switch (role) 
                {
                    case 1:
                        bookAppointment();
                        break;
                    case 2:
                        cout << "********** Available Doctors **********\n";
                        admin.displayDoctors();
                        break;
                    case 3:
                        cout << "********** Admin Dashboard **********\n";
                        admin.Set_Admin_Credentials();
                        break;
                    case 4:
                        cout << "Exiting the system...\n";
                        break;
                }
            } while(role != 4);
        }
        
    private:
        void bookAppointment() 
        {
            cout << "********** Patient Dashboard **********\n";
            Patient patient;
            patient.Set_Patient_Data();
            patient.saveToFile();

            if (!admin.doctors.empty()) 
            {
                cout << "\nSelect a doctor:\n";
                for (size_t i = 0; i < admin.doctors.size(); i++) 
                {
                    cout << i + 1 << ". " << admin.doctors[i].getName() 
                         << " (" << admin.doctors[i].getSpecialization() 
                         << ", Fee: $" << admin.doctors[i].getConsultationFee() << ")\n";
                }
        
                int docChoice;
                cout << "Enter doctor number: ";
                cin >> docChoice;

                if (docChoice >= 1 && docChoice <= admin.doctors.size()) 
                {
                    Doctor& selectedDoctor = admin.doctors[docChoice - 1];
                    selectedDoctor.displayAvailableSlots();

                    int slotChoice;
                    cout << "Enter slot number to book: ";
                    cin >> slotChoice;

                    if (selectedDoctor.bookAppointment(slotChoice - 1)) 
                    {
                        Billing bill(patient, selectedDoctor);
                        
                        char addTest;
                        vector<MedicalTest> commonTests = MedicalTest::commonTests();
                        
                        do {
                            cout << "\nAvailable Tests:\n";
                            for(size_t i = 0; i < commonTests.size(); i++) 
							{
                                cout << i+1 << ". " << commonTests[i].testName 
                                     << " ($" << commonTests[i].testFee << ")\n";
                            }
                            
                            cout << "Add a test? (Y/N): ";
                            cin >> addTest;
                            
                            if(toupper(addTest) == 'Y') 
							{
                                int testChoice;
                                cout << "Enter test number: ";
                                cin >> testChoice;
                                
                                if(testChoice >= 1 && testChoice <= commonTests.size()) {
                                    bill.addTest(commonTests[testChoice-1]);
                                    cout << commonTests[testChoice-1].testName << " added.\n";
                                } else {
                                    cout << "Invalid test selection.\n";
                                }
                            }
                        } while(toupper(addTest) == 'Y');
                        
                        bill.generateBill();
                        bill.saveBillToFile();
                        
                        cout << "\nAppointment and billing completed successfully!\n";
                    } 
                    else 
                    {
                        cout << "Slot unavailable or invalid selection.\n";
                    }
                } 
                else 
                {
                    cout << "Invalid doctor selection.\n";
                }
            } 
            else 
            {
                cout << "System Error.\nNo Doctor Available."<<endl;
            }
        }
};

int main() 
{
    HospitalSystem hospital;
    hospital.run();
    return 0;
}