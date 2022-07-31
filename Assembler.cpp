#include "Assembler.h"

bool isINT(std::string v)
{
	for (int i = 0; i < v.size(); i++) {
		if (!std::isdigit(v[i])) return 0;
	}
	return 1;
}

void Assembler::Pass1()
{
	int line = 0;
	while (P.hasMoreCommands()) {
		P.advance();
		int type = P.commandType();

		if (type == A_COMMNAD) {
			line++;
		}
		else if (type == L_COMMNAD) {
			std::string var = P.symbol();
			if (!table.contains(var)) {
				table.addEntry(var, line); // 다음 라인 
			}
		}
		else if (type == C_COMMNAD) {
			line++;
		}
	}
}

void Assembler::Pass2()
{

	int mem = 16; // 변수 메모리 할당

	while (P.hasMoreCommands()) {
		P.advance();

		int type = P.commandType();

		if (type == A_COMMNAD) {
			std::string var = P.symbol();

			if (isINT(var)) {
				ofs << 0 << std::bitset<15>(std::stoi(var)) << "\n";
			}
			else {
				if (table.contains(var)) {
					ofs << 0 << std::bitset<15>(table.GetAddress(var)) << "\n";
				}
				else {
					table.addEntry(var, mem);
					ofs << 0 << std::bitset<15>(mem++) << "\n";
				}
			}
		}
		else if (type == L_COMMNAD) {

		}
		else if (type == C_COMMNAD) {
			std::string comp = P.comp();
			std::string dest = P.dest();
			std::string jump = P.jump();

			ofs << 111 << comp << dest << jump << "\n";
		}
	}
}

Assembler::Assembler()
{
	ofs.open(P.PATH().substr(0, (P.PATH().find('.'))) + ".hack");
	Pass1();
	P.reset();
	Pass2();
	ofs.close();
}

Assembler::~Assembler()
{

}
