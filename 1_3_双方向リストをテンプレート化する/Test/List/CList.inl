/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once


 /*
   @fn
   @brief�@�R���X�g���N�^���s�ۂɁA�擪�ƏI�[�������m�[�h�𐶐�����
  */
template<class T>
CList<T>::CList()
{
	m_dummy = new TNode<T>();

	//�_�~�[�m�[�h
	m_dummy->m_next = m_dummy;
	m_dummy->m_prev = m_dummy;//���g�̃A�h���X�ɃZ�b�g���A�u�n�_�v�Ƃ���
	//m_dummy->m_record->m_name = "m_dummy";
}

/*
  @fn
  @brief�@�f�X�X�g���N�^
 */
template<class T>
CList<T>::~CList()
{
	TNode<T>* mNode = m_dummy->m_prev;
	TNode<T>* deleteNode = nullptr;
	// ���������m�[�h��S�č폜����
	while (mNode != m_dummy)
	{
		deleteNode = mNode;
		mNode = mNode->m_prev;
		delete deleteNode;
	}
	delete m_dummy;// �Ō�
	m_dummy = nullptr;
}




/*
  @fn
  @brief�@�m�[�h�𐶐����}������[const��]
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu�̌�ɑ}�����邩�j
  @param�@�iconst TRecord& record�j�}������f�[�^
 @param�@�iint cnt�j�}�������
 */
template<class T>
bool CList<T>::Insert(CConstIterator<T> itr, const T& record)
{
	if (itr.CheckNode() == false)
	{
		return false;//��������
	}


	//�m�[�h�𐶐�
	TNode<T> *Node = new TNode<T>();
	//�f�[�^�Z�b�g
	Node->m_record = new T{ record };


	//�}������ʒu�̑O�ɂ���m�[�h
	TNode<T>* InsertPrev = FindNode(itr);
	//�}������ʒu�̎��ɂ���m�[�h
	TNode<T>* InsertNext = FindNode(itr)->m_next;

	//���̃m�[�h�̌�ɑ}������
	Node->m_prev = InsertPrev;
	Node->m_next = InsertNext;

	//�O��̃m�[�h�̃|�C���^���q������
	InsertPrev->m_next = Node;
	InsertNext->m_prev = Node;

	return true;//��������
}

/*
  @fn
  @brief�@�m�[�h�𐶐����}������[��const��]
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu�̌�ɑ}�����邩�j
  @param�@�iconst TRecord& record�j�}������f�[�^
 @param�@�iint cnt�j�}�������
 */
template<class T>
bool CList<T>::Insert(CIterator<T> itr, const T& record)
{
	if (itr.CheckNode() == false)
	{
		return false;//��������
	}


	//�m�[�h�𐶐�
	TNode<T> *Node = new TNode<T>();
	//�f�[�^�Z�b�g
	Node->m_record = new T{ record };

	//�}������ʒu�̑O�ɂ���m�[�h
	//TNode<T>* InsertPrev = itr.m_node;
	TNode<T>* InsertPrev = FindNode(itr);
	//�}������ʒu�̎��ɂ���m�[�h
	//TNode<T>* InsertNext = itr.m_node->m_next;
	TNode<T>* InsertNext = FindNode(itr)->m_next;


	//���̃m�[�h�̌�ɑ}������
	Node->m_prev = InsertPrev;
	Node->m_next = InsertNext;

	//�O��̃m�[�h�̃|�C���^���q������
	InsertPrev->m_next = Node;
	InsertNext->m_prev = Node;

	return true;//��������
}

/*
  @fn
  @brief�@�m�[�h�𐶐����}������[const��]
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu���폜���邩�j
 */
