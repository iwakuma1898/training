/*
  @brief 成績データ
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <string>


struct TRecord
{
	int m_score;
	std::string m_name;

public:
	//共用体にする
	bool operator==(TRecord&) const;

	bool operator==(const TRecord&) const;

};