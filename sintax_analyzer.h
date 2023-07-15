#pragma once

const int CommandsAmount = 3;

enum class CommandType { // ������ �������������: CommandNames[(int)CommandType::CREATE] = "create table" � � CommandTypesFunctions �������� ����������
	CREATE,
	ALTER,
	DROP
};

const std::string CommandNames[CommandsAmount] = { // ����������� ������ ��� ��������� ����������, � ������� ����� ���������� ������
	"create table",
	"alter table",
	"drop table"
};

class Analyzer
{
private:
	std::string command;
	void initialise();
	bool StrStartsWith(std::string);
public:
	Analyzer();
	bool AnaliseCreateTable();
	bool AnaliseAlterTable();
	bool AnaliseDropTable();
	bool StartAnalis(std::string command);

};

typedef bool (Analyzer::* TypeCommandAnalise)();		//��� ������, �������������� ����� ��������� �� �����

const TypeCommandAnalise CommandTypesFunctions[CommandsAmount] = { // ����������� ������ ��� ��������� ����������, � ������� ����� ���������� ������
	&Analyzer::AnaliseCreateTable,	// ����� ������� ��� ������������������ ������ ��� ������� ���� �������
	&Analyzer::AnaliseAlterTable,
	&Analyzer::AnaliseDropTable
};