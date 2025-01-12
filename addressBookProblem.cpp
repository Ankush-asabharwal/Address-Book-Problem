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
};

class AddressBook {
public :
    list<Contacts> contacts;

public:
    void operator+ (Contacts &c){
        contacts.push_back(c);
    }

    void display(){
        for(auto contact : contacts){
            contact.display();
        }
    }
};

int main() {
    cout << "Welcome to Book Address Problem" << endl;

    Contacts c;
    cout << "Enter First Name: ";
    cin >> c.firstName;
    cout << "Enter Last Name: ";
    cin >> c.lastName;
    cout << "Enter Address : ";
    cin >> c.address;
    cout << "Enter City : ";
    cin >> c.city;
    cout << "Enter State : ";
    cin >> c.state;
    cout << "Enter ZIP Code: ";
    cin >> c.zip;
    cout << "Enter Phone Number: ";
    cin >> c.phoneNumber;
    cout << "Enter Email: ";
    cin >> c.email;

    cout << endl;

    AddressBook ad;
    ad + c;
    ad.display();
}