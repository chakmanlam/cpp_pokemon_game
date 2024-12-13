#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function declarations
void startGame(int& playerHP, const int maxHP, int& wildWins);
std::string chooseStarterPokemon();
void exploreWorld(const std::string& playerName, const std::string& starterPokemon, const std::string& rivalName, int& playerHP, const int maxHP, int& wildWins);
void rivalBattle(const std::string& playerName, const std::string& starterPokemon, const std::string& rivalName, int& playerHP);
void pokemonCenter(int& playerHP, const int maxHP);
bool handleWildBattle(const std::string& starterPokemon, int& playerHP);
void postBattleOptions(int& playerHP, const int maxHP);
bool handleRivalBattleTurn(const std::string& attackerName, const std::string& attackerPokemon, int& attackerHP, 
                           const std::string& defenderName, const std::string& defenderPokemon, int& defenderHP, 
                           const std::string& playerChoice);

int main() {
    std::srand(std::time(0));

    const int maxHP = 20; // Maximum HP for the player's Pokémon
    int playerHP = maxHP; // Current HP starts at maxHP
    int wildWins = 0; // Track the number of wild Pokémon wins

    startGame(playerHP, maxHP, wildWins);
    return 0;
}

void startGame(int& playerHP, const int maxHP, int& wildWins) {
    std::string playerName, rivalName;

    std::cout << "\nOak: Hello there! Welcome to the world of POKEMON!\n";
    std::cout << "\n      My name is OAK!\n";
    std::cout << "\n      People call me the POKEMON PROF!\n";
    std::cout << "\n      This world is inhabited by creatures called POKEMON!\n";
    std::cout << "\n      For some people, POKEMON are pets. Others use them for fights.\n";
    std::cout << "\n      Myself...I study POKEMON as a profession.\n";
    std::cout << "\n      First, what is your name?\n\n";
    std::getline(std::cin, playerName);

    std::cout << "\nOak: Right! So your name is " << playerName << "!\n";
    std::cout << "\n      This is my grandson.\n";
    std::cout << "      He's been your rival since you were a baby. ...Erm, what is his name again?\n\n";
    std::getline(std::cin, rivalName);

    std::cout << "\nOak: That's right! I remember now! His name is " << rivalName << "!\n";
    std::cout << "\n      Your very own POKEMON legend is about to unfold!\n";
    std::cout << "      A world of dreams and adventures with POKEMON awaits! Let's go!\n";

    std::string starterPokemon = chooseStarterPokemon();
    std::cout << "\nOak: You chose " << starterPokemon << "! A great choice for a new trainer like you, " << playerName << "!\n";

    exploreWorld(playerName, starterPokemon, rivalName, playerHP, maxHP, wildWins);
}

std::string chooseStarterPokemon() {
    std::string choice;
    std::cout << "\nOak: Now, choose your first Pokémon!\n\n";
    std::cout << "      Enter 1 for Charmander (Fire Type)\n";
    std::cout << "      Enter 2 for Bulbasaur (Grass Type)\n";
    std::cout << "      Enter 3 for Squirtle (Water Type)\n";

    while (true) {
        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") return "Charmander";
        else if (choice == "2") return "Bulbasaur";
        else if (choice == "3") return "Squirtle";
        else std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
    }
}

