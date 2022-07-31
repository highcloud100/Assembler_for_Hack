#pragma once

#include "Parser.h"
#include "SymbolTable.h"
#include <bitset>

bool isINT(std::string v);

class Assembler
{
	Parser P;
	SymbolTable table;

	std::ofstream ofs;

	void Pass1();

	void Pass2();

public:
	Assembler();
	~Assembler();
};

