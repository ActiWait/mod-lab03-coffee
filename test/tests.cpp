// Copyright 2022 GHA Test Team

#include <gtest/gtest->h>
#include "Automata.h"

struct AutomataTest : public testing::Test {
    Automata *AC;
    void SetUp() { AC = new Automata(); }
    void TearDown() { delete AC; }
};

TEST_F(AutomataTest, test1) {
    int value = AC->getCash();
    EXPECT_EQ(value, 0);
}

TEST_F(AutomataTest, test2) {
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::OFF);
}

TEST_F(AutomataTest, test3) {
    AC->on();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::WAIT);
}

TEST_F(AutomataTest, test4) {
    AC->on();
    AC->coin(70);
    int value = AC->getCash();
    EXPECT_EQ(value, 70);
}

TEST_F(AutomataTest, test5) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    std::string value = AC->getSelCoffee();
    EXPECT_EQ(value, "Americano");
}

TEST_F(AutomataTest, test6) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    AC->cool();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::COOK);
}

TEST_F(AutomataTest, test7) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    AC->cool();
    int value = AC->getCoin();
    EXPECT_EQ(value, 10);
}

TEST_F(AutomataTest, test8) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    AC->cook();
    AC->finish();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::WAIT);
}

TEST_F(AutomataTest, test9) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    AC->cook();
    AC->finish();
    AC->off();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::OFF);
}

TEST_F(AutomataTest, test10) {
    AC->on();
    AC->coin(70);
    AC->cook();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::ACCEPT);
}

TEST_F(AutomataTest, test11) {
    AC->on();
    AC->coin(70);
    AC->off();
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::ACCEPT);
}

TEST_F(AutomataTest, test12) {
    AC->on();
    AC->coin(70);
    AC->choice("Americano");
    STATES value = AC->getState();
    EXPECT_EQ(value, STATES::CHECK);
}
