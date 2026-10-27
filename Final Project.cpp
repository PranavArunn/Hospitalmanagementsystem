#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isemiratesidvalid(string id);
bool isUAEnumbervalid(string num);
int getDigit(const int number);
int sumOdddigits(const string cardnumber);
int sumEvendigits(const string cardnumber);

// ---------------- PATIENT CLASS ----------------
class Patient {
public:
    string name;
    int age;
    string phone_number;
    string emirates_id_number;
    string insurance;

    void getdetails(string n, int a, string phone, string eid) {
        name = n;
        age = a;
        phone_number = phone;
        emirates_id_number = eid;
    }

    void getdetails(string ins) {
        insurance = ins;
    }

    void display() {
        cout << "\n===========================================================================================\n";
        cout << "\nPatient Name: " << name;
        cout << "\n";
        cout << "\nAge: " << age;
        cout << "\n";
        cout << "\nPhone: " << phone_number;
        cout << "\n";
        cout << "\nEmirates ID: " << emirates_id_number;
        cout << "\n";
        cout << "\nInsurance: " << insurance;
        cout << "\n";
        cout << "\n===========================================================================================\n";
    }
};

// ---------------- PATIENT DETAILS ----------------
void patientdetails(Patient& p) {
    string name, phone, eid, insurance, choice;
    int age;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);
    cout << "\n";

    cout << "Enter age: ";
    cin >> age;
    cout << "\n";

    cout << "Enter phone: ";
    cin >> phone;
    cout << "\n";

    while (!isUAEnumbervalid(phone)) {
        cout << "Invalid UAE number ! Enter Again : ";
        cin >> phone;
    }

    cout << "Enter Emirates ID: ";
    cin >> eid;
    cout << "\n";

    while (!isemiratesidvalid(eid)) {
        cout << "Invalid emirates id ! Enter Again : ";
        cin >> eid;
    }

    p.getdetails(name, age, phone, eid);

    cout << "Do you have insurance (yes/no): ";
    cin >> choice;
    cout << "\n";

    if (choice == "yes" || choice == "Yes") {
        cout << "Enter insurance: ";
        cin >> insurance;
        p.getdetails(insurance);
    }
    else {
        p.getdetails("None");
    }

    p.display();
}

// ---------------- DOCTOR ----------------
class Doctor {
public:
    string doctor_name, appointment_time, choice;

    bool Askdetail() {
        cout << "Do you have appointment (yes/no): ";
        cin >> choice;
        cout << "\n";

        if (choice == "yes" || choice == "Yes") {
            cin.ignore();

            cout << "Enter doctor name: ";
            getline(cin, doctor_name);
            cout << "\n";

            cout << "Enter time: ";
            getline(cin, appointment_time);
            cout << "\n";

            cout << "\n===========================================================================================\n";
            cout << "\nDoctor: " << doctor_name;
            cout << "\nTime: " << appointment_time << "\n";
            cout << "\n===========================================================================================\n";

            return true;
        }

        cout << "Redirecting to booking...\n";
        return false;
    }
};

// ---------------- BOOKING ----------------
class Booking {
public:
    string name;
    int age;

    void getdetails() {
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);
        cout << "\n";

        cout << "Enter age: ";
        cin >> age;
        cout << "\n";
    }

    int suggestdoctor() {
        int choice;

        cout << "\n--- Doctors List ---\n";
        cout << "1. Dr. Sampath (Pediatrician)\n";
        cout << "2. Dr. Vidhya (General Practitioner)\n";
        cout << "3. Dr. Jason (General Surgeon)\n";
        cout << "4. Dr. Joseph (Neurologist)\n";
        cout << "5. Dr. Sandeep (Urologist)\n";
        cout << "6. Dr. Rohana (Dentist)\n";
        cout << "7. Dr. Sandipan (Ophthalmologist)\n";
        cout << "8. Dr. Jayashree (Gynecologist)\n";

        cout << "\n";

        cout << "Select doctor: ";
        cin >> choice;
        cout << "\n";

        string date, time;

        cin.ignore();

        cout << "Enter date: ";
        getline(cin, date);
        cout << "\n";

        cout << "Enter time: ";
        getline(cin, time);
        cout << "\n";

        cout << "\n=======================================================================================\n";
        cout << "\nBooking Confirmed\n";
        cout << "Date: " << date << "\n";
        cout << "Time: " << time << "\n";
        cout << "\n=======================================================================================\n";

        return choice - 1;
    }
};

