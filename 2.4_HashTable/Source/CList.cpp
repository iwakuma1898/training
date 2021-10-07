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

CNode* CList::GetDummy_First()const { return Dummy_First; };
CNode* CList::GetDummy_End()const { return Dummy_End; };

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
void CList::Insert(std::string lineKey, std::string lineName)
{
	//ノードを生成
	Node = new CNode();
	//ノードにセット
	Node->SetKey(lineKey);//SCORE
	Node->SetEngName(lineName);//名前

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
  @brief　生成したノードを全て削除する
 */
void CList::Exit()
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