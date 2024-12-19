from abc import ABC, abstractmethod

class Account(ABC):
    def __init__(self, balance):
        self.balance = balance

    @abstractmethod
    def calculate_interest(self):
        pass

class SavingsAccount(Account):
    def __init__(self, balance, rate, time):
        super().__init__(balance)
        self.rate = rate
        self.time = time

    def calculate_interest(self):
        interest = (self.balance * self.rate * self.time) / 100
        print(f"Savings Account Interest: {interest}")

class CurrentAccount(Account):
    def __init__(self, balance, maintenance_fee):
        super().__init__(balance)
        self.maintenance_fee = maintenance_fee

    def calculate_interest(self):
        self.balance -= self.maintenance_fee
        print(f"Balance after fee deduction: {self.balance}")

def main():
    account_type = int(input("Enter Account Type (1 for Savings, 2 for Current): "))

    if account_type < 1 or account_type > 2:
        print("Invalid account type.")
        return

    balance = float(input("Enter Account Balance: "))

    if balance < 1000 or balance > 1000000:
        print("Invalid balance. Balance must be between 1000 and 1,000,000.")
        return

    if account_type == 1:
        rate = float(input("Enter Interest Rate (%): "))
        time = int(input("Enter Time (years): "))

        if rate < 1 or rate > 15 or time < 1 or time > 10:
            print("Invalid input for rate or time.")
            return

        account = SavingsAccount(balance, rate, time)
        account.calculate_interest()
    elif account_type == 2:
        maintenance_fee = float(input("Enter Monthly Maintenance Fee: "))

        if maintenance_fee < 50 or maintenance_fee > 500:
            print("Invalid maintenance fee. Fee must be between 50 and 500.")
            return

        account = CurrentAccount(balance, maintenance_fee)
        account.calculate_interest()

if __name__ == "__main__":
    main()