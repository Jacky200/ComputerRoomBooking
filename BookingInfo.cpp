#include"BookingInfo.h"

BookingInfo::BookingInfo()
{
	char ch;
	ifstream ifs;
	ifs.open(BookingFile, ios::in);
	ifs >> ch;
	if (ifs.eof()) {
		mp.clear();
		this->FileisEmpty = true;
	}
	ifs.putback(ch);
	ifs.close();
}

//更新函数
void BookingInfo::updata_Booking()
{
	ofstream ofs;
	ofs.open(BookingFile, ios::out | ios::trunc);
	for (map<int, map<string, string>>::iterator it = mp.begin(); it != mp.end(); it++) {
		for (map<string, string>::iterator its = it->second.begin(); its != it->second.end(); its++) {
			ofs << its->first << ":" << its->second << " ";
		}
		ofs << endl;
	}
	ofs.close();
}

void BookingInfo::string_sub(string s, string& s1, string& s2)
{
	int start = 0;
	int pos=0;
	pos=s.find(":");
	s1 = s.substr(start, pos);//左闭右开
	start = pos + 1;
	s2 = s.substr(start, s.size());
}



void BookingInfo::ReadFileBooking()
{
	mp.clear();
	this->m_size = 0;

	ifstream ifs;
	string data;
	string interval;
	string s_id;
	string s_name;
	string c_id;
	string status;

	ifs.open(BookingFile, ios::in);
	string s1;
	string s2;
	while (ifs >> data && ifs >> interval && ifs >> s_id && ifs >> s_name && ifs >> c_id && ifs >> status) {
		map<string, string>m;
		this->string_sub(data, s1, s2);
		m.insert(make_pair(s1, s2));

		this->string_sub(interval, s1, s2);
		m.insert(make_pair(s1, s2));

		this->string_sub(s_id, s1, s2);
		m.insert(make_pair(s1, s2));

		this->string_sub(s_name, s1, s2);
		m.insert(make_pair(s1, s2));

		this->string_sub(c_id, s1, s2);
		m.insert(make_pair(s1, s2));

		this->string_sub(status, s1, s2);
		m.insert(make_pair(s1, s2));

		mp.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
}

void BookingInfo::Show_all(map<int, map<string, string>>& mp)
{
	for (map<int, map<string, string>>::iterator it = mp.begin(); it != mp.end(); it++) {
		for (map<string, string>::iterator its = it->second.begin(); its != it->second.end(); its++) {
			cout << its->first << ":" << its->second << " ";
		}
		cout << endl;
	}
}

bool BookingInfo::Modify(string data, string interval, string s_id, string s_name, string s_rid, string s)
{
	int ret = false;
	for (int i = 0; i < this->m_size; i++) {
		if (mp[i]["data"] == data && mp[i]["interval"] == interval && mp[i]["s_id"] == s_id && mp[i]["s_name"] == s_name && mp[i]["s_rid"] == s_rid) {
			mp[i]["status"] = s;
			ret = true;
		}
	}
	if (ret) {
		this->updata_Booking();
	}
	return ret;
	
}