// ---------------- VALIDATION ----------------
bool isemiratesidvalid(string id) {

    string clean = "";

    int i;

    for (i = 0; i < id.length(); i++) {

        char c = id[i];

        if (c != '-') {
            clean += c;
        }
    }

    if (clean.length() != 15 || clean.substr(0, 3) != "784") {
        return false;
    }

    for (i = 0; i < clean.length(); i++) {

        char c = clean[i];

        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

bool isUAEnumbervalid(string num) {

    string clean = "";

    int i;

    for (i = 0; i < num.length(); i++) {

        char c = num[i];

        if (isdigit(c)) {
            clean += c;
        }
    }

    if ((clean.length() == 10 && clean.substr(0, 2) == "05") ||
        (clean.length() == 12 && clean.substr(0, 3) == "971")) {

        return true;
    }

    return false;
}

// ---------------- REPORT ----------------
class Report_Generation {

private:
    string patient_name;
    string doctor_name;
    string diagnosis;
    string prescription;

public:

    void get_report() {

        cin.ignore();

        cout << "\n============================== ENTER REPORT DETAILS ===================================\n";

        cout << "Patient Name: ";
        getline(cin, patient_name);

        cout << "Doctor Name: ";
        getline(cin, doctor_name);

        cout << "Diagnosis: ";
        getline(cin, diagnosis);

        cout << "Prescription: ";
        getline(cin, prescription);

        cout << "\n=======================================================================================\n";
    }

    void display_report() {

        cout << "\n================================= MEDICAL REPORT ======================================\n";

        cout << "                              Patient: " << patient_name << "\n";
        cout << "                              Doctor: " << doctor_name << "\n";
        cout << "                              Diagnosis: " << diagnosis << "\n";
        cout << "                              Prescription: " << prescription << "\n";

        cout << "\n=======================================================================================\n";
    }
};

// ---------------- BILLING ----------------
class Billing {

private:
    string doctor_names[8] = {
        "Dr. Sampath",
        "Dr. Vidhya",
        "Dr. Jason",
        "Dr. Joseph",
        "Dr. Sandeep",
        "Dr. Rohan",
        "Dr. Sandipan",
        "Dr. Jayashree"
    };

    int doctor_fees[8] = {
        200,
        250,
        300,
        180,
        220,
        260,
        240,
        210
    };

public:

    void generateBill(int index) {

        if (index < 0 || index >= 8) {
            cout << "Invalid doctor!\n";
            return;
        }

        int* ptr = &doctor_fees[index];

        cout << "\n===================================== PAYMENT =========================================\n";

        cout << "Doctor : " << doctor_names[index] << "\n";
        cout << "Fee : " << *ptr << " AED\n\n";

        string cvv;
        string cardname;
        int amt;
        string pay;
        string cardnumber;
        int result = 0;

        cout << "Do you want to pay by cash or card? ";
        cin >> pay;
        cout << "\n";

        if (pay == "cash" || pay == "Cash") {

            cout << "Deposit the amount : ";
            cin >> amt;
            cout << "\n";

            cout << "The Amount has been transferred!";
        }

        else if (pay == "card" || pay == "Card") {

            do {

                cout << "Enter a credit Card Number #: ";
                cin >> cardnumber;
                cout << "\n";

                result = sumEvendigits(cardnumber) + sumOdddigits(cardnumber);

                if (result % 10 != 0) {
                    cout << "Your Card Number :: " << cardnumber << " is NOT valid\n";
                }

            } while (result % 10 != 0);

            cout << "Your Card Number :: " << cardnumber << " is valid\n";

            cout << "\n";

            cout << "Enter the Card Holder's name : ";

            cin.ignore();

            getline(cin, cardname);

            cout << "\n";

            cout << "Enter CVV : ";
            cin >> cvv;
            cout << "\n";

            while (cvv.length() != 3) {
                cout << "Invalid CVV. Enter again : ";
                cin >> cvv;
            }

            cout << "The Amount has been transferred!";
        }

        else {
            cout << "Enter a valid option";
        }

        cout << "\n=======================================================================================\n";
    }
};

// ---------------- MAIN ----------------
int main() {

    Patient p;
    Doctor d;
    Booking b;
    Billing bill;
    Report_Generation report;

    int choice;
    int doctorIndex = -1;

    do {

        cout << "\n==================================== APTECH CLINIC ====================================\n";

        cout << "                                   1. Patient Details\n";
        cout << "                                   2. Appointment / Booking\n";
        cout << "                                   3. Generate Report\n";
        cout << "                                   4. Billing\n";
        cout << "                                   5. Exit\n";

        cout << "\n=======================================================================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            patientdetails(p);
            break;

        case 2:

            if (!d.Askdetail()) {
                b.getdetails();
                doctorIndex = b.suggestdoctor();
            }

            break;

        case 3:
            report.get_report();
            report.display_report();
            break;

        case 4:

            if (doctorIndex != -1) {
                bill.generateBill(doctorIndex);
            }
            else {
                cout << "No booking found!\n";
            }

            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}

// ---------------- CARD VALIDATION ----------------
int getDigit(const int number) {

    return number % 10 + (number / 10 % 10);
}

int sumOdddigits(const string cardnumber) {

    int sum = 0;

    int i;

    for (i = cardnumber.size() - 1; i >= 0; i -= 2) {

        sum += cardnumber[i] - '0';
    }

    return sum;
}

int sumEvendigits(const string cardnumber) {

    int sum = 0;

    int i;

    for (i = cardnumber.size() - 2; i >= 0; i -= 2) {

        sum += getDigit((cardnumber[i] - '0') * 2);
    }

    return sum;
}
