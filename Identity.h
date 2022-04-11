#pragma once
#include<iostream>
using namespace std;
#include<string>
class Identity {
public:
	//定义接口
	virtual void Personal_Meue()=0; //显示菜单功能
	//成员属性
	string m_Name;
	string m_Pwd;
};