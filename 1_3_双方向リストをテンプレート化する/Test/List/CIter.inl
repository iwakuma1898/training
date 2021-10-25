#pragma once

//===========================
/*
  @brief �����q�̃N���X�iconst�Łj
  @author ��F���
  @date 10/6
 */
 //===========================

/*
  @breif	�R���X�g���N�^
 */
template<class T>
CConstIterator<T>::CConstIterator(TNode<T>* p)//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��
	//: m_node(p)
{
	m_node = p;
}

/*
  @breif�@�@���X�g�̐擪�Ɍ������ĂP�i�߂�i�j
  @return
 */
template<class T>
void CConstIterator<T>::GoPrevNode()
{
	m_node = m_node->m_prev;
}

/*
  @breif�@�@���X�g�̖����Ɍ������ĂP�i�߂�i�j
  @return
 */
template<class T>
void CConstIterator<T>::GoNextNode()
{
	m_node = m_node->m_next;
}

/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[const��]�i�j
 */
template<class T>
const T& CConstIterator<T>::Get()const { return *this->m_node->m_record; }



/**
 * @breif	�������Z�q���I�[�o�[���[�h[const��]
 * @return	������r��������
 */
template<class T>
bool CConstIterator<T>::operator==(const CConstIterator<T>& itr) const
{
	return m_node == itr.m_node;
}

/**
 * @breif	�񓙉����Z�q���I�[�o�[���[�h[const��]
 * @return	�񓙉���r��������
 */
template<class T>
bool CConstIterator<T>::operator!=(const CConstIterator<T>& itr) const
{
	return m_node != itr.m_node;
}


/**
* @brief	�m�[�h�ŕs���Ȃ��̂ł��邩���m�F����
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
template<class T>
bool CConstIterator<T>::CheckNode()
{
	if (m_node==nullptr)
	{
		return false;
	}
	else {
		return true;
	}
}



//===========================
/*
  @brief �����q�̃N���X�i��const�Łj
  @author ��F���
  @date 10/6
 */
 //===========================

///*
//  @breif	�R���X�g���N�^
// */
template<class T>
CIterator<T>::CIterator(TNode<T>* p) : CConstIterator<T>(p)//�p��
{

}



/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
template<class T>
T& CIterator<T>::Get() { return *this->m_node->m_record; }

/**
 * @breif	�������Z�q���I�[�o�[���[�h
 * @return	������r��������
 */
template<class T>
bool CIterator<T>::operator==(const CIterator<T>& itr) const
{
	return this->m_node == itr.m_node;
}


/**
 * @breif	�񓙉����Z�q���I�[�o�[���[�h
 * @return	�񓙉���r��������
 */
template<class T>
bool CIterator<T>::operator!=(const CIterator<T>& itr) const
{
	return this->m_node != itr.m_node;
}
