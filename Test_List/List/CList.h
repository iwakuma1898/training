/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "TNode.h"


class CList
{
private:
	TNode *m_dummyFirst;
	TNode *m_dummyEnd;
	TNode *m_node;//�Q�Ɨp�̃f�[�^

public:

	CList();
	void Exit();

	void SortScore();

	//�f�[�^���̎擾
	int  GetDataNum() { return 0; }
	//�f�[�^�̑}���i�C�e���[�^�j
	void Insert(int lineNum, std::string lineName);
	//�f�[�^�̍폜�i�C�e���[�^�j
	void Delete();
	//�擪�C�e���[�^�擾
	//TNode* GetDummy_First();
	//�擪�R���X�g�C�e���[�^�擾
	TNode* GetDummy_First()const;
	//�����C�e���[�^�擾
	//TNode* GetDummy_End();
	//�����R���X�g�C�e���[�^�擾
	TNode* GetDummy_End()const;

};