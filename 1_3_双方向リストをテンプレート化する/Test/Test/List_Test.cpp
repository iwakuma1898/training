/**********************************************************************************//**
    @file           List_Test.cpp
    @brief          GoogleTest自動テストコードの書き方サンプル                    
    Copyright &copy FromSoftware, Inc.
*//***********************************************************************************/


// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include <gtest/gtest.h>

// 例。自分のプロジェクトにあったヘッダファイルをincludeしてください。
#include "../List/CList.h"

#include "../List/TRecord.h"

#include "../List/CIter.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{

		//=================================== データ数の取得 ===================================
		
		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntWhenEmpty){
		    CList<TRecord> list;
			EXPECT_EQ(0,list.GetDataCnt());
		}

//		/**********************************************************************************//**
//			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
//			@details	ID:リスト-1\n
//						データ数の取得機能のテストです。\n
//						リスト末尾への挿入を行った際の戻り値を確認しています。\n
//						データ数が1増えていれば成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntAfterPush)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();//ノードは末尾
			TRecord record = {100,"testname"};//データ内容(スコア、名前)
			ASSERT_TRUE(list.Insert(it, record));//末尾の手前にデータを挿入する
			EXPECT_EQ(1, list.GetDataCnt());
		}
//		
//		/**********************************************************************************//**
//			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
//			@details	ID:リスト-2\n
//						データ数の取得機能のテストです。\n
//						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
//						データ数が増えていなければ成功です。\n
//		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntAfterPushFailed)
		{
			CList<TRecord> list;
			CIterator<TRecord> it = nullptr;//失敗させるようにnullptrを指定
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			ASSERT_FALSE(list.Insert(it, record));
			EXPECT_EQ(0, list.GetDataCnt());
		}

//		/**********************************************************************************//**
//			@brief		データの挿入を行った際の戻り値のテスト
//			@details	ID:リスト-3\n
//						データ数の取得機能のテストです。\n
//						データの挿入を行った際の戻り値を確認しています。\n
//						データ数が1増えていれば成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntPush)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//ノードは先頭ダミーノードの次に入れる

			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			ASSERT_TRUE(list.Insert(it, record));//先頭にデータを挿入する
			EXPECT_EQ(1, list.GetDataCnt());
		}

		//		/**********************************************************************************//**
//			@brief		データの挿入を行った際に失敗した時の戻り値のテスト
//			@details	ID:リスト4-\n
//						データ数の取得機能のテストです。\n
//						データの挿入を行った際の戻り値を確認しています。\n
//						データ数が0なら成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntPushFailed)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = nullptr;//失敗させるようにnullptrを指定
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			ASSERT_FALSE(list.Insert(it, record));//失敗させる
			EXPECT_EQ(0, list.GetDataCnt());
		}
	

		//		/**********************************************************************************//**
//			@brief		データの挿入を行った際の戻り値のテスト
//			@details	ID:リスト-5\n
//						データ数の取得機能のテストです。\n
//						データの挿入を行った際の戻り値を確認しています。\n
//						データ数が0なら成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntDelete)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//ノードは先頭ダミーノードの次に入れる

			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//先頭にデータを挿入する
			it = list.GetFirstIter();//「先頭ダミーノードの次」を指定する

			ASSERT_TRUE(list.Delete(it));//削除
			EXPECT_EQ(0, list.GetDataCnt());
		}

		//		/**********************************************************************************//**
//			@brief		データの削除が失敗した際の戻り値のテスト
//			@details	ID:リスト-6\n
//						データ数の取得機能のテストです。\n
//						データの挿入した後、削除を行った際の戻り値を確認しています。\n
//						データ数が1なら成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntDeleteFailed)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//ノードは先頭ダミーノードの次に入れる

			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			list.Insert(it, record);//先頭にデータを挿入する
			it = nullptr;//わざと失敗させる
			ASSERT_FALSE(list.Delete(it));
			EXPECT_EQ(1, list.GetDataCnt());
		}

		//		/**********************************************************************************//**
//			@brief		リストが空である場合に、データの削除を行った際の戻り値のテスト
//			@details	ID:リスト-7\n
//						データ数の取得機能のテストです。\n
//						リストが空である場合に、データの削除を行った際の戻り値を確認しています。\n
//						データ数が0なら成功です。\n
//		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataCntDeleteWhenEmpty)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//ノードは先頭ダミーノードの次に入れる(存在しないが)

			ASSERT_FALSE(list.Delete(it));
			EXPECT_EQ(0, list.GetDataCnt());
		}


