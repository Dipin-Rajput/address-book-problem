# include <iostream>
using namespace std;

class AddressBookMain{

public:
    void displayMessage(){ // function to display message
        cout << "\n-------------------- Welcome to Address Book Program --------------------\n";
    }
};

int main(){

    AddressBookMain msg; // Object for AddresssBookMain class

    msg.displayMessage(); // Function call to display message

    return 0;
}