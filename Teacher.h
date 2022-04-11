#pragma once
#include"Identity.h"
#include"BookingInfo.h"
#include"GlobalFile.h"
#include<fstream>
#include"ComputerRoom.h"
#include<vector>

class Teacher :public Identity {
public:
	//无参构造
	Teacher();
	//有参构造
	Teacher(int empid,string name,string pwd);

	//显示菜单功能
	virtual void Personal_Meue() ;

	//查看所有预约
	void show_AllBooking();

	//审核预约
	void Audit_Booking();


	//职工号
	int m_EmpId=0;

	//机房信息容器
	vector<computerRoom>cm;
};