#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <memory>

class Account {
private:
    std::string accountNumber;   // 账户编号
    double balance;  // 余额
    static int nextAccountNumber; // 下一个账户编号

protected:
    // 保护方法：允许子类访问
    double getBalance() const { return balance; }  //返回余额

public:
    Account(std::string owner, double initialDeposit = 0.0);
    virtual ~Account() = default;  // 虚析构函数，确保正确释放子类资源

    // 账户操作
    void deposit(double amount);
    virtual bool withdraw(double amount);  // 虚函数，允许子类重写

    // 获取账户信息（虚函数，支持多态）
    virtual std::string getAccountInfo() const;

    // 静态方法：获取账户总数
    static int getTotalAccounts();
};

#endif 