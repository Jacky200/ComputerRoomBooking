#pragma once
#include"Identity.h"
#include"ComputerRoomManager.h"
#include<vector>

class Manager :public Identity {
public:
	Manager();

	Manager(string name,string pwd);

	//��ʾ�˵�����
	virtual void Personal_Meue() ; 

	//����˺�
	void Add_Account();

	//�鿴�˺�
	void Show_AllAccount();
	
	//ɾ���˺�
	void Del_Account();

	//�鿴������Ϣ
	void Show_ComputerRoom();
	
	//���ԤԼ��¼
	void Clear_Booking();

	//������Ϣ���ļ�
	void SaveFile(string filename, int id, string name, string pwd);

	void SaveFileStudent(vector<Student>& s);
	void SaveFileTeacher(vector<Teacher>& t);

	//�ļ���ȡ����
	void ReadFile(string filename, int type);


	//student�ļ��Ƿ�Ϊ��
	bool StudentFIleisEmpty = false;

	//teacher�ļ��Ƿ�Ϊ��
	bool TeacherFileisEmpty = false;

	vector<Student>sv;
	vector<Teacher>tv;
};