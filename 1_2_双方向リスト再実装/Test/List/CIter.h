#pragma once
#include "TNode.h"

/*
  @brief 反復子のクラス（const版）
  @author 岩熊一樹
  @date 10/6
 */

class CConstIterator
{

protected:
	//参照中のノード
	TNode* m_node;

public:
/*
  @breif	コンストラクタ
 */
	CConstIterator(TNode* p);//番地を指定し、どこから始めるのかを指定

/*
  @breif　　リストの先頭に向かって１つ進める（）
  @return
 */
	void GoPrevNode();
/*
  @breif　　リストの末尾に向かって１つ進める（）
  @return
 */
	void GoNextNode();


/*
  @breif　　イテレータの指す要素を取得する[const版]（）
  @return　　イテレータの指す要素[const版]（）
 */
	TNode* Getm_node()const;/*{ return m_node; }*/

};


/*
  @brief 反復子のクラス（非const版）
  @author 岩熊一樹
  @date 10/6
 */

//イテレーター（リストなどのデータ構造を簡単に辿れる仕組み）
class CIterator :public CConstIterator
{
public:

/*
  @breif　コンストラクタ
 */
	CIterator(TNode* p) : CConstIterator(p) {}//継承

/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
	TNode* Getm_node();


};