//		//=================================== データの挿入 ===================================
//		
//		/**********************************************************************************//**
//			@brief		リストが空である場合に、リスト末尾にデータを追加した際の挙動テスト
//			@details	ID:リスト-9\n
//						リスト末尾のデータ追加テストです。\n
//						リストが空である場合に追加した際の挙動を確認しています。\n
//						イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれる。\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushFirstToEmpty)
		{
			CList<TRecord> list;
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();

			EXPECT_EQ(true, list.Insert(it, record));//先頭イテレータの場合のチェック
		}

		TEST(PushBackTest, TestPushEndToEmpty)
		{
			CList<TRecord> list;
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetEndIter();

			EXPECT_EQ(true, list.Insert(it, record));//末尾イテレータの場合のチェック
		}

		//		/**********************************************************************************//**
//			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動テスト
//			@details	ID:リスト-10\n
//						リスト末尾のデータ追加テストです。\n
//						リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動を確認しています。\n
//						成功：先頭に要素が挿入され、元々先頭だった要素が２番目になる。\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushFirstToSecond)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();

			list.Insert(it, record);//1個目のデータ先頭に挿入
			record = { 100,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更に先頭にデータ挿入	
			it = list.GetFirstIter();
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name== "FirstIn");//最初に入れたものが最後に2番目に来ているか？
		}

		//		/**********************************************************************************//**
//			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動テスト
//			@details	ID:リスト-11\n
//						リスト末尾のデータ追加テストです。\n
//						リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動を確認しています。\n
//						成功：イテレータの指す位置に要素が挿入される\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushEndToSecond)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();

			list.Insert(it, record);//1個目のデータ先頭に挿入
			record = { 100,"SecondIn" };//データ内容(スコア、名前)
			it = list.GetEndIter();

			list.Insert(it, record);//データが既にある中で末尾にデータ挿入	
			it = list.GetFirstIter();
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//最後に2番目が来ているか？
		}

		//		/**********************************************************************************//**
//			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
//			@details	ID:リスト-12\n
//						リスト末尾のデータ追加テストです。\n
//						リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動を確認しています。\n
//						成功：イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれる。\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushMiddle)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();
			list.Insert(it, record);//1個目のデータ

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目のデータ挿入	


			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			it = list.GetFirstIter();
			list.Insert(it, record);//1番目の次⇒2番目に挿入する
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//リストの2番目に3番目に挿入したノードが来ているか？
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//3番目に挿入したノードの位置にあった要素が後ろにずれているか？
		}


		//		/**********************************************************************************//**
//			@brief		ConstIteratorを指定して挿入を行った際の挙動テスト
//			@details	ID:リスト-13\n
//						リスト末尾のデータ追加テストです。\n
//						ConstIteratorを指定して挿入を行った際の挙動を確認しています。\n
//						成功：イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれる。\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushMiddleConst)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CConstIterator<TRecord> it = list.GetFirstIter();
			list.Insert(it, record);//1個目のデータ

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目のデータ挿入	


			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.GetFirstIter();
			list.Insert(it, record);//
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//リストの2番目に3番目に挿入したノードが来ているか？
			it.GoNextNode();
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//3番目に挿入したノードの位置にあった要素が後ろにずれているか？
		}


		//		/**********************************************************************************//**
//			@brief		不正なイテレータを渡して、挿入した場合の挙動テスト
//			@details	ID:リスト-14\n
//						リスト末尾のデータ追加テストです。\n
//						不正なイテレータを渡して、挿入した場合の挙動を確認しています。\n
//						成功：何も起こらない\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestPushWrongfulIIterator)
		{
			CList<TRecord> list;
			TRecord record = { 100,"testname" };//データ内容(スコア、名前)
			CIterator<TRecord> it = nullptr;
			list.Insert(it, record);
			EXPECT_EQ(0, list.GetDataCnt());//何も起きていない（データが増えていない）ことをチェック
		}


		//		//=================================== データの削除 ===================================

		//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		リストが空である場合に、削除を行った際の挙動
