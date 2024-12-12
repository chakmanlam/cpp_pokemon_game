#include <iostream>
#include <string>

void startGame();
std::string chooseStarterPokemon();

int main() {
    startGame();
    return 0;
}

void startGame() {
    std::string playerName, rivalName;

    std::cout << "\nOak: Hello there! Welcome to the world of POKEMON!\n";
    std::cout << "\n      My name is OAK!\n";
    std::cout << "\n      People call me the POKEMON PROF!\n";
    std::cout << "\n      This world is inhabited by creatures called POKEMON!\n";
    std::cout << "\n      For some people, POKEMON are pets. Others use them for fights.\n";
    std::cout << "\n      Myself...I study POKEMON as a profession.\n";
    std::cout << "\n      First, what is your name?\n";
    std::getline(std::cin, playerName);

    std::cout << "\nOak: Right! So your name is " << playerName << "!\n";
    std::cout << "\n      This is my grandson.\n";
    std::cout << "      He's been your rival since you were a baby. ...Erm, what is his name again?\n";
    std::getline(std::cin, rivalName);

    std::cout << "\nOak: That's right! I remember now! His name is " << rivalName << "!\n";
    std::cout << "\n      Your very own POKEMON legend is about to unfold!\n";
    std::cout << "      A world of dreams and adventures with POKEMON awaits! Let's go!\n";

    std::string starterPokemon = chooseStarterPokemon();
    std::cout << "\nOak: You chose " << starterPokemon << "! A great choice for a new trainer like you, " << playerName << "!\n";
}

std::string chooseStarterPokemon() {
    std::string choice;
    std::cout << "\nOak: Now, choose your first Pokémon!\n";
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
