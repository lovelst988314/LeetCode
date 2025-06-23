#include "AccountManager.h"
#include "SavingsAccount.h"
#include <iostream>

void AccountManager::addAccount(std::unique_ptr<Account> account) {
    accounts.push_back(std::move(account));
    std::cout << "账户添加成功，当前账户总数: " << accounts.size() << std::endl;
}

void AccountManager::displayAllAccounts() const {
    std::cout << "\n===== 所有账户信息 =====" << std::endl;
    for (const auto& account : accounts) {
        std::cout << account->getAccountInfo() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

void AccountManager::processInterest() {
    std::cout << "\n===== 处理利息 =====" << std::endl;
    for (auto& account : accounts) {
        // 动态转换：尝试转为 SavingsAccount
        if (auto savings = dynamic_cast<SavingsAccount*>(account.get())) {
            savings->addInterest();
        } else {
            std::cout << "跳过非储蓄账户" << std::endl;
        }
    }
    std::cout << "====================" << std::endl;
}

Account* AccountManager::getAccount(size_t index) const {
    if (index < accounts.size()) {
        return accounts[index].get();
    }
    return nullptr;
}