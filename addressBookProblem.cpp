# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
using namespace std;
    
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

        cout << "\nContact added successfully\n";
    }

    // UC3: Ability to edit contact in address book

    void editContact(){

        if(addressBook.empty()){ // Check if addressBook is empty or not
            cout << "\nAddress Book is empty, please add contact first\n";
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

                cout << "Enter new zip [current zip: "<< contact.zip << "]: "; getline(cin, input);
                if(!input.empty()){contact.zip = input;}

                cout << "Enter new phone number [current phone number: "<< contact.phoneNumber<< "]: "; getline(cin, input);
                if(!input.empty()){contact.phoneNumber = input;}

                cout << "Enter new email [current email: "<< contact.email << "]: "; getline(cin, input);
                if(!input.empty()){contact.email = input;}

                cout << "\nContact updated successfully\n";

                return;
            }
        }

        cout << "\nContact Not found, please enter valid name\n";
    }

    // UC4: Ability to delete contact in address book

    void deleteContact(){

        if(addressBook.empty()){ // Check if addressBook is empty or not
            cout << "\nAddress Book is empty, please add contact first\n";
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
            cout << "\nAddress Book is empty, please add contact first\n";
            return;
        }

        int count = 1;

        for(const auto& contact : addressBook){ // Loop to iterate over addressBook
            cout << "\nContact: " << count << " ------------------------------" << endl;
            contact.displayContact(); // Fucntion call to display contact
            count++;
        }
    }
};

void manageAddressBook(AddressBook& book){

    char input;

    // UC5: Ability to add mulitple contacts in address book

    // do - while loop to perform operations mulitple times

    do{
        cout << "\nEnter 1 to add new contact";
        cout << "\nEnter 2 to edit contact";
        cout << "\nEnter 3 to delete contact";
        cout << "\nEnter 4 to display contacts\n";

        int choice;

        cout << "\nEnter your choice: "; cin >> choice;

        switch(choice){

            case 1:
                book.addContact(); // Function call to add contact
                break;

            case 2:
                book.editContact(); // Function call to edit contact
                break;

            case 3:
                book.deleteContact(); // Function call to delete contact
                break;

            case 4:
                book.displayContacts(); // Function call to display contact
                break;

            default:
                cout << "\nInvalid Choice, please enter from above choices";
                break;
        }

        cout << "\nDo you want to continue? (y/n): "; cin >> input;
    }
    while(input == 'y' || input == 'Y');

    cout << "\nReturning to Main Menu\n";
}

// UC6: Refactor to add mulitple address book in address book system

class AddressBookMain{

    unordered_map<string, AddressBook> addressBooks;

public:

    void displayMessage(){ // Function to display message
        cout << "\n-------------------- Welcome to Address Book Program --------------------\n";
    }

    void addAddressBook(){ // Function to add address book

        string bookName;
        cout << "\nEnter address book name: ";cin.ignore(); getline(cin, bookName);
        addressBooks[bookName] = AddressBook();
        cout << "\nAddress Book '" << bookName << "' added successfully." << endl;
    }

    void selectAddressBook(){ // Function to select address book

        if(addressBooks.empty()){
            cout << "\nNo address book is available, please add one first\n";
            return;
        }

        cout << "\nAvailable Address Books:\n\n";

        for(auto book : addressBooks){
            cout << "- " << book.first << endl;
        }

        string bookName;
        cout << "\nEnter the address book name to use: "; cin.ignore(); getline(cin, bookName);
        
        if(addressBooks.find(bookName) != addressBooks.end()){
            manageAddressBook(addressBooks[bookName]);
        }
        else{
            cout << "\nAddress Book Not found, please enter valid name\n";
        }
    }

    void displayAddressBooks(){ // Function call to display address book

        if(addressBooks.empty()){
            cout << "\nNo address book is available, please add one first\n";
            return;
        }

        cout << "\nAvailable Address Books:\n\n";

        for(auto book : addressBooks){
            cout << "- " << book.first << endl;
        }
    }
};


int main(){

    AddressBookMain addressBookMain; // Object for AddresssBookMain class
    addressBookMain.displayMessage(); // Function call to display message

    char input;

    // do - while loop to perform operations mulitple times

    do{
        cout << "\nEnter 1 to add new address book";
        cout << "\nEnter 2 to select an address book";
        cout << "\nEnter 3 to display address books\n";

        int choice;

        cout << "\nEnter your choice: "; cin >> choice;

        switch(choice){
            
            case 1:
                addressBookMain.addAddressBook(); // Function call to add address book
                break;

            case 2:
                addressBookMain.selectAddressBook(); // Function call to select address book
                break;

            case 3:
                addressBookMain.displayAddressBooks(); // Function call to dispaly address books
                break;

            default:
                cout << "\nInvalid Choice, please enter from above choices\n";
                break;
        }

        cout << "\nDo you want to continue? (y/n): "; cin >> input;
    }
    while(input == 'y' || input == 'Y');

    cout << "\nClosing Address Book Program, Thank You for Joining.\n\n";

    return 0;
}