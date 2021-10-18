/*
  @brief ¬Ñƒf[ƒ^
  @author ŠâŒFˆê÷
  @date 10/18
 */

#include "TRecord.h"

bool TRecord::operator==(TRecord& data) const
{
	return m_score == data.m_score && m_name == data.m_name;
}
//-----------------------------------------------------------------------------
bool TRecord::operator==(const TRecord& data) const
{
	return m_score == data.m_score && m_name == data.m_name;
}