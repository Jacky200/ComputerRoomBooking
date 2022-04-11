#include"ComputerRoomManager.h"

ComputerRoomManager::ComputerRoomManager()
{

}

void ComputerRoomManager::Show_Menu()
{
	cout << "***********************欢迎来到Jacky机房预约系统*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.学  生  登  录                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.教  师  登  录                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.管  理  员  登 录                 |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.退  出  程  序                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

void ComputerRoomManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void ComputerRoomManager::Login_Verify(string filename, int type)
{
	Identity* identity = NULL;
	ifstream ifs;
	int id = 0;
	string name;
	string pwd;
	if (type == 1) {
		cout << "请输入您的学号:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入您的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入您的用户名:" << endl;
	cin >> name;
	cout << "请输入您的密码:" << endl;
	cin >> pwd;

	int fid;
	string fname;
	string fpwd;
	bool ret = false;
	if (type == 1) {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在，打开失败" << endl;
			return;
		}
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "登录成功" << endl;
				ret = true;
				identity = new Student(id, name, pwd);
				break;
			}
		}
	}
	else if (type == 2) {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在，打开失败" << endl;
			return;
		}
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "登录成功" << endl;
				ret = true;
				identity = new Teacher(id, name, pwd);
				break;
			}
		}
	}
	else {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在，打开失败" << endl;
			return;
		}
		while ( ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "登录成功" << endl;
				ret = true;
				identity = new Manager(name, pwd);
				break;
			}
		}
	}

	if (!ret) {
		cout << "账号或密码错误" << endl;
		return;
	}

	system("pause");
	system("cls");
	//登录成功就调显示函数
	if (type == 1) {
		this->Student_Menu(identity);
	}
	else if (type == 2) {
		this->Teacher_Menu(identity);
	}
	else {
		this->Manager_Menu(identity);
	}

	//功能结束就删除identity（堆上的空间）
	delete identity;
}

void ComputerRoomManager::Manager_Menu(Identity*& manager)
{
	Manager* m = (Manager*)manager;
	bool ret = false;
	while (true)
	{
		m->Personal_Meue();
		cout << "请输入您的选择:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://增加账号
			m->Add_Account();
			break;
		case 2://查看账号
			m->Show_AllAccount();
			break;
		case 3://删除账号
			m->Del_Account();
			break;
		case 4://查看机房信息
			m->Show_ComputerRoom();
			break;
		case 5://清空预约记录
			m->Clear_Booking();
			break;
		case 6://退出程序
			cout << "退出管理员页面" << endl;
			ret = true;
			break;
		default:
			cout << "选择错误，请重新输入" << endl;
			break;
		}
		if (ret) {
			break;
		}
		system("pause");
		system("cls");
	}

}


void ComputerRoomManager::Student_Menu(Identity*& student)
{
	Student* s = (Student*)student;
	bool ret = false;
	while (true)
	{
		s->Personal_Meue();
		cout << "请输入您的选择:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: //申请预约
			s->Booking();
			break;
		case 2:  //查看我的预约
			s->Show_Booking();
			break;
		case 3: //查看所有预约
			s->Show_AllBooking();
			break;
		case 4: //取消预约
			s->CancelBooking();
			break;
		case 5: //退出登录
			cout << "退出学生页面" << endl;
			ret = true;
			break;
		default:
			cout << "选择错误，请重新输入" << endl;
			break;
		}
		if (ret) {
			break;
		}
		system("pause");
		system("cls");
	}
}

void ComputerRoomManager::Teacher_Menu(Identity*& teacher)
{
	Teacher* t = (Teacher*)teacher;
	bool ret = false;
	while (true)
	{
		t->Personal_Meue();
		cout << "请输入您的选择:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: //查看所有预约
			t->show_AllBooking();
			break;
		case 2: //审核预约
			t->Audit_Booking();
			break;
		case 3:
			ret = true;
			cout << "退出登录......." << endl;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
		if (ret) {
			break;
		}
		system("pause");
		system("cls");
	}
}

ComputerRoomManager::~ComputerRoomManager()
{

}