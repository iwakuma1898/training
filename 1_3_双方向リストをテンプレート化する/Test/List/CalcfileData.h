#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "CList.h"


template<class T>//テンプレート化
void DataInList(std::ifstream &file, CList<T> m_List);