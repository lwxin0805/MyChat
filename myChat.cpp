#include "myChat.h"
#include<iostream>
using namespace std;

int main()
{
	char choice;
	string ans1, ans2;
	mychat c;
	c.User_Interface();
	bool flag = true;
	cout << "��ѡ������Ҫ����ķ���" << endl;
	while (flag)
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << "�ɹ�����ע���˻�����" << endl;
			c.Register();
			cout << "����Ҫ���������" << endl;
			cout << "yes/no" << endl;
			cin >> ans1;
			if (ans1 == "yes")
			{
				c.User_Interface();
				flag = true;
				continue;
			}
			else
			{
				flag = false;
			}
			break;
		}
		case '2':
		{
			cout << "�ɹ������¼�˻�����" << endl;
			flag = false;
			c.Login();
			cout << "����Ҫ���������" << endl;
			cout << "yes/no" << endl;
			cin >> ans2;
			if (ans2 == "yes")
			{
				c.User_Interface();
				flag = true;
				continue;
			}
			else
			{
				flag = false;
			}
			break;
		}
		case '3':
		{
			cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
			flag = false;
			return 0;
		}
		default:
		{
			cout << "û�и�ѡ�� �������������룺" << endl;
			flag = true;
			cin >> choice;
		}
		}
	}
}