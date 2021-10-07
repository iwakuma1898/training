/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#include "CList.h"

 /*
   @fn
   @brief�@�����o�ϐ��̎Q��
  */

CNode* CList::GetDummy_First()const { return Dummy_First; };
CNode* CList::GetDummy_End()const { return Dummy_End; };

/*
  @fn
  @brief�@�R���X�g���N�^���s�ۂɁA�擪�ƏI�[�������m�[�h�𐶐�����
 */
CList::CList()
{
	Dummy_First = new CNode();
	Dummy_End = new CNode();

	//�n�_�̐ݒ�
	Dummy_First->SetNext(Dummy_End);
	Dummy_First->SetPrev(Dummy_First);//���g�̃A�h���X�ɃZ�b�g���A�u�n�_�v�Ƃ���

	//�I�_�̐ݒ�
	Dummy_End->SetNext(Dummy_End);//���g�̃A�h���X�ɃZ�b�g���A�u�I�_�v�Ƃ���
	Dummy_End->SetPrev(Dummy_First);
}

/*
  @fn
  @brief�@�m�[�h�𐶐����}������
  @param�@�iint lineNum�j�ǂݎ�������̐��l
  @param�@�istd::string lineName�j�ǂݎ�������̖��O
 */
void CList::Insert(std::string lineKey, std::string lineName)
{
	//�m�[�h�𐶐�
	Node = new CNode();
	//�m�[�h�ɃZ�b�g
	Node->SetKey(lineKey);//SCORE
	Node->SetEngName(lineName);//���O

	//�m�[�h������ӏ�������
	for (CNode *i = Dummy_First; i != Dummy_End; i = i->GetNext())
	{
		if (i->GetNext() == Dummy_End)
		{
			//�V�����m�[�h��}������
			Node->SetPrev(i);
			Node->SetNext(Dummy_End);

			//�O��̃m�[�h�̃|�C���^���q������
			i->SetNext(Node);
			Dummy_End->SetPrev(Node);

			break;
		}
	}

}



/*
  @fn
  @brief�@���������m�[�h��S�č폜����
 */
void CList::Exit()
{
	CNode *box = Dummy_First;
	while (box != Dummy_End)
	{
		Node = box;
		box = box->GetNext();
		delete Node;
	}
	delete box;//box==Dummy_End���폜���ďI��
}