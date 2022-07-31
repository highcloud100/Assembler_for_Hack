#pragma once

#include <map>
#include <iostream>


class SymbolTable {
	std::map<std::string, int> map;
public:
	SymbolTable();
	void addEntry(std::string symbol, int address);
	bool contains(std::string symbol);
	int GetAddress(std::string symbol);
};