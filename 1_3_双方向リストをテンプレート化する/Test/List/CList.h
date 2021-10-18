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
#include "CIter.h"


template<class T>//テンプレート化
class CList
{
private:
	TNode<T> *m_dummyFirst;
	TNode<T> *m_dummyEnd;
	TNode<T> *m_node;//参照用のデータ

public:

	CList();

	/**
* @brief	データをセットする
* @return　
*/
	void Init(std::ifstream &file);
/**
* @brief	終了処理
* @return　
*/
	void Exit();


/**
* @brief	データの挿入（イテレータ）
* @return　 成功ならtrue,失敗ならfalse
*/
	bool Insert(CConstIterator<T> itr, const TRecord& record);
	/**
	* @brief	データの削除（イテレータ）
	* @return　 成功ならtrue,失敗ならfalse
	*/
	bool Delete(CConstIterator<T> itr);


/**
* @brief	先頭ノードを指すイテレータの取得
* @return　　先頭イテレータ
*/
	CIterator<T> GetFirstNode();


	/**
	* @brief	先頭ダミーノードの取得
	* @return　　先頭ダミーノード
	*/
	TNode<T>* GetDummy_First()const;

/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 */
	CIterator<T> GetEndNode();

	/**
	* @brief	末尾ダミーノードの取得
	* @return　　末尾ダミーノード
	*/
	TNode<T>* GetDummy_End()const;


/**
* @brief	指定された番目のノードを返す
* @return　　指定された番目のノード
*/
	TNode<T>* GetNode(int listNumber)const;




	/**
* @brief	先頭ダミーノードを指すイテレータの取得
* @return　　先頭ダミーイテレータ
*/
	CIterator<T> GetDummyFirst();
		/**
	 * @brief	末尾ダミーノードを指すイテレータの取得
	 * @return	末尾ダミーイテレータ
	 */
	CIterator<T> GetDummyEnd();


/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
	int  GetDataCnt() const;


};