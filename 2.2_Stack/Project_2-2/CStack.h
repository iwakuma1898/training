/*
  @brief �X�^�b�N�̃N���X
  @author ��F���
  @date 10/8
 */

#pragma once
#include "CList.h"
#include "CNode.h"

class CStack
{
private:
	CList m_List;

	bool m_InputEndFg;
	int m_DataCnt;
	std::string m_str;

public:

	void Init();
	void Update();
	void Draw();
	void Clear();

};