//			@details	ID:リスト-16\n
//						成功：何も起こらない\n
//		*//***********************************************************************************/
		TEST(GetDataNumTest, TestDeleteWhenEmpty)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//「先頭ダミーノードの次」を指定する(存在しないが)

			ASSERT_FALSE(list.Delete(it));
			EXPECT_EQ(0, list.GetDataCnt());//何も起きていない（データが増えていない）ことをチェック
		}

				//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
//			@details	ID:リスト-17\n
//						成功：先頭要素の削除\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestDeleteFirst)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();

			list.Insert(it, record);//1個目のデータ先頭に挿入
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更にデータ挿入
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更にデータ挿入

			it = list.GetFirstIter();//先頭イテレータを指定
			ASSERT_TRUE(list.Delete(it));
			it = list.GetFirstIter();//先頭イテレータを指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//先頭要素の削除されて2番目が来ているか？
		}

		//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
//			@details	ID:リスト-18\n
//						成功：末尾要素の削除\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestDeleteEnd)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();
			list.Insert(it, record);//1個目のデータ先頭に挿入

			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			it.GoNextNode();
			list.Insert(it, record);//更にデータ挿入

			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			it.GoNextNode();
			list.Insert(it, record);//更にデータ挿入

			it = list.GetEndIter();
			ASSERT_TRUE(list.Delete(it));
			it = list.GetEndIter();
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//末尾が削除されて2番目が来ているか？
		}


		//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
//			@details	ID:リスト-19\n
//						成功：指定要素の削除\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestDeleteCenter)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CIterator<TRecord> it = list.GetFirstIter();
			list.Insert(it, record);//1個目のデータ先頭に挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更にデータ挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更にデータ挿入
			//中間ノードを指定
			it = list.GetFirstIter();
			it.GoNextNode();
			ASSERT_TRUE(list.Delete(it));

			//中間ノードが削除されたかチェック
			it = list.GetFirstIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
			it = list.GetEndIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");
		}

				//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		ConstIteratorを指定して削除を行った際の挙動
//			@details	ID:リスト-20\n
//						成功：指定要素の削除\n
//		*//***********************************************************************************/
		TEST(PushBackTest, TestDeleteCenterConst)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CConstIterator<TRecord> it = list.GetFirstIter();
			list.Insert(it, record);//1個目のデータ先頭に挿入

			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			it.GoNextNode();//次へ
			list.Insert(it, record);//更にデータ挿入

			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			it.GoNextNode();//次へ
			list.Insert(it, record);//更にデータ挿入

			//中間ノードを指定
			it = list.GetFirstIter();
			it.GoNextNode();
			ASSERT_TRUE(list.Delete(it));

			//中間ノードが削除されたかチェック
			it = list.GetFirstIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
			it = list.GetEndIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");
		}


		//**********************************************************************************//**
		//　@interface　データの削除テスト
		//	@brief		不正なイテレータを渡して、削除した場合の挙動
//			@details	ID:リスト-21\n
//						成功：何も起こらない\n
//		*//***********************************************************************************/

		TEST(PushBackTest, TestDeleteWrongfulIIterator)
		{
			CList<TRecord> list;
			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			CConstIterator<TRecord> it = list.GetEndIter();
			list.Insert(it, record);//1個目のデータ先頭に挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//更にデータ挿入
			it /*= nullptr*/;//不正なイテレータを指定
			ASSERT_FALSE(list.Delete(it));

			//中間ノードが削除されたかチェック
			it = list.GetFirstIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
			it = list.GetEndIter();//ノードを指定

			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");
		}


//=================================== 先頭イテレータの取得 ===================================

//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		リストが空である場合に、呼び出した際の挙動
//	@details	ID:リスト-23\n
//	@result　　 成功：ダミーノードを指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenEmpty)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();//

			EXPECT_EQ(true, it.GetRecord()->m_name== "m_dummy");
		}

//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		リストに要素が一つある場合に、呼び出した際の挙動
//	@details	ID:リスト-24\n
//	@result　　 成功：先頭要素を指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenOneNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得

			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
//	@details	ID:リスト-25\n
//	@result　　 成功：先頭要素を指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenTwoNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}


//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		データの挿入を行った後に、呼び出した際の挙動
//	@details	ID:リスト-26\n
//	@result　　 成功：先頭要素を指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenInsert)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		データの削除を行った後に、呼び出した際の挙動
//	@details	ID:リスト-27\n
//	@result　　 成功：先頭要素を指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenDelete)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}



