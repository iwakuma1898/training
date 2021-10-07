/*
　CNodeの派生クラス
  @brief ハッシュテーブル専用のCNodeクラス
  　　　 CList* MyList;で配列に連結しているリストを把握できる
  @author 岩熊一樹
  @date 10/6
 */


#pragma once
#include "CList.h"

//派生クラス
class CNode_Table :public CNode
{
protected:
	CList* MyList;

public:
	void SetMyList(CList *list);
	CList* GetMyList()const;

};