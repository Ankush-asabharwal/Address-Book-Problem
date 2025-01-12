#include<iostream>
#include<list>

using namespace std;

class Contacts {
public:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    int zip;
    long int phoneNumber;
    string email;

    Contacts(string firstName, string lastName, string address, string city, string state, int zip, long int phoneNumber, string email) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }

    Contacts() {}

    void display() {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Zip: " << zip << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void input() {
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter State: ";
        cin >> state;
        cout << "Enter ZIP Code: ";
        cin >> zip;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter Email: ";
        cin >> email;
    }
};

class AddressBook {
public:
    list<Contacts> contacts;

    void addContact(const Contacts& c) {
        contacts.push_back(c);
    }

    void display() {
        if (contacts.empty()) {
            cout << "No contacts available!" << endl;
            return;
        }
        for (list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++) {
            it->display();
            cout << endl;
        }
    }

    bool editContact(string name) {
        for (list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++) {
            if (it->firstName == name) {
                cout << "Contact Found!" << endl;
                it->display();
                cout << endl;
                cout << "Enter new details: ";
                it->input();
                cout << "Contact Updated!" << endl;
                return true;
            }
        }
        cout << "Contact not found!" << endl;
        return false;
    }

    void removeContact(string name) {
        for (list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++) {
            if (it->firstName == name) {
                contacts.erase(it);
                cout << "Contact removed successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }
};

int main() {
    AddressBook addressBook;
    char choice;

    do {
        cout << "Welcome to the Address Book!" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Remove Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Please choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
        case '1': {
            Contacts newContact;
            newContact.input();
            addressBook.addContact(newContact);
            cout << "Contact added successfully!" << endl;
            break;
        }
        case '2': {
            addressBook.display();
            break;
        }
        case '3': {
            string name;
            cout << "Enter the first name of the contact you want to edit: ";
            cin >> name;
            addressBook.editContact(name);
            break;
        }
        case '4': {
            string name;
            cout << "Enter the first name of the contact you want to remove: ";
            cin >> name;
            addressBook.removeContact(name);
            break;
        }
        case '5':
            cout << "Exiting Address Book" << endl;
            break;
        default:
            cout << "Invalid choice! Please choose between 1-5." << endl;
        }

        cout << endl;

    } while (choice != '5');

    return 0;
}
