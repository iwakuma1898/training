/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/8
 */

#include "CList.h"

 /*
   @fn
   @brief�@�����o�ϐ��̎Q��
  */

const CNode* CList::GetDummy_First()const { return Dummy_First; };
const CNode* CList::GetDummy_End()const { return Dummy_End; };

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
void CList::Insert(int lineNum, std::string lineName)
{
	//�m�[�h�𐶐�
	Node = new CNode();
	//�m�[�h�ɃZ�b�g
	Node->SetNum(lineNum);//SCORE
	Node->SetName(lineName);//���O

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
  @brief�@SCORE���ɕ��בւ���
 */
void CList::SortScore()
{
	CNode *MaxScoreNode;//�\�[�g�̊�l
	CNode *NowConfirm;//�擪���m�肵���ʒu��m�邽�߂̂���
	CNode *PrevBox;//�����z���p
	CNode *NextBox;//�����z���p

	//���X�g�̐擪���擾
	MaxScoreNode = Dummy_First->GetNext();//�擪�̃m�[�h��SCORE�����ɍő�l�ɐݒ�

	//�m�����Adummy_Firs���n�߂�
	NowConfirm = Dummy_First;

	//�\�[�g
	while (NowConfirm != Dummy_End)//�m���dummy_End�ɓ��B����܂�
	{
		//�ő�l��T��
		for (CNode *i = NowConfirm->GetNext(); i != Dummy_End; i = i->GetNext())
		{
			if (MaxScoreNode->GetNum() < i->GetNum())//�ő�l�����������ꍇ
			{
				MaxScoreNode = i;//�ő�l���X�V
			}

		}
		//���[�v�𔲂�����AMaxScoreNode�����m���̒��ōő�l��SCORE�����m�[�h

		//�ő�l�̃m�[�hMaxScoreNode�̑O��̃m�[�h�֌W���q���Ȃ���
		PrevBox = MaxScoreNode->GetPrev();
		PrevBox->SetNext(MaxScoreNode->GetNext());
		NextBox = MaxScoreNode->GetNext();
		NextBox->SetPrev(MaxScoreNode->GetPrev());

		//�ő�l�̃m�[�hMaxScoreNode���m���ɓ���邽�߁A�O��̃m�[�h�֌W���q���Ȃ���
		NextBox = NowConfirm->GetNext();//MaxScoreNode�̎��ɂȂ�m�[�h
		NextBox->SetPrev(MaxScoreNode);//MaxScoreNode��O�ɐݒ�

		NowConfirm->SetNext(MaxScoreNode);//�m���̎���MaxScoreNode������

		//�ő�l�̃m�[�hMaxScoreNode�ɐݒ肳��Ă���O��|�C���^���X�V����
		MaxScoreNode->SetPrev(NowConfirm);//MaxScoreNode�̑O�ɂȂ�m�[�h�͊m���
		MaxScoreNode->SetNext(NextBox);

		//�m�����X�V
		NowConfirm = MaxScoreNode;

		//�ő�l���A�m���̎��ɉ��肷��
		MaxScoreNode = MaxScoreNode->GetNext();
	}

}

/*
  @fn
  @brief�@���������m�[�h��S�č폜����
 */
void CList::Clear()
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