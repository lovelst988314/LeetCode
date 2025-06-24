#include <iostream>
#include "AccountManager.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

int main() {
    system("chcp 65001"); // 设置控制台编码为 UTF-8
    
    AccountManager manager;

    // 创建不同类型的账户
    manager.addAccount(std::make_unique<SavingsAccount>("Alice", 1000.0, 0.03));
    manager.addAccount(std::make_unique<CreditAccount>("Bob", 500.0, 2000.0));
    manager.addAccount(std::make_unique<Account>("Charlie", 2000.0));

    // 显示所有账户
    manager.displayAllAccounts();

    // 处理利息（仅储蓄账户生效）
    manager.processInterest();
    manager.displayAllAccounts();

    // 测试信用账户透支
    auto credit = dynamic_cast<CreditAccount*>(manager.getAccount(1));
    if (credit) {
        std::cout << "\n尝试从信用账户透支 1500 元..." << std::endl;
        credit->withdraw(1500.0);  // 透支 1000
        manager.displayAllAccounts();
    }

    
    // 测试储蓄账户取款
    return 0;

}