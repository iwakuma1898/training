/*
  @brief �o�������X�g�̃N���X��inl
  @author ��F���
  @date 10/18
 */
#pragma once
#include "CList.h"


 /*
   @fn
   @brief�@�R���X�g���N�^���s�ۂɁA�擪�ƏI�[�������m�[�h�𐶐�����
  */
template<class T>//�e���v���[�g��
CList<T>::CList()
{
	m_dummyFirst = new TNode();
	m_dummyEnd = new TNode();

	//�n�_�̐ݒ�
	m_dummyFirst->m_next = m_dummyEnd;
	m_dummyFirst->m_prev = m_dummyFirst;//���g�̃A�h���X�ɃZ�b�g���A�u�n�_�v�Ƃ���
	m_dummyFirst->m_record.m_score = 1;
	m_dummyFirst->m_record.m_name = "dummyFirst";


	//�I�_�̐ݒ�
	m_dummyEnd->m_next = m_dummyEnd;//���g�̃A�h���X�ɃZ�b�g���A�u�I�_�v�Ƃ���
	m_dummyEnd->m_prev = m_dummyFirst;
	m_dummyEnd->m_record.m_score = 99999;
	m_dummyEnd->m_record.m_name = "dummyEnd";
}




/*
  @fn
  @brief�@���������m�[�h��S�č폜����
 */
template<class T>//�e���v���[�g��
void CList<T>::Exit()
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
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu�̌�ɑ}�����邩�j
  @param�@�iconst TRecord& record�j�}������f�[�^
 @param�@�iint cnt�j�}�������
 */
template<class T>//�e���v���[�g��
bool CList<T>::Insert(CConstIterator<T> itr, const TRecord& record)
{

	//�m�[�h�𐶐�
	m_node = new TNode();
	//�f�[�^�Z�b�g
	m_node->m_record.m_score = record.m_score;//
	m_node->m_record.m_name = record.m_name;//���O

	//�����ւ̎w��̏ꍇ�Am_dummyEnd�̑O�ɑ}������
	if (itr.Getm_node() == m_dummyEnd)//�C�e���[�^���������w�肵�Ă��Ă�����
	{
		//�}������ʒu�̑O�ɂ���m�[�h
		TNode* InsertPrev = itr.Getm_node()->m_prev;
		//�}������ʒu�̎��ɂ���m�[�h
		TNode* InsertNext = itr.Getm_node();

		////�m�[�h��}������
		m_node->m_prev = InsertPrev;
		m_node->m_next = InsertNext;

		//�O��̃m�[�h�̃|�C���^���q������
		InsertPrev->m_next = m_node;
		InsertNext->m_prev = m_node;

		return true;//��������
	}

	//�����łȂ��ꍇ�A�m�[�h������ӏ�������
	for (TNode *i = m_dummyFirst; i != m_dummyEnd; i = i->m_next)
	{
		if (i == itr.Getm_node())//���������ꍇ�i�擪�E���ԃm�[�h�̌�ɑ}������ꍇ�j
		{
			//�}������ʒu�̑O�ɂ���m�[�h
			TNode* InsertPrev = i;
			//�}������ʒu�̎��ɂ���m�[�h
			TNode* InsertNext = i->m_next;

			//���̃m�[�h�̌�ɑ}������
			m_node->m_prev = InsertPrev;
			m_node->m_next = InsertNext;

			//�O��̃m�[�h�̃|�C���^���q������
			InsertPrev->m_next = m_node;
			InsertNext->m_prev = m_node;

			return true;//��������
		}

	}

	return false;// ��������Y�����Ȃ���΁A�}�����s�i�����������݂��Ȃ��m�[�h�̎w��j�Ɣ��f
}

/*
  @fn
  @brief�@�m�[�h�𐶐����}������
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu���폜���邩�j
 */
template<class T>//�e���v���[�g��
bool CList<T>::Delete(CConstIterator<T> itr)
{
	//�m�[�h�̍폜�ӏ�������
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		if (i == itr.Getm_node())//���������ꍇ�i�擪�E���ԃm�[�h�̌���폜����ꍇ�j
		{
			//�폜����ʒu�̑O�ɂ���m�[�h
			TNode* DeletePrev = i->m_prev;
			//�폜����ʒu�̎��ɂ���m�[�h
			TNode* DeleteNext = i->m_next;

			//�O��̃m�[�h�̃|�C���^���q������
			DeletePrev->m_next = DeleteNext;
			DeleteNext->m_prev = DeletePrev;

			//�폜
			delete i;

			return true;//��������
		}

	}

	return false;// ��������Y�����Ȃ���΁A���s�i�����������݂��Ȃ��m�[�h�̎w��j�Ɣ��f
}

/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�C�e���[�^
*/
template<class T>//�e���v���[�g��
CIterator<T> CList<T>::GetFirstNode()
{
	return CIterator<T>(m_dummyFirst->m_next);
}


/**
* @brief	�擪�_�~�[�m�[�h�̎擾
* @return�@�@�擪�_�~�[�m�[�h
*/
template<class T>//�e���v���[�g��
TNode<T>* CList<T>::GetDummy_First()const { return m_dummyFirst; };



/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾
 * @return	�����C�e���[�^
 */
template<class T>//�e���v���[�g��
CIterator<T> CList<T>::GetEndNode()
{
	return CIterator<T>(m_dummyEnd->m_prev);
}

/**
* @brief	�����_�~�[�m�[�h�̎擾
* @return�@�@�����_�~�[�m�[�h
*/
template<class T>//�e���v���[�g��
TNode<T>* CList<T>::GetDummy_End()const { return m_dummyEnd; };

/**
* @brief	�w�肳�ꂽ�Ԗڂ̃m�[�h��Ԃ�
* @return�@�@�w�肳�ꂽ�Ԗڂ̃m�[�h
*/
template<class T>//�e���v���[�g��
TNode<T>* CList<T>::GetNode(int listNumber)const
{
	int cnt = 1;//1�Ԗ�

	//�擪���烊�X�g��H�萔����
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		if (cnt == listNumber)
		{
			return i;
		}

		cnt++;//�X�V
	}

	//�����������Ă��܂��Ȃ�A���X�g�̃m�[�h�̐��ɑ΂��Ĉ����Ɍ�肪����
	return false;
}




/**
* @brief	�擪�_�~�[�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�_�~�[�C�e���[�^
*/
template<class T>//�e���v���[�g��
CIterator<T> CList<T>::GetDummyFirst()
{
	return CIterator<T>(m_dummyFirst);
}
/**
* @brief	�����_�~�[�m�[�h���w���C�e���[�^�̎擾
* @return	�����_�~�[�C�e���[�^
*/
template<class T>//�e���v���[�g��
CIterator<T> CList<T>::GetDummyEnd()
{
	return CIterator<T>(m_dummyEnd);
}


/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
template<class T>//�e���v���[�g��
int  CList<T>::GetDataCnt() const
{
	int cnt = 0;

	//�m�[�h��������
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		cnt++;
	}

	return cnt;
}

