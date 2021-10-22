#include "TRecord.h"

//=============================================================================
// 成績データ構造体の実装
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