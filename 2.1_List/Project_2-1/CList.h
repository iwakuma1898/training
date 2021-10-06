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
		//�f�[�^�ǂݍ��݁E�K�v�ȕ��̃m�[�h����
		FileLoad_SetList(fileName);
		//SCORE���Ƀ\�[�g
		SortScore();
	}

	void Draw()
	{
		//���X�g�̐擪���擾
		node = dummy_First->GetNext();

		while (node != dummy_End)
		{
			std::cout << node->GetScore();
			std::cout << node->GetName() << std::endl;

			node = node->GetNext();
		}

	}

	//�f�[�^��ǂݍ��݁A�f�[�^���Z�b�g
	void FileLoad_SetList(const char *fileName)
	{
		std::ifstream file(fileName);  // �ǂݍ��ރt�@�C���̃p�X���w��
		std::string line;//�ǂݍ��ݗp�i1�s���j

		node = new CNode();//�f�[�^�Ƃ��Ă̍ŏ��̃m�[�h�𐶐�����

		//�n�_�̐ݒ�
		dummy_First = new CNode();
		dummy_First->SetNext(node);
		dummy_First->SetPrev(dummy_First);//���g�̃A�h���X�ɃZ�b�g���A�u�n�_�v�Ƃ���

		//�I�_�̐ݒ�
		dummy_End = new CNode();
		dummy_End->SetNext(dummy_End);//���g�̃A�h���X�ɃZ�b�g���A�u�I�_�v�Ƃ���
		dummy_End->SetPrev(node);

		//���݂̃m�[�g�ɁA�I�_�Ǝn�_���Z�b�g
		node->SetPrev(dummy_First);//�擪���_�~�[�ɂ��Ďn�_��������悤�ɂ���
		node->SetNext(dummy_End);//�������_�~�[�ɂ��ďI�_��������悤�ɂ���


		CNode *NowNode = node;//���̃m�[�h�Ɉڂ鎞�́A�����z���p�̃f�[�^

		while (std::getline(file, line)) {  // 1�s���ǂݍ���

			int Num = 0;
			int NumPlace = 1;//���̏d��
			int EndScoreNum = line.find("\t"); //line.find("\t")�Ő����񂪏I��镶���������

			for (int i = EndScoreNum - 1; i >= 0; i--)//�����񂪏I����O����������𐔒l������
			{
				Num += (line[i] - '0')*NumPlace;//������̈ꕔ�𐔎��ɕϊ����A���̏d�݂��|���đ��
				NumPlace *= 10;//�����グ��
			}

			//�m�[�h�ɃZ�b�g
			node->SetScore(Num);//SCORE
			node->SetName(line.substr(EndScoreNum));//���O

			//������͂����f�[�^�������z��
			NowNode = node;
			//���̃m�[�h�𐶐�
			node = new CNode();
			node->SetPrev(NowNode);//�O�̃m�[�h�͍�����͂����m�[�h
			node->SetNext(dummy_End);//�������_�~�[�ɂ��ďI�_��������悤�ɂ���
			//������͂����m�[�h�̃��X�g�̌q������
			NowNode->SetNext(node);//�O�̃m�[�h�͎�����͂���m�[�h
		}
		//���[�v�𔲂�����A�Ō�̃m�[�h�𒲐�����
		NowNode->SetNext(dummy_End);//�Ō�ɓ��͂����m�[�h�̖�����dummy�ɂ���
	}


	void SortScore()
	{
		CNode *MaxScoreNode;//�\�[�g�̊�l
		CNode *NowConfirm;//�擪���m�肵���ʒu��m�邽�߂̂���
		CNode *PrevBox;//�����z���p
		CNode *NextBox;//�����z���p

		//���X�g�̐擪���擾
		MaxScoreNode = dummy_First->GetNext();//�擪�̃m�[�h��SCORE�����ɍő�l�ɐݒ�

		//�m�����Adummy_Firs���n�߂�
		NowConfirm = dummy_First;

		//�\�[�g
		while (NowConfirm != dummy_End)//�m���dummy_End�ɓ��B����܂�
		{
			//�ő�l��T��
			for (CNode *i = NowConfirm->GetNext(); i != dummy_End; i = i->GetNext())
			{
				if (MaxScoreNode->GetScore() < i->GetScore())//�ő�l�����������ꍇ
				{
					MaxScoreNode = i;//�ő�l���X�V
				}

			}
			//���[�v�𔲂�����AMaxScoreNode�����m���̒��ōő�l��SCORE�����m�[�h

			//�ő�l�̃m�[�hMaxScoreNode�̑O��̃m�[�h�֌W���q���Ȃ���
			PrevBox = MaxScoreNode->GetPrev();
			PrevBox->SetNext(MaxScoreNode->GetNext());
			NextBox = MaxScoreNode->GetNext();
			NextBox->SetPrev(MaxScoreNode->GetPrev());

			//�ő�l�̃m�[�hMaxScoreNode���m���ɓ���邽�߁A�O��̃m�[�h�֌W���q���Ȃ���
			NextBox = NowConfirm->GetNext();//MaxScoreNode�̎��ɂȂ�m�[�h
			NextBox->SetPrev(MaxScoreNode);//MaxScoreNode��O�ɐݒ�

			NowConfirm->SetNext(MaxScoreNode);//�m���̎���MaxScoreNode������

			//�ő�l�̃m�[�hMaxScoreNode�ɐݒ肳��Ă���O��|�C���^���X�V����
			MaxScoreNode->SetPrev(NowConfirm);//MaxScoreNode�̑O�ɂȂ�m�[�h�͊m���
			MaxScoreNode->SetNext(NextBox);

			//�m�����X�V
			NowConfirm = MaxScoreNode;

			//�ő�l���A�m���̎��ɉ��肷��
			MaxScoreNode = MaxScoreNode->GetNext();
		}

	}
};