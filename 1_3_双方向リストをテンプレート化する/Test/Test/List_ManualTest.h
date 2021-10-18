/**********************************************************************************//**
	@file           List_ManualTest.h
	@brief          GoogleTest手動テストコードの書き方サンプル定義、宣言   
	@note Copyright (c) FromSoftware, Inc.
*//***********************************************************************************/

#if !defined ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
#define      ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___

//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// マクロ定義
//--------------------------------------------------------------------------------
// コンパイル関連手動テスト(リスト)

// ※コンパイルが通れば成功
#define TT_TEST_GET_DATA_NUM_IS_CONST// ID:リスト8
#define TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST	// ID:リスト34
#define TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST	// ID:リスト46


// ※コンパイルが通らなければ成功
//#define TT_TEST_INSERT_WHEN_CONST// ID:リスト15	
//#define TT_TEST_ERASE_WHEN_CONST				// ID:リスト22
//#define TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST	// ID:リスト28
//#define TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST	// ID:リスト40
//#define TT_TEST_GET_ITERATOR_WHEN_CONST		// ID:イテレータ2
//#define TT_TEST_ITERATOR_COPY_WHEN_CONST		// ID:イテレータ17
//#define TT_TEST_ITERATOR_ASSIGN_WHEN_CONST	// ID:イテレータ19


#endif // ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___