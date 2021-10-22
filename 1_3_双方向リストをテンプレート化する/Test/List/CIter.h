/*
  @brief 反復子のクラス（const版）
  @author 岩熊一樹
  @date 10/6
 */

#pragma once

template<class T>
struct TNode;

template<class T>
class CConstIterator
{
public:
	TNode<T>* m_node;

/*
  @breif	コンストラクタ
 */
	explicit CConstIterator(TNode<T>* p);//番地を指定し、どこから始めるのかを指定

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
	const T* GetRecord()const;
};


/*
  @brief 反復子のクラス（非const版）
  @author 岩熊一樹
  @date 10/6
 */

//イテレーター（リストなどのデータ構造を簡単に辿れる仕組み）
template<class T>
class CIterator :public CConstIterator<T>
{
public:
	TNode<T>* m_node;

/*
  @breif　コンストラクタ
 */
	CIterator(TNode<T>* p) : CConstIterator<T>(p) {}//継承

/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
	T* GetRecord();

};

#include "CIter.inl"