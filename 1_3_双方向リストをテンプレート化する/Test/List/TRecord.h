/*
  @brief ¬Ñƒf[ƒ^
  @author ŠâŒFˆê÷
  @date 10/6
 */

#pragma once
#include <string>

struct TRecord
{
public:
	int m_score;
	std::string m_name;

	bool operator==(TRecord&) const;
	bool operator==(const TRecord&) const;

};

