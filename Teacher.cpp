#include"Teacher.h"
//无参构造
Teacher::Teacher()
{

}
//有参构造
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

//显示菜单功能
void Teacher::Personal_Meue()
{
	cout << "***********************欢迎来到教师模式*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.查  看  预  约                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.审  核  预  约                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.退  出  登  录                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//查看所有预约
void Teacher::show_AllBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "当前无学生预约" << endl;
		return;
	}
	bf.ReadFileBooking();
	bf.Show_all(bf.mp);
}

//审核预约
void Teacher::Audit_Booking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "当前预约记录为空" << endl;
		return;
	}
	bf.ReadFileBooking();

	string data;
	string interval;
	string s_rid;

	cout << "审核信息中......." << endl;
	int s = 0;
	while (true) {
		cout << "1.星期一" << endl;
		cout << "2.星期一" << endl;
		cout << "3.星期一" << endl;
		cout << "4.星期一" << endl;
		cout << "5.星期一" << endl;
		cout << "请选择通过审核日期:" << endl;
		cin >> s;
		if (s > 0 && s < 6) {
			break;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}

	switch (s)
	{
	case 1:
		data = "星期一";
		break;
	case 2:
		data = "星期二";
		break;
	case 3:
		data = "星期三";
		break;
	case 4:
		data = "星期四";
		break;
	case 5:
		data = "星期五";
		break;
	default:
		break;
	}

	while (true)
	{
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		cout << "请输入通过审核的时间段:" << endl;
		cin >> s;
		if (s == 1 || s == 2) {
			break;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}

	if (s == 1) {
		interval = "上午";
	}
	else {
		interval = "下午";
	}

	
	while (true)
	{

		for (int i = 0; i < (signed)cm.size(); i++) {
			cout << i + 1 << "." << cm[i].m_id << "机房" << " 容量:" << cm[i].m_capacity << endl;
		}
		cout << "请输入您的选择" << endl;
		cin >> s;
		if (s > 0 && s <= (signed)cm.size()) {
			break;
		}
		else {
			cout << "选择错误，请重新输入" << endl;
		}

	}
	bool flag = false;
	string s_id;
	string s_name;
	cout << "请输入学号:" << endl;
	cin >> s_id;
	cout << "请输入学生姓名:" << endl;
	cin >> s_name;
	
	flag = bf.Modify(data, interval,s_id ,s_name , to_string(cm[s - 1].m_id), "审核通过");
	if (flag) {
		cout << "审核通过" << endl;
	}
	else {
		cout << "审核失败" << endl;
	}
}

