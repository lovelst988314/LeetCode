#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;   // 利率

public:
    SavingsAccount(std::string owner, double initialDeposit = 0.0, double rate = 0.02);
    
    // 计算并添加利息
    void addInterest();

    // 重写账户信息获取方法
    std::string getAccountInfo() const override;
};

#endif // SAVINGS_ACCOUNT_H