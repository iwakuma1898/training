/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/8
 */

#pragma once
#include <string>

class CNode
{
private:
	int Num;
	std::string Name;
	CNode *Prev, *Next;//タスクの前後関係を指すポインタ

public:

	void SetNum(int &num);
	void SetName(const std::string &name);
	void SetPrev(CNode *prev);
	void SetNext(CNode *next);

	int GetNum()const;
	const std::string& GetName()const;
	CNode* GetPrev()const;
	CNode* GetNext()const;
};


