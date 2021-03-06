/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <string>

class CNode
{
private:
	int Score;
	std::string Name;
	CNode *Prev, *Next;//タスクの前後関係を指すポインタ

public:

	void SetScore(const int &score);
	void SetName(const std::string &name);
	void SetPrev(CNode *prev);
	void SetNext(CNode *next);

	int GetScore()const ;
	std::string GetName()const ;
	CNode* GetPrev()const;
	CNode* GetNext()const ;
};


