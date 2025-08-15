//  Mobile Bank Project
//  main.cpp
//  ebappiahkubi_Final
//  Created by Enoch Appiah-kubi on 4/21/25.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Ledger{
    string transactiontype;
    double amount;
    vector<Ledger>transactionhistory;
};

struct Account{
    string name;
    int accountnum;
    double accountbalance;
    Ledger thistory;
};

Account account;
vector<Account>Accounts;

int userid;

int accountnumgen = 1001;

void createaccount(){
    cout << "Account owner name? ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, account.name);
    
    account.accountnum = accountnumgen;
    ++accountnumgen;
    account.accountbalance = 0;

    Accounts.push_back(account);
    
    cout << account.accountnum << endl;
    cout << account.name << endl;
}

void findAccount() {
    int userid;
    int accountsize = Accounts.size();
    accountsize = accountsize - 1;
    while (true) {
        cout << "What's your account number? ";
        cin >> userid;
        userid = userid - 1001;
        //cout << accountsize;
        if (cin.fail() or userid < 0 or userid > accountsize) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        }
        else {
            break;
        }
    }
    
}

    
    double depositinput;
    double withdrawinput;
    char command;
    
    
    void transmemory(){
        switch (command){
            case 'd': Accounts[userid].thistory.transactiontype = "Deposited ";
                Accounts[userid].thistory.amount = depositinput;
                Accounts[userid].thistory.transactionhistory.push_back(Accounts[userid].thistory);
                break;
            case 'w': Accounts[userid].thistory.transactiontype = "Withdrew ";
                Accounts[userid].thistory.amount = withdrawinput;
                Accounts[userid].thistory.transactionhistory.push_back(Accounts[userid].thistory);
                break;
        }
    }
    
    void vt(){
        findAccount();
        int i = 0;
        while (i <= Accounts[userid].thistory.transactionhistory.size()){
            cout << Accounts[userid].thistory.transactionhistory[i].transactiontype << " $";
            cout << Accounts[userid].thistory.transactionhistory[i].amount << endl;
            ++i;
        }
    }
    
    void deposit(){
        findAccount();
        cout << "How much would you like to deposit? $";
        cin >> depositinput;
        cout << "You deposited $" << depositinput << endl;
        Accounts[userid].accountbalance = Accounts[userid].accountbalance + depositinput;
        transmemory();
    }
    
void withdraw(){
    findAccount();
    while (true) {
        cout << "How much would you like to withdraw? $";
        cin >> withdrawinput;
        if (Accounts[userid].accountbalance >= withdrawinput){
            cout << "You withdrew $" << withdrawinput << endl;
            Accounts[userid].accountbalance = Accounts[userid].accountbalance - withdrawinput;
            transmemory();
            break;
        }
        else {
            cout << "Insufficient Funds";
            break;
        }
        
    }
}
        void checkbalance(){
            findAccount();
            cout << Accounts[userid].name << endl << Accounts[userid].accountnum << endl;
            cout << "Account balance is currently $" << Accounts[userid].accountbalance << endl;
        }
    void display_menu() {
        cout << "\n";
        cout << "Menu Program\n\n"
        << "COMMANDS\n"
        << "C - Account Create\n"
        << "D - Deposit\n"
        << "W - Withdraw\n"
        << "B - Check Balance\n"
        << "T - View Transaction\n"
        << "X   Exit\n";
    }
    
    int main(){
        while (tolower(command) != 'x') {
            display_menu();
            cout << "Command: ";
            cin >> command;
            command = tolower(command);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (command) {
                case 'c':
                    createaccount();
                    break;
                    
                case 'd':
                    deposit();
                    break;
                    
                case 'w':
                    withdraw();
                    break;
                    
                case 'b':
                    checkbalance();
                    break;
                    
                case 't':
                    vt();
                    break;
                    
                case 'x':
                    cout << "Bye!\n\n";
                    break;
                    
                default:
                    cout << "Not a valid command. Please try again.\n\n";
                    break;
            }
        }
    }

