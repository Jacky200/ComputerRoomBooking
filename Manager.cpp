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

//��ʾ�˵�����
void Manager::Personal_Meue()
{
	cout << "*********************��ӭ�������Աģʽ*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.��  ��  ��  ��                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.��  ��  ��  ��                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.ɾ  ��  ��  ��                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.��  ��  ��  ��  ��  Ϣ            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 5.��  ��  Ԥ  Լ  ��  ¼            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 6.ע  ��  ��  ¼                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//����˺�
void Manager::Add_Account()
{
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.��ӽ�ʦ�˺�" << endl;
	cout << "3.�˳�" << endl;
	int s = 0;
	cin >> s;
	int id=0;
	string name;
	string pwd;
	if (s == 1) {
		cout << "������ѧ��ID:" << endl;
		cin >> id;
		cout << "�������û���:" << endl;
		cin >> name;
		cout << "����������:" << endl;
		cin >> pwd;

		this->SaveFile(StudentFile, id, name, pwd);
		this->StudentFIleisEmpty = false;

	}
	else if(s==2){
		cout << "������ְ��ID:" << endl;
		cin >> id;
		cout << "�������û���:" << endl;
		cin >> name;
		cout << "����������:" << endl;
		cin >> pwd;

		this->SaveFile(TeacherFile, id, name, pwd);
		this->TeacherFileisEmpty = false;

	}
	else {
		return;
	}
	cout << "������Ϣ�ɹ�" << endl;
	return;
	
}

//�鿴�˺�
void Manager::Show_AllAccount()
{
	cout << "1.��ʾ����ѧ���˺���Ϣ" << endl;
	cout << "2.��ʾ���н�ʦ�˺���Ϣ" << endl;
	cout << "3.�˳�" << endl;
	int s = 0;
	cout << "����������ѡ��" << endl;
	cin >> s;
	if (s == 1) {
		if (this->StudentFIleisEmpty) {
			cout << "��ǰѧ����ϢΪ��" << endl;
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
			cout << "��ǰ��ʦ��ϢΪ��" << endl;
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

//ɾ���˺�
void Manager::Del_Account()
{
	cout << "1.ɾ��ѧ����Ϣ" << endl;
	cout << "2.ɾ����ʦ��Ϣ" << endl;
	cout << "3.�˳�" << endl;
	int s;
	cout << "����������ѡ��:" << endl;
	cin >> s;
	int id;
	string name;
	string pwd;
	if (s == 1) {
		cout << "������ѧ��ID:" << endl;
		cin >> id;
		for (vector<Student>::iterator it = sv.begin(); it != sv.end(); it++) {
			if ((*it).m_stuid == id) {
				sv.erase(it);
				cout << "ɾ���ɹ�" << endl;
				this->SaveFileStudent(sv);
				return;
			}
		}
		cout << "ɾ��ʧ��" << endl;
		return;
	}
	else if (s == 2) {
		cout << "�������ʦID:" << endl;
		cin >> id;
		for (vector<Teacher>::iterator it = tv.begin(); it != tv.end(); it++) {
			if ((*it).m_EmpId == id) {
				tv.erase(it);
				cout << "ɾ���ɹ�" << endl;
				this->SaveFileTeacher(tv);
				return;
			}
		}
		cout << "ɾ��ʧ��" << endl;
		return;
	}
	else {
		return;
	}
}

//�鿴������Ϣ
void Manager::Show_ComputerRoom()
{
	ifstream ifs;
	ifs.open(ComputerRoom, ios::in);
	int id=0;
	int num=0;
	while (ifs >> id && ifs >> num) {
		cout << "������:" << id << " ��������:" << num << endl;
	}
	ifs.close();
}

//���ԤԼ��¼
void Manager::Clear_Booking()
{
	cout << "1.ȷ�����" << endl;
	cout << "2.�˳�" << endl;
	int s = 0;
	cin >> s;
	if(s==1){
		ofstream ofs;
		ofs.open(BookingFile, ios::trunc);
		ofs.close();
		cout << "��ճɹ�" << endl;
	}
	return;
}

void Manager::SaveFile(string filename, int id, string name, string pwd)
{
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
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
			cout << "�ļ�Ϊ��" << endl;
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
			cout << "�ļ�Ϊ��" << endl;
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
