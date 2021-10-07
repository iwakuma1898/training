/*
  @brief �n�b�V���e�[�u���N���X
  @author ��F���
  @date 10/6
 */

#include "CTable.h"

 /*
   @fn
   @brief�@�m�[�h�𐶐����}������
   @param�@�istd::string lineKey�j�ǂݎ�����L�[
   @param�@�istd::string lineEngName�j�ǂݎ�������O
  */
void CTable::Insert(std::string lineKey, std::string  lineEngName)
{
	//�n�b�V���l���Z�o����
	int hashkey = CalcHash(lineKey);

	if (Table[hashkey].GetEngName() == "")//�󂫂�����ꍇ
	{
		//�z��ɃZ�b�g
		Table[hashkey].SetKey(lineKey);
		Table[hashkey].SetEngName(lineEngName);
	}
	else//���ɔz��ɒl�������Ă����ꍇ
	{
		//�A�����X�g������Ă��Ȃ��ꍇ
		if (Table[hashkey].GetNext() == NULL)
		{
			List = new CList();//���X�g�𐶐�����
			List->Insert(lineKey, lineEngName);//�m�[�h�𐶐������X�g�ɑ}��
			Table[hashkey].SetMyList(List);//�z��ɕR�Â������X�g�Ƃ��ēo�^����
		}
		else//�A�����X�g��H��A�����Ƀm�[�h�𐶐�����
		{
			//���̔z��ɕR�Â������X�g���X�g��,�m�[�h�𐶐����}��
			Table[hashkey].GetMyList()->Insert(lineKey, lineEngName);
		}
	}

}

/*
  @fn
  @brief�@�n�b�V���e�[�u������������
  @param�@�istd::string Key�j�L�[
 */
std::string CTable::Search(std::string Key)
{
	//�n�b�V���l���Z�o����
	int hashkey = CalcHash(Key);

	//����
	if (Table[hashkey].GetKey() == Key)//��v�����ꍇ
	{
		return Table[hashkey].GetEngName();//
	}
	else//Key���Ⴄ�Ȃ�A���X�g��H��
	{
		if (Table[hashkey].GetEngName() == "")//�z��ɂ��������������X�g�������Ă��Ȃ��ꍇ
		{
			return "�p�P�ꂪ������܂���ł����B�idata.txt�̍�����ɖ����P��ł͂���܂��񂩁H�j";
		}

		List = Table[hashkey].GetMyList();//���̔z��ɕR�Â������X�g

		if(List ==NULL)//�z��ɂ͂P�P�ꂾ���ŁA���X�g�������Ă��Ȃ��ꍇ
		{
			return "�p�P�ꂪ������܂���ł����B�idata.txt�̍�����ɖ����P��ł͂���܂��񂩁H�j";
		}


		////�z��ɕR�Â������X�g��T��
		for (CNode *i = List->GetDummy_First()->GetNext(); i != List->GetDummy_End(); i = i->GetNext())
		{
			if (i->GetKey() == Key)
			{
				return i->GetEngName();//
			}
		}
		//���[�v�𔲂����ꍇ�AKey�̓��͒l������Ă���Ƃ�������
		return "�p�P�ꂪ������܂���ł����B�idata.txt�̍�����ɖ����P��ł͂���܂��񂩁H�j";
	}
}

/*
  @fn
  @brief�@�n�b�V���l���Z�o����
  @param�@�istd::string Key�j�L�[
 */
int CTable::CalcHash(std::string Key)//�L�[����n�b�V���l���v�Z
{
	int num = 0;
	int length = Key.size(); //������̒���
	for (int i = 0; i < length; i++)
	{
		num += (Key[i] - '0');//������𐔒l�ɕϊ�
	}
	int hash = num % TableMAX;//�n�b�V���l��
	return hash;
}

/*
  @fn
  @brief�@�n�b�V���e�[�u���ɕR�Â������X�g���폜����
 */
void CTable::Exit()
{
	for (int i = 0; i < TableMAX; i++)//�e�[�u���̑S�Ă̔z���T��
	{
		if (Table[i].GetMyList() != NULL)//�z��ɕR�Â������X�g�𔭌�
		{
			Table[i].GetMyList()->Exit();//���X�g���폜
		}
	}
}