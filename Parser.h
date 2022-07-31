#pragma once

#include <iostream>
#include <fstream>
#include <string>

enum COMMANDTYPE
{
	A_COMMNAD,
	C_COMMNAD,
	L_COMMNAD,
	COMMENT,
	ERROR
};

class Parser
{
	std::string path;
	std::string curCommand;
	std::ifstream ifs;


public:

	Parser();
	~Parser();
	bool hasMoreCommands();
	void advance();

	int commandType();

	void reset();

	std::string symbol();

	std::string dest();

	std::string comp();

	std::string jump();
	std::string PATH();
};



