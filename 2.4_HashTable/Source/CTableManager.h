#pragma once
#include "CTable.h"

class CTableManager
{
private:
	CTable myTable;
	std::string inputStr;
	std::string outputStr;
	bool InputEndFg;//

public:

	bool Init(const char *fileName);
	void Update();
	void Clear();

};