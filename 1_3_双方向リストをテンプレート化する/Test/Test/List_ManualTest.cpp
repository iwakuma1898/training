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


	//=================================== ID ===================================

//		/**********************************************************************************//**
//			@brief		データ数の取得機能について、constのメソッドであるかのテスト
//			@details	ID:リスト-8(手動)\n
//						データ数の取得機能のテストです。\n
//						constのメソッドであるかを確認しています。\n
//						有効にしてコンパイルが通れば成功です。\n
//						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
//		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_IS_CONST
			const CList<TRecord> list;
			EXPECT_EQ(0,list.GetDataCnt());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}
//
//		/**********************************************************************************//**
//			@brief		リストのデータ追加について、非constが保障されているかのテスト
//			@details	ID:リスト-15(手動)\n
//						リストのデータ追加テストです。\n
//						非constが保障されているかを確認しています。\n
//						有効にしてコンパイルエラーになれば成功です。\n
//						TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
//
//			@return		なし
//		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const CList<TRecord> list;
			CConstIterator<TRecord> it = list.GetDummyFirst();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		//		/**********************************************************************************//**
//			@brief		リストのデータ削除について、非constが保障されているかのテスト
//			@details	ID:リスト-22(手動)\n
//						リストのデータ削除テストです。\n
//						非constが保障されているかを確認しています。\n
//						有効にしてコンパイルエラーになれば成功です。\n
//						TT_TEST_ERASE_WHEN_CONSTマクロを定義すると有効になります。\n
//
//			@return		なし
//		*//***********************************************************************************/
		TEST(ListManualTest, TestEraseWhenConst)
		{
#if defined TT_TEST_ERASE_WHEN_CONST
			const CList<TRecord> list;
			CConstIterator<TRecord> it = list.GetDummyFirst();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_ERASE_WHEN_CONST
			SUCCEED();
		}

//**********************************************************************************
//	@brief		先頭イテレータの取得において、constのリストから、ConstIteratorでないIteratorの取得が行えないかをテスト
//	@details	ID:リスト-28(手動)\n
//				有効にしてコンパイルエラーになれば成功です。\n
//				TT_TEST_GET_HEAD_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n
//	@return		なし
//***********************************************************************************/
		TEST(ListManualTest, TestIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			const CList<TRecord> list;
			CIterator<TRecord> it = list.GetDummyFirst();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			SUCCEED();
		}
//**********************************************************************************
//	@brief		先頭コンストイテレータの取得においてコンストのメゾットかをテスト
//	@details	ID:リスト-34\n
//				有効にしてコンパイルが通れば成功です。\n
//				TT_TEST_GET_HEAD_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n
//	@return		なし
//***********************************************************************************/

		TEST(ListManualTest, TestConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST
			CList<TRecord> list;
			CConstIterator<TRecord> it = list.GetDummyFirst();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			SUCCEED();
		}

//**********************************************************************************
//	@brief		末尾イテレータの取得において、constのリストから、ConstIteratorでないIteratorの取得が行えないかをテスト
//	@details	ID:リスト-40\n
//				有効にしてコンパイルエラーになれば成功です。\n
//				TT_TEST_GET_TAIL_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n
//	@return		なし
//***********************************************************************************/
		TEST(ListManualTest, TestEndIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			const CList<TRecord> list;
			CIterator<TRecord> it = list.GetDummyEnd();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			SUCCEED();
		}

//**********************************************************************************
//	@brief		末尾コンストイテレータの取得においてコンストのメゾットかをテスト
//	@details	ID:リスト-46\n
//				有効にしてコンパイルが通れば成功です。\n
//				TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n
//	@return		なし
//***********************************************************************************/

		TEST(ListManualTest, TestConstEndIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			CList<TRecord> list;
			CConstIterator<TRecord> it = list.GetDummyEnd();
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//
#endif //TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}


		//=================================== イテレータ ===================================

//**********************************************************************************//**
//　@interface　イテレータの指す要素を取得する
//	@brief		ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
//	@details	ID:イテレータ-2\n
//	@result　　 成功：コンパイルエラーになることをチェック。自動テスト化しなくてよい。
//		        TT_TEST_GET_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n
//***********************************************************************************/
		TEST(IteratorTest, TestIteratorWhenSubstitutionConst)
		{
#if defined TT_TEST_GET_ITERATOR_WHEN_CONST	
			const CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetDummyEnd();
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndNode();//末尾イテレータの取得
			EXPECT_EQ(true, it.Getm_node()->m_record.m_name == "FirstIn");

#endif //TT_TEST_GET_ITERATOR_WHEN_CONST	
			SUCCEED();
		}


		//**********************************************************************************//**
		//　@interface　イテレータのコピーを行う
		//	@brief		ConstIteratorから、Iteratorのコピーが作成されないかをチェック
		//	@details	ID:イテレータ-17\n
		//	@result　　 成功：コンパイルエラーになることを確認する。自動テスト化しなくてよい。
		//***********************************************************************************/
		TEST(IteratorManualTest, TestIteratorCopyWhenConst)
		{
#if defined TT_TEST_ITERATOR_COPY_WHEN_CONST
			CConstIterator<TRecord> constItr;
			CIterator<TRecord> itr(constItr);
#endif// TT_TEST_ITERATOR_COPY_WHEN_CONST
			SUCCEED();
		}


		//**********************************************************************************//**
		//　@interface　イテレータの代入を行う
		//	@brief		IteratorにConstIteratorを代入できない事をチェック
		//	@details	ID:イテレータ-19\n
		//	@result　　 成功：コンパイルエラーになることを確認する。自動テスト化しなくてよい。
		//***********************************************************************************/
		TEST(IteratorManualTest, TestIteratorAssignWhenConst)
		{
#if defined TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			CIterator<TRecord> itr;
			CConstIterator<TRecord> constItr;
			itr = constItr;
#endif// TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			SUCCEED();
		}


	}	// chapter2
}	//	ex01_DataStructure
