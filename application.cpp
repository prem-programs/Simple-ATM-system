#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class accH {
private:
    long acc, pin, ePin;
    long amount = 0;
    string name;

public:
    void getDetails() {
        cout << "##################################\n";
        cout << "#  Welcome to SimpleBank System  #\n";
        cout << "##################################\n\n";
        
        cout << "Enter your name : ";
        cin.ignore();         
        getline(cin, name);     // allow spaces in name
        
        cout << "Enter acc no :  ";
        cin >> acc;
        
        cout << "Enter pin : ";
        cin >> pin;
        
        ePin = pin ^ 100100100;  // simple XOR encryption
    }

    void performTransaction() {
        int userChoice;
        cout << "Enter (1 = deposit) & (2 = withdraw): ";
        cin >> userChoice;

        if (userChoice == 1) {
            long Dcash;
            cout << "Enter amount you want to deposit: $";
            cin >> Dcash;
            if (Dcash <= 0) {
                cout << "Invalid deposit amount. Must be more than $0.\n";
               
            }
            amount += Dcash;
            cout << "Amount deposited successfully.\n";
        }
        else if (userChoice == 2) {
            long Wcash;
            cout << "Enter amount to withdraw: $";
            cin >> Wcash;
            if (Wcash <= 0) {
                cout << "Invalid withdrawal amount. Must be more than $0.\n";
                return;
            }
            if (Wcash > amount) {
                cout << "Insufficient balance!\n";
                return;
            }
            amount -= Wcash;
            cout << "Amount withdrawn successfully.\n";
        }
        else {
            cout << "Invalid option selected.\n";
        }

        cout << "########## Thanks for visiting ##########\n";
    }

    void viewBalance() {
        char c2;
        cout << "Want to view balance? (y/n): ";
        cin >> c2;
        if (c2 == 'Y' || c2 == 'y') {
            cout << "Balance: $" << amount << endl;
        }
    }

    void saveCopy() {
        ofstream out("data.txt", ios::app);
        
        if (!out) {
            cerr << "Error creating file!\n";
            return;
        }
        out << "______________________\n";
        out << "Name       : " << name << "\n";
        out << "Account No : " << acc << "\n";
        out << "PIN (Encrypted): " << ePin << "\n";
        out << "Balance    : $" << amount << "\n";
        out << "______________________\n";
        out.close();
        cout << "All your data is updated in 'data.txt'.\n";
    }
};

int main() {
    accH user;
    user.getDetails();          
    user.performTransaction();  
    user.viewBalance();         
    user.saveCopy();            
    return 0;
}