/*
  @brief �o�������X�g���\������m�[�h�i�ŏ��P�ʁj�̃N���X
  @author ��F���
  @date 10/6
 */

#pragma once
#include <string>
#include "TRecord.h"

template<class T>//�e���v���[�g��
struct TNode
{
	TNode *m_prev;//�O�|�C���^
	TNode *m_next;//��|�C���^

	//TRecord m_record;//���уf�[�^
	T* m_record;//���уf�[�^//�^��ݒ�ł���悤�ɂ���

};


