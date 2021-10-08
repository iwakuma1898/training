/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/8
 */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "CNode.h"

class CList
{
private:
	CNode *Dummy_First;
	CNode *Dummy_End;
	CNode *Node;//参照用のデータ

public:
	const CNode* GetDummy_First()const;
	const CNode* GetDummy_End()const;

	CList();
	void Insert(int lineNum, std::string lineName);
	void SortScore();
	void Clear();
};