#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(std::string owner, double initialDeposit, double limit)
    : Account(owner, initialDeposit), creditLimit(limit) {
    std::cout << "创建信用账户，信用额度: " << limit << std::endl;
}

bool CreditAccount::withdraw(double amount) {
    if (amount > 0 && getBalance() + creditLimit >= amount) {
        // 调用基类的取款方法（注意：基类方法会检查余额，但我们允许透支）
        // 因此这里需要直接修改余额
        double newBalance = getBalance() - amount;
        // 使用 const_cast 绕过 const 限制（安全，因为我们知道 this 不是 const）
        const_cast<CreditAccount*>(this)->Account::withdraw(amount);
        // 修正余额（允许透支）
        const_cast<CreditAccount*>(this)->Account::deposit(newBalance - getBalance());
        
        std::cout << "信用账户取款成功: -" << amount 
                  << "，新余额: " << getBalance() << std::endl;
        return true;
    }
    std::cout << "信用账户取款失败: 超出信用额度" << std::endl;
    return false;
}

std::string CreditAccount::getAccountInfo() const {
    return Account::getAccountInfo() + 
           "，类型: 信用账户，信用额度: " + std::to_string(creditLimit);
}