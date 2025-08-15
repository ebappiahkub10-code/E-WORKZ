📱 Mobile Bank (C++ Console Application)
Author: Enoch Appiah-Kubi
Date Created: April 21, 2025
Language: C++
Status: Functional – with persistent data storage

📌 Overview
Mobile Bank is a simple command-line banking system that allows users to:

Create accounts with password protection

Deposit and withdraw funds

View account balance

Track transaction history

Save data persistently in a file

This program is built entirely in C++ and stores account information locally in a .txt file, simulating a basic banking database.

✨ Features
🔐 Login System with password hashing (for secure storage)

🗂 File-based database (MobileBankDB.txt) to store accounts & transactions

💰 Deposit & Withdraw functionality

📜 Transaction history per account

💾 Data persistence between sessions

🖥 User-friendly console menu

🛠 Technologies Used
C++ Standard Library

<iostream>, <fstream>, <string>, <vector>, <functional>, <iomanip>, <filesystem>

File I/O for persistent data storage

Password Hashing using std::hash

📂 File Structure
bash
Copy
Edit
MobileBank/
│
├── main.cpp                # Main application code
├── MobileBankDB.txt        # Persistent account & transaction storage
└── README.md               # Project documentation
🚀 How to Run
1. Compile
bash
Copy
Edit
g++ -std=c++17 main.cpp -o MobileBank
2. Run
bash
Copy
Edit
./MobileBank
📖 Menu Commands
Command	Description
C	Create a new account
D	Deposit funds
W	Withdraw funds
B	Check account balance
T	View transaction history
X	Exit program

🔒 Security
Passwords are hashed before being stored.

The program uses std::hash to ensure raw passwords are never saved.

Account data is saved in MobileBankDB.txt in a human-readable format.

📌 Example Usage
pgsql
Copy
Edit
Menu Program

COMMANDS
C - Account Create
D - Deposit
W - Withdraw
B - Check Balance
T - View Transaction
X - Exit

Command: C
Account owner name? John Doe
Create a password: ********
✅ Account created successfully!
Account Number: 1001
Name: John Doe
🗄 Data Persistence
Account data is stored in:

javascript
Copy
Edit
~/Desktop/MobileBankDB.txt
The file is automatically created if it doesn’t exist.

Example file contents:

yaml
Copy
Edit
=== Mobile Bank Database ===

Account: John Doe (1001)
Balance: $1500
Password Hash: 84736487236487236
Transactions:
   Deposited $1000
   Deposited $500
📅 Future Improvements
Implement cross-platform password masking (e.g., ***** while typing)

Encrypt database file for added security

Add account deletion feature

Support multiple currencies

📜 License
This project is open-source. You are free to use and modify it for educational purposes.
