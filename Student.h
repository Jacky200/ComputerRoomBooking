#pragma once
#include "Identity.h"
#include"GlobalFile.h"
#include<vector>
#include<map>
#include"ComputerRoom.h"
#include<fstream>
#include"BookingInfo.h"

class Student :public Identity {
public:
	Student();//无参构造

	Student(int id, string name, string pwd);//有参构造

	virtual void Personal_Meue() ; //显示菜单功能

	//申请预约
	void Booking();

	//查看预约
	void Show_Booking();

	//查看所有预约
	void Show_AllBooking();

	//取消预约
	void CancelBooking();

	//成员属性
	int m_stuid=0;

	//机房信息容器
	vector<computerRoom>cm;

};