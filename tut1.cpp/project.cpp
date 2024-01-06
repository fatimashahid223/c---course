#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    patient *next;
};

class linkedqueue
{
    patient *head, *last;

public:
    linkedqueue() //constructor
    {
        head = NULL;
        last = NULL;
    }
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};

int linkedqueue::search(int item)
{
    if (head == NULL)
        return false;
    else
    {
        int flag = 0;
        patient *p = new patient();
        p = head;

        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
}

int readnumber()
{
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

patient linkedqueue::input()
{
    int flag = 0;
    patient *p = new patient();
    cout << "\n   Please enter data for the patient\n";
    cout << "\n   First name     : ";
    getline(cin, p->firstname);
    cout << "   Last name      : ";
    getline(cin, p->lastname);

again:
    cout << "   Blood Group    : ";
    cin >> p->blood;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0)
    {
        cout << "\n   Invalid Blood Group. Try Again..\n\n";
        goto again;
    }
    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    cout << "   Age            : ";
    cin >> p->age;
    cout << "   Mobile number  : ";
    cin >> p->ID;

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation canceled.";
    }
    return *p;
}

void output(patient *p)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient data:\n";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;
    cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}

void linkedqueue::insertatbeg()
{
    patient *p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void linkedqueue::insertatend()
{
    patient *p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n  ----------PATIENT ADDED-----------";
    output(p);
}

void linkedqueue::getpatientout()
{
    system("cls");
    if (head == NULL)
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient *p = new patient();
        p = head;
        head = head->next;
        cout << "\n  Patient to operate:";
        output(p);
    }
}

void linkedqueue::listofpatients()
{
    if (head == NULL)
    {
        cout << "\n  No patient in the hospital.\n";
    }
    else
    {
        int i = 1;
        patient *p = new patient();
        p = head;
        while (p != NULL)
        {
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n   Serial no          : " << i;
            cout << "\n   First Name         : " << p->firstname;
            cout << "\n   Last Name          : " << p->lastname;
            cout << "\n   Gender             : " << p->gender;
            cout << "\n   Age                : " << p->age;
            cout << "\n   Blood Group        : " << p->blood;
            cout << "\n   Mobile Number      : " << p->ID;
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            p = p->next;
            i++;
        }
    }
}

int main()
{
    linkedqueue l;
    int choise, t;
    do
    {
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout << "\n   1. Admit a patient";
        cout << "\n   2. Discharge a patient";
        cout << "\n   3. Show patient list";
        cout << "\n   4. Exit";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n   Enter your choice: ";
        choise = readnumber();
        system("cls");
        switch (choise)
        {
        case 1:
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
            l.insertatend();
            break;
        case 2:
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
            l.getpatientout();
            break;
        case 3:
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
            l.listofpatients();
            break;
        case 4:
            exit(0);
        default:
            cout << "\n  Invalid choice. Please try again.\n";
        }

        cout << "\n\n  Do you want to continue (1/0)?: ";
        t = readnumber();
    } while (t == 1);
    return 0;
}
