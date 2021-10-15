#pragma once
#include "TNode.h"

/*
  @brief �����q�̃N���X�iconst�Łj
  @author ��F���
  @date 10/6
 */

class CConstIterator
{

protected:
	//�Q�ƒ��̃m�[�h
	TNode* m_node;

public:
/*
  @breif	�R���X�g���N�^
 */
	CConstIterator(TNode* p);//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��

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
	TNode* Getm_node()const;/*{ return m_node; }*/

};


/*
  @brief �����q�̃N���X�i��const�Łj
  @author ��F���
  @date 10/6
 */

//�C�e���[�^�[�i���X�g�Ȃǂ̃f�[�^�\�����ȒP�ɒH���d�g�݁j
class CIterator :public CConstIterator
{
public:

/*
  @breif�@�R���X�g���N�^
 */
	CIterator(TNode* p) : CConstIterator(p) {}//�p��

/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
	TNode* Getm_node();


};

