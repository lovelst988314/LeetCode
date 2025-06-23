#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(std::string owner, double initialDeposit, double rate)
    : Account(owner, initialDeposit), interestRate(rate) {
    std::cout << "创建储蓄账户，利率: " << rate * 100 << "%" << std::endl;
}

void SavingsAccount::addInterest() {
    double interest = getBalance() * interestRate;
    deposit(interest);  // 调用基类的存款方法
    std::cout << "利息计算成功: +" << interest 
              << " (利率: " << interestRate * 100 << "%)" << std::endl;
}

std::string SavingsAccount::getAccountInfo() const {
    return Account::getAccountInfo() + 
           "，类型: 储蓄账户，利率: " + std::to_string(interestRate * 100) + "%";
}