#include <iostream>
#include <vector>
#include <map>
enum class STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
    private:
        int cash;
        std::vector<std::string> menu;
        std::map<std::string, int> prices;
        STATES state;
        std::string selected_coffee;

    public: 
        Automata();
        void on();
        void off();
        void coin(int sum);
        void etMenu();
        STATES getState();
        void choice(std::string drink);
        bool check(std::string chosen_drink);
        void cancel();
        void cook();
        void finish();
};