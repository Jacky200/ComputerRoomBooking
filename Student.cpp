#include"Student.h"

Student::Student()//无参构造
{

}

Student::Student(int id, string name, string pwd)//有参构造
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

void Student::Personal_Meue() //显示菜单功能
{
	cout << "*********************欢迎进入学生模式*********************" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
	cout << "\t\t| 1.申  请  预  约                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 2.查  看  我  的  预  约            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 3.查  看  所  有  预  约            |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 4.取  消  预  约                    |    \t\t" << endl;
	cout << "\t\t|                                     |    \t\t" << endl;
	cout << "\t\t| 5.退  出  登  录                    |    \t\t" << endl;
	cout << "\t\t -------------------------------------     \t\t" << endl;
}

//申请预约
void Student::Booking()
{
	string data;
	string interval;
	int s = 0;
	cout << "=====开始进行预约=====" << endl;
	while (true) {
		cout << "1.周一" << endl;
		cout << "2.周一" << endl;
		cout << "3.周一" << endl;
		cout << "4.周一" << endl;
		cout << "5.周一" << endl;
		cout << "请选择日期:" << endl;
		cin >> s;
		if (s > 0 && s < 6) {
			break;
		}
		else {
			cout << "选择错误，请重新输入" << endl;
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

	while (true) {
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		cout << "请输入您的选择:" << endl;
		cin >> s;
		if (s == 1 || s == 2) {
			break;
		}
		else {
			cout << "选择错误，请重新输入" << endl;
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
			cout << i+1 << "." << cm[i].m_id << "机房" << " 容量:" << cm[i].m_capacity << endl;
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

	string status = "审核中";
	//写入文件
	ofstream ofs;
	ofs.open(BookingFile, ios::out | ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " "
		<< "s_id:" << this->m_stuid << " " << "s_name:" << this->m_Name << " "
		<< "s_rid:" << cm[s-1].m_id << " " << "status:" << status << endl;

	cout << "预约成功，老师审核中" << endl;
}

//查看我的预约
void Student::Show_Booking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "当前预约记录为空" << endl;
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

//查看所有预约
void Student::Show_AllBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "当前预约记录为空" << endl;
		return;
	}
	bf.ReadFileBooking();
	bf.Show_all(bf.mp);
}

//取消预约
void Student::CancelBooking()
{
	BookingInfo bf;
	if (bf.FileisEmpty) {
		cout << "当前预约记录为空" << endl;
		return;
	}
	bf.ReadFileBooking();
	
	string data;
	string interval;
	string s_id=to_string(this->m_stuid);
	string s_name = this->m_Name;
	string s_rid;
	
	cout << "取消预约中......." << endl;
	int s = 0;
	while (true) {
		cout << "1.星期一" << endl;
		cout << "2.星期一" << endl;
		cout << "3.星期一" << endl;
		cout << "4.星期一" << endl;
		cout << "5.星期一" << endl;
		cout << "请选择取消日期:" << endl;
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
		cout << "请输入取消的时间段:" << endl;
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
	flag=bf.Modify(data, interval, to_string(this->m_stuid), this->m_Name, to_string(cm[s - 1].m_id), "取消预约");
	if (flag) {
		cout << "取消成功" << endl;
	}
	else {
		cout << "取消失败" << endl;
	}
}
