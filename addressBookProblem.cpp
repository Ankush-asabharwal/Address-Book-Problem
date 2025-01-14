#include <iostream>
#include <list>
#include <map>
#include <string>

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

public:
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
                cout << "Enter new details for the contact:\n";
                it->input();
                cout << "Contact Updated!" << endl;
                return true;
            }
        }
        cout << "Contact not found!" << endl;
        return false;
    }

    bool removeContact(string name) {
        for (list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++) {
            if (it->firstName == name) {
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }
};

class Dictionary {
public:
    map<string, AddressBook> addressBooks;

    void addAddressBook(string name) {
        if (addressBooks.find(name) != addressBooks.end()) {
            cout << "The name for the address book is already occupied! Select another name." << endl;
            return;
        }
        addressBooks[name] = AddressBook();
        cout << "Address book '" << name << "' created successfully!" << endl;
    }

    AddressBook* getAddressBook(string name) {
        if (addressBooks.find(name) != addressBooks.end()) {
            return &addressBooks[name];
        }
        cout << "Address book not found!" << endl;
        return nullptr;
    }

    void listAddressBooks() {
        if (addressBooks.empty()) {
            cout << "No address books available!" << endl;
            return;
        }
        cout << "Available Address Books:" << endl;
        for (auto& pair : addressBooks) {
            cout << "- " << pair.first << endl;
        }
    }
};

int main() {
    Dictionary dict;
    char choice;
    string bookName;
    string name;

    do {
        cout << "\nWelcome to the Address Book Manager\n";
        cout << "Options:\n";
        cout << "1. Create a new address book\n";
        cout << "2. Select an address book\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            cout << "Enter a name for the new address book: ";
            cin >> bookName;
            dict.addAddressBook(bookName);
            break;
        }
        case '2': {
            dict.listAddressBooks();
            cout << "Enter the name of the address book to use: ";
            cin >> bookName;
            AddressBook* ad = dict.getAddressBook(bookName);
            if (ad) {
                char subChoice;
                do {
                    cout << "\nManaging Address Book: " << bookName << "\n";
                    cout << "Options:\n";
                    cout << "a. Add contact\n";
                    cout << "e. Edit contact\n";
                    cout << "r. Remove contact\n";
                    cout << "d. Display contacts\n";
                    cout << "q. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                    case 'a': {
                        Contacts c;
                        c.input();
                        ad->addContact(c);
                        break;
                    }
                    case 'e': {
                        cout << "Enter the first name of the contact to edit: ";
                        cin >> name;
                        ad->editContact(name);
                        break;
                    }
                    case 'r': {
                        cout << "Enter the first name of the contact to remove: ";
                        cin >> name;
                        if (ad->removeContact(name)) {
                            cout << "Contact deleted!" << endl;
                        } else {
                            cout << "Contact not found!" << endl;
                        }
                        break;
                    }
                    case 'd': {
                        ad->display();
                        break;
                    }
                    case 'q': {
                        cout << "Returning to main menu...\n";
                        break;
                    }
                    default:
                        cout << "Invalid choice! Please choose a valid option.\n";
                    }
                } while (subChoice != 'q');
            }
            break;
        }
        case '3': {
            cout << "Exiting the program...\n";
            break;
        }
        default:
            cout << "Invalid choice! Please choose a valid option.\n";
        }
    } while (choice != '3');

    return 0;
}
