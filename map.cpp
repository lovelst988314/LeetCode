#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<int, std::string> orderedMap;
    std::unordered_map<int, std::string> unorderedMap;

    orderedMap[1] = "one";
    orderedMap[2] = "two";
    orderedMap[3] = "three";

    unorderedMap[1] = "one";
    unorderedMap[2] = "two";
    unorderedMap[3] = "three";

    std::cout << "Ordered Map:" << std::endl;
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Unordered Map:" << std::endl;
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}