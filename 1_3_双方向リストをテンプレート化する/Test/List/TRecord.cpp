/*
  @brief ¬Ρf[^
  @author βFκχ
  @date 10/6
 */

#include "TRecord.h"


  /**
   * @breif	ΏZqπI[o[[h[ρconstΕ] 
   * @return	Ώδr΅½Κ
   */
bool TRecord::operator==(TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}
/**
 * @breif	ΏZqπI[o[[h[constΕ]
 * @return	Ώδr΅½Κ
 */
bool TRecord::operator==(const TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}