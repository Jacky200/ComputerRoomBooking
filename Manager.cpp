#include"Manager.h"
#include"GlobalFile.h"
#include<fstream>

Manager::Manager()
{
	
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//显示菜单功能
void Manager::Personal_Meue()
{
	cout << "*********************欢迎进入管理员模式*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.添  加  账  号                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.查  看  账  号                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.删  除  账  号                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.查  看  机  房  信  息            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 5.清  空  预  约  记  录            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 6.注  销  登  录                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//添加账号
void Manager::Add_Account()
{
	cout << "1.添加学生账号" << endl;
	cout << "2.添加教师账号" << endl;
	cout << "3.退出" << endl;
	int s = 0;
	cin >> s;
	int id=0;
	string name;
	string pwd;
	if (s == 1) {
		cout << "请输入学号ID:" << endl;
		cin >> id;
		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入密码:" << endl;
		cin >> pwd;

		this->SaveFile(StudentFile, id, name, pwd);
		this->StudentFIleisEmpty = false;

	}
	else if(s==2){
		cout << "请输入职工ID:" << endl;
		cin >> id;
		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入密码:" << endl;
		cin >> pwd;

		this->SaveFile(TeacherFile, id, name, pwd);
		this->TeacherFileisEmpty = false;

	}
	else {
		return;
	}
	cout << "保存信息成功" << endl;
	return;
	
}

//查看账号
void Manager::Show_AllAccount()
{
	cout << "1.显示所有学生账号信息" << endl;
	cout << "2.显示所有教师账号信息" << endl;
	cout << "3.退出" << endl;
	int s = 0;
	cout << "请输入您的选择" << endl;
	cin >> s;
	if (s == 1) {
		if (this->StudentFIleisEmpty) {
			cout << "当前学生信息为空" << endl;
			return;
		}
		else {
			sv.clear();
			this->ReadFile(StudentFile,1);
			for (vector<Student>::iterator it = sv.begin(); it != sv.end(); it++) {
				cout << (*it).m_stuid << " " << (*it).m_Name << " " << (*it).m_Pwd << endl;
			}
		}
	}
	else if (s == 2) {
		if (this->TeacherFileisEmpty) {
			cout << "当前老师信息为空" << endl;
			return;
		}
		else {
			tv.clear();
			this->ReadFile(TeacherFile, 2);
			for (vector<Teacher>::iterator it = tv.begin(); it != tv.end(); it++) {
				cout << (*it).m_EmpId << " " << (*it).m_Name << " " << (*it).m_Pwd << endl;
			}
		}
	}
	return;
}

//删除账号
void Manager::Del_Account()
{
	cout << "1.删除学生信息" << endl;
	cout << "2.删除教师信息" << endl;
	cout << "3.退出" << endl;
	int s;
	cout << "请输入您的选择:" << endl;
	cin >> s;
	int id;
	string name;
	string pwd;
	if (s == 1) {
		cout << "请输入学生ID:" << endl;
		cin >> id;
		for (vector<Student>::iterator it = sv.begin(); it != sv.end(); it++) {
			if ((*it).m_stuid == id) {
				sv.erase(it);
				cout << "删除成功" << endl;
				this->SaveFileStudent(sv);
				return;
			}
		}
		cout << "删除失败" << endl;
		return;
	}
	else if (s == 2) {
		cout << "请输入教师ID:" << endl;
		cin >> id;
		for (vector<Teacher>::iterator it = tv.begin(); it != tv.end(); it++) {
			if ((*it).m_EmpId == id) {
				tv.erase(it);
				cout << "删除成功" << endl;
				this->SaveFileTeacher(tv);
				return;
			}
		}
		cout << "删除失败" << endl;
		return;
	}
	else {
		return;
	}
}

//查看机房信息
void Manager::Show_ComputerRoom()
{
	ifstream ifs;
	ifs.open(ComputerRoom, ios::in);
	int id=0;
	int num=0;
	while (ifs >> id && ifs >> num) {
		cout << "机房号:" << id << " 电脑数量:" << num << endl;
	}
	ifs.close();
}

//清空预约记录
void Manager::Clear_Booking()
{
	cout << "1.确认清空" << endl;
	cout << "2.退出" << endl;
	int s = 0;
	cin >> s;
	if(s==1){
		ofstream ofs;
		ofs.open(BookingFile, ios::trunc);
		ofs.close();
		cout << "清空成功" << endl;
	}
	return;
}

void Manager::SaveFile(string filename, int id, string name, string pwd)
{
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	if (filename==ManagerFile) {
		ofs << name << " " << pwd << endl;
	}
	else {
		ofs << id << " " << name << " " << pwd << endl;
	}
	ofs.close();
}

void Manager::ReadFile(string filename, int type)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	char ch;
	if (type == 1) {
		ifs >> ch;
		if (ifs.eof()) {
			cout << "文件为空" << endl;
			this->StudentFIleisEmpty = true;
			sv.clear();
			ifs.close();
			return;
		}
		ifs.putback(ch);
		int id;
		string name;
		string pwd;
		while (ifs >> id && ifs >> name && ifs >> pwd) {
			sv.push_back(Student(id, name, pwd));
		}
		return;
	}
	else if (type == 2) {
		ifs >> ch;
		if (ifs.eof()) {
			cout << "文件为空" << endl;
			this->TeacherFileisEmpty = true;
			tv.clear();
			ifs.close();
			return;
		}
		ifs.putback(ch);
		int id;
		string name;
		string pwd;
		while (ifs >> id && ifs >> name && ifs >> pwd) {
			tv.push_back(Teacher(id, name, pwd));
		}
		return;
	}
}

void Manager::SaveFileStudent(vector<Student>& s)
{
	ofstream ofs;
	ofs.open(StudentFile, ios::out | ios::trunc );

	for (vector<Student>::iterator it = s.begin(); it != s.end(); it++) {
		ofs << (*it).m_stuid << " " << (*it).m_Name << " " << (*it).m_Pwd << endl;
	}
	ofs.close();
}

void Manager::SaveFileTeacher(vector<Teacher>& t)
{
	ofstream ofs;
	ofs.open(TeacherFile, ios::out | ios::trunc);

	for (vector<Teacher>::iterator it = t.begin(); it != t.end(); it++) {
		ofs << (*it).m_EmpId << " " << (*it).m_Name << " " << (*it).m_Pwd << endl;
	}
	ofs.close();
}
