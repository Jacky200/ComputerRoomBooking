#include"ComputerRoomManager.h"
#include<iostream>
using namespace std;
int main() {
	ComputerRoomManager crm;
	while (true)
	{
		crm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1: //ѧ����¼
			crm.Login_Verify(StudentFile, 1);
			break;
		case 2://��ʦ��¼
			crm.Login_Verify(TeacherFile, 2);
			break;
		case 3://����Ա��¼
			crm.Login_Verify(ManagerFile,3);
			break;
		case 4://�˳�ϵͳ
			crm.ExitSystem();
			break;
		default:
			cout << "��������������ѡ��" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}