/*
�@CNode�̔h���N���X
  @brief �n�b�V���e�[�u����p��CNode�N���X
  �@�@�@ CList* MyList;�Ŕz��ɘA�����Ă��郊�X�g��c���ł���
  @author ��F���
  @date 10/6
 */


#pragma once
#include "CList.h"

//�h���N���X
class CNode_Table :public CNode
{
protected:
	CList* MyList;

public:
	void SetMyList(CList *list);
	CList* GetMyList()const;

};