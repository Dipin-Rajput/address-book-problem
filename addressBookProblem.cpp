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

public:

    string firstName, lastName, fullName, address, city, state, zip, phoneNumber, email;

    // UC1: Ability to create contact in address book

    Contact(string firstName, string lastName, string address, string city, string state, string zip, string phoneNumber, string email){

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
        cout << "Email: " <<  email << endl;
    }
};

class AddressBook{

    vector<Contact> addressBook;

public:

    // UC2: Ability to add new contact in address book

    void addContact(){

        string firstName, lastName, address, city, state, zip, phoneNumber, email;

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

    // UC3: Ability to edit contact in address book

    void editContact(){

        if(addressBook.empty()){ // Check if addressBook is empty or not
            cout << "\nAddress Book is empty, please add contact first";
            return;
        }

        string firstName, lastName, fullName, input;

        cout << "\nEnter your first name: "; cin >> firstName;
        cout << "Enter your last name: "; cin >> lastName;
        fullName = firstName + " " + lastName;

        for(auto& contact : addressBook){ // Loop to find the contact with name
            if(contact.fullName == fullName){

                cout << "\n-------------------- Editing contact details for '" << fullName << "' --------------------";
                cout << "\n-------------------- Press enter to keep current details --------------------\n";

                cout << "\nEnter new address [current address: "<< contact.address << "]: "; cin.ignore(); getline(cin, input);
                if(!input.empty()){contact.address = input;}

                cout << "Enter new city [current city: "<< contact.city << "]: "; getline(cin, input);
                if(!input.empty()){contact.city = input;}

                cout << "Enter new state [current state: "<< contact.state << "]: "; getline(cin, input);
                if(!input.empty()){contact.state = input;}

                cout << "Enter new zip [current zip: "<< contact.zip << "]: "; cin >> contact.zip;
                if(!input.empty()){contact.zip = input;}

                cout << "Enter new phone number [current phone number: "<< contact.phoneNumber<< "]: "; cin >> contact.phoneNumber;
                if(!input.empty()){contact.phoneNumber = input;}

                cout << "Enter new email [current email: "<< contact.email << "]: "; cin.ignore(); getline(cin, input);
                if(!input.empty()){contact.email = input;}

                cout << "\nContact updated successfully\n";

                return;
            }
        }

        cout << "\nContact Not found, please enter valid name\n";
    }

    // UC3: Ability to edit contact in address book

    void deleteContact(){

        if(addressBook.empty()){ // Check if addressBook is empty or not
            cout << "\nAddress Book is empty, please add contact first";
            return;
        }

        string firstName, lastName, fullName;

        cout << "\nEnter your first name: "; cin >> firstName;
        cout << "Enter your last name: "; cin >> lastName;
        fullName = firstName + " " + lastName;

        for(auto itr = addressBook.begin(); itr != addressBook.end(); ++itr){ // Loop to find the contact with name using iterator
            if(itr->fullName == fullName){
                addressBook.erase(itr);
                cout << "\nContact deleted successfully\n";
                return;
            }
        }

        cout << "\nContact Not found, please enter valid name\n";
    }

    void displayContacts(){

        if(addressBook.empty()){ // Check if addressBook is empty or not
            cout << "\nAddress Book is empty, please add contact first";
            return;
        }

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
    addressBook.displayContacts(); // Function call to display contact
    addressBook.editContact(); // Function call to edit contact
    addressBook.displayContacts(); // Function call to display contact after edit
    addressBook.deleteContact(); // Function call to delete contact
    addressBook.displayContacts(); // Fuction call to display contact after delete

    return 0;
}