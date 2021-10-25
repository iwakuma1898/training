#pragma once

//===========================
/*
  @brief 反復子のクラス（const版）
  @author 岩熊一樹
  @date 10/6
 */
 //===========================

/*
  @breif	コンストラクタ
 */
template<class T>
CConstIterator<T>::CConstIterator(TNode<T>* p)//番地を指定し、どこから始めるのかを指定
	//: m_node(p)
{
	m_node = p;
}

/*
  @breif　　リストの先頭に向かって１つ進める（）
  @return
 */
template<class T>
void CConstIterator<T>::GoPrevNode()
{
	m_node = m_node->m_prev;
}

/*
  @breif　　リストの末尾に向かって１つ進める（）
  @return
 */
template<class T>
void CConstIterator<T>::GoNextNode()
{
	m_node = m_node->m_next;
}

/*
  @breif　　イテレータの指す要素を取得する[const版]（）
  @return　　イテレータの指す要素[const版]（）
 */
template<class T>
const T& CConstIterator<T>::Get()const { return *this->m_node->m_record; }



/**
 * @breif	等価演算子をオーバーロード[const版]
 * @return	等価比較した結果
 */
template<class T>
bool CConstIterator<T>::operator==(const CConstIterator<T>& itr) const
{
	return m_node == itr.m_node;
}

/**
 * @breif	非等価演算子をオーバーロード[const版]
 * @return	非等価比較した結果
 */
template<class T>
bool CConstIterator<T>::operator!=(const CConstIterator<T>& itr) const
{
	return m_node != itr.m_node;
}


/**
* @brief	ノードで不正なものであるかを確認する
* @return	ダミーノードであるかの真偽結果
*/
template<class T>
bool CConstIterator<T>::CheckNode()
{
	if (m_node==nullptr)
	{
		return false;
	}
	else {
		return true;
	}
}



//===========================
/*
  @brief 反復子のクラス（非const版）
  @author 岩熊一樹
  @date 10/6
 */
 //===========================

///*
//  @breif	コンストラクタ
// */
template<class T>
CIterator<T>::CIterator(TNode<T>* p) : CConstIterator<T>(p)//継承
{

}



/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
template<class T>
T& CIterator<T>::Get() { return *this->m_node->m_record; }

/**
 * @breif	等価演算子をオーバーロード
 * @return	等価比較した結果
 */
template<class T>
bool CIterator<T>::operator==(const CIterator<T>& itr) const
{
	return this->m_node == itr.m_node;
}


/**
 * @breif	非等価演算子をオーバーロード
 * @return	非等価比較した結果
 */
template<class T>
bool CIterator<T>::operator!=(const CIterator<T>& itr) const
{
	return this->m_node != itr.m_node;
}
