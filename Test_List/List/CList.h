/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "TNode.h"


class CList
{
private:
	TNode *m_dummyFirst;
	TNode *m_dummyEnd;
	TNode *m_node;//参照用のデータ

public:

	CList();
	void Exit();

	void SortScore();

	//データ数の取得
	int  GetDataNum() { return 0; }
	//データの挿入（イテレータ）
	void Insert(int lineNum, std::string lineName);
	//データの削除（イテレータ）
	void Delete();
	//先頭イテレータ取得
	//TNode* GetDummy_First();
	//先頭コンストイテレータ取得
	TNode* GetDummy_First()const;
	//末尾イテレータ取得
	//TNode* GetDummy_End();
	//末尾コンストイテレータ取得
	TNode* GetDummy_End()const;

};