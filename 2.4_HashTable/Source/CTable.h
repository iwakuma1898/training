/*
  @brief ハッシュテーブルクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include "CNode_Table.h"

#define TableMAX (20)

class CTable
{
private:
	CNode_Table Table[TableMAX];
	CList *List;
	CNode *NowNode;//検索用
	CNode *InsertNode;//挿入する用のノード

public:
	void Insert(std::string lineKey, std::string  lineEngName);
	std::string Search(std::string key);
	int CalcHash(std::string key);//キーからハッシュ値を計算
	void Clear();

};



