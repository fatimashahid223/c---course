#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Patient {
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    Patient* next;
};

class LinkedQueue {
    Patient* head;
    Patient* last;

public:
    LinkedQueue() : head(nullptr), last(nullptr) {}

    Patient input();
    void insertAtEnd();
    void insertAtBeg();
    void getPatientOut();
    void listOfPatients();
    int search(int);

    char departmentName[50];
};

int LinkedQueue::search(int item) {
    if (head == nullptr)
        return false;
    else {
        Patient* p = head;

        while (p->next != nullptr && p->ID != item) {
            p = p->next;
        }

        return (p->ID == item);
    }
}

int readNumber() {
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

Patient LinkedQueue::input() {
    int flag = 0;
    Patient* p = new Patient();

    cout << "\n   Please enter data for patient\n";
    cout << "\n   First name     : ";
    getline(cin, p->firstname);
    cout << "   Last name      : ";
    getline(cin, p->lastname);

again:
    cout << "   Blood Group    : ";
    cin >> p->blood;

    if (strcmp(p->blood, "A+") == 0 || strcmp(p->blood, "a+") == 0 ||
        strcmp(p->blood, "A-") == 0 || strcmp(p->blood, "a-") == 0 ||
        strcmp(p->blood, "B+") == 0 || strcmp(p->blood, "b+") == 0 ||
        strcmp(p->blood, "B-") == 0 || strcmp(p->blood, "b-") == 0 ||
        strcmp(p->blood, "O+") == 0 || strcmp(p->blood, "o+") == 0 ||
        strcmp(p->blood, "O-") == 0 || strcmp(p->blood, "o-") == 0 ||
        strcmp(p->blood, "AB+") == 0 || strcmp(p->blood, "ab+") == 0 ||
        strcmp(p->blood, "AB-") == 0 || strcmp(p->blood, "ab-") == 0)
        flag = 1;

    if (flag == 0) {
        cout << "\n   Invalid Blood Group. Try Again.\n\n";
        goto again;
    }

    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    cout << "   Age            : ";
    cin >> p->age;
    cout << "   Mobile number  : ";
    cin >> p->ID;

    if (search(p->ID)) {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
    }

    return *p;
}

void output(Patient* p) {
    cout << "\n  ------------------------------------";
    cout << "\n   Patient data:\n";
    cout << "   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;
    cout << "\n  ------------------------------------";
}

void LinkedQueue::insertAtBeg() {
    Patient* p = new Patient();
    *p = input();

    if (p->ID == 0)
        return;

    if (head == nullptr) {
        head = p;
        last = p;
        p->next = nullptr;
    } else {
        p->next = head;
        head = p;
    }

    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void LinkedQueue::insertAtEnd() {
    Patient* p = new Patient();
    *p = input();

    if (p->ID == 0)
        return;

    if (head == nullptr) {
        head = p;
        last = p;
        p->next = nullptr;
    } else {
        p->next = nullptr;
        last->next = p;
        last = p;
    }

    system("cls");
    cout << "\n  ------------------------------------";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  ------------------------------------";
    cout << "\n  ----------PATIENT ADDED-----------";
    output(p);
}

void LinkedQueue::getPatientOut() {
    system("cls");

    if (head == nullptr) {
        cout << "\n  No Patient to operate";
    } else {
        Patient* p = head;
        head = head->next;
        cout << "\n  Patient to operate:";
        output(p);
    }
}

void LinkedQueue::listOfPatients() {
    if (head == nullptr) {
        cout << "\n  No patient";
    }

    system("cls");
    cout << "\n  ------------------------------------";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  ------------------------------------";
    Patient* p = head;

    while (p != nullptr) {
        cout << "\n   Patient data:\n";
        cout << "   First Name       : " << p->firstname;
        cout << "\n   Last Name        : " << p->lastname;
        cout << "\n   Gender           : " << p->gender;
        cout << "\n   Age              : " << p->age;
        cout << "\n   Blood Group      : " << p->blood;
        cout << "\n   Mobile Number    : " << p->ID;
        cout << "\n  ------------------------------------";
        p = p->next;
    }

    cout << "\n";
}

void departmentMenu(LinkedQueue* q) {
    int choice = 0;

    while (choice != 5) {
        system("cls");
        cout << "\n  ------------------------------------";
        cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  ------------------------------------";
        cout << "\n\n   " << q->departmentName << " DEPARTMENT\n\n";
        cout << "   1. Admit a patient\n";
        cout << "   2. Discharge a patient\n";
        cout << "   3. List of patients\n";
        cout << "   4. Search a patient\n";
        cout << "   5. Exit\n\n";
        cout << "   Please enter your choice : ";

        choice = readNumber();

        switch (choice) {
            case 1:
                q->insertAtEnd();
                break;
            case 2:
                q->getPatientOut();
                break;
            case 3:
                q->listOfPatients();
                break;
            case 4:
                int searchID;
                cout << "\n   Enter mobile number to search: ";
                searchID = readNumber();
                if (q->search(searchID))
                    cout << "\n   Found";
                else
                    cout << "\n   Not Found";
                break;
            case 5:
                break;
            default:
                cout << "\n   Invalid Choice.";
        }

        cout << "\n\n";
    }
}

int main() {
    LinkedQueue dept1;
    strcpy(dept1.departmentName, "ORTHOPEDIC");
    departmentMenu(&dept1);

    return 0;
}
