/*
  @brief �o�������X�g���\������m�[�h�i�ŏ��P�ʁj�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include <string>


class CNode
{
protected:
	std::string Key;//�L�[
	std::string EngName;//�L�[�ɕR�Â����p�P��
	CNode *Prev, *Next;//�^�X�N�̑O��֌W���w���|�C���^

public:

	void SetKey(const std::string &name);
	void SetEngName(const std::string &name);
	void SetPrev(CNode *prev);
	void SetNext(CNode *next);

	std::string GetKey()const;
	std::string GetEngName()const ;
	CNode* GetPrev()const;
	CNode* GetNext()const ;
};

