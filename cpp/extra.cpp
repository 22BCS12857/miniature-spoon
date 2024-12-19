#include <iostream>
#include <memory>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double balance) : balance(balance) {}
    virtual ~Account() {}
    virtual void calculateInterest() = 0;
};

class SavingsAccount : public Account {
private:
    double rate;
    int time;
public:
    SavingsAccount(double balance, double rate, int time)
        : Account(balance), rate(rate), time(time) {}

    void calculateInterest() override {
        double interest = (balance * rate * time) / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    double maintenanceFee;
public:
    CurrentAccount(double balance, double maintenanceFee)
        : Account(balance), maintenanceFee(maintenanceFee) {}

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Balance after fee deduction: " << balance << endl;
    }
};

int main() {
    int accountType;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    if (accountType < 1 || accountType > 2) {
        cout << "Invalid account type." << endl;
        return 0;
    }

    double balance;
    cout << "Enter Account Balance: ";
    cin >> balance;

    if (balance < 1000 || balance > 1000000) {
        cout << "Invalid balance. Balance must be between 1000 and 1,000,000." << endl;
        return 0;
    }

    if (accountType == 1) {
        double rate;
        int time;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        cout << "Enter Time (years): ";
        cin >> time;

        if (rate < 1 || rate > 15 || time < 1 || time > 10) {
            cout << "Invalid input for rate or time." << endl;
            return 0;
        }

        unique_ptr<Account> account = make_unique<SavingsAccount>(balance, rate, time);
        account->calculateInterest();
    } else if (accountType == 2) {
        double maintenanceFee;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> maintenanceFee;

        if (maintenanceFee < 50 || maintenanceFee > 500) {
            cout << "Invalid maintenance fee. Fee must be between 50 and 500." << endl;
            return 0;
        }

        unique_ptr<Account> account = make_unique<CurrentAccount>(balance, maintenanceFee);
        account->calculateInterest();
    }

    return 0;
}
