/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
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
	CNode* GetDummy_First()const ;
	CNode* GetDummy_End()const;

	CList();
	void Insert(std::string lineKey, std::string lineName);
	void Exit();
};