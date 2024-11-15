#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>

using namespace std;

void combatHUD();
void HUD();
void CreateMonster();
void Combat();
void Moving();
void Shop();

// Игрок
string name = " ", race = " ", sex = " ";
int level = 1, xp = 0, health, totalHealth = 100, maxHealth = 100, nextLevel = 75, gold = 50;
int monsterhp = 0, monsterXp = 0, monsterLevel = 0;
int swordDamage = 5;
int potionCount = 0;

// Монстр
string monsterName[] = { "Dragon", "Skeleton", "Lich", "Werewolf", "Demon", "Zombie", "Witch" };
int amountOfMonsters = 6;
string currentMonster = " ";

void LevelUp() {
    if (xp >= nextLevel) {
        level++;
        xp -= nextLevel;
        nextLevel += 50 * level;
        maxHealth += 20;
        totalHealth = maxHealth; 
        gold += 20;
        cout << "Congratulations! You've reached level " << level << "!\n";
        Sleep(1000);
    }
}

void HUD() {
    Sleep(500);
    system("cls");
    cout << "Name: " << name << "       Health: " << totalHealth << "/" << maxHealth
        << "\nRace: " << race
        << "\nSex: " << sex
        << "\nLevel: " << level
        << "\nExperience: " << xp
        << "\nXP to Next Level: " << nextLevel - xp
        << "\nGold: " << gold
        << "\nPotions: " << potionCount
        << "\nSword Damage: " << swordDamage << endl;
}

void CreateMonster() {
    int monsterIndex = rand() % amountOfMonsters;
    currentMonster = monsterName[monsterIndex];
    monsterLevel = level + rand() % 3;
    monsterhp = monsterLevel * 20 + (rand() % 10);
    monsterXp = monsterhp / 2;
}

void CombatHUD() {
    Sleep(500);
    system("cls");
    cout << "Name: " << name << "            Monster: " << currentMonster
        << "\nHealth: " << totalHealth << "/" << maxHealth << "            Monster Health: " << monsterhp
        << "\nLevel: " << level << "            Monster Level: " << monsterLevel << endl;
}

void Combat() {
    CombatHUD();
    int playerAttack;
    int playerDamage = swordDamage + (level * 2);
    int monsterAttack = 3 + (monsterLevel * 2);

    while (totalHealth > 0 && monsterhp > 0) {
        cout << "\n1. Attack\n2. Block\n3. Run\n4. Use Potion\n\n";
        cin >> playerAttack;

        if (playerAttack == 1) {
            cout << "ATTACK! You dealt " << playerDamage << " damage to the " << currentMonster << endl;
            monsterhp -= playerDamage;

            if (monsterhp > 0) {
                totalHealth -= monsterAttack;
                cout << currentMonster << " attacks! You take " << monsterAttack << " damage." << endl;
                if (totalHealth < 0) totalHealth = 0;
            }
            CombatHUD();
        }
        else if (playerAttack == 2) {
            int blockChance = rand() % 100;
            if (blockChance >= 50) {
                cout << "You successfully blocked the attack and restored some health!\n";
                int heal = 10 + (level * 2);
                totalHealth = min(totalHealth + heal, maxHealth);
            }
            else {
                cout << "Block failed! You took " << monsterAttack << " damage.\n";
                totalHealth -= monsterAttack;
            }
        }
        else if (playerAttack == 3) {
            if (rand() % 100 >= 50) {
                cout << "You successfully escaped!\n";
                return;
            }
            else {
                cout << "Escape failed! " << currentMonster << " attacks and deals " << monsterAttack << " damage.\n";
                totalHealth -= monsterAttack;
            }
        }
        else if (playerAttack == 4) {
            if (potionCount > 0) {
                int healAmount = 30 + (level * 5);
                totalHealth = min(totalHealth + healAmount, maxHealth);
                potionCount--;
                cout << "You used a potion and restored " << healAmount << " health!\n";
            }
            else {
                cout << "You don't have any potions left!\n";
            }
        }
        else {
            cout << "Invalid choice! Try again.\n";
            continue;
        }
    }

    if (totalHealth > 0) {
        cout << "You defeated the " << currentMonster << " and earned " << monsterXp << " XP and 10 gold!\n";
        xp += monsterXp;
        gold += 10;
        LevelUp();
    }
    else {
        cout << "You were defeated...\n";
        exit(0);
    }
}

void Shop() {
    int choice;
    cout << "\nWelcome to the shop!\n";
    cout << "1. Buy Potion (15 gold) - Restores health\n";
    cout << "2. Buy Sword Upgrade (30 gold) - Increases damage\n";
    cout << "3. Exit Shop\n\n";
    cin >> choice;

    if (choice == 1) {
        if (gold >= 15) {
            potionCount++;
            gold -= 15;
            cout << "You bought a potion!\n";
        }
        else {
            cout << "Not enough gold!\n";
        }
    }
    else if (choice == 2) {
        if (gold >= 30) {
            swordDamage += 5;
            gold -= 30;
            cout << "You bought a sword upgrade! New sword damage: " << swordDamage << endl;
        }
        else {
            cout << "Not enough gold!\n";
        }
    }
    else if (choice == 3) {
        cout << "Exiting shop...\n";
    }
    else {
        cout << "Invalid choice, try again.\n";
        Shop();
    }
}

void Moving() {
    int choice;
    cout << "\n1. Move Left\n2. Rest\n3. Move Right\n4. Visit Shop\n\n";
    cin >> choice;

    if (choice == 1 || choice == 3) {
        cout << "Moving...\n";
        if (rand() % 100 >= 50) {
            CreateMonster();
            cout << "A " << currentMonster << " appears! Prepare for battle!\n";
            Sleep(1000);
            Combat();
        }
        else {
            cout << "The path is clear.\n";
        }
    }
    else if (choice == 2) {
        cout << "You rest and restore health.\n";
        int healAmount = 20 + (level * 5);
        totalHealth = min(totalHealth + healAmount, maxHealth);
        cout << "Restored " << healAmount << " health.\n";
    }
    else if (choice == 4) {
        Shop();
    }
    else {
        cout << "Invalid choice! Try again.\n";
    }
    HUD();
    Moving();
}

int main() {
    // Character creation
    cout << "Enter character name: ";
    cin >> name;

    cout << "Enter character race: ";
    cin >> race;

    cout << "Enter character gender: ";
    cin >> sex;

    cout << "Creating character...\n";
    Sleep(1000);
    HUD();
    Moving();

    return 0;
}
