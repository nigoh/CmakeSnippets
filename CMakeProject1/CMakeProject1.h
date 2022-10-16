// CMakeProject1.h : 標準のシステム インクルード ファイル用のインクルード ファイル、
// または、プロジェクト専用のインクルード ファイル。

#pragma once

#include <iostream>

// TODO: プログラムに必要な追加ヘッダーをここで参照します。

class Snippet1
{
public:
	Snippet1(const uint16_t & MaxRecNum, const uint16_t& Interval);
	~Snippet1();

	bool init();
	bool next();
	bool prev();
	void printRec(const uint16_t &Count);

private:
	const int REC_NUM = 100;
	
	uint16_t _m_max_rec_num;	// 最大レコード
	uint16_t _m_curr_pos;		// 表示しているレコードの最初の位置
	uint16_t _m_interval;		// 間隔
};

