/*
  @brief �o�������X�g���\������m�[�h�i�ŏ��P�ʁj�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include <string>

class CNode
{
private:
	int Num;
	std::string Name;
	CNode *Prev, *Next;//�^�X�N�̑O��֌W���w���|�C���^

public:

	void SetNum(const int &num);
	void SetName(const std::string &name);
	void SetPrev(CNode *prev);
	void SetNext(CNode *next);

	int GetNum()const;
	std::string GetName()const;
	CNode* GetPrev()const;
	CNode* GetNext()const;
};


