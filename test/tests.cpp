// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test_off, test1) {
	Automata a = Automata();
	STATES result = a.getState();
	EXPECT_EQ(OFF, result);
}

TEST(test_on, test2) {
	Automata a = Automata();
	a.on();
	STATES result = a.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(test_off, test3) {
	Automata a = Automata();
	a.on();
	a.off();
	STATES result = a.getState();
	EXPECT_EQ(OFF, result);
}

TEST(test_coin, test4) {
	Automata a = Automata();
	a.on();
	a.coin(100);
	STATES result = a.getState();
	EXPECT_EQ(ACCEPT, result);
}

TEST(test_coin, test5) {
	Automata a = Automata();
	a.on();
	a.coin(100);
	a.coin(100);
	STATES result = a.getState();
	EXPECT_EQ(ACCEPT, result);
}

TEST(test_cancel, test6) {
	Automata a = Automata();
	a.on();
	a.coin(100);
	a.cancel();
	STATES result = a.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(test_choice, test7) {
	Automata a = Automata();
	a.on();
	a.coin(200);
	a.choice(4);
	STATES result = a.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(test_choice, test8) {
	Automata a = Automata();
	a.on();
	a.coin(250);
	a.choice(4);
	STATES result = a.getState();
	EXPECT_EQ(CHECK, result);
}

TEST(test_cancle, test9) {
	Automata a = Automata();
	a.on();
	a.coin(250);
	a.choice(4);
	a.cancel();
	STATES result = a.getState();
	EXPECT_EQ(WAIT, result);
}

TEST(test_cook, test10) {
	Automata a = Automata();
	a.on();
	a.coin(250);
	a.choice(4);
	a.cook();
	STATES result = a.getState();
	EXPECT_EQ(COOK, result);
}

TEST(test_finish, test11) {
	Automata a = Automata();
	a.on();
	a.coin(250);
	a.choice(4);
	a.cook();
	a.finish();
	STATES result = a.getState();
	EXPECT_EQ(WAIT, result);
}
