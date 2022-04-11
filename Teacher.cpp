#include"Teacher.h"
//�޲ι���
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(ComputerRoom, ios::in);
	int s_id = 0;
	int num = 0;

	cm.clear();
	while (ifs >> s_id && ifs >> num) {
		computerRoom crm;
		crm.m_id = s_id;
		crm.m_capacity = num;
		cm.push_back(crm);
	}
}

//��ʾ�˵�����
void Teacher::Personal_Meue()
{
	cout << "***********************��ӭ������ʦģʽ*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.��  ��  Ԥ  Լ                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.��  ��  Ԥ  Լ                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.��  ��  ��  ¼                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//�鿴����ԤԼ
void Teacher::show_AllBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "��ǰ��ѧ��ԤԼ" << endl;
		return;
	}
	bf.ReadFileBooking();
	bf.Show_all(bf.mp);
}

//���ԤԼ
void Teacher::Audit_Booking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "��ǰԤԼ��¼Ϊ��" << endl;
		return;
	}
	bf.ReadFileBooking();

	string data;
	string interval;
	string s_rid;

	cout << "�����Ϣ��......." << endl;
	int s = 0;
	while (true) {
		cout << "1.����һ" << endl;
		cout << "2.����һ" << endl;
		cout << "3.����һ" << endl;
		cout << "4.����һ" << endl;
		cout << "5.����һ" << endl;
		cout << "��ѡ��ͨ���������:" << endl;
		cin >> s;
		if (s > 0 && s < 6) {
			break;
		}
		else {
			cout << "�����������������" << endl;
		}
	}

	switch (s)
	{
	case 1:
		data = "����һ";
		break;
	case 2:
		data = "���ڶ�";
		break;
	case 3:
		data = "������";
		break;
	case 4:
		data = "������";
		break;
	case 5:
		data = "������";
		break;
	default:
		break;
	}

	while (true)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "������ͨ����˵�ʱ���:" << endl;
		cin >> s;
		if (s == 1 || s == 2) {
			break;
		}
		else {
			cout << "�����������������" << endl;
		}
	}

	if (s == 1) {
		interval = "����";
	}
	else {
		interval = "����";
	}

	
	while (true)
	{

		for (int i = 0; i < (signed)cm.size(); i++) {
			cout << i + 1 << "." << cm[i].m_id << "����" << " ����:" << cm[i].m_capacity << endl;
		}
		cout << "����������ѡ��" << endl;
		cin >> s;
		if (s > 0 && s <= (signed)cm.size()) {
			break;
		}
		else {
			cout << "ѡ���������������" << endl;
		}

	}
	bool flag = false;
	string s_id;
	string s_name;
	cout << "������ѧ��:" << endl;
	cin >> s_id;
	cout << "������ѧ������:" << endl;
	cin >> s_name;
	
	flag = bf.Modify(data, interval,s_id ,s_name , to_string(cm[s - 1].m_id), "���ͨ��");
	if (flag) {
		cout << "���ͨ��" << endl;
	}
	else {
		cout << "���ʧ��" << endl;
	}
}

