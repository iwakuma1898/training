#pragma once
#include "CList.h"
#include "TNode.h"

//�C�e���[�^�[�i���X�g�Ȃǂ̃f�[�^�\�����ȒP�ɒH���d�g�݁j
class CIter {

private:
	//���X�g
	CList* m_list;

	//�Q�ƒ��̃m�[�h
	TNode* m_node;

public:
	//�C�e���[�^�̎w���v�f���擾����[��const��]�i�j



};

class ConstCIter:public CIter
{

private:
	//

public:

	//���X�g�̐擪�Ɍ������ĂP�i�߂�i�j

	//���X�g�̖����Ɍ������ĂP�i�߂�i�j

	//�C�e���[�^�̎w���v�f���擾����[const��]�i�j


};


//
////�C�e���[�^�[�i���X�g�Ȃǂ̃f�[�^�\�����ȒP�ɒH���d�g�݁j
//class CIter {
//
//private:
//	//���X�g
//	CTaskList* List;
//
//	//�Q�ƒ��̃m�[�h
//	CTask* Task;
//
//public:
//	//�R���X�g���N�^
//	CTaskIter(CTaskList* list);
//
//	//���̃^�X�N�����鎞�ɐ^��Ԃ�
//	bool HasNext();
//
//	//���̃^�X�N�����o��
//	CTask* Next();
//
//
//	//���O�ɎQ�Ƃ����^�X�N���폜����
//	void Remove();
//
//};
