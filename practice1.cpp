#include "practice1.h"
#include <iostream>
using namespace std;

vector<string> PotionCraft::getPotions() {
    return inventory;
}

void PotionCraft::brewPotion(string name) {
    inventory.push_back(name);
}

string PotionCraft::consumePotion(string name) {
    for (int i = 0; i < inventory.size(); i++) {
        if (name == inventory[i]) {
            string consumed = inventory[i];
            inventory.erase(inventory.begin() + i);
            return consumed;
        }
    }
    return "";
}

void PotionCraft::brewMultiplePotions(vector<string> potions) {
    for (int i = 0; i < potions.size(); i++) {
        inventory.push_back(potions[i]);
    }
}

vector<string> PotionCraft::fillExternalContainer(vector<string>& container) {
    for (int i = 0; i < inventory.size(); i++) {
        container.push_back(inventory[i]);
    }
    return container;
}