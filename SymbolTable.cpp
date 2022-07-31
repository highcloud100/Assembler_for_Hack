#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	map.insert(std::pair<std::string, int>("SP", 0));
	map.insert(std::pair<std::string, int>("LCL", 1));
	map.insert(std::pair<std::string, int>("ARG", 2));
	map.insert(std::pair<std::string, int>("THIS", 3));
	map.insert(std::pair<std::string, int>("THAT", 4));
	map.insert(std::pair<std::string, int>("R0",0));
	map.insert(std::pair<std::string, int>("R1", 1));
	map.insert(std::pair<std::string, int>("R2", 2));
	map.insert(std::pair<std::string, int>("R3", 3));
	map.insert(std::pair<std::string, int>("R4", 4));
	map.insert(std::pair<std::string, int>("R5", 5));
	map.insert(std::pair<std::string, int>("R6", 6));
	map.insert(std::pair<std::string, int>("R7", 7));
	map.insert(std::pair<std::string, int>("R8", 8));
	map.insert(std::pair<std::string, int>("R9", 9));
	map.insert(std::pair<std::string, int>("R10", 10));
	map.insert(std::pair<std::string, int>("R11", 11));
	map.insert(std::pair<std::string, int>("R12", 12));
	map.insert(std::pair<std::string, int>("R13", 13));
	map.insert(std::pair<std::string, int>("R14", 14));
	map.insert(std::pair<std::string, int>("R15", 15));
	map.insert(std::pair<std::string, int>("SCREEN", 16384));
	map.insert(std::pair<std::string, int>("KBD", 24576));
}

void SymbolTable::addEntry(std::string symbol,int address) {
	map.insert(std::pair<std::string, int>(symbol, address));
}

bool SymbolTable::contains(std::string symbol)
{
	return map.find(symbol) != map.end();
}

int SymbolTable::GetAddress(std::string symbol)
{
	return map.find(symbol)->second;
}
