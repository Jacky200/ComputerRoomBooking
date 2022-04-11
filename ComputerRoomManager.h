#pragma once
#include<iostream>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"GlobalFile.h"
#include<fstream>
#include<vector>

using namespace std;
class ComputerRoomManager {
public:
	ComputerRoomManager();
	//��ҳ��ʾ����
	void Show_Menu();
	//��ҳ�˳�ϵͳ����
	void ExitSystem();

	//��¼��֤����
	void Login_Verify(string filename,int type);

	//����Աҳ��
	void Manager_Menu(Identity* &manager);

	//ѧ��ҳ����ϵͳ
	void Student_Menu(Identity* &student);

	//��ʦҳ����ϵͳ
	void Teacher_Menu(Identity*& teacher);

	~ComputerRoomManager();

	
};