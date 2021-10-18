/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/6
 */

#pragma once
#include <string>
#include "TRecord.h"

template<class T>//テンプレート化
struct TNode
{
	TNode *m_prev;//前ポインタ
	TNode *m_next;//後ポインタ

	//TRecord m_record;//成績データ
	T* m_record;//成績データ//型を設定できるようにする

};


