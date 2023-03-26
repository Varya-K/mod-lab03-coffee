// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
    num_of_chousen_drink = -1;
}

Automata::Automata(std::vector <std::string> Menu,
                   std::vector <int> Prices) : Automata() {
    if (Menu.size() == Prices.size()) {
        menu = Menu;
        prices = Prices;
    } else {
        std::cout << "Incorrect data! The basic menu has been installed."
                  << std::endl;
        Automata();
    }
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The coffee machine is ready to work." << std::endl;
        getMenu();
    } else {
        std::cout << "The coffee machine is already working." << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "The coffee machine turns off." << std::endl;
    } else if (state == OFF) {
        std::cout << "The coffe machine is already turned off." << std::endl;
    } else {
        std::cout << "The coffe machine can't be turned off at the moment."
                  << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        if (money > 0) {
            state = ACCEPT;
            cash += money;
            std::cout << "Money accepted. Your account: "
                      << cash <<" rub." << std::endl;
        } else {
            std::cout << "Incorrect value." << std::endl;
        }
    } else {
        std::cout << "The opperation can't be done." << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Menu: " << std::endl;
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i + 1 << ". " << menu[i] << " - "
                  << prices[i] << " rub." << std::endl;
    }
}
STATES Automata::getState() {
    return state;
}

void Automata::choice(int num_of_choice) {
    if (state == ACCEPT) {
        if (num_of_choice > menu.size() || num_of_choice <= 0) {
            std::cout << "Wrong number!";
        } else {
            state = CHECK;
            num_of_chousen_drink = num_of_choice-1;
            std::cout << "You have chosen " << menu[num_of_choice-1]
                      << " for " << prices[num_of_choice - 1]
                      << " rub." << std::endl;
            check();
        }
    } else {
        std::cout << "The opperation can't be done." << std::endl;
    }
}

void Automata::check() {
    if (state == CHECK) {
        if (prices[num_of_chousen_drink] <= cash) {
            std::cout << "You have deposited enough money,"
                      << "the drink can be cooked." << std::endl;
        } else {
            std::cout << "You haven't deposited enough money." << std::endl;
            cancel();
        }
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[num_of_chousen_drink];
        std::cout << "Please, take your drink!" << std::endl;
    } else {
        std::cout << "The opperation can't be done." << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "The operation was canceled.";
        if (cash > 0) std::cout << " Please, take your cash: "
                      << cash << " rub." << std::endl;
        cash = 0;
        num_of_chousen_drink = -1;
        state = WAIT;
    } else {
        std::cout << "The opperation can't be done." << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        if (cash > 0) std::cout << "Please, take the change: "
                        << cash << " rub." << std::endl;
        cash = 0;
        num_of_chousen_drink = -1;
        std::cout << "Have a good day! Come back again!" << std::endl;
    } else {
        std::cout << "The opperation can't be done." << std::endl;
    }
}
