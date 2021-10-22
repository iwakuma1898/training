/*
  @brief �����q�̃N���X�iconst�Łj
  @author ��F���
  @date 10/6
 */

#pragma once

template<class T>
struct TNode;

template<class T>
class CConstIterator
{
public:
	TNode<T>* m_node;

/*
  @breif	�R���X�g���N�^
 */
	explicit CConstIterator(TNode<T>* p);//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��

/*
  @breif�@�@���X�g�̐擪�Ɍ������ĂP�i�߂�i�j
  @return
 */
	void GoPrevNode();
/*
  @breif�@�@���X�g�̖����Ɍ������ĂP�i�߂�i�j
  @return
 */
	void GoNextNode();


/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[const��]�i�j
 */
	const T* GetRecord()const;
};


/*
  @brief �����q�̃N���X�i��const�Łj
  @author ��F���
  @date 10/6
 */

//�C�e���[�^�[�i���X�g�Ȃǂ̃f�[�^�\�����ȒP�ɒH���d�g�݁j
template<class T>
class CIterator :public CConstIterator<T>
{
public:
	TNode<T>* m_node;

/*
  @breif�@�R���X�g���N�^
 */
	CIterator(TNode<T>* p) : CConstIterator<T>(p) {}//�p��

/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
	T* GetRecord();

};

#include "CIter.inl"