#pragma once
#include "CList.h"
#include "TNode.h"

//イテレーター（リストなどのデータ構造を簡単に辿れる仕組み）
class CIter {

private:
	//リスト
	CList* m_list;

	//参照中のノード
	TNode* m_node;

public:
	//イテレータの指す要素を取得する[非const版]（）



};

class ConstCIter:public CIter
{

private:
	//

public:

	//リストの先頭に向かって１つ進める（）

	//リストの末尾に向かって１つ進める（）

	//イテレータの指す要素を取得する[const版]（）


};


//
////イテレーター（リストなどのデータ構造を簡単に辿れる仕組み）
//class CIter {
//
//private:
//	//リスト
//	CTaskList* List;
//
//	//参照中のノード
//	CTask* Task;
//
//public:
//	//コンストラクタ
//	CTaskIter(CTaskList* list);
//
//	//次のタスクがある時に真を返す
//	bool HasNext();
//
//	//次のタスクを取り出す
//	CTask* Next();
//
//
//	//直前に参照したタスクを削除する
//	void Remove();
//
//};
