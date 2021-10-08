/*
  @brief �X�^�b�N�̃N���X
  @author ��F���
  @date 10/8
 */

#include "CQueue.h"

void CQueue::Init()
{
	m_InputEndFg = false;
	m_DataCnt = 1;

	printf("\n");
	printf("<�L���[��p����������o���v���O����>\n");
	printf("\n");
}

void CQueue::Update()
{
	while (m_InputEndFg == false)
	{
		printf("\n");
		printf("%d�l�ڂ̃f�[�^�����\n", m_DataCnt);
		printf("���O����͂��Ă��������F");

		std::cin >> m_str;//����
		m_List.Insert(m_DataCnt, m_str);//�m�[�h�𐶐����}������

		printf("\n");
		printf("���͂𑱂��܂����H\n");
		printf("y�F�͂��A���͂𑱂��܂�\n");
		printf("n�F�������A�I�����܂�\n");

		rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A

		char YorN = getchar();//�L�[�{�[�h������͂��������̈ꕶ��������ϐ��Ɋi�[����ϐ�

		if (YorN == 'n')//�I������
		{
			m_InputEndFg = true;
		}

		m_DataCnt++;
	}
}

void CQueue::Draw()
{
	printf("\n");
	printf("<������o�����ɏo��>\n");
	for (CNode *i = m_List.GetDummy_First()->GetNext(); i != m_List.GetDummy_End(); i = i->GetNext())
	{
		std::cout << i->GetNum() << "�ԖځF";
		std::cout << i->GetName() << std::endl;
	}
}

void CQueue::Clear()
{
	printf("\n");
	printf("�G���^�[�L�[�ŏI��\n");
	rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A
	getchar();

	//���X�g�̍폜
	m_List.Clear();
}