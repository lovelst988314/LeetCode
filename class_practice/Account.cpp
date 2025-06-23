#include "Account.h"
#include <iostream>

// 静态成员初始化
int Account::nextAccountNumber = 1000;
// nextAccountNumber 是一个 静态成员变量
// 它属于整个类，而不是类的某个对象
// 所有 Account 对象共享同一个 nextAccountNumber
// 必须在类外进行定义（不能仅在类内声明）


// 构造函数实现
Account::Account(std::string owner, double initialDeposit) 
    : balance(initialDeposit) {
    accountNumber = "ACC" + std::to_string(++nextAccountNumber);
    std::cout << "创建账户: " << accountNumber << "，所有者: " << owner << std::endl;
}

// 存款实现
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "存款成功: +" << amount 
                  << "，新余额: " << balance << std::endl;
    } else {
        std::cout << "存款失败: 金额必须大于 0" << std::endl;
    }
}

// 取款实现
bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        std::cout << "取款成功: -" << amount 
                  << "，新余额: " << balance << std::endl;
        return true;
    }
    std::cout << "取款失败: 余额不足或金额无效" << std::endl;
    return false;
}

// 获取账户信息实现
std::string Account::getAccountInfo() const {
    return "账户编号: " + accountNumber + 
           "，余额: " + std::to_string(balance);
}

// 静态方法实现
int Account::getTotalAccounts() {
    return nextAccountNumber - 1000;
}
 //1.是属于类本身而不是类的实例（对象）的函数。
 //2.不能访问非静态成员变量 
 //3.不能是虚函数 
 //4.可以访问静态成员变量和静态成员函数