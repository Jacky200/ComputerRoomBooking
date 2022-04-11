#include"Student.h"

Student::Student()//�޲ι���
{

}

Student::Student(int id, string name, string pwd)//�вι���
{
	this->m_stuid = id;
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

void Student::Personal_Meue() //��ʾ�˵�����
{
	cout << "*********************��ӭ����ѧ��ģʽ*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.��  ��  Ԥ  Լ                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.��  ��  ��  ��  Ԥ  Լ            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.��  ��  ��  ��  Ԥ  Լ            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.ȡ  ��  Ԥ  Լ                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 5.��  ��  ��  ¼                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//����ԤԼ
void Student::Booking()
{
	string data;
	string interval;
	int s = 0;
	cout << "=====��ʼ����ԤԼ=====" << endl;
	while (true) {
		cout << "1.��һ" << endl;
		cout << "2.��һ" << endl;
		cout << "3.��һ" << endl;
		cout << "4.��һ" << endl;
		cout << "5.��һ" << endl;
		cout << "��ѡ������:" << endl;
		cin >> s;
		if (s > 0 && s < 6) {
			break;
		}
		else {
			cout << "ѡ���������������" << endl;
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

	while (true) {
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "����������ѡ��:" << endl;
		cin >> s;
		if (s == 1 || s == 2) {
			break;
		}
		else {
			cout << "ѡ���������������" << endl;
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
			cout << i+1 << "." << cm[i].m_id << "����" << " ����:" << cm[i].m_capacity << endl;
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

	string status = "�����";
	//д���ļ�
	ofstream ofs;
	ofs.open(BookingFile, ios::out | ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " "
		<< "s_id:" << this->m_stuid << " " << "s_name:" << this->m_Name << " "
		<< "s_rid:" << cm[s-1].m_id << " " << "status:" << status << endl;

	cout << "ԤԼ�ɹ�����ʦ�����" << endl;
}

//�鿴�ҵ�ԤԼ
void Student::Show_Booking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "��ǰԤԼ��¼Ϊ��" << endl;
		return;
	}
	bf.ReadFileBooking();
	bool ret = false;
	for (map<int, map<string, string>>::iterator it = bf.mp.begin(); it != bf.mp.end(); it++) {
		for (map<string, string>::iterator its = it->second.begin(); its != it->second.end(); its++) {
			if (its->second == to_string(this->m_stuid)) {
				ret = true;
				break;
			}
		}
		if (ret) {
			for (map<string, string>::iterator itss = it->second.begin(); itss != it->second.end(); itss++) {
				cout << itss->first << ":" << itss->second << " ";
			}
			cout << endl;
			ret = false;
		}
	}
}

//�鿴����ԤԼ
void Student::Show_AllBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "��ǰԤԼ��¼Ϊ��" << endl;
		return;
	}
	bf.ReadFileBooking();
	bf.Show_all(bf.mp);
}

//ȡ��ԤԼ
void Student::CancelBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "��ǰԤԼ��¼Ϊ��" << endl;
		return;
	}
	bf.ReadFileBooking();
	
	string data;
	string interval;
	string s_id=to_string(this->m_stuid);
	string s_name = this->m_Name;
	string s_rid;
	
	cout << "ȡ��ԤԼ��......." << endl;
	int s = 0;
	while (true) {
		cout << "1.����һ" << endl;
		cout << "2.����һ" << endl;
		cout << "3.����һ" << endl;
		cout << "4.����һ" << endl;
		cout << "5.����һ" << endl;
		cout << "��ѡ��ȡ������:" << endl;
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
		cout << "������ȡ����ʱ���:" << endl;
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
	flag=bf.Modify(data, interval, to_string(this->m_stuid), this->m_Name, to_string(cm[s - 1].m_id), "ȡ��ԤԼ");
	if (flag) {
		cout << "ȡ���ɹ�" << endl;
	}
	else {
		cout << "ȡ��ʧ��" << endl;
	}
}
