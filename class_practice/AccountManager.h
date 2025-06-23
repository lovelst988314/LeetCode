#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include "Account.h"
#include <vector>
#include <memory>

class AccountManager {
private:
    std::vector<std::unique_ptr<Account>> accounts;

public:
    // 添加账户
    void addAccount(std::unique_ptr<Account> account);

    // 显示所有账户信息
    void displayAllAccounts() const;

    // 处理利息（仅对储蓄账户生效）
    void processInterest();

    // 获取账户（用于测试）
    Account* getAccount(size_t index) const;
};

#endif // ACCOUNT_MANAGER_H