// CMakeProject1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "CMakeProject1.h"

using namespace std;



Snippet1::Snippet1(const uint16_t& MaxRecNum, const uint16_t& Interval)
{
	this->_m_curr_pos = 0;
	this->_m_interval = Interval;
	this->_m_max_rec_num = MaxRecNum;
}

Snippet1::~Snippet1()
{
}

bool Snippet1::init()
{
	// 進めるレコード位置の算出
	uint16_t t_next = this->_m_interval;
	//レコード取得後の位置が最大レコード位置より大きい場合
	if (this->_m_curr_pos + this->_m_interval > this->_m_max_rec_num)
	{
		// 剰余を格納
		t_next = this->_m_max_rec_num % this->_m_interval;
	}

	printRec(t_next);

	this->_m_curr_pos += t_next;

	return true;
}

bool Snippet1::next()
{
	// 現在レコード位置と最大レコード位置が同値の場合
	if (this->_m_curr_pos == this->_m_max_rec_num)
	{
		cout << "Equal value curr_pos max_rec_num" << endl;
		return true;
	}

	// 進めるレコード位置の算出
	uint16_t t_next = this->_m_interval;
	//レコード取得後の位置が最大レコード位置より大きい場合
	if (this->_m_curr_pos + this->_m_interval > this->_m_max_rec_num)
	{
		// 剰余を格納
		t_next = this->_m_max_rec_num % this->_m_interval;
	}

	printRec(t_next);

	// レコード位置の更新
	this->_m_curr_pos += t_next;
	return true;
}

bool Snippet1::prev()
{
	if (this->_m_curr_pos == this->_m_interval)
	{
		cout << "empty pos" << endl;
		return true;
	}

	// 取得レコード位置を戻す
	uint16_t t_prev_offset = this->_m_interval;
	if (this->_m_curr_pos == this->_m_max_rec_num)
	{
		// 端数を格納
		t_prev_offset += this->_m_max_rec_num % this->_m_interval;
	}
	else 
	{
		t_prev_offset += this->_m_interval;
	}

	this->_m_curr_pos -= t_prev_offset;


	printRec(this->_m_interval);
	// レコード位置の更新
	this->_m_curr_pos += this->_m_interval;

	return true;
}

void Snippet1::printRec(const uint16_t& Count)
{
	cout << "------------------------------------" << endl;
	cout << "Interval" << this->_m_interval << endl;
	for (size_t i = 0; i < Count; i++)
	{
		int tmp = this->_m_max_rec_num - ( Count + this->_m_curr_pos );
 		cout << "Rec:" << tmp + (i + 1) << endl;
	}
	cout << "------------------------------------" << endl;
}

int main()
{

	Snippet1 a(15, 6);

	cout << "INIT" << endl;
	a.init();

	cout << "NEXT" << endl;
	a.next();

	cout << "NEXT" << endl;
	a.next();

	cout << "NEXT" << endl;
	a.next();

	cout << "NEXT" << endl;
	a.next();

	cout << "PREV" << endl;
	a.prev();

	cout << "PREV" << endl;
	a.prev();

	cout << "PREV" << endl;
	a.prev();

	cout << "PREV" << endl;
	a.prev();

	cout << "Hello CMake." << endl;
	return 0;
}
