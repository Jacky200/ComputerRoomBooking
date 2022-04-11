#include"ComputerRoomManager.h"
#include<iostream>
using namespace std;
int main() {
	ComputerRoomManager crm;
	while (true)
	{
		crm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1: //学生登录
			crm.Login_Verify(StudentFile, 1);
			break;
		case 2://老师登录
			crm.Login_Verify(TeacherFile, 2);
			break;
		case 3://管理员登录
			crm.Login_Verify(ManagerFile,3);
			break;
		case 4://退出系统
			crm.ExitSystem();
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}