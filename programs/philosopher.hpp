#ifndef __PHYLOSOPHER_HPP__
#define __PHYLOSOPHER_HPP__

#include "chopsticks.hpp"
#include <cerrno>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

class Philosopher {
protected:
	int ID;
	std::string getSignature() const;
	void takeChop(const std::string& phi_info, std::vector<Chopsticks>& chop, const int ID,
				  const bool leftFirst);
	void putChop(const std::string& phi_info, std::vector<Chopsticks>& chop, const int ID,
				 const bool leftFirst);

public:
	Philosopher() = delete;
	Philosopher(int ID) : ID{ ID } {}
	//定義第 ID 根筷子為 left_chop, ID+1 為 right_chop, 若 ID+1 overflow, 則第 0 為 right_chop
	void eat(std::vector<Chopsticks>& chop, const bool leftFirst = rand() % 2);
	void immediately_eat(std::vector<Chopsticks>& chop);
	void think() const;
};

#endif