//=================================== 先頭コンストイテレータの取得 ===================================



//**********************************************************************************//**
//　@interface　先頭コンストイテレータの取得テスト
//	@brief		リストが空である場合に、呼び出した際の挙動
//	@details	ID:リスト-29\n
//	@result　　 成功：ダミーノードを指すイテレータが返る
//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenEmptyConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();//

			EXPECT_EQ(true, it.GetRecord()->m_name == "m_dummy");
		}

		//**********************************************************************************//**
		//　@interface　先頭コンストイテレータの取得テスト
		//	@brief		リストに要素が一つある場合に、呼び出した際の挙動
		//	@details	ID:リスト-30\n
		//	@result　　 成功：先頭要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenOneNodeConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　先頭コンストイテレータの取得テスト
		//	@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		//	@details	ID:リスト-31\n
		//	@result　　 成功：先頭要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenTwoNodeConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}


		//**********************************************************************************//**
		//　@interface　先頭コンストイテレータの取得テスト
		//	@brief		データの挿入を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-32\n
		//	@result　　 成功：先頭要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenInsertConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　先頭コンストイテレータの取得テスト
		//	@brief		データの削除を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-33\n
		//	@result　　 成功：先頭要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetIteratorTest, TestIteratorWhenDeleteConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入
			it = list.GetFirstIter();//先頭イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}


//=================================== 末尾イテレータの取得 ===================================


//**********************************************************************************//**
//　@interface　先頭イテレータの取得テスト
//	@brief		リストが空である場合に、呼び出した際の挙動
//	@details	ID:リスト-35\n
//	@result　　 成功：ダミーノードを指すイテレータが返る
//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenEmpty)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();//

			EXPECT_EQ(true, it.GetRecord()->m_name == "m_dummy");
		}

		//**********************************************************************************//**
		//　@interface　先頭イテレータの取得テスト
		//	@brief		リストに要素が一つある場合に、呼び出した際の挙動
		//	@details	ID:リスト-36\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenOneNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter(); //末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　先頭イテレータの取得テスト
		//	@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		//	@details	ID:リスト-37\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenTwoNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");
		}


		//**********************************************************************************//**
		//　@interface　先頭イテレータの取得テスト
		//	@brief		データの挿入を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-38\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenInsert)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　先頭イテレータの取得テスト
		//	@brief		データの削除を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-39\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndConstIteratorWhenInsert)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");
		}


//=================================== 末尾コンストイテレータの取得 ===================================


//**********************************************************************************//**
//　@interface　末尾コンストイテレータの取得テスト
//	@brief		リストが空である場合に、呼び出した際の挙動
//	@details	ID:リスト-41\n
//	@result　　 成功：ダミーノードを指すイテレータが返る
//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenEmptyConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();//

			EXPECT_EQ(true, it.GetRecord()->m_name == "m_dummy");
		}

		//**********************************************************************************//**
		//　@interface　末尾コンストイテレータの取得テスト
		//	@brief		リストに要素が一つある場合に、呼び出した際の挙動
		//	@details	ID:リスト-42\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenOneNodeConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter(); //末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　末尾コンストイテレータの取得テスト
		//	@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		//	@details	ID:リスト-43\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenTwoNodeConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");
		}


		//**********************************************************************************//**
		//　@interface　末尾コンストイテレータの取得テスト
		//	@brief		データの挿入を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-44\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenInsertConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");
		}

		//**********************************************************************************//**
		//　@interface　末尾コンストイテレータの取得テスト
		//	@brief		データの削除を行った後に、呼び出した際の挙動
		//	@details	ID:リスト-45\n
		//	@result　　 成功：末尾要素を指すイテレータが返る
		//***********************************************************************************/
		TEST(GetEndIteratorTest, TestEndIteratorWhenDeleteConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入
			it = list.GetEndIter();//末尾イテレータの取得
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");
		}

