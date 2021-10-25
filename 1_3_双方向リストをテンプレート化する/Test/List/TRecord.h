/*
  @brief 成績データ
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <string>

struct TRecord
{
public:
	int m_score;
	std::string m_name;

	/**
 * @breif	等価演算子をオーバーロード[非const版]
 * @return	等価比較した結果
 */
	bool operator==(TRecord&) const;
	/**
 * @breif	等価演算子をオーバーロード[const版]
 * @return	等価比較した結果
 */
	bool operator==(const TRecord&) const;

};

