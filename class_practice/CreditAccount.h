#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
private:
    double creditLimit;  // 信用额度

public:
    CreditAccount(std::string owner, double initialDeposit = 0.0, 
                 double limit = 1000.0);
    
    // 重写取款方法（支持透支）
    bool withdraw(double amount) override;    // override 显示地指示这是一个重写基类方法

    // 重写账户信息获取方法
    std::string getAccountInfo() const override;
};

#endif // CREDIT_ACCOUNT_H