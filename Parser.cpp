#include "Parser.h"

Parser::Parser() {
	std::cin >> path;
	std::cout << path << "\n";
	ifs.open(path);
	std::cout << ifs.is_open() << "\n";
	if (!ifs) {
		std::cerr << "read error\n";
		return;
	}
}

Parser::~Parser()
{	
	ifs.close();
}

bool Parser::hasMoreCommands()
{	
	return ifs.peek() != EOF;
}

void Parser::advance()
{
	if(hasMoreCommands())
		std::getline(ifs, curCommand);
	curCommand.erase(remove(curCommand.begin(), curCommand.end(), ' '), curCommand.end());
	curCommand = curCommand.substr(0, curCommand.find('/'));
	//std::cout << curCommand << "\n";
}

int Parser::commandType()
{

	if (curCommand[0] == '@') {
		return A_COMMNAD;
	}	
	else if (curCommand[0] == '(' && curCommand[curCommand.size() - 1] == ')') {
		return L_COMMNAD;
	}
	else if (curCommand[0] == '/') {
		return COMMENT;
	}
	else if(comp() == "error") {
		return ERROR;
	}
	return C_COMMNAD;
}

void Parser::reset()
{
	if(ifs)
		ifs.seekg(0, std::ios::beg);
}

std::string Parser::symbol()
{
	std::string var;
	if (commandType() == A_COMMNAD) {
		var = curCommand.substr(1);
	}
	else if (commandType() == L_COMMNAD) {
		var = curCommand.substr(1, curCommand.size() - 2);
	}
	else {
		std::cerr << "symbol() error\n";
		return "";
	}
	return var;
}

std::string Parser::dest()
{
	if (commandType() != C_COMMNAD) return "error";

	int pos = curCommand.find('=');

	if (pos == std::string::npos) {
		return "000";
	}
	
	std::string dest = curCommand.substr(0,pos);

	if (dest == "M") {
		return "001";
	}
	else if (dest == "D") {
		return "010";
	}
	else if (dest == "MD") {
		return "011";
	}
	else if (dest == "A") {
		return "100";
	}
	else if (dest == "AM") {
		return "101";
	}
	else if (dest == "AD") {
		return "110";
	}
	else if (dest == "AMD") {
		return "111";
	}

	return "error";
}

std::string Parser::comp()
{

	int epos = curCommand.find('=');
	int spos = curCommand.find(';');

	std::string var;

	if (epos == std::string::npos && spos == std::string::npos) {
		var = curCommand;
	}
	else if (epos != std::string::npos && spos == std::string::npos) {
		var = curCommand.substr(curCommand.find('=') + 1);
	}
	else if (epos == std::string::npos && spos != std::string::npos) {
		var = curCommand.substr(0, curCommand.find(';'));
	}

	if (var.find('A') != std::string::npos) {
		if (var == "0") {
			return "0101010";
		}
		else if (var == "1") {
			return "0111111";
		}
		else if (var == "-1") {
			return "0111010";
		}
		else if (var == "D") {
			return "0001100";
		}
		else if (var == "A") {
			return "0110000";
		}
		else if (var == "!D") {
			return "0001101";
		}
		else if (var == "!A") {
			return "0110001";
		}
		else if (var == "-D") {
			return "0001111";
		}
		else if (var == "-A") {
			return "0110011";
		}
		else if (var == "D+1") {
			return "0011111";
		}
		else if (var == "A+1") {
			return "0110111";
		}
		else if (var == "D-1") {
			return "0001110";
		}
		else if (var == "A-1") {
			return "0110010";
		}
		else if (var == "D+A") {
			return "0000010";
		}
		else if (var == "D-A") {
			return "0010011";
		}
		else if (var == "A-D") {
			return "0000111";
		}
		else if (var == "D&A") {
			return "0000000";
		}
		else if (var == "D|A") {
			return "0010101";
		}
	}
	else {
		if (var == "0") {
			return "0101010";
		}
		else if (var == "1") {
			return "0111111";
		}
		else if (var == "-1") {
			return "0111010";
		}
		else if (var == "D") {
			return "0001100";
		}
		else if (var == "M") {
			return "1110000";
		}
		else if (var == "!D") {
			return "0001101";
		}
		else if (var == "!M") {
			return "1110001";
		}
		else if (var == "-D") {
			return "0001111";
		}
		else if (var == "-M") {
			return "1110011";
		}
		else if (var == "D+1") {
			return "0011111";
		}
		else if (var == "M+1") {
			return "1110111";
		}
		else if (var == "D-1") {
			return "0001110";
		}
		else if (var == "M-1") {
			return "1110010";
		}
		else if (var == "D+M") {
			return "1000010";
		}
		else if (var == "D-M") {
			return "1010011";
		}
		else if (var == "M-D") {
			return "1000111";
		}
		else if (var == "D&M") {
			return "1000000";
		}
		else if (var == "D|M") {
			return "1010101";
		}
	}
	return "error";
}

std::string Parser::jump()
{
	if (commandType() != C_COMMNAD) return "error";

	int pos = curCommand.find(';');

	if (pos == std::string::npos) {
		return "000";
	}

	std::string dest = curCommand.substr(curCommand.find(';')+1);

	if (dest == "JGT") {
		return "001";
	}
	else if (dest == "JEQ") {
		return "010";
	}
	else if (dest == "JGE") {
		return "011";
	}
	else if (dest == "JLT") {
		return "100";
	}
	else if (dest == "JNE") {
		return "101";
	}
	else if (dest == "JLE") {
		return "110";
	}
	else if (dest == "JMP") {
		return "111";
	}

	return "error";
}

std::string Parser::PATH() {
	return path;
}