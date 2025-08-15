//  Updated Mobile Bank Project With Login & Database
//  main.cpp
//  Enoch Appiah-kubi 
//  08/15/2025.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <fstream>
#include <filesystem>

using namespace std;

void initDatabaseFile() {
    string filename = "MobileBankDB.txt";

    // If file doesn't exist, create it
    if (!filesystem::exists(filename)) {
        ofstream file(filename);
        if (file) {
            file << "=== Mobile Bank Database ===\n";
            file.close();
            cout << "[INFO] Database file created: "
                 << filesystem::absolute(filename) << endl;
        } else {
            cerr << "[ERROR] Could not create database file." << endl;
        }
    } else {
        cout << "[INFO] Database file already exists at: "
             << filesystem::absolute(filename) << endl;
    }
}

const string DATA_FILE = "/Users/enoch/Desktop/Mobile Bank DB.txt";
const string savePath = DATA_FILE;

struct Ledger{
    string transactiontype;
    double amount;
    vector<Ledger>transactionhistory;
};

struct Account{
    string name;
    int accountnum;
    double accountbalance;
    string passwordHash;
    Ledger thistory;
    vector<Ledger> transactionhistory;
};


vector<Account>Accounts;

int userid;

int accountnumgen = 1001;

string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

void saveAccounts() {
    string dataFilePath = getenv("HOME") + string("/Desktop/MobileBankDB.txt");
       string prettyFilePath = getenv("HOME") + string("/Desktop/MobileBankDB_READABLE.txt");

    
    ofstream file(DATA_FILE);
    if (!file) {
        cerr << "Error saving data.\n";
        return;
    }
    file << "=== Mobile Bank Database ===\n\n";
    file << accountnumgen << endl;
    file << Accounts.size() << endl;
    for (const auto& acc : Accounts) {
        file << "Account: " << acc.name << " (" << acc.accountnum << ")" << endl;
        file << "Balance: $" << acc.accountbalance << endl;
        file << "Password Hash: " << acc.passwordHash << endl;
        file << "Transactions:\n" << acc.transactionhistory.size() << "\n";
        if (acc.transactionhistory.empty()) {
            file << "    [none]\n\n";
        } else {
            for (const auto& t : acc.transactionhistory) {
                file << "   " << t.transactiontype << " $" << t.amount << "\n";
            }
        }
    }
    file.close();
    
    
    
    cout << "Loaded " << Accounts.size() << " account(s) from " << DATA_FILE << endl;
}
    
    void loadAccounts() {
    ifstream infile(DATA_FILE);
        if (!infile){
            cout << "No existing data found at: " << DATA_FILE << "\n";
            return; // no file yet
        }
    int numAccounts;
    infile >> accountnumgen;
    infile >> numAccounts;
    infile.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < numAccounts; i++) {
        Account acc;
        getline(infile, acc.name);
        infile >> acc.accountnum;
        infile >> acc.accountbalance;
        infile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(infile, acc.passwordHash);
        int numTrans;
        infile >> numTrans;
        infile.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int j = 0; j < numTrans; j++) {
            Ledger l;
            getline(infile, l.transactiontype);
            infile >> l.amount;
            infile.ignore(numeric_limits<streamsize>::max(), '\n');
            acc.transactionhistory.push_back(l);
        }
        Accounts.push_back(acc);
    }
}
bool login() {
    int accNum;
    string pass;
    cout << "Account number: ";
    cin >> accNum;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int index = -1;
    for (int i = 0; i < Accounts.size(); i++) {
        if (Accounts[i].accountnum == accNum) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "❌ Account not found.\n";
        return false;
    }
    
    int attempts = 3;
    while (attempts > 0) {
        cout << "Password: ";
        getline(cin, pass);
        if (Accounts[index].passwordHash == hashPassword(pass)) {
            userid = index;
            return true;
        } else {
            attempts--;
            cout << "❌ Incorrect password. Attempts left: " << attempts << endl;
        }
    }
    cout << "Account locked for this session due to too many failed attempts.\n";
    return false;
}

void createaccount(){
    Account account;
    cout << "Account owner name? ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, account.name);
    
    string pass;
    cout << "Create a password: ";
    getline(cin, pass);
    account.passwordHash = hashPassword(pass);
    
    account.accountnum = accountnumgen;
    ++accountnumgen;
    account.accountbalance = 0;
    account.transactionhistory.clear();

    Accounts.push_back(account);
    saveAccounts();
    
    cout << "✅ Account created successfully!\n";
    cout << "Account Number: " << account.accountnum << endl;
    cout << "Name: " << account.name << endl;
}

void findAccount() {
    int userid;
    long long accountsize = Accounts.size();
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
        if (command == 'd') {
            Accounts[userid].thistory.transactiontype = "Deposited ";
            Accounts[userid].thistory.amount = depositinput;
            Accounts[userid].transactionhistory.push_back(Accounts[userid].thistory);
        } else if (command == 'w') {
            Accounts[userid].thistory.transactiontype = "Withdrew ";
            Accounts[userid].thistory.amount = withdrawinput;
            Accounts[userid].transactionhistory.push_back(Accounts[userid].thistory);
        }
    }
    
    void vt(){
        if (!login()) return;
        //findAccount();
        int i = 0;
        while (i < Accounts[userid].transactionhistory.size()){
            cout << Accounts[userid].transactionhistory[i].transactiontype << " $" << Accounts[userid].transactionhistory[i].amount << endl;
            ++i;
            
        }
        }
            
    
    void deposit(){
        if (!login()) return;
        //findAccount();
        cout << "How much would you like to deposit? $";
        cin >> depositinput;
        cout << "You deposited $" << depositinput << endl;
        Accounts[userid].accountbalance = Accounts[userid].accountbalance + depositinput;
        transmemory();
        saveAccounts();
    }
    
void withdraw(){
    if (!login()) return;
    //findAccount();
    while (true) {
        cout << "How much would you like to withdraw? $";
        cin >> withdrawinput;
        if (Accounts[userid].accountbalance >= withdrawinput){
            Accounts[userid].accountbalance = Accounts[userid].accountbalance - withdrawinput;
            transmemory();
            saveAccounts();
            cout << "You withdrew $" << withdrawinput << endl;
            break;
        }
        else {
            cout << "Insufficient Funds" << endl;
            break;
        }
        
    }
}
        void checkbalance(){
            if (!login()) return;
            //findAccount();
            saveAccounts();
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
        initDatabaseFile(); // create file or show location
        loadAccounts();
    
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
                    saveAccounts();
                    cout << "Bye!\n\n";
                    break;
                    
                default:
                    cout << "Not a valid command. Please try again.\n\n";
                    break;
            }
        }
    }
