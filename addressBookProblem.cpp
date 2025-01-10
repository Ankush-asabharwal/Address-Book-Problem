#include<iostream>

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

    Contacts(string firstName, string lastName, string address, string city, string state, int zip, long int phoneNumber){
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phoneNumber = phoneNumber;
    }

public:
    void display(){
        cout << "First Name : " << firstName << endl;
        cout << "Last Name : " << lastName << endl;
        cout << "Address : " << address << endl;
        cout << "City : " << city << endl;
        cout << "State : " << state << endl;
        cout << "Zip : " << zip << endl;
        cout << "Phone Number : " << phoneNumber << endl;    
    }
};

int main(){
    cout << "Welcome to Book Address Problem" << endl;

    Contacts c("Ankusha", "Sabharwal", "GTB nagar", "Ludhiana", "Punjab", 141010, 8360765920);
    c.display();
   
}