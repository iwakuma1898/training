/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <string>


class CNode
{
protected:
	std::string Key;//キー
	std::string EngName;//キーに紐づいた英単語
	CNode *Prev, *Next;//タスクの前後関係を指すポインタ

public:

	void SetKey(const std::string &name);
	void SetEngName(const std::string &name);
	void SetPrev(CNode *prev);
	void SetNext(CNode *next);

	std::string GetKey()const;
	std::string GetEngName()const ;
	CNode* GetPrev()const;
	CNode* GetNext()const ;
};

