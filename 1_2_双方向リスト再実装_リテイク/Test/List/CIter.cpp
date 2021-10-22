#include "CIter.h"

//===========================CConstIterator
/*
  @breif	�R���X�g���N�^
 */
CConstIterator::CConstIterator(TNode* p)//�Ԓn���w�肵�A�ǂ�����n�߂�̂����w��
{
	m_node = p;
}

/*
  @breif�@�@���X�g�̐擪�Ɍ������ĂP�i�߂�i�j
  @return
 */
void CConstIterator::GoPrevNode()
{
	m_node = m_node->m_prev;
}

/*
  @breif�@�@���X�g�̖����Ɍ������ĂP�i�߂�i�j
  @return
 */
void CConstIterator::GoNextNode()
{
	m_node = m_node->m_next;
}

/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[const��]�i�j
 */
const TRecord& CConstIterator::GetRecord()const { return m_node->m_record; }


//===========================CIterator


/*
  @breif�@�@�C�e���[�^�̎w���v�f���擾����[��const��]�i�j
  @return�@�@�C�e���[�^�̎w���v�f[��const��]�i�j
 */
TRecord& CIterator::GetRecord() { return m_node->m_record; }