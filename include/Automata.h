// Copyright 2022 UNN-IASR
#pragma once
#include <string>
#include <vector>


enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::vector <std::string> menu = { "Espresso", "Cappuccino",
                                      "Americano", "Macchiato",
                                      "Mocha", "Latte",
                                      "Flat White" };
    std::vector <int> prices = {120, 200, 180, 220, 210, 160, 250};
    STATES state;
    int num_of_chousen_drink;
    void check();
 public:
    Automata();
    Automata(std::vector <std::string> Menu, std::vector <int> Prices);
    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(int num_of_choice);
    void cook();
    void finish();
    void cancel();
};
