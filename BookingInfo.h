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

	//��ȡ�ļ�����
	void ReadFileBooking();
	//���º���
	void updata_Booking();

	//�ַ���Ϣ��������
	void string_sub(string s, string &s1,string &s2);

	//��ʾ���е�ԤԼ��Ϣ
	void Show_all(map<int, map<string, string>>& mp);

	//�޸�ԤԼ��Ϣ
	bool Modify(string data, string interval, string s_id, string s_name, string s_rid, string s);

	//��¼ԤԼ������
	int m_size=0;
	bool FileisEmpty = false;

	//���ԤԼ�����Ϣ
	map<int, map<string, string>>mp;
};