/*
  @brief ���уf�[�^
  @author ��F���
  @date 10/6
 */

#include "TRecord.h"


  /**
   * @breif	�������Z�q���I�[�o�[���[�h[��const��] 
   * @return	������r��������
   */
bool TRecord::operator==(TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}
/**
 * @breif	�������Z�q���I�[�o�[���[�h[const��]
 * @return	������r��������
 */
bool TRecord::operator==(const TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}