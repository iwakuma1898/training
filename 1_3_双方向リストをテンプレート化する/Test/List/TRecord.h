/*
  @brief ¬Ρf[^
  @author βFκχ
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
 * @breif	ΏZqπI[o[[h[ρconstΕ]
 * @return	Ώδr΅½Κ
 */
	bool operator==(TRecord&) const;
	/**
 * @breif	ΏZqπI[o[[h[constΕ]
 * @return	Ώδr΅½Κ
 */
	bool operator==(const TRecord&) const;

};

