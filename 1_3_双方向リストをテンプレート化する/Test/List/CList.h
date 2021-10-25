/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once


template<class T>
struct TNode
{
	TNode* m_prev;//前ポインタ
	TNode* m_next;//後ポインタ

	T* m_record;//成績データ
};

template<class T>
class CConstIterator;
template<class T>
class CIterator;


template<class T>
class CList
{
private:
	TNode<T> *m_dummy;


public:


	CList();//コンストラクタ
	~CList();//デスストラクタ


/**
* @brief	データの挿入（イテレータ）[const版]
* @return　 成功ならtrue,失敗ならfalse
*/
	bool Insert(CConstIterator<T> itr, const T& record);

	/**
* @brief	データの挿入（イテレータ）[非const版]
* @return　 成功ならtrue,失敗ならfalse
*/
	bool Insert(CIterator<T> itr, const T& record);

	/**
	* @brief	データの削除（イテレータ）[const版]
	* @return　 成功ならtrue,失敗ならfalse
	*/
	bool Delete(CConstIterator<T> itr);


	/**
	* @brief	データの削除（イテレータ）[非const版]
	* @return　 成功ならtrue,失敗ならfalse
	*/
	bool Delete(CIterator<T> itr);


	/**
* @brief	先頭ノードを指すイテレータの取得[const版]
* @return　　先頭イテレータ
*/
	CConstIterator<T> GetConstFirstIter();

	/**
* @brief	先頭ノードを指すイテレータの取得[非const版]
* @return　　先頭イテレータ
*/
	CIterator<T> GetFirstIter();


	/**
	 * @brief	末尾ノードを指すイテレータの取得[const版]
	 * @return	末尾イテレータ
	 //////*/
	CConstIterator<T> GetConstEndIter();


/**
 * @brief	末尾ノードを指すイテレータの取得[非const版]
 * @return	末尾イテレータ
 //////*/
	CIterator<T> GetEndIter();

///**
//* @brief	指定された番目のイテレータを返す
//* @return　　指定された番目のイテレータ
//*/
	CConstIterator<T> GetIter(int listNumber)const;

	///**
//* @brief	指定された番目のイテレータを返す
//* @return　　指定された番目のイテレータ
//*/
	CIterator<T> GetIter(int listNumber);


/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
	int  GetDataCnt() const;


	/**
* @brief	イテレータが、ダミーノードであるかを確認する[const版]
* @return	ダミーノードであるかの真偽結果
*/
	bool CheckIterDummy(CConstIterator<T> Iter);

		/**
* @brief	イテレータが、ダミーノードであるかを確認する[非const版]
* @return	ダミーノードであるかの真偽結果
*/
	bool CheckIterDummy(CIterator<T> Iter);


	/**
 * @brief		イテレータが指すノードを探索する
 * @param[in]	指定位置のイテレータ
 * @return		指定位置のノード、失敗はnullptrを返す
 */
	TNode<T>* FindNode(CIterator<T> itr);
	TNode<T>* FindNode(CConstIterator<T> itr);

};


#include "CList.inl"
