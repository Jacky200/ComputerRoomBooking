#pragma once
#include"Identity.h"
#include"BookingInfo.h"
#include"GlobalFile.h"
#include<fstream>
#include"ComputerRoom.h"
#include<vector>

class Teacher :public Identity {
public:
	//�޲ι���
	Teacher();
	//�вι���
	Teacher(int empid,string name,string pwd);

	//��ʾ�˵�����
	virtual void Personal_Meue() ;

	//�鿴����ԤԼ
	void show_AllBooking();

	//���ԤԼ
	void Audit_Booking();


	//ְ����
	int m_EmpId=0;

	//������Ϣ����
	vector<computerRoom>cm;
};