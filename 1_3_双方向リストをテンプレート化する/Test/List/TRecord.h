/*
  @brief ���уf�[�^
  @author ��F���
  @date 10/6
 */

#pragma once
#include <string>


struct TRecord
{
	int m_score;
	std::string m_name;

public:
	//���p�̂ɂ���
	bool operator==(TRecord&) const;

	bool operator==(const TRecord&) const;

};