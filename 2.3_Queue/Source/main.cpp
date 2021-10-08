#include "CQueue.h"

CQueue myQueue;

int main()
{
	//初期化
	myQueue.Init();

	//更新（入力）
	myQueue.Update();

	//描画
	myQueue.Draw();

	//終了処理
	myQueue.Clear();

	return 0;
}