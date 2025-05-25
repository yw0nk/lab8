

class Account {
public:
    Account(double initial = 0.0);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;

private:
    double balance;
};

