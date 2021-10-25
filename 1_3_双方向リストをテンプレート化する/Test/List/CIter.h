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
protected:
	TNode<T>* m_node;

public:


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
	const T& Get()const;


	/**
 * @breif	等価演算子をオーバーロード[const版]
 * @return	等価比較した結果
 */
	bool operator==(const CConstIterator& itr) const;

	/**
* @breif	非等価演算子をオーバーロード[const版]
* @return	非等価比較した結果
*/
	bool operator!=(const CConstIterator& itr) const;


	/**
* @brief	ノードで不正なものであるかを確認する
* @return	ダミーノードであるかの真偽結果
*/
	bool CheckNode();
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

/*
  @breif　コンストラクタ
 */
	explicit CIterator(TNode<T>* p = nullptr);


/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
	T& Get();


/**
 * @breif	等価演算子をオーバーロード[非const版]
 * @return	等価比較した結果
 */
	bool operator==(const CIterator& itr) const;

	/**
 * @breif	非等価演算子をオーバーロード[非const版]
 * @return	非等価比較した結果
 */
	bool operator!=(const CIterator& itr) const;
};

#include "CIter.inl"