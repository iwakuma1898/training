/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once


template<class T>
struct TNode
{
	TNode *m_prev;//�O�|�C���^
	TNode *m_next;//��|�C���^

	T* m_record;//���уf�[�^
};

template<class T>
class CConstIterator;
template<class T>
class CIterator;
/*
  @brief �o�������X�g�̃N���X
  @author ��F���
  @date 10/6
 */
template<class T>
class CList
{
private:
	TNode<T> *m_dummy;


public:

	CList();//�R���X�g���N�^
	~CList();//�f�X�X�g���N�^


/**
* @brief	�f�[�^�̑}���i�C�e���[�^�j
* @return�@ �����Ȃ�true,���s�Ȃ�false
*/
	bool Insert(CConstIterator<T> itr, const T& record);
	/**
	* @brief	�f�[�^�̍폜�i�C�e���[�^�j
	* @return�@ �����Ȃ�true,���s�Ȃ�false
	*/
	bool Delete(CConstIterator<T> itr);


/**
* @brief	�擪�m�[�h���w���C�e���[�^�̎擾
* @return�@�@�擪�C�e���[�^
*/
	CIterator<T> GetFirstIter();




/**
 * @brief	�����m�[�h���w���C�e���[�^�̎擾
 * @return	�����C�e���[�^
 //////*/
	CIterator<T> GetEndIter();




///**
//* @brief	�w�肳�ꂽ�Ԗڂ̃C�e���[�^��Ԃ�
//* @return�@�@�w�肳�ꂽ�Ԗڂ̃C�e���[�^
//*/
	CConstIterator<T> GetIter(int listNumber)const;



/**
* @brief	���X�g�̃m�[�h����Ԃ�
* @return	���X�g�̃m�[�h��
*/
	int  GetDataCnt() const;



};


#include "CList.inl"
