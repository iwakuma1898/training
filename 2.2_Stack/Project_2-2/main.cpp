#include "CStack.h"

CStack myStack;

int main()
{
	//初期化
	myStack.Init();

	//更新（入力）
	myStack.Update();

	//描画
	myStack.Draw();

	//終了処理
	myStack.Clear();


	return 0;
}