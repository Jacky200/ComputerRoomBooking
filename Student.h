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
	Student();//�޲ι���

	Student(int id, string name, string pwd);//�вι���

	virtual void Personal_Meue() ; //��ʾ�˵�����

	//����ԤԼ
	void Booking();

	//�鿴ԤԼ
	void Show_Booking();

	//�鿴����ԤԼ
	void Show_AllBooking();

	//ȡ��ԤԼ
	void CancelBooking();

	//��Ա����
	int m_stuid=0;

	//������Ϣ����
	vector<computerRoom>cm;

};