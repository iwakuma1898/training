#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "CNode.h"

class List
{
private:
	CNode *dummy_First;
	CNode *dummy_End;
	CNode *node;

public:

	void Init(const char *fileName)
	{
		//データ読み込み・必要な分のノード生成
		FileLoad_SetList(fileName);
		//SCORE順にソート
		SortScore();
	}

	void Draw()
	{
		//リストの先頭を取得
		node = dummy_First->GetNext();

		while (node != dummy_End)
		{
			std::cout << node->GetScore();
			std::cout << node->GetName() << std::endl;

			node = node->GetNext();
		}

	}

	//データを読み込み、データをセット
	void FileLoad_SetList(const char *fileName)
	{
		std::ifstream file(fileName);  // 読み込むファイルのパスを指定
		std::string line;//読み込み用（1行ずつ）

		node = new CNode();//データとしての最初のノードを生成する

		//始点の設定
		dummy_First = new CNode();
		dummy_First->SetNext(node);
		dummy_First->SetPrev(dummy_First);//自身のアドレスにセットし、「始点」とする

		//終点の設定
		dummy_End = new CNode();
		dummy_End->SetNext(dummy_End);//自身のアドレスにセットし、「終点」とする
		dummy_End->SetPrev(node);

		//現在のノートに、終点と始点をセット
		node->SetPrev(dummy_First);//先頭をダミーにして始点が分かるようにする
		node->SetNext(dummy_End);//末尾をダミーにして終点が分かるようにする


		CNode *NowNode = node;//次のノードに移る時の、引っ越し用のデータ

		while (std::getline(file, line)) {  // 1行ずつ読み込む

			int Num = 0;
			int NumPlace = 1;//桁の重み
			int EndScoreNum = line.find("\t"); //line.find("\t")で数字列が終わる文字列を検索

			for (int i = EndScoreNum - 1; i >= 0; i--)//数字列が終わる手前＝＝数字列を数値化する
			{
				Num += (line[i] - '0')*NumPlace;//文字列の一部を数字に変換し、桁の重みを掛けて代入
				NumPlace *= 10;//桁を上げる
			}

			//ノードにセット
			node->SetScore(Num);//SCORE
			node->SetName(line.substr(EndScoreNum));//名前

			//今回入力したデータを引っ越し
			NowNode = node;
			//次のノードを生成
			node = new CNode();
			node->SetPrev(NowNode);//前のノードは今回入力したノード
			node->SetNext(dummy_End);//末尾をダミーにして終点が分かるようにする
			//今回入力したノードのリストの繋ぎ直し
			NowNode->SetNext(node);//前のノードは次回入力するノード
		}
		//ループを抜けたら、最後のノードを調整する
		NowNode->SetNext(dummy_End);//最後に入力したノードの末尾をdummyにする
	}


	void SortScore()
	{
		CNode *MaxScoreNode;//ソートの基準値
		CNode *NowConfirm;//先頭が確定した位置を知るためのもの
		CNode *PrevBox;//引っ越し用
		CNode *NextBox;//引っ越し用

		//リストの先頭を取得
		MaxScoreNode = dummy_First->GetNext();//先頭のノードのSCOREを仮に最大値に設定

		//確定列を、dummy_Firsより始める
		NowConfirm = dummy_First;

		//ソート
		while (NowConfirm != dummy_End)//確定列がdummy_Endに到達するまで
		{
			//最大値を探す
			for (CNode *i = NowConfirm->GetNext(); i != dummy_End; i = i->GetNext())
			{
				if (MaxScoreNode->GetScore() < i->GetScore())//最大値が見つかった場合
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
};