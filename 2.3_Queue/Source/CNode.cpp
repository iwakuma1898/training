/*
  @brief �o�������X�g���\������m�[�h�i�ŏ��P�ʁj�̃N���X
  @author ��F���
  @date 10/8
 */

#include "CNode.h"

 //�m�[�h�N���X�̃����o�ϐ��ւ̑��
void CNode::SetNum(int &num) { Num = num; }
void CNode::SetName(const std::string &name) { Name = name; }
void CNode::SetPrev(CNode *prev) { Prev = prev; }
void CNode::SetNext(CNode *next) { Next = next; }

//�m�[�h�N���X�̃����o�ϐ��̎Q��
int CNode::GetNum()const { return Num; };
const std::string& CNode::GetName()const { return Name; };
CNode* CNode::GetPrev()const { return Prev; };
CNode* CNode::GetNext()const { return Next; };