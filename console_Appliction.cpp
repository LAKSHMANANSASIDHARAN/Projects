/*Im really happy beacuse Today I Have completed my first console application. 
Banking System Code
This program simulates a basic banking system with the following features:
1. Create a new bank account for users.
2. Deposit money into the account.
3. Withdraw money from the account.
4. Check account balance and view mini-statements of transactions.
5. Display all users who have accounts in the bank.

Key Components:

1. Struct ministatement:
    Holds details about individual transactions like day, withdrawal/deposit status (WD), and balance (Bal).

2. Class Bank:
   Attributes:
      Name: Stores the user's name.
      Account_Number: Stores the account number.
      Account_Balance: Tracks the user's current balance.
      Mini_Statement: Stores a list of all transactions.
   Methods:
     getname(), getac(): Get the account name and account number.
     setb(): Add deposited money to the balance.
     setd(): Deduct withdrawn money from the balance.
     Mini_statement()`: Add a transaction to the mini-statement.
     Account_checking()`: Display the current account balance.
     statement(): Display a list of all transactions (mini-statement). If no transactions, it shows a message.

3. Global Function `showAllUsers():
     Displays the list of all registered users by looping through the `bankAccounts` vector.

How the Program Works:

Main Loop: The program keeps running until the user chooses to stop. 
   First, it asks if you want to see all registered users.
   Then, it lets you create a new bank account by entering the user's name and account number.
   After creating an account, you can:
    Check the balance.
    Deposit money.
    Withdraw money.
    View the mini-statement of transactions.
   You can continue banking actions for the user or register another user.

Multiple Users: The program supports multiple users by storing their details in the `bankAccounts` vector. Each user can have their own account and transactions tracked separately.
This program is a simple way to simulate a basic banking system, and more features can be added later to enhance it. Hope this helps! */
#include <iostream>
#include <vector>
using namespace std;

struct ministatement {
    int day;
    int WD;
    int Bal;
};

class Bank {
private:
    string Name;
    int Account_Number;
    int Account_Balance;
    vector<ministatement> Mini_Statement;

public:
    Bank(string name, int num1) {
        Name = name;
        Account_Number = num1;
        Account_Balance = 0;
    }

    string getname() {
        return Name;
    }

    void setname(string newname) {
        Name = newname;
    }

    void Mini_statement(int d, int ww, int B) {
        ministatement data;
        data.Bal = B;
        data.day = d;
        data.WD = ww;
        Mini_Statement.push_back(data);
    }

    int getac() {
        return Account_Number;
    }

    void setac(int an) {
        Account_Number = an;
    }

    int getb() {
        return Account_Balance;
    }

    void setb(int ab) {
        Account_Balance += ab;
    }

    void setd(int ab) {
        Account_Balance -= ab;
    }

    void Account_checking() {
        cout << "Name: " << Name << endl;
        cout << "Account_Number: " << Account_Number << endl;
        cout << "Account_Balance: " << Account_Balance << endl;
    }

    void statement() {
        cout << "Name: " << Name << endl;
        cout << "Account_Number: " << Account_Number << endl;
        cout << "Account_Balance: " << Account_Balance << endl;
        if (Mini_Statement.empty()) {
            cout << "No transactions have been made!" << endl;
        } else {
            for (size_t i = 0; i < Mini_Statement.size(); i++) {
                cout << " Day " << i + 1 << " ";
                if (Mini_Statement[i].WD == 0) {
                    cout << "Withdraw ";
                } else if (Mini_Statement[i].WD == 1) {
                    cout << "Deposit ";
                } else {
                    cout << "No transactions!! ";
                }
                cout << "Balance: " << Mini_Statement[i].Bal << endl;
            }
        }
    }
};

void showAllUsers(vector<Bank>& bankAccounts) {
    cout << "List of all bank users:" << endl;
    for (size_t i = 0; i < bankAccounts.size(); ++i) {
        cout << "User " << i + 1 << ": " << bankAccounts[i].getname()
             << ", Account Number: " << bankAccounts[i].getac() << endl;
    }
}

int main() {
    vector<Bank> bankAccounts;
    bool process = true;
    int day = 1;
    int need;
    while (process) {
        string name;
        int an;

        cout << "Do you want to see all users? Press 1 for Yes, 0 for No: ";
        int viewUsers;
        cin >> viewUsers;
        if (viewUsers == 1) {
            showAllUsers(bankAccounts);
        }

        cout << "Please Enter the Name: ";
        cin >> name;
        cout << "Enter the Account Number: ";
        cin >> an;

        Bank newAccount(name, an);
        bankAccounts.push_back(newAccount);

        bool session = true;
        while (session) {
            int need, deposite, withdraw;

            cout << "Press 1 for Balance checking" << endl;
            cout << "Press 2 for Deposit" << endl;
            cout << "Press 3 for Withdraw" << endl;
            cout << "Press 4 for Mini statement" << endl;
            cin >> need;

            if (need == 1) {
                newAccount.Account_checking();
                cout << "--------------------------------------" << endl;
            } else if (need == 2) {
                cout << "How much you want to deposit: ";
                cin >> deposite;
                newAccount.setb(deposite);
                newAccount.Mini_statement(day++, 1, newAccount.getb());
            } else if (need == 3) {
                cout << "How much you want to withdraw: ";
                cin >> withdraw;
                if (withdraw > newAccount.getb()) {
                    cout << "Invalid Amount" << endl;
                } else {
                    newAccount.setd(withdraw);
                    newAccount.Mini_statement(day++, 0, newAccount.getb());
                }
            } else if (need == 4) {
                newAccount.statement();
            }

            cout << "Do you want to continue? (1: Yes, 0: No): ";
            cin >> need;
            if (need == 0) {
                session = false;
            }
        }

        cout << "Do you want to register another user? (1: Yes, 0: No): ";
        cin >> need;
        if (need == 0) {
            process = false;
        }
    }

    cout << "Thanks for using our Bank!" << endl;
    return 0;
}
