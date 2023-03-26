#include "Automata.h"
#include <iostream>

int main(){
    std::vector <std::string> Menu = {"Espresso", 
                                      "Cappuccino", "Americano", "Macchiato", 
                                      "Mocha", "Latte", "Flat White", "Raf"};
    std::vector <int> Prices = { 120, 200, 
                                180, 220, 210, 160, 250, 230 };
    Automata a = Automata(Menu, Prices);
    a.on();
    a.coin(100);
    a.coin(100);
    a.choice(4);
    a.coin(200);
    a.coin(50);
    a.choice(4);
    a.cook();
    a.finish();
    a.off();
}
