#include"ComputerRoomManager.h"

ComputerRoomManager::ComputerRoomManager()
{

}

void ComputerRoomManager::Show_Menu()
{
	cout << "***********************��ӭ����Jacky����ԤԼϵͳ*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.ѧ  ��  ��  ¼                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.��  ʦ  ��  ¼                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.��  ��  Ա  �� ¼                 |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.��  ��  ��  ��                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

void ComputerRoomManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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
		cout << "����������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "����������ְ����:" << endl;
		cin >> id;
	}
	cout << "�����������û���:" << endl;
	cin >> name;
	cout << "��������������:" << endl;
	cin >> pwd;

	int fid;
	string fname;
	string fpwd;
	bool ret = false;
	if (type == 1) {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڣ���ʧ��" << endl;
			return;
		}
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��¼�ɹ�" << endl;
				ret = true;
				identity = new Student(id, name, pwd);
				break;
			}
		}
	}
	else if (type == 2) {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڣ���ʧ��" << endl;
			return;
		}
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��¼�ɹ�" << endl;
				ret = true;
				identity = new Teacher(id, name, pwd);
				break;
			}
		}
	}
	else {
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڣ���ʧ��" << endl;
			return;
		}
		while ( ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "��¼�ɹ�" << endl;
				ret = true;
				identity = new Manager(name, pwd);
				break;
			}
		}
	}

	if (!ret) {
		cout << "�˺Ż��������" << endl;
		return;
	}

	system("pause");
	system("cls");
	//��¼�ɹ��͵���ʾ����
	if (type == 1) {
		this->Student_Menu(identity);
	}
	else if (type == 2) {
		this->Teacher_Menu(identity);
	}
	else {
		this->Manager_Menu(identity);
	}

	//���ܽ�����ɾ��identity�����ϵĿռ䣩
	delete identity;
}

void ComputerRoomManager::Manager_Menu(Identity*& manager)
{
	Manager* m = (Manager*)manager;
	bool ret = false;
	while (true)
	{
		m->Personal_Meue();
		cout << "����������ѡ��:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://�����˺�
			m->Add_Account();
			break;
		case 2://�鿴�˺�
			m->Show_AllAccount();
			break;
		case 3://ɾ���˺�
			m->Del_Account();
			break;
		case 4://�鿴������Ϣ
			m->Show_ComputerRoom();
			break;
		case 5://���ԤԼ��¼
			m->Clear_Booking();
			break;
		case 6://�˳�����
			cout << "�˳�����Աҳ��" << endl;
			ret = true;
			break;
		default:
			cout << "ѡ���������������" << endl;
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
		cout << "����������ѡ��:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: //����ԤԼ
			s->Booking();
			break;
		case 2:  //�鿴�ҵ�ԤԼ
			s->Show_Booking();
			break;
		case 3: //�鿴����ԤԼ
			s->Show_AllBooking();
			break;
		case 4: //ȡ��ԤԼ
			s->CancelBooking();
			break;
		case 5: //�˳���¼
			cout << "�˳�ѧ��ҳ��" << endl;
			ret = true;
			break;
		default:
			cout << "ѡ���������������" << endl;
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
		cout << "����������ѡ��:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: //�鿴����ԤԼ
			t->show_AllBooking();
			break;
		case 2: //���ԤԼ
			t->Audit_Booking();
			break;
		case 3:
			ret = true;
			cout << "�˳���¼......." << endl;
			break;
		default:
			cout << "�������,����������" << endl;
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