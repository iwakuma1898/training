/*
  @brief ���уf�[�^
  @author ��F���
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
 * @breif	�������Z�q���I�[�o�[���[�h[��const��]
 * @return	������r��������
 */
	bool operator==(TRecord&) const;
	/**
 * @breif	�������Z�q���I�[�o�[���[�h[const��]
 * @return	������r��������
 */
	bool operator==(const TRecord&) const;

};

