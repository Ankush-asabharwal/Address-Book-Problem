#include<iostream>
#include<list>

using namespace std;

class Contacts {
public :
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

    Contacts() {
    }

public:
    void display() {
        cout << "First Name : " << firstName << endl;
        cout << "Last Name : " << lastName << endl;
        cout << "Address : " << address << endl;
        cout << "City : " << city << endl;
        cout << "State : " << state << endl;
        cout << "Zip : " << zip << endl;
        cout << "Phone Number : " << phoneNumber << endl;    
        cout << "Email : " << email << endl;
    }

    void input() {
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Address : ";
        cin >> address;
        cin.ignore();
        getline(cin, address);
        cout << "Enter City : ";
        cin >> city;
        cout << "Enter State : ";
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
public :
    list<Contacts> contacts;

public:
    void operator+ (Contacts &c) {
        contacts.push_back(c);
    }

    void display() {
        if(contacts.empty()){
            cout << "List is empty" << endl;
        }
        for(auto contact : contacts){
            contact.display();
        }
    }

    bool edit(string &name) {
        for(list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++){
            if(it->firstName == name) {
                cout << "Contact Found!" << endl;
                cout << "Contact Found" << endl;
                cout << "First Name: " << it->firstName << endl;
                cout << "Last Name: " << it->lastName << endl;
                cout << "Address: " << it->address << endl;
                cout << "City: " << it->city << endl;
                cout << "State: " << it->state << endl;
                cout << "Zip: " << it->zip << endl;
                cout << "Phone Number: " << it->phoneNumber << endl;
                cout << "Email: " << it->email << endl;

                cout << "Enter new Details : " << endl;
                it->input();
                cout << "Contact Updated!" << endl;
                cout << endl;
                return true;
            }
        }
        return false;
    }

    bool remove(string &name) {
        for(list<Contacts>::iterator it = contacts.begin(); it != contacts.end(); it++){
            if(it->firstName == name) {
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "Welcome to Book Address Problem" << endl;

    Contacts c;
    c.input();
    cout << endl;

    AddressBook ad;
    ad + c;
    ad.display();

    cout << "Do you want to edit or remove the contact : (Input e to edit and r to remove the contact)" << endl;
    char choice;
    cin >> choice;
    string name;
    if(choice == 'e'){
        cout << "String name to edit : " << endl;
        cin >> name;
        if(ad.edit(name)){
            ad.display();
        }else{
            cout << "Contact Not Found!" << endl;
        }
    }
    else if(choice == 'r') {
        cout << "Enter name to delete the contact : " << endl;
        cin >> name;
        if (ad.remove(name)) {
            cout << "Contact Deleted!" << endl;
        }else{
            cout << "Contact Not Found!" << endl;
        }
    }
}