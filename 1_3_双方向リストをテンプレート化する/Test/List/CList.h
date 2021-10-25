/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once


template<class T>
struct TNode
{
	TNode* m_prev;//�O�|�C���^
	TNode* m_next;//��|�C���^

	T* m_record;//���уf�[�^
};

template<class T>
class CConstIterator;
template<class T>
class CIterator;


template<class T>
class CList
{
private:
	TNode<T> *m_dummy;


public:


	CList();//�R���X�g���N�^
	~CList();//�f�X�X�g���N�^


/**
* @brief	�f�[�^�̑}���i�C�e���[�^�j[const��]
* @return�@ �����Ȃ�true,���s�Ȃ�false
*/
	bool Insert(CConstIterator<T> itr, const T& record);

	/**
* @brief	�f�[�^�̑}���i�C�e���[�^�j[��const��]
* @return�@ �����Ȃ�true,���s�Ȃ�false
*/
	bool Insert(CIterator<T> itr, const T& record);

	/**
	* @brief	�f�[�^�̍폜�i�C�e���[�^�j[const��]
	* @return�@ �����Ȃ�true,���s�Ȃ�false
	*/
	bool Delete(CConstIterator<T> itr);


	/**
	* @brief	�f�[�^�̍폜�i�C�e���[�^�j[��const��]
	* @return�@ �����Ȃ�true,���s�Ȃ�false
	*/
	bool Delete(CIterator<T> itr);


	/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾[const��]
* @return�@�@�擪�C�e���[�^
*/
	CConstIterator<T> GetConstFirstIter();

	/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾[��const��]
* @return�@�@�擪�C�e���[�^
*/
	CIterator<T> GetFirstIter();


	/**
	 * @brief	�����m�[�h���w���C�e���[�^�̎擾[const��]
	 * @return	�����C�e���[�^
	 //////*/
	CConstIterator<T> GetConstEndIter();


/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾[��const��]
 * @return	�����C�e���[�^
 //////*/
	CIterator<T> GetEndIter();

///**
//* @brief	�w�肳�ꂽ�Ԗڂ̃C�e���[�^��Ԃ�
//* @return�@�@�w�肳�ꂽ�Ԗڂ̃C�e���[�^
//*/
	CConstIterator<T> GetIter(int listNumber)const;

	///**
//* @brief	�w�肳�ꂽ�Ԗڂ̃C�e���[�^��Ԃ�
//* @return�@�@�w�肳�ꂽ�Ԗڂ̃C�e���[�^
//*/
	CIterator<T> GetIter(int listNumber);


/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
	int  GetDataCnt() const;


	/**
* @brief	�C�e���[�^���A�_�~�[�m�[�h�ł��邩���m�F����[const��]
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
	bool CheckIterDummy(CConstIterator<T> Iter);

		/**
* @brief	�C�e���[�^���A�_�~�[�m�[�h�ł��邩���m�F����[��const��]
* @return	�_�~�[�m�[�h�ł��邩�̐^�U����
*/
	bool CheckIterDummy(CIterator<T> Iter);


	/**
 * @brief		�C�e���[�^���w���m�[�h��T������
 * @param[in]	�w��ʒu�̃C�e���[�^
 * @return		�w��ʒu�̃m�[�h�A���s��nullptr��Ԃ�
 */
	TNode<T>* FindNode(CIterator<T> itr);
	TNode<T>* FindNode(CConstIterator<T> itr);

};


#include "CList.inl"
