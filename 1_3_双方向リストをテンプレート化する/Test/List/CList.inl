/*
  @brief 双方向リストのクラスのinl
  @author 岩熊一樹
  @date 10/18
 */
#pragma once
#include "CList.h"


 /*
   @fn
   @brief　コンストラクタ実行際に、先頭と終端を示すノードを生成する
  */
template<class T>//テンプレート化
CList<T>::CList()
{
	m_dummyFirst = new TNode();
	m_dummyEnd = new TNode();

	//始点の設定
	m_dummyFirst->m_next = m_dummyEnd;
	m_dummyFirst->m_prev = m_dummyFirst;//自身のアドレスにセットし、「始点」とする
	m_dummyFirst->m_record.m_score = 1;
	m_dummyFirst->m_record.m_name = "dummyFirst";


	//終点の設定
	m_dummyEnd->m_next = m_dummyEnd;//自身のアドレスにセットし、「終点」とする
	m_dummyEnd->m_prev = m_dummyFirst;
	m_dummyEnd->m_record.m_score = 99999;
	m_dummyEnd->m_record.m_name = "dummyEnd";
}




/*
  @fn
  @brief　生成したノードを全て削除する
 */
template<class T>//テンプレート化
void CList<T>::Exit()
{
	TNode *box = m_dummyFirst;
	while (box != m_dummyEnd)
	{
		m_node = box;
		box = box->m_next;
		delete m_node;
	}
	delete box;//box==Dummy_Endを削除して終了
}


/*
  @fn
  @brief　ノードを生成し挿入する
  @param　（CIterator itr）イテレータ（どの位置の後に挿入するか）
  @param　（const TRecord& record）挿入するデータ
 @param　（int cnt）挿入する個数
 */
template<class T>//テンプレート化
bool CList<T>::Insert(CConstIterator<T> itr, const TRecord& record)
{

	//ノードを生成
	m_node = new TNode();
	//データセット
	m_node->m_record.m_score = record.m_score;//
	m_node->m_record.m_name = record.m_name;//名前

	//末尾への指定の場合、m_dummyEndの前に挿入する
	if (itr.Getm_node() == m_dummyEnd)//イテレータが末尾を指定していていたら
	{
		//挿入する位置の前にあるノード
		TNode* InsertPrev = itr.Getm_node()->m_prev;
		//挿入する位置の次にあるノード
		TNode* InsertNext = itr.Getm_node();

		////ノードを挿入する
		m_node->m_prev = InsertPrev;
		m_node->m_next = InsertNext;

		//前後のノードのポインタを繋ぎ直し
		InsertPrev->m_next = m_node;
		InsertNext->m_prev = m_node;

		return true;//処理抜け
	}

	//末尾でない場合、ノードを入れる箇所を検索
	for (TNode *i = m_dummyFirst; i != m_dummyEnd; i = i->m_next)
	{
		if (i == itr.Getm_node())//見つかった場合（先頭・中間ノードの後に挿入する場合）
		{
			//挿入する位置の前にあるノード
			TNode* InsertPrev = i;
			//挿入する位置の次にあるノード
			TNode* InsertNext = i->m_next;

			//そのノードの後に挿入する
			m_node->m_prev = InsertPrev;
			m_node->m_next = InsertNext;

			//前後のノードのポインタを繋ぎ直し
			InsertPrev->m_next = m_node;
			InsertNext->m_prev = m_node;

			return true;//処理抜け
		}

	}

	return false;// いずれも該当しなければ、挿入失敗（そもそも存在しないノードの指定）と判断
}

/*
  @fn
  @brief　ノードを生成し挿入する
  @param　（CIterator itr）イテレータ（どの位置を削除するか）
 */
template<class T>//テンプレート化
bool CList<T>::Delete(CConstIterator<T> itr)
{
	//ノードの削除箇所を検索
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		if (i == itr.Getm_node())//見つかった場合（先頭・中間ノードの後を削除する場合）
		{
			//削除する位置の前にあるノード
			TNode* DeletePrev = i->m_prev;
			//削除する位置の次にあるノード
			TNode* DeleteNext = i->m_next;

			//前後のノードのポインタを繋ぎ直し
			DeletePrev->m_next = DeleteNext;
			DeleteNext->m_prev = DeletePrev;

			//削除
			delete i;

			return true;//処理抜け
		}

	}

	return false;// いずれも該当しなければ、失敗（そもそも存在しないノードの指定）と判断
}

/**
* @brief	先頭ノードを指すイテレータの取得
* @return　　先頭イテレータ
*/
template<class T>//テンプレート化
CIterator<T> CList<T>::GetFirstNode()
{
	return CIterator<T>(m_dummyFirst->m_next);
}


/**
* @brief	先頭ダミーノードの取得
* @return　　先頭ダミーノード
*/
template<class T>//テンプレート化
TNode<T>* CList<T>::GetDummy_First()const { return m_dummyFirst; };



/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 */
template<class T>//テンプレート化
CIterator<T> CList<T>::GetEndNode()
{
	return CIterator<T>(m_dummyEnd->m_prev);
}

/**
* @brief	末尾ダミーノードの取得
* @return　　末尾ダミーノード
*/
template<class T>//テンプレート化
TNode<T>* CList<T>::GetDummy_End()const { return m_dummyEnd; };

/**
* @brief	指定された番目のノードを返す
* @return　　指定された番目のノード
*/
template<class T>//テンプレート化
TNode<T>* CList<T>::GetNode(int listNumber)const
{
	int cnt = 1;//1番目

	//先頭からリストを辿り数える
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		if (cnt == listNumber)
		{
			return i;
		}

		cnt++;//更新
	}

	//処理抜けしてしまうなら、リストのノードの数に対して引数に誤りがある
	return false;
}




/**
* @brief	先頭ダミーノードを指すイテレータの取得
* @return　　先頭ダミーイテレータ
*/
template<class T>//テンプレート化
CIterator<T> CList<T>::GetDummyFirst()
{
	return CIterator<T>(m_dummyFirst);
}
/**
* @brief	末尾ダミーノードを指すイテレータの取得
* @return	末尾ダミーイテレータ
*/
template<class T>//テンプレート化
CIterator<T> CList<T>::GetDummyEnd()
{
	return CIterator<T>(m_dummyEnd);
}


/**
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
template<class T>//テンプレート化
int  CList<T>::GetDataCnt() const
{
	int cnt = 0;

	//ノード個数を検索
	for (TNode *i = m_dummyFirst->m_next; i != m_dummyEnd; i = i->m_next)
	{
		cnt++;
	}

	return cnt;
}

