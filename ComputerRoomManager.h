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
	//主页显示函数
	void Show_Menu();
	//主页退出系统函数
	void ExitSystem();

	//登录验证函数
	void Login_Verify(string filename,int type);

	//管理员页面
	void Manager_Menu(Identity* &manager);

	//学生页面子系统
	void Student_Menu(Identity* &student);

	//教师页面子系统
	void Teacher_Menu(Identity*& teacher);

	~ComputerRoomManager();

	
};