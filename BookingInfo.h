#pragma once
#include<string>
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"GlobalFile.h"

class BookingInfo {
public:
	BookingInfo();

	//读取文件函数
	void ReadFileBooking();
	//更新函数
	void updata_Booking();

	//字符信息解析函数
	void string_sub(string s, string &s1,string &s2);

	//显示所有的预约信息
	void Show_all(map<int, map<string, string>>& mp);

	//修改预约信息
	bool Modify(string data, string interval, string s_id, string s_name, string s_rid, string s);

	//记录预约的数量
	int m_size=0;
	bool FileisEmpty = false;

	//存放预约类的信息
	map<int, map<string, string>>mp;
};