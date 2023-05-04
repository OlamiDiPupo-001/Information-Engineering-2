
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(const std::string& accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    const std::string& getAccountNumber() const {
        return accountNumber;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accountNumber, double balance)
        : Account(accountNumber, balance) {}

    void withdraw(double amount) {
        // Charge a $1.50 transaction fee for each withdrawal
        double totalAmount = amount + 1.5;
        if (balance >= totalAmount) {
            balance -= totalAmount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added. New balance: " << balance << std::endl;
    }

    double getInterestRate() const {
        return interestRate;
    }
};

class Client {
private:
    std::string name;
    std::vector<std::unique_ptr<Account>> accounts;

public:
    Client(const std::string& name)
        : name(name) {}

    void addAccount(std::unique_ptr<Account> account) {
        accounts.push_back(std::move(account));
    }

    void printAccounts() const {
        std::cout << "Accounts for " << name << ":\n";
        for (const auto& account : accounts) {
            std::cout << account->getAccountNumber() << " - $" << account->getBalance() << "\n";
        }
    }

    const std::string& getName() const {
        return name;
    }
};

class Bank {
private:
    std::vector<std::unique_ptr<Client>> clients;

public:
    void addClient(std::unique_ptr<Client> client) {
        clients.push_back(std::move(client));
    }

    void printClients() const {
        std::cout << "Clients:\n";
        for (const auto& client : clients) {
            std::cout << client->getName() << "\n";
            client->printAccounts();
            std::cout << "\n";
        }
    }
};

int main() {
    // Create smart pointers to accounts
    std::unique_ptr<Account> account1 = std::make_unique<Account>("A10001", 5000);
    std::unique_ptr<SavingsAccount> account2 = std::make_unique<SavingsAccount>("S10001", 10000, 2.5);
    std::unique_ptr<CheckingAccount> account3 = std::make_unique<CheckingAccount>("C10001", 2000);

    // Deposit and withdraw from accounts
    account1->deposit(1000);
    account1->withdraw(2000);
    account2->deposit(500);
    account2->addInterest();
    account3->withdraw(500);

    // Create smart pointers to clients and add accounts to them
    std::unique_ptr<Client> client1 = std::make_unique<Client>("John Doe");
    client1->addAccount(std::move(account1));
    client1->addAccount(std::move(account2));

    std::unique_ptr<Client> client2 = std::make_unique<Client>("Jane Smith");
    client2->addAccount(std::move(account3));

    // Create vector of smart pointers to clients and add them to the bank
    std::vector<std::unique_ptr<Client>> clients;
    clients.push_back(std::move(client1));
    clients.push_back(std::move(client2));

    // Create bank and add clients to it
    Bank bank;
    for(auto& client : clients) {
        bank.addClient(std::move(client));
    }

    // Print bank clients and their accounts
    bank.printClients();

    return 0;
}




/*
#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0) : real_(real), imag_(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real_ - other.real_, imag_ - other.imag_);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real_ * other.real_ - imag_ * other.imag_,
                       imag_ * other.real_ + real_ * other.imag_);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real_ << (c.imag_ >= 0 ? " + " : " - ") << std::abs(c.imag_) << "i";
        return os;
    }

private:
    double real_;
    double imag_;
};

int main() {
    Complex a(1, 2);
    Complex b(3, 4);

    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
    std::cout << "a - b = " << d << std::endl;
    std::cout << "a * b = " << e << std::endl;

    return 0;
}
*/
