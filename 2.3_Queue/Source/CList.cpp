/*
  @brief 双方向リストのクラス
  @author 岩熊一樹
  @date 10/8
 */

#include "CList.h"

 /*
   @fn
   @brief　メンバ変数の参照
  */

const CNode* CList::GetDummy_First()const { return Dummy_First; };
const CNode* CList::GetDummy_End()const { return Dummy_End; };

/*
  @fn
  @brief　コンストラクタ実行際に、先頭と終端を示すノードを生成する
 */
CList::CList()
{
	Dummy_First = new CNode();
	Dummy_End = new CNode();

	//始点の設定
	Dummy_First->SetNext(Dummy_End);
	Dummy_First->SetPrev(Dummy_First);//自身のアドレスにセットし、「始点」とする

	//終点の設定
	Dummy_End->SetNext(Dummy_End);//自身のアドレスにセットし、「終点」とする
	Dummy_End->SetPrev(Dummy_First);
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
	Node = new CNode();
	//ノードにセット
	Node->SetNum(lineNum);//SCORE
	Node->SetName(lineName);//名前

	//ノードを入れる箇所を検索
	for (CNode *i = Dummy_First; i != Dummy_End; i = i->GetNext())
	{
		if (i->GetNext() == Dummy_End)
		{
			//新しいノードを挿入する
			Node->SetPrev(i);
			Node->SetNext(Dummy_End);

			//前後のノードのポインタを繋ぎ直し
			i->SetNext(Node);
			Dummy_End->SetPrev(Node);

			break;
		}
	}

}

/*
  @fn
  @brief　SCORE順に並べ替える
 */
void CList::SortScore()
{
	CNode *MaxScoreNode;//ソートの基準値
	CNode *NowConfirm;//先頭が確定した位置を知るためのもの
	CNode *PrevBox;//引っ越し用
	CNode *NextBox;//引っ越し用

	//リストの先頭を取得
	MaxScoreNode = Dummy_First->GetNext();//先頭のノードのSCOREを仮に最大値に設定

	//確定列を、dummy_Firsより始める
	NowConfirm = Dummy_First;

	//ソート
	while (NowConfirm != Dummy_End)//確定列がdummy_Endに到達するまで
	{
		//最大値を探す
		for (CNode *i = NowConfirm->GetNext(); i != Dummy_End; i = i->GetNext())
		{
			if (MaxScoreNode->GetNum() < i->GetNum())//最大値が見つかった場合
			{
				MaxScoreNode = i;//最大値を更新
			}

		}
		//ループを抜けたら、MaxScoreNodeが未確定列の中で最大値のSCOREを持つノード

		//最大値のノードMaxScoreNodeの前後のノード関係を繋ぎなおす
		PrevBox = MaxScoreNode->GetPrev();
		PrevBox->SetNext(MaxScoreNode->GetNext());
		NextBox = MaxScoreNode->GetNext();
		NextBox->SetPrev(MaxScoreNode->GetPrev());

		//最大値のノードMaxScoreNodeを確定列に入れるため、前後のノード関係を繋ぎなおす
		NextBox = NowConfirm->GetNext();//MaxScoreNodeの次になるノード
		NextBox->SetPrev(MaxScoreNode);//MaxScoreNodeを前に設定

		NowConfirm->SetNext(MaxScoreNode);//確定列の次にMaxScoreNodeが来る

		//最大値のノードMaxScoreNodeに設定されている前後ポインタを更新する
		MaxScoreNode->SetPrev(NowConfirm);//MaxScoreNodeの前になるノードは確定列
		MaxScoreNode->SetNext(NextBox);

		//確定列を更新
		NowConfirm = MaxScoreNode;

		//最大値を、確定列の次に仮定する
		MaxScoreNode = MaxScoreNode->GetNext();
	}

}

/*
  @fn
  @brief　生成したノードを全て削除する
 */
void CList::Clear()
{
	CNode *box = Dummy_First;
	while (box != Dummy_End)
	{
		Node = box;
		box = box->GetNext();
		delete Node;
	}
	delete box;//box==Dummy_Endを削除して終了
}