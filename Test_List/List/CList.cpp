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

TNode* CList::GetDummy_First()const { return m_dummyFirst; };
TNode* CList::GetDummy_End()const { return m_dummyEnd; };

/*
  @fn
  @brief�@�R���X�g���N�^���s�ۂɁA�擪�ƏI�[�������m�[�h�𐶐�����
 */
CList::CList()
{
	m_dummyFirst = new TNode();
	m_dummyEnd = new TNode();

	//�n�_�̐ݒ�
	m_dummyFirst->m_next = m_dummyEnd;
	m_dummyFirst->m_prev=m_dummyFirst;//���g�̃A�h���X�ɃZ�b�g���A�u�n�_�v�Ƃ���

	//�I�_�̐ݒ�
	m_dummyEnd->m_next=m_dummyEnd;//���g�̃A�h���X�ɃZ�b�g���A�u�I�_�v�Ƃ���
	m_dummyEnd->m_prev=m_dummyFirst;
}

/*
  @fn
  @brief�@���������m�[�h��S�č폜����
 */
void CList::Exit()
{
	TNode *box = m_dummyFirst;
	while (box != m_dummyEnd)
	{
		m_node = box;
		box = box->m_next;
		delete m_node;
	}
	delete box;//box==Dummy_End���폜���ďI��
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
	m_node = new TNode();
	//�m�[�h�ɃZ�b�g
	m_node->m_record.m_score=lineNum;//SCORE
	m_node->m_record.m_name = lineName;//���O

	//�m�[�h������ӏ�������
	for (TNode *i = m_dummyFirst; i != m_dummyEnd; i = i->m_next)
	{
		if (i->m_next == m_dummyEnd)
		{
			//�V�����m�[�h��}������
			m_node->m_prev=i;
			m_node->m_next = m_dummyEnd;

			//�O��̃m�[�h�̃|�C���^���q������
			i->m_next=m_node;
			m_dummyEnd->m_prev=m_node;

			break;
		}
	}

}



///
//  @fn
//  @brief�@SCORE���ɕ��בւ���
//

void CList::SortScore()
{
	TNode *MaxScoreNode;//�\�[�g�̊�l
	TNode *NowConfirm;//�擪���m�肵���ʒu��m�邽�߂̂���
	TNode *PrevBox;//�����z���p
	TNode *NextBox;//�����z���p

	//���X�g�̐擪���擾
	MaxScoreNode = m_dummyFirst->m_next;//�擪�̃m�[�h��SCORE�����ɍő�l�ɐݒ�

	//�m�����Adummy_Firs���n�߂�
	NowConfirm = m_dummyFirst;

	//�\�[�g
	while (NowConfirm != m_dummyEnd)//�m���dummy_End�ɓ��B����܂�
	{
		//�ő�l��T��
		for (TNode *i = NowConfirm->m_next; i != m_dummyEnd; i = i->m_next)
		{
			if (MaxScoreNode->m_record.m_score < i->m_record.m_score)//�ő�l�����������ꍇ
			{
				MaxScoreNode = i;//�ő�l���X�V
			}

		}
		//���[�v�𔲂�����AMaxScoreNode�����m���̒��ōő�l��SCORE�����m�[�h

		//�ő�l�̃m�[�hMaxScoreNode�̑O��̃m�[�h�֌W���q���Ȃ���
		PrevBox = MaxScoreNode->m_prev;
		PrevBox->m_next = (MaxScoreNode->m_next);
		NextBox = MaxScoreNode->m_next;
		NextBox->m_prev = (MaxScoreNode->m_prev);

		//�ő�l�̃m�[�hMaxScoreNode���m���ɓ���邽�߁A�O��̃m�[�h�֌W���q���Ȃ���
		NextBox = NowConfirm->m_next;//MaxScoreNode�̎��ɂȂ�m�[�h
		NextBox->m_prev = (MaxScoreNode);//MaxScoreNode��O�ɐݒ�

		NowConfirm->m_next = (MaxScoreNode);//�m���̎���MaxScoreNode������

		//�ő�l�̃m�[�hMaxScoreNode�ɐݒ肳��Ă���O��|�C���^���X�V����
		MaxScoreNode->m_prev = (NowConfirm);//MaxScoreNode�̑O�ɂȂ�m�[�h�͊m���
		MaxScoreNode->m_next = (NextBox);

		//�m�����X�V
		NowConfirm = MaxScoreNode;

		//�ő�l���A�m���̎��ɉ��肷��
		MaxScoreNode = MaxScoreNode->m_next;
	}

}


