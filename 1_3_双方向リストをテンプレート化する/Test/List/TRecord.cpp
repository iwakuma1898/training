/*
  @brief 成績データ
  @author 岩熊一樹
  @date 10/6
 */

#include "TRecord.h"


  /**
   * @breif	等価演算子をオーバーロード[非const版] 
   * @return	等価比較した結果
   */
bool TRecord::operator==(TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}
/**
 * @breif	等価演算子をオーバーロード[const版]
 * @return	等価比較した結果
 */
bool TRecord::operator==(const TRecord& pData) const
{
	return m_score == pData.m_score && m_name == pData.m_name;
}