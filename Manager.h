#pragma once
#include"Identity.h"
#include"ComputerRoomManager.h"
#include<vector>

class Manager :public Identity {
public:
	Manager();

	Manager(string name,string pwd);

	//显示菜单功能
	virtual void Personal_Meue() ; 

	//添加账号
	void Add_Account();

	//查看账号
	void Show_AllAccount();
	
	//删除账号
	void Del_Account();

	//查看机房信息
	void Show_ComputerRoom();
	
	//清空预约记录
	void Clear_Booking();

	//保存信息到文件
	void SaveFile(string filename, int id, string name, string pwd);

	void SaveFileStudent(vector<Student>& s);
	void SaveFileTeacher(vector<Teacher>& t);

	//文件读取函数
	void ReadFile(string filename, int type);


	//student文件是否为空
	bool StudentFIleisEmpty = false;

	//teacher文件是否为空
	bool TeacherFileisEmpty = false;

	vector<Student>sv;
	vector<Teacher>tv;
};