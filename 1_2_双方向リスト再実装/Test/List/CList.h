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

class CList
{
private:
	TNode *m_dummyFirst;
	TNode *m_dummyEnd;
	TNode *m_node;//参照用のデータ

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
	bool Insert(CConstIterator itr, const TRecord& record);
	/**
	* @brief	データの削除（イテレータ）
	* @return　 成功ならtrue,失敗ならfalse
	*/
	bool Delete(CConstIterator itr);


/**
* @brief	先頭ノードを指すイテレータの取得
* @return　　先頭イテレータ
*/
	CIterator GetFirstNode();


	/**
	* @brief	先頭ダミーノードの取得
	* @return　　先頭ダミーノード
	*/
	TNode* GetDummy_First()const;

/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 */
	CIterator GetEndNode();

	/**
	* @brief	末尾ダミーノードの取得
	* @return　　末尾ダミーノード
	*/
	TNode* GetDummy_End()const;


/**
* @brief	指定された番目のノードを返す
* @return　　指定された番目のノード
*/
	TNode* GetNode(int listNumber)const;




	/**
* @brief	先頭ダミーノードを指すイテレータの取得
* @return　　先頭ダミーイテレータ
*/
	CIterator GetDummyFirst();
		/**
	 * @brief	末尾ダミーノードを指すイテレータの取得
	 * @return	末尾ダミーイテレータ
	 */
	CIterator GetDummyEnd();


/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
	int  GetDataCnt() const;


};