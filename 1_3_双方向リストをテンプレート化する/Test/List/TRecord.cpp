#include "TRecord.h"

//=============================================================================
// ���уf�[�^�\���̂̎���
//=============================================================================
bool TRecord::operator==(TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}
//-----------------------------------------------------------------------------
bool TRecord::operator==(const TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}