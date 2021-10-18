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


template<class T>//�e���v���[�g��
class CList
{
private:
	TNode<T> *m_dummyFirst;
	TNode<T> *m_dummyEnd;
	TNode<T> *m_node;//�Q�Ɨp�̃f�[�^

public:

	CList();

	/**
* @brief	�f�[�^���Z�b�g����
* @return�@
*/
	void Init(std::ifstream &file);
/**
* @brief	�I������
* @return�@
*/
	void Exit();


/**
* @brief	�f�[�^�̑}���i�C�e���[�^�j
* @return�@ �����Ȃ�true,���s�Ȃ�false
*/
	bool Insert(CConstIterator<T> itr, const TRecord& record);
	/**
	* @brief	�f�[�^�̍폜�i�C�e���[�^�j
	* @return�@ �����Ȃ�true,���s�Ȃ�false
	*/
	bool Delete(CConstIterator<T> itr);


/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�C�e���[�^
*/
	CIterator<T> GetFirstNode();


	/**
	* @brief	�擪�_�~�[�m�[�h�̎擾
	* @return�@�@�擪�_�~�[�m�[�h
	*/
	TNode<T>* GetDummy_First()const;

/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾
 * @return	�����C�e���[�^
 */
	CIterator<T> GetEndNode();

	/**
	* @brief	�����_�~�[�m�[�h�̎擾
	* @return�@�@�����_�~�[�m�[�h
	*/
	TNode<T>* GetDummy_End()const;


/**
* @brief	�w�肳�ꂽ�Ԗڂ̃m�[�h��Ԃ�
* @return�@�@�w�肳�ꂽ�Ԗڂ̃m�[�h
*/
	TNode<T>* GetNode(int listNumber)const;




	/**
* @brief	�擪�_�~�[�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�_�~�[�C�e���[�^
*/
	CIterator<T> GetDummyFirst();
		/**
	 * @brief	�����_�~�[�m�[�h���w���C�e���[�^�̎擾
	 * @return	�����_�~�[�C�e���[�^
	 */
	CIterator<T> GetDummyEnd();


/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
	int  GetDataCnt() const;


};