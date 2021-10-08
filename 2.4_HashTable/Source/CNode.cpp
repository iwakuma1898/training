/*
  @brief �o�������X�g���\������m�[�h�i�ŏ��P�ʁj�̃N���X
  @author ��F���
  @date 10/6
 */

#include "CNode.h"

//�m�[�h�N���X�̃����o�ϐ��ւ̑��
void CNode::SetKey(const std::string &key) { Key = key; }
void CNode::SetEngName(const std::string &name) { EngName = name; }
void CNode::SetPrev(CNode *prev) { Prev = prev; }
void CNode::SetNext(CNode *next) { Next = next; }

//�m�[�h�N���X�̃����o�ϐ��̎Q��
const std::string& CNode::GetKey()const { return Key; };
const std::string& CNode::GetEngName()const { return EngName; };
CNode* CNode::GetPrev()const { return Prev; };
CNode* CNode::GetNext()const { return Next; };


