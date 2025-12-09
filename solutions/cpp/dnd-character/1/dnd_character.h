#pragma once

namespace dnd_character {
int ability ();
int modifier (const int n);

struct Character {
    int strength = ability();     // 1
    int dexterity = ability();    // 2
    int constitution = ability(); // 3
    int intelligence = ability(); // 4
    int wisdom = ability();       // 5
    int charisma = ability();     // 6
    int hitpoints = 10 + modifier(constitution);
};

}  // namespace dnd_character