template<class T>
bool CList<T>::Delete(CConstIterator<T> itr)
{
	//�m�[�h�̍폜�ӏ�������
	for (TNode<T> *i = m_dummy->m_next; i != m_dummy; i = i->m_next)
	{
		//if (i == itr.m_node)//���������ꍇ�i�擪�E���ԃm�[�h�̌���폜����ꍇ�j
		if (i == FindNode(itr))//���������ꍇ�i�擪�E���ԃm�[�h�̌���폜����ꍇ�j
		{
			//�폜����ʒu�̑O�ɂ���m�[�h
			TNode<T>* DeletePrev = i->m_prev;
			//�폜����ʒu�̎��ɂ���m�[�h
			TNode<T>* DeleteNext = i->m_next;

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

/*
  @fn
  @brief�@�m�[�h�𐶐����}������[��const��]
  @param�@�iCIterator itr�j�C�e���[�^�i�ǂ̈ʒu���폜���邩�j
 */
template<class T>
bool CList<T>::Delete(CIterator<T> itr)
{
	//�m�[�h�̍폜�ӏ�������
	for (TNode<T> *i = m_dummy->m_next; i != m_dummy; i = i->m_next)
	{
		if (i == FindNode(itr))//���������ꍇ�i�擪�E���ԃm�[�h�̌���폜����ꍇ�j
		{
			//�폜����ʒu�̑O�ɂ���m�[�h
			TNode<T>* DeletePrev = i->m_prev;
			//�폜����ʒu�̎��ɂ���m�[�h
			TNode<T>* DeleteNext = i->m_next;

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
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾[const��]
* @return�@�@�擪�C�e���[�^
*/
template<class T>
CConstIterator<T> CList<T>::GetConstFirstIter()
{
	return CConstIterator<T>(m_dummy->m_next);
}

/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾[��const��]
* @return�@�@�擪�C�e���[�^
*/
template<class T>
CIterator<T> CList<T>::GetFirstIter()
{
	return CIterator<T>(m_dummy->m_next);
}

/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾[const��]
 * @return	�����C�e���[�^
 */
template<class T>
CConstIterator<T> CList<T>::GetConstEndIter()
{
	return CConstIterator<T>(m_dummy->m_prev);
}



/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾[��const��]
 * @return	�����C�e���[�^
 */
template<class T>
CIterator<T> CList<T>::GetEndIter()
{
	return CIterator<T>(m_dummy->m_prev);
}

/**
* @brief	�w�肳�ꂽ�Ԗڂ̃m�[�h��Ԃ�[const��]
* @return�@�@�w�肳�ꂽ�Ԗڂ̃m�[�h
*/
template<class T>
CConstIterator<T> CList<T>::GetIter(int listNumber)const
{
	int cnt = 0;//(0�x�[�X)

	//�擪���烊�X�g��H�萔����
	for (CIterator<T> i = m_dummy->m_next; i.m_node != m_dummy; i.GoNextNode())
	{
		if (cnt == listNumber)
		{
			return i;
		}

		cnt++;//�X�V
	}

	//�����������Ă��܂��Ȃ�A���X�g�̃m�[�h�̐��ɑ΂��Ĉ����Ɍ�肪����
}

/**
* @brief	�w�肳�ꂽ�Ԗڂ̃m�[�h��Ԃ�[��const��]
* @return�@�@�w�肳�ꂽ�Ԗڂ̃m�[�h
*/
template<class T>
CIterator<T> CList<T>::GetIter(int listNumber)
{
	int cnt = 0;//(0�x�[�X)

	//�擪���烊�X�g��H�萔����
	for (CIterator<T> i = GetFirstIter(); CheckIterDummy(i) == false; i.GoNextNode())
	{
		if (cnt == listNumber)
		{
			return i;
		}

		cnt++;//�X�V
	}

	//�����������Ă��܂��Ȃ�A���X�g�̃m�[�h�̐��ɑ΂��Ĉ����Ɍ�肪����
}




/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
template<class T>
int  CList<T>::GetDataCnt() const
{
	int cnt = 0;

	//�m�[�h��������
	for (TNode<T> *i = m_dummy->m_next; i != m_dummy; i = i->m_next)
	{
		cnt++;
	}

	return cnt;
}

/**
* @brief	�C�e���[�^���A�_�~�[�m�[�h�ł��邩���m�F����[const��]
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
template<class T>
bool CList<T>::CheckIterDummy(CConstIterator<T> Iter)
{
	if (Iter == CConstIterator<T>(m_dummy))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* @brief	�C�e���[�^���A�_�~�[�m�[�h�ł��邩���m�F����[��const��]
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
template<class T>
bool CList<T>::CheckIterDummy(CIterator<T> Iter)
{
	if (Iter == CIterator<T>(m_dummy))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* @brief		�C�e���[�^���w���m�[�h��T������[const��]
* @param[in]	�w��ʒu�̃C�e���[�^
* @return		�w��ʒu�̃m�[�h�A���s��nullptr��Ԃ�
*/
template<class T>
TNode<T>* CList<T>::FindNode(CConstIterator<T> itr)
{
	TNode<T>* Node = m_dummy;

	do
	{// �}���w��ʒu��T��
		CConstIterator<T> temp(Node);
		if (temp == itr) 
		{
			return Node;
		}
		Node = Node->m_next;
	} while (Node != m_dummy);

	return nullptr;
}

/**
* @brief		�C�e���[�^���w���m�[�h��T������[��const��]
* @param[in]	�w��ʒu�̃C�e���[�^
* @return		�w��ʒu�̃m�[�h�A���s��nullptr��Ԃ�
*/
template<class T>
TNode<T>* CList<T>::FindNode(CIterator<T> itr)
{
	TNode<T>* Node = m_dummy;

	do
	{// �}���w��ʒu��T��
		CIterator<T> temp(Node);
		if (temp == itr)
		{
			return Node;
		}
		Node = Node->m_next;
	} while (Node != m_dummy);

	return nullptr;
}

