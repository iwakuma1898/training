//#include "CIter.h"
//
////===========================CConstIterator
///*
//  @breif	�R���X�g���N�^
// */
//template<class T>//�e���v���[�g��
//CConstIterator<T>::CConstIterator(TNode<T>* p)//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��
//{
//	m_node = p;
//}
//
///*
//  @breif�@�@���X�g�̐擪�Ɍ������ĂP�i�߂�i�j
//  @return
// */
//template<class T>//�e���v���[�g��
//void CConstIterator<T>::GoPrevNode()
//{
//	m_node = m_node->m_prev;
//}
//
///*
//  @breif�@�@���X�g�̖����Ɍ������ĂP�i�߂�i�j
//  @return
// */
//template<class T>//�e���v���[�g��
//void CConstIterator<T>::GoNextNode()
//{
//	m_node = m_node->m_next;
//}
//
///*
//  @breif�@�@�C�e���[�^�̎w���v�f���擾����[const��]�i�j
//  @return�@�@�C�e���[�^�̎w���v�f[const��]�i�j
// */
//template<class T>//�e���v���[�g��
//TNode<T>* CConstIterator<T>::Getm_node()const { return m_node; }
//
//
//
//
////===========================CIterator
//
//
///*
//  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
//  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
// */
//template<class T>//�e���v���[�g��
//TNode<T>* CIterator<T>::Getm_node() { return m_node; }