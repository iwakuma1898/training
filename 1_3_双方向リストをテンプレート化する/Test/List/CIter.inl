#pragma once


//===========================CConstIterator
/*
  @breif	�R���X�g���N�^
 */
template<class T>
CConstIterator<T>::CConstIterator(TNode<T>* p)//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��
	: m_node(p)
{
	//m_node = p;
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
//const T& CConstIterator<T>::GetRecord()const { return m_node->m_record; }
const T* CConstIterator<T>::GetRecord()const { return m_node->m_record; }


//===========================CIterator


/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
template<class T>
//T& CIterator<T>::GetRecord() { return m_node->m_record; }
T* CIterator<T>::GetRecord() { return m_node->m_record; }