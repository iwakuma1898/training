/**********************************************************************************//**
	@file           List_ManualTest.cpp
	@brief          GoogleTest手動テストコードの書き方サンプル
	@par            手動テストとは、チェックリスト内の「自動テスト化しなくてよい」項目を指します。
	                defineマクロの条件分岐により、必要なものだけコンパイル対象になるようにしてください。
	@note Copyright (c) FromSoftware, Inc.
*//***********************************************************************************/


//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include <gtest/gtest.h>

// 例。自分のプロジェクトにあったヘッダファイルをincludeしてください。
//#include "LinkedList.h"
#include "../List/CList.h"


//#include "pch.h"
#include "List_ManualTest.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
//		//--------------------------------------------------------------------------------
//		// コンパイル関連手動テスト
//		//--------------------------------------------------------------------------------
//		/**********************************************************************************//**
//			@brief		データ数の取得機能について、constのメソッドであるかのテスト
//			@details	ID:リスト-8(手動)\n
//						データ数の取得機能のテストです。\n
//						constのメソッドであるかを確認しています。\n
//						有効にしてコンパイルが通れば成功です。\n
//						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
//		*//***********************************************************************************/
//		TEST(GetDataNumTest, TestGetDataNumWhenConst)
//		{
//#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
//			const LinkedList list;
//			EXPECT_EQ(0,list.GetDataNum());
//#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
//			SUCCEED();
//		}
//
//		/**********************************************************************************//**
//			@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
//			@details	ID:リスト-15(手動)\n
//						リスト末尾のデータ追加テストです。\n
//						非constが保障されているかを確認しています。\n
//						有効にしてコンパイルエラーになれば成功です。\n
//						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
//
//			@return		なし
//		*//***********************************************************************************/
//		TEST(ListManualTest, TestInsertWhenConst)
//		{
//#if defined TT_TEST_INSERT_WHEN_CONST
//			const LinkedList list;
//			LinkedList::ConstIterator it = list.GetBegin();
//			list.Insert(it, 1);//ここでエラー
//#endif //TT_TEST_INSERT_WHEN_CONST
//			SUCCEED();
//		}
	}	// chapter2
}	//	ex01_DataStructure
