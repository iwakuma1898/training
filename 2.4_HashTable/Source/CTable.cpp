/*
  @brief ハッシュテーブルクラス
  @author 岩熊一樹
  @date 10/6
 */

#include "CTable.h"

 /*
   @fn
   @brief　ノードを生成し挿入する
   @param　（std::string lineKey）読み取ったキー
   @param　（std::string lineEngName）読み取った名前
  */
void CTable::Insert(std::string lineKey, std::string  lineEngName)
{
	//ハッシュ値を算出する
	int hashkey = CalcHash(lineKey);

	if (Table[hashkey].GetEngName() == "")//空きがある場合
	{
		//配列にセット
		Table[hashkey].SetKey(lineKey);
		Table[hashkey].SetEngName(lineEngName);
	}
	else//既に配列に値が入っていた場合
	{
		//連結リストが作られていない場合
		if (Table[hashkey].GetNext() == NULL)
		{
			List = new CList();//リストを生成する
			List->Insert(lineKey, lineEngName);//ノードを生成しリストに挿入
			Table[hashkey].SetMyList(List);//配列に紐づいたリストとして登録する
		}
		else//連結リストを辿り、末尾にノードを生成する
		{
			//この配列に紐づいたリストリストに,ノードを生成し挿入
			Table[hashkey].GetMyList()->Insert(lineKey, lineEngName);
		}
	}

}

/*
  @fn
  @brief　ハッシュテーブルを検索する
  @param　（std::string Key）キー
 */
std::string CTable::Search(std::string Key)
{
	//ハッシュ値を算出する
	int hashkey = CalcHash(Key);

	//検索
	if (Table[hashkey].GetKey() == Key)//一致した場合
	{
		return Table[hashkey].GetEngName();//
	}
	else//Keyが違うなら、リストを辿る
	{
		if (Table[hashkey].GetEngName() == "")//配列にそもそも辞書リストが入っていない場合
		{
			return "英単語が見つかりませんでした。（data.txtの左側列に無い単語ではありませんか？）";
		}

		List = Table[hashkey].GetMyList();//この配列に紐づいたリスト

		if(List ==NULL)//配列には１単語だけで、リストが続いていない場合
		{
			return "英単語が見つかりませんでした。（data.txtの左側列に無い単語ではありませんか？）";
		}


		////配列に紐づいたリストを探索
		for (CNode *i = List->GetDummy_First()->GetNext(); i != List->GetDummy_End(); i = i->GetNext())
		{
			if (i->GetKey() == Key)
			{
				return i->GetEngName();//
			}
		}
		//ループを抜けた場合、Keyの入力値が誤っているということ
		return "英単語が見つかりませんでした。（data.txtの左側列に無い単語ではありませんか？）";
	}
}

/*
  @fn
  @brief　ハッシュ値を算出する
  @param　（std::string Key）キー
 */
int CTable::CalcHash(std::string Key)//キーからハッシュ値を計算
{
	int num = 0;
	int length = Key.size(); //文字列の長さ
	for (int i = 0; i < length; i++)
	{
		num += (Key[i] - '0');//文字列を数値に変換
	}
	int hash = num % TableMAX;//ハッシュ値化
	return hash;
}

/*
  @fn
  @brief　ハッシュテーブルに紐づいたリストを削除する
 */
void CTable::Exit()
{
	for (int i = 0; i < TableMAX; i++)//テーブルの全ての配列を探索
	{
		if (Table[i].GetMyList() != NULL)//配列に紐づいたリストを発見
		{
			Table[i].GetMyList()->Exit();//リストを削除
		}
	}
}