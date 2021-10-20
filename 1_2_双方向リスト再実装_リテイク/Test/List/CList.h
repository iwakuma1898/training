/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "TNode.h"
#include "CIter.h"

class CList
{
private:
	TNode *m_dummy;
	TNode *m_node;//�Q�Ɨp�̃f�[�^

public:

	CList();//�R���X�g���N�^
	~CList();//�f�X�X�g���N�^

	/**
* @brief	�I������
* @return�@
*/
	void Clear();

/**
* @brief	�f�[�^�̑}���i�C�e���[�^�j
* @return�@ �����Ȃ�true,���s�Ȃ�false
*/
	bool Insert(CConstIterator itr, const TRecord& record);
	/**
	* @brief	�f�[�^�̍폜�i�C�e���[�^�j
	* @return�@ �����Ȃ�true,���s�Ȃ�false
	*/
	bool Delete(CConstIterator itr);


/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�C�e���[�^
*/
	CIterator GetFirstIter();




/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾
 * @return	�����C�e���[�^
 */
	CIterator GetEndIter();




/**
* @brief	�w�肳�ꂽ�Ԗڂ̃m�[�h��Ԃ�
* @return�@�@�w�肳�ꂽ�Ԗڂ̃m�[�h
*/
	TNode* GetNode(int listNumber)const;




/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
	int  GetDataCnt() const;



};