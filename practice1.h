#ifndef PRACTICE1_H
#define PRACTICE1_H
#include <vector>
#include <string>

class PotionCraft {
private:
    std::vector<std::string> inventory;
public:
    std::vector<std::string> getPotions();
    void brewPotion(std::string name);
    std::string consumePotion(std::string name);
    void brewMultiplePotions(std::vector<std::string> potions);
    std::vector<std::string> fillExternalContainer(std::vector<std::string>& container);
};
#endif