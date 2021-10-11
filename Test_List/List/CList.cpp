/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/6
 */

#include "CList.h"

 /*
   @fn
   @brief　メンバ変数の参照
  */

TNode* CList::GetDummy_First()const { return m_dummyFirst; };
TNode* CList::GetDummy_End()const { return m_dummyEnd; };

/*
  @fn
  @brief　コンストラクタ実行際に、先頭と終端を示すノードを生成する
 */
CList::CList()
{
	m_dummyFirst = new TNode();
	m_dummyEnd = new TNode();

	//始点の設定
	m_dummyFirst->m_next = m_dummyEnd;
	m_dummyFirst->m_prev=m_dummyFirst;//自身のアドレスにセットし、「始点」とする

	//終点の設定
	m_dummyEnd->m_next=m_dummyEnd;//自身のアドレスにセットし、「終点」とする
	m_dummyEnd->m_prev=m_dummyFirst;
}

/*
  @fn
  @brief　生成したノードを全て削除する
 */
void CList::Exit()
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
  @param　（int lineNum）読み取った文の数値
  @param　（std::string lineName）読み取った文の名前
 */
void CList::Insert(int lineNum, std::string lineName)
{
	//ノードを生成
	m_node = new TNode();
	//ノードにセット
	m_node->m_record.m_score=lineNum;//SCORE
	m_node->m_record.m_name = lineName;//名前

	//ノードを入れる箇所を検索
	for (TNode *i = m_dummyFirst; i != m_dummyEnd; i = i->m_next)
	{
		if (i->m_next == m_dummyEnd)
		{
			//新しいノードを挿入する
			m_node->m_prev=i;
			m_node->m_next = m_dummyEnd;

			//前後のノードのポインタを繋ぎ直し
			i->m_next=m_node;
			m_dummyEnd->m_prev=m_node;

			break;
		}
	}

}



///
//  @fn
//  @brief　SCORE順に並べ替える
//

void CList::SortScore()
{
	TNode *MaxScoreNode;//ソートの基準値
	TNode *NowConfirm;//先頭が確定した位置を知るためのもの
	TNode *PrevBox;//引っ越し用
	TNode *NextBox;//引っ越し用

	//リストの先頭を取得
	MaxScoreNode = m_dummyFirst->m_next;//先頭のノードのSCOREを仮に最大値に設定

	//確定列を、dummy_Firsより始める
	NowConfirm = m_dummyFirst;

	//ソート
	while (NowConfirm != m_dummyEnd)//確定列がdummy_Endに到達するまで
	{
		//最大値を探す
		for (TNode *i = NowConfirm->m_next; i != m_dummyEnd; i = i->m_next)
		{
			if (MaxScoreNode->m_record.m_score < i->m_record.m_score)//最大値が見つかった場合
			{
				MaxScoreNode = i;//最大値を更新
			}

		}
		//ループを抜けたら、MaxScoreNodeが未確定列の中で最大値のSCOREを持つノード

		//最大値のノードMaxScoreNodeの前後のノード関係を繋ぎなおす
		PrevBox = MaxScoreNode->m_prev;
		PrevBox->m_next = (MaxScoreNode->m_next);
		NextBox = MaxScoreNode->m_next;
		NextBox->m_prev = (MaxScoreNode->m_prev);

		//最大値のノードMaxScoreNodeを確定列に入れるため、前後のノード関係を繋ぎなおす
		NextBox = NowConfirm->m_next;//MaxScoreNodeの次になるノード
		NextBox->m_prev = (MaxScoreNode);//MaxScoreNodeを前に設定

		NowConfirm->m_next = (MaxScoreNode);//確定列の次にMaxScoreNodeが来る

		//最大値のノードMaxScoreNodeに設定されている前後ポインタを更新する
		MaxScoreNode->m_prev = (NowConfirm);//MaxScoreNodeの前になるノードは確定列
		MaxScoreNode->m_next = (NextBox);

		//確定列を更新
		NowConfirm = MaxScoreNode;

		//最大値を、確定列の次に仮定する
		MaxScoreNode = MaxScoreNode->m_next;
	}

}