void exploreWorld(const std::string& playerName, const std::string& starterPokemon, const std::string& rivalName, int& playerHP, const int maxHP, int& wildWins) {
    std::string action;
    bool exitGame = false;

    do {
        std::cout << "\nYou are on your Pokémon journey, " << playerName << ". What would you like to do?\n\n";
        std::cout << "      1. Explore the tall grass\n";
        std::cout << "      2. Visit a Pokémon Center\n";
        std::cout << "      3. Exit the game\n";
        std::cout << "\nYour choice: ";
        std::cin >> action;

        if (action == "1") {
            if (handleWildBattle(starterPokemon, playerHP)) {
                wildWins++; // Increment win counter
                if (wildWins >= 3) { // Trigger rival battle after 3 wins
                    std::cout << "\nYou hear footsteps behind you...\n";
                    rivalBattle(playerName, starterPokemon, rivalName, playerHP);
                    std::cout << "\nThe Pokémon adventure has come to an end. Thank you for playing!\n";
                    exit(0); // Terminate the game completely
                }
                postBattleOptions(playerHP, maxHP); // Handle post-battle options
            }
        } else if (action == "2") {
            pokemonCenter(playerHP, maxHP);
        } else if (action == "3") {
            std::cout << "\nThank you for playing the Pokémon adventure, " << playerName << "!\n";
            exitGame = true;
        } else {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (!exitGame);
}

void pokemonCenter(int& playerHP, const int maxHP) {
    std::cout << "\nYou enter the Pokémon Center. Nurse Joy greets you warmly.\n";
    bool exitCenter = false;

    while (!exitCenter) {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "      1. Heal your Pokémon\n";
        std::cout << "      2. Visit the PokéMart (Coming Soon...)\n";
        std::cout << "      3. Talk to Nurse Joy (Coming Soon...)\n";
        std::cout << "      4. Exit the Pokémon Center\n";
        std::cout << "Your choice: ";
        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "\nNurse Joy heals your Pokémon to full health.\n";
            playerHP = maxHP;
            std::cout << "Your Pokémon's HP is now fully restored: " << playerHP << "/" << maxHP << "\n";
        } else if (choice == "2") {
            std::cout << "\nThe PokéMart is currently under development. Stay tuned for updates!\n";
        } else if (choice == "3") {
            std::cout << "\nTalking to Nurse Joy is currently under development. Stay tuned for updates!\n";
        } else if (choice == "4") {
            std::cout << "\nYou leave the Pokémon Center feeling refreshed.\n";
            exitCenter = true;
        } else {
            std::cout << "\nInvalid choice. Please select a valid option.\n";
        }
    }
}

bool handleWildBattle(const std::string& starterPokemon, int& playerHP) {
    int wildHP = 15;
    std::string wildPokemon;
    int randomPokemon = std::rand() % 3;

    switch (randomPokemon) {
        case 0: wildPokemon = "Pidgey"; break;
        case 1: wildPokemon = "Rattata"; break;
        case 2: wildPokemon = "Zubat"; break;
    }

    std::cout << "\nA wild " << wildPokemon << " appears!\n";
    std::cout << "Do you want to fight it? (yes/no): ";
    std::string fightChoice;
    std::cin >> fightChoice;

    if (fightChoice != "yes") {
        std::cout << "\nYou decided to avoid the wild " << wildPokemon << ".\n";
        return false;
    }

    while (playerHP > 0 && wildHP > 0) {
        std::cout << "\nChoose your move:\n";
        std::cout << "      1. Tackle\n";
        std::cout << "      2. Defend\n";
        std::cout << "Your choice: ";
        std::string moveChoice;
        std::cin >> moveChoice;

        if (moveChoice == "1") {
            int playerAttack = std::rand() % 10 + 5; // Random damage (5-15)
            std::cout << "\n" << starterPokemon << " used Tackle! It dealt " << playerAttack << " damage!\n";
            wildHP -= playerAttack;

            if (wildHP <= 0) {
                std::cout << "The wild " << wildPokemon << " fainted!\n";
                std::cout << "You won the battle!\n";
                return true; // Battle won
            }
        } else if (moveChoice == "2") {
            std::cout << "\nYou chose to defend! Let's see how effective it is...\n";

            int wildAttack = std::rand() % 10 + 5;
            int defenseChance = std::rand() % 100;

            if (defenseChance < 33) {
                std::cout << "\nDefense successful! You completely blocked the attack!\n";
                wildAttack = 0;
            } else if (defenseChance < 66) {
                std::cout << "\nDefense partially successful! Damage is reduced by half.\n";
                wildAttack /= 2;
            } else {
                std::cout << "\nDefense failed! You take full damage.\n";
            }

            std::cout << "The wild " << wildPokemon << " used Tackle! It dealt " << wildAttack << " damage!\n";
            playerHP -= wildAttack;

        } else {
            std::cout << "\nInvalid move! The wild " << wildPokemon << " attacks while you're distracted!\n";
            int wildAttack = std::rand() % 10 + 5;
            std::cout << "The wild " << wildPokemon << " used Tackle! It dealt " << wildAttack << " damage!\n";
            playerHP -= wildAttack;
        }

        if (playerHP <= 0) {
            std::cout << "\n" << starterPokemon << " fainted!\n";
            std::cout << "You were defeated by the wild " << wildPokemon << "!\n";
            std::cout << "Game Over! Better luck next time.\n";
            exit(0); // Terminate the game
        }

        // Display HP
        std::cout << "\n" << starterPokemon << "'s HP: " << playerHP << "\n";
        std::cout << wildPokemon << "'s HP: " << wildHP << "\n";
    }
    return false; // If loop exits without a win
}

void postBattleOptions(int& playerHP, const int maxHP) {
    bool exitPostBattle = false;

    while (!exitPostBattle) {
        std::cout << "\nWhat would you like to do next?\n";
        std::cout << "      1. Continue exploring\n";
        std::cout << "      2. Visit Pokémon Center\n";
        std::cout << "      3. Exit the game\n";
        std::cout << "Your choice: ";
        std::string postChoice;
        std::cin >> postChoice;

        if (postChoice == "1") {
            std::cout << "\nYou decide to continue exploring.\n";
            exitPostBattle = true;
        } else if (postChoice == "2") {
            pokemonCenter(playerHP, maxHP);
            exitPostBattle = true;
        } else if (postChoice == "3") {
            std::cout << "\nThank you for playing the Pokémon adventure!\n";
            exit(0); // Exit the game
        } else {
            std::cout << "\nInvalid choice. Please select a valid option.\n";
        }
    }
}

void rivalBattle(const std::string& playerName, const std::string& starterPokemon, const std::string& rivalName, int& playerHP) {
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "\n" << rivalName << ": Hey, " << playerName << "! I've been waiting for you. Let's battle!\n\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";
    std::cout << "==================================\n";

     // Determine rival's Pokémon
    std::string rivalPokemon;
    if (starterPokemon == "Charmander") {
        rivalPokemon = "Squirtle"; // Counter to Charmander
    } else if (starterPokemon == "Bulbasaur") {
        rivalPokemon = "Charmander"; // Counter to Bulbasaur
    } else {
        rivalPokemon = "Bulbasaur"; // Counter to Squirtle
    }
    std::cout << "==================================\n";
    std::cout << rivalName << " sends out " << rivalPokemon << "!\n";
    std::cout << "==================================\n";
    std::cout << playerName << " sends out " << starterPokemon << "!\n";
    std::cout << "==================================\n";

    int rivalHP = 25; // Rival's Pokémon HP

    // Battle loop
    while (playerHP > 0 && rivalHP > 0) {
        std::cout << "\nChoose your move:\n";
        std::cout << "      1. Tackle\n";
        std::cout << "      2. Defend\n";
        std::cout << "Your choice: ";
        std::string playerChoice;
        std::cin >> playerChoice;

        // Call handleRivalBattleTurn for each turn
        if (handleRivalBattleTurn(playerName, starterPokemon, playerHP, rivalName, rivalPokemon, rivalHP, playerChoice)) {
            break; // End the battle if someone faints
        }

        // Display HP after each turn
        std::cout << "\n" << starterPokemon << "'s HP: " << playerHP << "\n";
        std::cout << rivalPokemon << "'s HP: " << rivalHP << "\n";
        }

        // Determine winner
        if (playerHP > 0) {
            std::cout << "\nYou defeated " << rivalName << "!\n";
            std::cout << "Congratulations on becoming a Pokémon Master!\n";
        } else {
            std::cout << "\n" << rivalName << " defeated you!\n";
            std::cout << "Game Over! Better luck next time, " << playerName << "!\n";
            exit(0); // End the game
        }
}

bool handleRivalBattleTurn(const std::string& playerName, const std::string& starterPokemon, int& playerHP, 
                           const std::string& rivalName, const std::string& rivalPokemon, int& rivalHP, 
                           const std::string& playerChoice) {
    if (playerChoice == "1") {
        // Attack move
        int critChance = std::rand() % 100; // 0-99 (10% chance for critical hit)
        int playerAttack = std::rand() % 10 + 5; // Random damage (5-15)
        
        if (critChance < 20) {
            playerAttack *= 2; // Double the damage
            std::cout << "\nCritical hit! " << starterPokemon << " used Tackle! It dealt " << playerAttack << " damage to " << rivalPokemon << "!\n";
        } else {
            std::cout << "\n" << starterPokemon << " used Tackle! It dealt " << playerAttack << " damage to " << rivalPokemon << "!\n";
        }

        rivalHP -= playerAttack;

        // Check if the defender's Pokémon fainted
        if (rivalHP <= 0) {
            std::cout << "\n" << rivalPokemon << " fainted!\n";
            return true; // Battle ends
        }
    } else if (playerChoice == "2") {
        // Defend move
        std::cout << "\nYou chose to defend! Let's see how effective it is...\n";

        int rivalAttack = std::rand() % 10 + 5;
        int defenseChance = std::rand() % 100;

        if (defenseChance < 33) {
            std::cout << "\nDefense successful! You completely blocked the attack!\n";
            rivalAttack = 0;
        } else if (defenseChance < 66) {
            std::cout << "\nDefense partially successful! Damage is reduced by half.\n";
            rivalAttack /= 2;
        } else {
            std::cout << "\nDefense failed! You take full damage.\n";
        }

        std::cout << "It dealt " << rivalAttack << " damage to " << starterPokemon << "!\n";
        playerHP -= rivalAttack;
    } else {
        // Invalid move
        std::cout << "\nInvalid move! " << rivalName << "'s " << rivalPokemon << " attacks while you're distracted!\n";
        
        int rivalAttack = std::rand() % 10 + 5;
        std::cout << "The wild " << rivalPokemon << " used Tackle! It dealt " << rivalAttack << " damage!\n";
        playerHP -= rivalAttack;
    }

    // Check if the attacker's Pokémon fainted
    if (playerHP <= 0) {
        std::cout << "\n" << starterPokemon << " fainted!\n";
        return true; // Battle ends
    }

    return false; // Continue the battle
}

