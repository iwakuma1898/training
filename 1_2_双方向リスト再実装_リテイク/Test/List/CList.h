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
	TNode *m_dummy;


public:

	CList();//コンストラクタ
	~CList();//デスストラクタ


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
	CIterator GetFirstIter();




/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 //////*/
	CIterator GetEndIter();




///**
//* @brief	指定された番目のイテレータを返す
//* @return　　指定された番目のイテレータ
//*/
	CIterator GetIter(int listNumber)const;



/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
	int  GetDataCnt() const;



};