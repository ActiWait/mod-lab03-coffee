// Copyright 2022 UNN-IASR

#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu.insert(menu.begin(), {"White coffee",
                                "Espresso",
                                "Latte",
                                "Americano"});
    prices.insert({{"White coffee", 30},
                    {"Espresso", 40},
                    {"Latte", 50},
                    {"Americano", 60}});
    state = STATES::OFF;
    selected_coffee;
}
int Automata::getCash() {
    return cash;
}
std::string Automata::getSelCoffee() {
    return selected_coffee;
}
void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        etMenu();
    }
}
void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
    }
}
void Automata::coin(int sum) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash+=sum;
        std::cout << "Now the account has " << cash << " coins" << "\n";
        state = STATES::ACCEPT;
    }
}
void Automata::etMenu() {
    std::cout << "Menu:" << "\n";
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << " : " << prices[menu[i]] << "\n";
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(std::string drink) {
    if (state == STATES::ACCEPT) {
        state = STATES::CHECK;
        selected_coffee = drink;
    }
}
bool Automata::check(std::string chosen_drink) {
    return prices[chosen_drink] <= cash;
}
void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        state = STATES::WAIT;
    }
}
void Automata::cook() {
    if (state == STATES::CHECK && check(selected_coffee)) {
        state = STATES::COOK;
        cash -= prices[selected_coffee];
        std::cout << "Cooking... " << "\n";
        for (int i = 1; i < 5; i++) {
            std::cout << 25*(i) << "%\n";
        }
        std::cout << "Your coffee is ready!" << "\n";
    }
}
void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        std::cout << "Your change: " << cash << "\n";
    }
}
