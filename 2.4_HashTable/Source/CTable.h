/*
  @brief �n�b�V���e�[�u���N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include "CNode_Table.h"

#define TableMAX (20)

class CTable
{
private:
	CNode_Table Table[TableMAX];
	CList *List;
	CNode *NowNode;//�����p
	CNode *InsertNode;//�}������p�̃m�[�h

public:
	void Insert(std::string lineKey, std::string  lineEngName);
	std::string Search(std::string key);
	int CalcHash(std::string key);//�L�[����n�b�V���l���v�Z
	void Clear();

};



