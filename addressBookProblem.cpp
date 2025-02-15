# include <iostream>
using namespace std;

class Contact{

    string firstName, lastName, fullName, address, city, state, email;
    int zip, phoneNumber;

public:

    // UC1: Ability to create contact in address book

    Contact(string firstName, string lastName, string address, string city, string state, int zip, int phoneNumber, string email){

        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phoneNumber = phoneNumber;
        this->email = email;

        this->fullName = firstName + " " + lastName;
    }

    void displayContact(){

        cout << "\nFull Name: " << fullName << endl;
        cout << "Address: " <<  address << endl;
        cout << "City: " <<  city << endl;
        cout << "State: " <<  state << endl;
        cout << "Zip: " <<  zip << endl;
        cout << "Phone Number: " <<  phoneNumber << endl;
        cout << "Email: " <<  email << "\n" << endl;
    }
};

class AddressBookMain{

public:
    void displayMessage(){ // function to display message
        cout << "\n-------------------- Welcome to Address Book Program --------------------\n";
    }
};

int main(){

    AddressBookMain msg; // Object for AddresssBookMain class
    msg.displayMessage(); // Function call to display message

    string firstName, lastName, address, city, state, email;
    int zip, phoneNumber;

    // User - Input

    cout << "\nEnter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;

    cin.ignore(); // function to clear the newline character ('\n')

    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your city: ";
    getline(cin, city);
    cout << "Enter your state: ";
    getline(cin, state);
    cout << "Enter your zip: ";
    cin >> zip;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;

    cin.ignore(); // function to clear the newline character ('\n')

    cout << "Enter your email: ";
    getline(cin, email);

    Contact contact(firstName, lastName, address, city, state, zip, phoneNumber, email); // Object for Contact class

    contact.displayContact(); // fucntion call to display contact

    return 0;
}