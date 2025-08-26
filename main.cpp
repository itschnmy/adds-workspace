#include <iostream>
#include "practice1.h"

int main() {
    PotionCraft pc;

    // Test brewPotion
    pc.brewPotion("Healing");
    pc.brewPotion("Mana");
    pc.brewPotion("Stamina");

    std::cout << "Initial potions:\n";
    for (auto &p : pc.getPotions()) {
        std::cout << p << " ";
    }
    std::cout << "\n\n";

    // Test consumePotion
    std::string consumed = pc.consumePotion("Mana");
    std::cout << "Consumed potion: " << consumed << "\n";

    std::cout << "Potions after consuming Mana:\n";
    for (auto &p : pc.getPotions()) {
        std::cout << p << " ";
    }
    std::cout << "\n\n";

    // Test consumePotion for non-existent potion
    consumed = pc.consumePotion("Invisibility");
    std::cout << "Tried to consume Invisibility -> got: \"" << consumed << "\"\n\n";

    // Test brewMultiplePotions
    pc.brewMultiplePotions({"Fire", "Ice", "Poison"});
    std::cout << "Potions after brewing multiple:\n";
    for (auto &p : pc.getPotions()) {
        std::cout << p << " ";
    }
    std::cout << "\n\n";

    // Test fillExternalContainer
    std::vector<std::string> external;
    pc.fillExternalContainer(external);

    std::cout << "External container contents:\n";
    for (auto &p : external) {
        std::cout << p << " ";
    }
    std::cout << "\n\n";

    // Final check: inventory is unchanged
    std::cout << "Final inventory (unchanged after fillExternalContainer):\n";
    for (auto &p : pc.getPotions()) {
        std::cout << p << " ";
    }
    std::cout << "\n";

    return 0;
}