//=================================== イテレータの指す要素を取得する ===================================

		//**********************************************************************************//**
		//　@interface　イテレータの指す要素を取得する
		//	@brief		リストの参照がない状態で呼び出した際の挙動
		//	@details	ID:イテレータ-0\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorWhenNoList)
		{
			EXPECT_TRUE(true, ASSERT_DEATH(CIterator it)); 
		}

		TEST(IteratorTest, TestIteratorWhenNoListConst)
		{
			EXPECT_TRUE(true, ASSERT_DEATH(CConstIterator constIt));
		}

		//**********************************************************************************//**
		//　@interface　イテレータの指す要素を取得する
		//	@brief		Iteratorから取得した要素に対して、値の代入が行えるかをチェック
		//	@details	ID:イテレータ-1\n
		//	@result　　 成功：代入後に再度呼び出し、値が変更されていることを確認
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorWhenSubstitution)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定
			it.GetRecord()->m_name = "Changed";//Iteratorから取得した要素に対して、値の代入
			EXPECT_EQ(true, it.GetRecord()->m_name == "Changed");//値が変更されていることを確認
		}

		TEST(IteratorTest, TestIteratorWhenSubstitutionWhenConst)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定
			//it.GetRecord()->m_name = "Changed";//
			//EXPECT_EQ(true, it.GetRecord()->m_name == "Changed");//	
			EXPECT_TRUE(true, ASSERT_DEATH(it.GetRecord()->m_name = "Changed"));//constなので、コンパイルエラーになることを確認
		}

		//**********************************************************************************//**
		//　@interface　イテレータの指す要素を取得する
		//	@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-3\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestFirstIteratorWhenEnpty)
		{
			//Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			//リストは空なのでGetFirstNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(CIterator it = list.GetFirstNode()));

		}

		TEST(IteratorTest, TestFirstIteratorWhenEnpty_Const)
		{
			//Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			//リストは空なのでGetFirstNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(CConstIterator it = list.GetFirstNode()));

		}


		//**********************************************************************************//**
		//　@interface　イテレータの指す要素を取得する
		//	@brief		末尾イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-4\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestEndIteratorWhenEnpty)
		{
			CList<TRecord> list;//リスト生成
			//リストは空なのでGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(CIterator it = list.GetEndNode()));

		}

		TEST(IteratorTest, TestEndIteratorWhenEnpty_Const)
		{
			//Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			//リストは空なのでGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(CConstIterator it = list.GetEndNode()));
		}

		//=================================== イテレータをリストの末尾に向かって一つ進める ===================================


		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		リストの参照がない状態で呼び出した際の挙動
		//	@details	ID:イテレータ-5\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorForEndWhenNoList)
		{
			
			CIterator<TRecord> *it;
			//イテレータをリストの末尾に向かって一つ進める//Assertが発生したらOK
			EXPECT_TRUE(true, ASSERT_DEATH(it->GoNextNode()));
		}

		TEST(IteratorTest, TestIteratorForEndWhenNoList_Const)
		{
			CConstIterator<TRecord> *constIt;
			//イテレータをリストの末尾に向かって一つ進める//Assertが発生したらOK
			EXPECT_TRUE(true, ASSERT_DEATH(constIt->GoNextNode()));
		}


		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-6\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestFirstIteratorForEndWhenListEmpty)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();

			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			//リストが空なのでGetFirstNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetFirstNode()));
		}

		TEST(IteratorTest, TestFirstIteratorForEndWhenListEmpty_Const)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();

			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
		 //リストが空なのでGetFirstNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetFirstNode()));
		}

		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		末尾イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-7\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestEndIteratorForEndWhenListEmpty)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetFirstIter();

			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			//末尾イテレータGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetEndNode()));
		}

		TEST(IteratorTest, TestEndIteratorForEndWhenListEmpty_Const)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetFirstIter();

			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			//末尾イテレータGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetEndNode()));
		}



		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
		//	@details	ID:イテレータ-8\n
		//	@result　　 成功：次の要素を指す.リストの先頭から末尾まで呼び出しを行い、期待されている要素が格納されているかを確認
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorForEndWhenTwoNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			it = list.GetFirstIter();//先頭イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
		}

		TEST(IteratorTest, TestIteratorForEndWhenTwoNode_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();


			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			it = list.GetFirstIter();//先頭イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it.GoNextNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
		}

		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
		//	@details	ID:イテレータ-9\n
		//	@result　　 成功：次の要素を指す.インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認
		//***********************************************************************************/


		TEST(IteratorTest, TestPreIteratorForEndWhenIncrement_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();


			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			int Increment = 0;
			it = list.GetIter(Increment);//イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
			it = list.GetIter(++Increment);//前置インクリメント（インクリメントしてから代入）、イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it = list.GetIter(++Increment);//前置インクリメント（インクリメントしてから代入）、イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
		}


		//**********************************************************************************//**
		//　@interface　イテレータをリストの末尾に向かって一つ進める
		//	@brief		後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
		//	@details	ID:イテレータ-10\n
		//	@result　　 成功：次の要素を指す.インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認
		//***********************************************************************************/


		TEST(IteratorTest, TestPostIteratorForEndWhenIncrement_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();


			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			int Increment = 0;
			it = list.GetIter(Increment);//イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認

			it = list.GetIter(Increment++);//後置インクリメント（インクリメントは代入式が終わってから）
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//後置インクリメントなので、itに代入時点では（Increment =＝ 1）のはず
			it = list.GetIter(Increment);//現在のイテレータを指定してみる
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//後置インクリメントなので、itに代入後では（Increment =＝ 2）のはず

			it = list.GetIter(Increment++);//後置インクリメント（インクリメントは代入式が終わってから）
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//後置インクリメントなので、itに代入時点では（Increment =＝ 2）のはず
			it = list.GetIter(Increment);//現在のイテレータを指定してみる
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//後置インクリメントなので、itに代入後では（Increment =＝ 3）のはず

		}




		//=================================== イテレータをリストの先頭に向かって一つ進める ===================================

		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		リストの参照がない状態で呼び出した際の挙動
		//	@details	ID:イテレータ-11\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorForFirstWhenNoList)
		{
			//Assertが発生したらOK
			CIterator<TRecord> *it;
			//イテレータをリストの末尾に向かって一つ進める//Assertが発生したらOK
			EXPECT_TRUE(true, ASSERT_DEATH(it->GoNextNode()));
		}

		TEST(IteratorTest, TestIteratorForFirstWhenNoList_Const)
		{
			//Assertが発生したらOK
			CConstIterator<TRecord> *constIt;
			//イテレータをリストの末尾に向かって一つ進める//Assertが発生したらOK
			EXPECT_TRUE(true, ASSERT_DEATH(constIt->GoNextNode()));
		}


		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-12\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/
		TEST(IteratorTest, TestEndIteratorForFirstWhenListEmpty)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			//リストが空なのでGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetEndNode()));
		}

		TEST(IteratorTest, TestEndIteratorForFirstWhenListEmpty_Const)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			//リストが空なのでGetEndNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetEndNode()));
		}


		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		先頭イテレータに対して呼び出した際の挙動
		//	@details	ID:イテレータ-13\n
		//	@result　　 成功：Assert発生
		//***********************************************************************************/

		TEST(IteratorTest, TestFirstIteratorForFirstWhenListEmpty)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			it.GoPrevNode();//イテレータをリストの先頭に向かって一つ進める
			//先頭イテレータGetFirstNodeは存在しない
			EXPECT_TRUE(true, ASSERT_DEATH(it = list.GetFirstNode()));
		}

		TEST(IteratorTest, TestFirstIteratorForFirstWhenListEmpty_Const)
		{
			////Assertが発生したらOK
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			it.GoPrevNode();//イテレータをリストの先頭に向かって一つ進める
			EXPECT_TRUE(true,ASSERT_DEATH(it = list.GetFirstNode())); //先頭イテレータGetFirstNodeは存在しない

		}

		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
		//	@details	ID:イテレータ-14\n
		//	@result　　 成功：前の要素を指す.リストの末尾から先頭まで呼び出しを行い、期待されている要素が格納されているかを確認
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorForFirstWhenTwoNode)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			it = list.GetEndIter();//末尾イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
		}

		TEST(IteratorTest, TestIteratorForFirstWhenTwoNode_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			it = list.GetEndIter();//末尾イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it.GoPrevNode();//イテレータをリストの末尾に向かって一つ進める
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
		}



		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
		//	@details	ID:イテレータ-15\n
		//	@result　　 成功：前の要素を指す.デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認
		//***********************************************************************************/


		TEST(IteratorTest, TestPreIteratorForFirstWhenDecrement_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			int decrement = 2;
			it = list.GetIter(decrement);//イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//3個目を確認
			it = list.GetIter(--decrement);//前置インクリメント（インクリメントしてから代入）、イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//2個目を確認
			it = list.GetIter(--decrement);//前置インクリメント（インクリメントしてから代入）、イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//1個目を確認
		}


		//**********************************************************************************//**
		//　@interface　イテレータをリストの先頭に向かって一つ進める
		//	@brief		後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
		//	@details	ID:イテレータ-16\n
		//	@result　　 成功：前の要素を指す.デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認
		//***********************************************************************************/


		TEST(IteratorTest, TestIteratorWhenDecrement_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入

			it.GoNextNode();
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//2個目を挿入

			it.GoNextNode();
			record = { 300,"ThirdIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//3個目を挿入

			int decrement = 2;
			it = list.GetIter(decrement);//イテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//1個目を確認

			it = list.GetIter(decrement--);//後置インクリメント（インクリメントは代入式が終わってから）
			EXPECT_EQ(true, it.GetRecord()->m_name == "ThirdIn");//後置インクリメントなので、itに代入時点では（Increment =＝ 1）のはず
			it = list.GetIter(decrement);//現在のイテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//後置インクリメントなので、itに代入後では（Increment =＝ 2）のはず

			it = list.GetIter(decrement--);//後置インクリメント（インクリメントは代入式が終わってから）
			EXPECT_EQ(true, it.GetRecord()->m_name == "SecondIn");//後置インクリメントなので、itに代入時点では（Increment =＝ 2）のはず
			it = list.GetIter(decrement);//現在のイテレータの指定
			EXPECT_EQ(true, it.GetRecord()->m_name == "FirstIn");//後置インクリメントなので、itに代入後では（Increment =＝ 3）のはず
		}

		//=================================== イテレータのコピーを行う ===================================

		//**********************************************************************************//**
		//　@interface　イテレータのコピーを行う
		//	@brief		コピーコンストラクト後の値がコピー元と等しいことをチェック
		//	@details	ID:イテレータ-18\n
		//	@result　　 成功：コピーコンストラクト後の値がコピー元と等しい
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorAndCopyIterator)
		{

			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定		
			CIterator<TRecord> copyIt = it;//イテレータのコピーを行う
			EXPECT_EQ(true, it.GetRecord()->m_name == copyIt.GetRecord()->m_name);//コピーコンストラクト後の値がコピー元と等しい
		}

		TEST(IteratorTest, TestIteratorAndCopyIterator_Const)
		{

			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定	
			CConstIterator<TRecord> copyIt = it;//イテレータのコピーを行う
			EXPECT_EQ(true, it.GetRecord()->m_name == copyIt.GetRecord()->m_name);//コピーコンストラクト後の値がコピー元と等しい
		}




		//=================================== イテレータの代入を行う ===================================


		//**********************************************************************************//**
		//　@interface　イテレータの代入を行う
		//	@brief		代入後の値がコピー元と等しいことをチェック
		//	@details	ID:イテレータ-20\n
		//	@result　　 成功：代入後の値がコピー元と等しい
		//***********************************************************************************/
		TEST(IteratorTest, TestIteratorAndCopyIteratorSubstitution)
		{

			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定
			it.GetRecord()->m_name = "FirstIn_Changed";//代入を行う
			CIterator<TRecord> copyIt = it;//イテレータのコピーを行う
			EXPECT_EQ(true, copyIt.GetRecord()->m_name == "FirstIn_Changed");//代入後の値がコピー元と等しい
		}

		TEST(IteratorTest, TestIteratorAndCopyIteratorSubstitution_Const)
		{

			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it, record);//1個目を挿入
			it = list.GetFirstIter();//ノードを指定
			//it.GetRecord()->m_name = "FirstIn_Changed";//
			//CConstIterator copyIt = it;//
			//EXPECT_EQ(true, copyIt.GetRecord()->m_name == "FirstIn_Changed");//
			EXPECT_TRUE(true, ASSERT_DEATH(it.GetRecord()->m_name = "FirstIn_Changed"));//constなので、コンパイルエラーになることを確認
		}



		//=================================== 二つのイテレータが同一のものであるか、比較を行う ===================================

		//**********************************************************************************//**
		//　@interface　二つのイテレータが同一のものであるか、比較を行う
		//	@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
		//	@details	ID:イテレータ-21\n
		//	@result　　 成功：戻り値がTRUE
		//***********************************************************************************/
		TEST(IteratorTest, TestEQ_FirstIteratorAndEndIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetFirstIter();
			CIterator<TRecord> it_B = list.GetFirstIter();
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
			it_A = list.GetEndIter();
			it_B = list.GetEndIter();
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestEQ_FirstIteratorAndEndIterator_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it_A = list.GetFirstIter();
			CConstIterator<TRecord> it_B = list.GetFirstIter();
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
			it_A = list.GetEndIter();
			it_B = list.GetEndIter();
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}


		//**********************************************************************************//**
		//　@interface　二つのイテレータが同一のものであるか、比較を行う
		//	@brief		同一のイテレータを比較した際の挙動
		//	@details	ID:イテレータ-22\n
		//	@result　　 成功：戻り値がTRUE
		//***********************************************************************************/
		TEST(IteratorTest, TestEQ_SameIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CIterator<TRecord> it_B = list.GetFirstIter();//イテレータ指定
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestEQ_SameIterator_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CConstIterator<TRecord> it_B = list.GetFirstIter();//イテレータ指定
			EXPECT_EQ(true, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}



		//**********************************************************************************//**
		//　@interface　二つのイテレータが同一のものであるか、比較を行う
		//	@brief		異なるイテレータを比較した際の挙動
		//	@details	ID:イテレータ-23\n
		//	@result　　 成功：戻り値がFALSE
		//***********************************************************************************/
		TEST(IteratorTest, TestEQ_DifferentIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//2個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CIterator<TRecord> it_B = list.GetEndIter();//Aとは異なるイテレータ指定
			EXPECT_EQ(false, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestEQ_DifferentIterator_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//2個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CConstIterator<TRecord> it_B = list.GetEndIter();//Aとは異なるイテレータ指定
			EXPECT_EQ(false, it_A.GetRecord()->m_name == it_B.GetRecord()->m_name);
		}


		//=================================== 二つのイテレータが異なるものであるか、比較を行う ===================================

		//**********************************************************************************//**
		//　@interface　二つのイテレータが異なるものであるか、比較を行う
		//	@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
		//	@details	ID:イテレータ-24\n
		//	@result　　 成功：戻り値がFALSE
		//***********************************************************************************/
		TEST(IteratorTest, TestNoEQ_FirstIteratorAndEndIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetFirstIter();
			CIterator<TRecord> it_B = list.GetFirstIter();
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);

			it_A = list.GetEndIter();
			it_B = list.GetEndIter();
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestNoEQ_FirstIteratorAndEndIterator_Const)
		{
			CList<TRecord> list;//リスト生成

			CConstIterator<TRecord> it_A = list.GetFirstIter();
			CConstIterator<TRecord> it_B = list.GetFirstIter();
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);

			it_A = list.GetEndIter();
			it_B = list.GetEndIter();
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}

		//**********************************************************************************//**
		//　@interface　二つのイテレータが異なるものであるか、比較を行う
		//	@brief		同一のイテレータを比較した際の挙動
		//	@details	ID:イテレータ-25\n
		//	@result　　 成功：戻り値がFALSE
		//***********************************************************************************/
		TEST(IteratorTest, TestNotEQ_SameIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CIterator<TRecord> it_B = list.GetFirstIter();//イテレータ指定
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestNotEQ_SameIterator_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CConstIterator<TRecord> it_B = list.GetFirstIter();//イテレータ指定
			EXPECT_EQ(false, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}



		//**********************************************************************************//**
		//　@interface　二つのイテレータが異なるものであるか、比較を行う
		//	@brief		異なるイテレータを比較した際の挙動
		//	@details	ID:イテレータ-26\n
		//	@result　　 成功：戻り値がTRUE
		//***********************************************************************************/
		TEST(IteratorTest, TestNotEQ_DifferentIterator)
		{
			CList<TRecord> list;//リスト生成
			CIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//2個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CIterator<TRecord> it_B = list.GetEndIter();//Aとは異なるイテレータ指定
			EXPECT_EQ(true, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}

		TEST(IteratorTest, TestNotEQ_DifferentIterator_Const)
		{
			CList<TRecord> list;//リスト生成
			CConstIterator<TRecord> it_A = list.GetEndIter();

			TRecord record = { 100,"FirstIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//1個目を挿入
			record = { 200,"SecondIn" };//データ内容(スコア、名前)
			list.Insert(it_A, record);//2個目を挿入
			it_A = list.GetFirstIter();//イテレータ指定
			CConstIterator<TRecord> it_B = list.GetEndIter();//Aとは異なるイテレータ指定
			EXPECT_EQ(true, it_A.GetRecord()->m_name != it_B.GetRecord()->m_name);
		}



	}

}