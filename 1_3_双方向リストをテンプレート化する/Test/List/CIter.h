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
protected:
	TNode<T>* m_node;

public:


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
	const T& Get()const;


	/**
 * @breif	�������Z�q���I�[�o�[���[�h[const��]
 * @return	������r��������
 */
	bool operator==(const CConstIterator& itr) const;

	/**
* @breif	�񓙉����Z�q���I�[�o�[���[�h[const��]
* @return	�񓙉���r��������
*/
	bool operator!=(const CConstIterator& itr) const;


	/**
* @brief	�m�[�h�ŕs���Ȃ��̂ł��邩���m�F����
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
	bool CheckNode();
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

/*
  @breif�@�R���X�g���N�^
 */
	explicit CIterator(TNode<T>* p = nullptr);


/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
	T& Get();


/**
 * @breif	�������Z�q���I�[�o�[���[�h[��const��]
 * @return	������r��������
 */
	bool operator==(const CIterator& itr) const;

	/**
 * @breif	�񓙉����Z�q���I�[�o�[���[�h[��const��]
 * @return	�񓙉���r��������
 */
	bool operator!=(const CIterator& itr) const;
};

#include "CIter.inl"