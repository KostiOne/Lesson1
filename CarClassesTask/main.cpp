#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include "Game.h"
#include "Player.h"
#include "Store.h"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initializeStores(Store& retroStore, Store& modernStore) {
    retroStore.addGame(Game("Super Mario Bros. 3", 89.99, "Platformer", 1988));
    retroStore.addGame(Game("Final Fantasy VII", 149.99, "RPG", 1997, true)); 
    retroStore.addGame(Game("Street Fighter II", 79.99, "Fighting", 1991));
    retroStore.addGame(Game("Sonic the Hedgehog", 69.99, "Platformer", 1991));
    retroStore.addGame(Game("The Legend of Zelda: Ocarina of Time", 199.99, "Action RPG", 1998, true));
    retroStore.addGame(Game("Chrono Trigger", 299.99, "RPG", 1995, true));

    modernStore.addGame(Game("Cyberpunk 2077", 59.99, "RPG", 2020));
    modernStore.addGame(Game("Elden Ring", 69.99, "Action RPG", 2022));
    modernStore.addGame(Game("God of War Ragnarök", 69.99, "Action Adventure", 2022));
    modernStore.addGame(Game("Starfield", 69.99, "RPG", 2023));
    modernStore.addGame(Game("Spider-Man 2", 69.99, "Action Adventure", 2023));
    modernStore.addGame(Game("Baldur's Gate 3", 59.99, "RPG", 2023));
}

int displayMainMenu(const Player& player) {
    clearConsole();
    std::cout << "\n=== Welcome to Game Shopping Plaza ===";
    std::cout << "\nYour Balance: $" << std::fixed << std::setprecision(2) << player.getMoney() << std::endl;
    std::cout << "\n1. Visit Retro Game Haven (Specializing in Classic Games)";
    std::cout << "\n2. Visit Next Gen Games (Modern Releases)";
    std::cout << "\n3. View My Collection";
    std::cout << "\n4. Exit";
    std::cout << "\nEnter your choice (1-4): ";

    int choice;
    std::cin >> choice;
    return choice;
}

void handleStoreVisit(Store& store, Player& player) {
    clearConsole();

    std::cout << "\n*** Welcome to " << store.getName() << " ***";
    if (store.getName() == "Retro Game Haven") {
        std::cout << "\nHome to rare classics and collector's editions!";
    }
    else {
        std::cout << "\nYour destination for the latest releases!";
    }

    store.displayGames();

    std::cout << "\nEnter the ID of the game you want to buy (0 to cancel): ";
    int gameId;
    std::cin >> gameId;

    if (gameId == 0) return;

    Game* selectedGame = store.getGame(gameId);
    if (selectedGame) {
        if (player.buyGame(*selectedGame)) {
            std::cout << "\nSuccessfully purchased " << selectedGame->getDescription() << "!\n";
            if (selectedGame->isCollectors()) {
                std::cout << "Congratulations on acquiring this collector's edition!\n";
            }
        }
        else {
            std::cout << "\nNot enough money to buy this game!\n";
        }
    }
    else {
        std::cout << "\nInvalid game ID!\n";
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void handleInventory(const Player& player) {
    clearConsole();
    player.displayInventory();

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    Store retroStore("Retro Game Haven");
    Store modernStore("Next Gen Games");

    initializeStores(retroStore, modernStore);

    Player player(500.00);

    while (true) {
        int choice = displayMainMenu(player);

        if (choice == 4) {
            break;
        }

        switch (choice) {
        case 1:
            handleStoreVisit(retroStore, player);
            break;
        case 2:
            handleStoreVisit(modernStore, player);
            break;
        case 3:
            handleInventory(player);
            break;
        default:
            std::cout << "\nInvalid choice!\n";
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    }

    clearConsole();
    std::cout << "\nThanks for shopping! Final collection:\n";
    player.displayInventory();

    return 0;
}
