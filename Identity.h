#pragma once
#include<iostream>
using namespace std;
#include<string>
class Identity {
public:
	//����ӿ�
	virtual void Personal_Meue()=0; //��ʾ�˵�����
	//��Ա����
	string m_Name;
	string m_Pwd;
};