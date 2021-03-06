/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */

#include "CList.h"


/*
  @fn
  @brief　コンストラクタ実行際に、先頭と終端を示すノードを生成する
 */
CList::CList()
{
	m_dummy = new TNode();

	//ダミーノード
	m_dummy->m_next = m_dummy;
	m_dummy->m_prev = m_dummy;//自身のアドレスにセットし、「始点」とする
	m_dummy->m_record.m_name = "m_dummy";
}

/*
  @fn
  @brief　デスストラクタ
 */
CList::~CList()
{
	TNode* mNode = m_dummy->m_prev;
	TNode* deleteNode = nullptr;
	// 生成したノードを全て削除する
	while (mNode != m_dummy)
	{
		deleteNode = mNode;
		mNode = mNode->m_prev;
		delete deleteNode;
	}
	delete m_dummy;// 最後
	m_dummy = nullptr;
}




/*
  @fn
  @brief　ノードを生成し挿入する
  @param　（CIterator itr）イテレータ（どの位置の後に挿入するか）
  @param　（const TRecord& record）挿入するデータ
 @param　（int cnt）挿入する個数
 */
bool CList::Insert(CConstIterator itr, const TRecord& record) 
{
	if (itr.m_node ==nullptr)
	{
		return false;//処理抜け
	}


	//ノードを生成
	TNode *pNode = new TNode();
	//データセット
	pNode->m_record.m_score = record.m_score;//
	pNode->m_record.m_name = record.m_name;//名前


	//挿入する位置の前にあるノード
	TNode* InsertPrev = itr.m_node;
	//挿入する位置の次にあるノード
	TNode* InsertNext = itr.m_node->m_next;

	//そのノードの後に挿入する
	pNode->m_prev = InsertPrev;
	pNode->m_next = InsertNext;

	//前後のノードのポインタを繋ぎ直し
	InsertPrev->m_next = pNode;
	InsertNext->m_prev = pNode;

	return true;//処理抜け
}

/*
  @fn
  @brief　ノードを生成し挿入する
  @param　（CIterator itr）イテレータ（どの位置を削除するか）
 */
bool CList::Delete(CConstIterator itr)
{
	//ノードの削除箇所を検索
	for (TNode *i = m_dummy->m_next; i != m_dummy; i = i->m_next)
	{
		if (i == itr.m_node)//見つかった場合（先頭・中間ノードの後を削除する場合）
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
CIterator CList::GetFirstIter()
{
	return CIterator(m_dummy->m_next);
}




/**
 * @brief	末尾ノードを指すイテレータの取得
 * @return	末尾イテレータ
 */
CIterator CList::GetEndIter()
{
	return CIterator(m_dummy->m_prev);
}

/**
* @brief	指定された番目のノードを返す
* @return　　指定された番目のノード
*/
CIterator CList::GetIter(int listNumber)const
{
	int cnt = 0;//(0ベース)

	//先頭からリストを辿り数える
	for (CIterator i = m_dummy->m_next; i.m_node != m_dummy; i.GoNextNode())
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
* @brief	リストのノード数を返す
* @return	リストのノード数
*/
int  CList::GetDataCnt() const
{
	int cnt = 0;

	//ノード個数を検索
	for (TNode *i = m_dummy->m_next; i != m_dummy; i = i->m_next)
	{
		cnt++;
	}

	return cnt;
}

