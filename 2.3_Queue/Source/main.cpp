#include "CList.h"
#include "CNode.h"


CList myList;

int main()
{
	printf("\n");
	printf("<�L���[��p����������o���v���O����>\n");
	printf("\n");

	//����
	bool InputEndFg = false;//
	int DataCnt = 1;
	std::string str;

	while (InputEndFg == false)
	{
		printf("\n");
		printf("%d�l�ڂ̃f�[�^�����\n", DataCnt);
		printf("���O����͂��Ă��������F");

		std::cin >> str;//����
		myList.Insert(DataCnt, str);//�m�[�h�𐶐����}������

		printf("\n");
		printf("���͂𑱂��܂����H\n");
		printf("y�F�͂��A���͂𑱂��܂�\n");
		printf("n�F�������A�I�����܂�\n");

		rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A

		char YorN = getchar();//�L�[�{�[�h������͂��������̈ꕶ��������ϐ��Ɋi�[����ϐ�

		if (YorN == 'n')//�I������
		{
			InputEndFg = true;
		}


		DataCnt++;
	}

	//�`��
	printf("\n");
	printf("<������o�����ɏo��>\n");
	for (CNode *i = myList.GetDummy_First()->GetNext(); i != myList.GetDummy_End(); i = i->GetNext())
	{
		std::cout << i->GetNum()<<"�ԖځF";
		std::cout << i->GetName() << std::endl;
	}

	printf("\n");
	printf("�G���^�[�L�[�ŏI��\n");
	rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A
	getchar();

	//���X�g�̍폜
	myList.Exit();

	return 0;
}