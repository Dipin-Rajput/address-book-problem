# include <iostream>
# include <vector>
# include <string>
using namespace std;

class AddressBookMain{

public:
    void displayMessage(){ // function to display message
        cout << "\n-------------------- Welcome to Address Book Program --------------------\n";
    }
};
    
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

    void displayContact() const{ // Function to display contact

        cout << "\nFull Name: " << fullName << endl;
        cout << "Address: " <<  address << endl;
        cout << "City: " <<  city << endl;
        cout << "State: " <<  state << endl;
        cout << "Zip: " <<  zip << endl;
        cout << "Phone Number: " <<  phoneNumber << endl;
        cout << "Email: " <<  email << "\n" << endl;
    }
};

class AddressBook{

    vector<Contact> addressBook;

public:

    // UC2: Ability to add new contact in address book

    void addContact(){

        string firstName, lastName, address, city, state, email;
        int zip, phoneNumber;

        // User - Input

        cout << "\nEnter your first name: "; cin >> firstName;
        cout << "Enter your last name: ";  cin >> lastName;

        cin.ignore(); // Function to clear the newline character ('\n')

        cout << "Enter your address: "; getline(cin, address);
        cout << "Enter your city: "; getline(cin, city);
        cout << "Enter your state: "; getline(cin, state);
        cout << "Enter your zip: "; cin >> zip;
        cout << "Enter your phone number: "; cin >> phoneNumber;

        cin.ignore(); // Function to clear the newline character ('\n')

        cout << "Enter your email: "; getline(cin, email);

        Contact newContact(firstName, lastName, address, city, state, zip, phoneNumber, email); // Object for Contact class
        addressBook.push_back(newContact); // Add contact to addressBook vector
    }

    void displayContacts(){

        for(const auto& contact : addressBook){ // Loop to iterate over addressBook
            contact.displayContact(); // Fucntion call to display contact
        }
    }
};


int main(){

    AddressBookMain addressBookMain; // Object for AddresssBookMain class
    addressBookMain.displayMessage(); // Function call to display message

    AddressBook addressBook; // Object for AdressBook class
    addressBook.addContact(); // Function call to add contact
    addressBook.displayContacts(); // Function call to display contacts

    return 0;
}