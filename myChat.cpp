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
	cout << "请选择您想要进入的服务" << endl;
	while (flag)
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << "成功进入注册账户服务" << endl;
			c.Register();
			cout << "还需要其他服务嘛？" << endl;
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
			cout << "成功进入登录账户服务" << endl;
			flag = false;
			c.Login();
			cout << "还需要其他服务嘛？" << endl;
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
			cout << "成功退出，欢迎下次再使用" << endl;
			flag = false;
			return 0;
		}
		default:
		{
			cout << "没有该选项 ，请您重新输入：" << endl;
			flag = true;
			cin >> choice;
		}
		}
	}
}