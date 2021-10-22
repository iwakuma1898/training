/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once


template<class T>
struct TNode
{
	TNode *m_prev;//前ポインタ
	TNode *m_next;//後ポインタ

	T* m_record;//成績データ
};

template<class T>
class CConstIterator;
template<class T>
class CIterator;
/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */
template<class T>
class CList
{
private:
	TNode<T> *m_dummy;


public:

	CList();//コンストラクタ
	~CList();//デスストラクタ


/**
* @brief	データの挿入（イテレータ）
* @return　 成功ならtrue,失敗ならfalse
*/
	bool Insert(CConstIterator<T> itr, const T& record);
	/**
	* @brief	データの削除（イテレータ）
	* @return　 成功ならtrue,失敗ならfalse
	*/
	bool Delete(CConstIterator<T> itr);


/**
* @brief	先頭ノードを指すイテレータの取得
* @return　　先頭イテレータ
*/
	CIterator<T> GetFirstIter();




/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 //////*/
	CIterator<T> GetEndIter();




///**
//* @brief	指定された番目のイテレータを返す
//* @return　　指定された番目のイテレータ
//*/
	CConstIterator<T> GetIter(int listNumber)const;



/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
	int  GetDataCnt() const;



};


#include "CList.inl"
