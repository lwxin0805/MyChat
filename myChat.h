#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include <ctime>
#include<cstdlib> //包含rand和srand函数的头文件
using namespace std;
//interface有问题 
class mychat
{
public:
	mychat()
	{
		//user_file.open("User_Information.txt", ios::app); //如果没有就创建，存在的话就在文件末尾追加新数据
	}
	void User_Interface()
	{
		cout << "####################################################################\n";
		cout << "*****     1.注册账户  2.登陆账户  3.退出     *****\n";
		cout << "####################################################################\n\n";
	}
	void User_Interface1(string phonenumber)
	{
		cout << "#########################################################################\n";
		cout << "*****     1.添加好友  2.查看聊天记录  3.朋友圈  4.设置  5.退出     *****\n";
		cout << "#########################################################################\n\n";
		cout << "请选择您要进入的服务" << endl;
		char choice;
		bool flag = true;
		cin >> choice;
		while (flag)
		{
			switch (choice)
			{
			case '1':
			{
				cout << "成功进入添加好友服务" << endl;
				flag = false;
				User_Interface2(phonenumber);
				break;
			}
			case '2':
			{
				cout << "成功进入聊天服务" << endl;
				flag = false;
				User_Interface3(phonenumber);
				break;
			}
			case '3':
			{
				cout << "成功进入朋友圈服务" << endl;
				flag = false;
				User_Interface5(phonenumber);
				break;
			}
			case '4':
			{
				cout << "成功进入查看设置服务" << endl;
				Setting(phonenumber);
				flag = false;
				break;
			}
			case '5':
			{
				cout << "成功退出，欢迎下次再使用" << endl;
				flag = false;
				return;
				break;
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
	void User_Interface2(string phonenumber)
	{
		cout << "##############################################################################\n";
		cout << "*****     1.通过手机号码添加好友  2.通过昵称添加好友  3.查看好友申请  4.退出     *****\n";
		cout << "##############################################################################\n\n";
		cout << "请选择您要进入的服务" << endl;
		bool flag = true;
		char choice;
		string ans1,ans2,ans3;
		cout << "请选择您想要进入的服务" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "成功进入通过手机号码添加好友服务" << endl;
				AddFriendPhonenumber(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans1;
				if (ans1 == "yes")
				{
					User_Interface1(phonenumber);
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
				cout << "成功进入通过昵称添加好友服务" << endl;
				AddFriendUsername(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans2;
				if (ans2 == "yes")
				{
					User_Interface1(phonenumber);
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
				cout << "成功进入查看好友申请服务" << endl;
				FriendList(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans3;
				if (ans3 == "yes")
				{
					User_Interface1(phonenumber);
					flag = true;
					continue;
				}
				else
				{
					flag = false;
				}
				break;
			}
			case '4':
			{
				cout << "成功退出，欢迎下次再使用" << endl;
				flag = false;
				return ;
				break;
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
	void User_Interface3(string phonenumber)
	{
		cout << "##############################################################################\n";
		cout << "*****     1.留言  2.查看聊天记录  3.退出     *****\n";
		cout << "##############################################################################\n\n";
		cout << "请选择您要进入的服务" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2;
		cout << "请选择您想要进入的服务" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "成功进入留言服务" << endl;
				Message(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans1;
				if (ans1 == "yes")
				{
					User_Interface1(phonenumber);
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
				cout << "成功进入查看聊天记录服务" << endl;
				User_Interface4(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans2;
				if (ans2 == "yes")
				{
					User_Interface1(phonenumber);
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
				return;
				break;
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
	void User_Interface4(string phonenumber)
	{
		cout << "####################################################################################################\n";
		cout << "*****     1.利用手机号查看聊天记录  2.利用昵称查看聊天记录  3.利用关键词查看聊天记录  4.退出     *****\n";
		cout << "####################################################################################################\n\n";
		cout << "请选择您要进入的服务" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2, ans3;
		cout << "请选择您想要进入的服务" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "成功进入利用手机号查看聊天记录服务" << endl;
				Check_History_Phone(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans1;
				if (ans1 == "yes")
				{
					User_Interface3(phonenumber);
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
				cout << "成功进入利用昵称查看聊天记录服务" << endl;
				Check_History_Username(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans2;
				if (ans2 == "yes")
				{
					User_Interface3(phonenumber);
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
				cout << "成功进入利用关键词查看聊天记录服务" << endl;
				Check_History_Highlight(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans2;
				if (ans2 == "yes")
				{
					User_Interface3(phonenumber);
					flag = true;
					continue;
				}
				else
				{
					flag = false;
				}
				break;
			}
			case '4':
			{
				cout << "成功退出，欢迎下次再使用" << endl;
				flag = false;
				return;
				break;
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
	void User_Interface5(string phonenumber)
	{
		cout << "##########################################################\n";
		cout << "*****     1.发布朋友圈  2.查看朋友圈  3.退出     *****\n";
		cout << "##########################################################\n\n";
		cout << "请选择您要进入的服务" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2, ans3,ans4;
		cout << "请选择您想要进入的服务" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "成功进入发布朋友圈服务" << endl;
				Moment_Publish(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans1;
				if (ans1 == "yes")
				{
					User_Interface1(phonenumber);
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
				cout << "成功进入查看朋友圈服务" << endl;
				Moment_Check(phonenumber);
				cout << "还需要其他服务嘛？" << endl;
				cout << "yes/no" << endl;
				cin >> ans2;
				if (ans2 == "yes")
				{
					User_Interface1(phonenumber);
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
				return;
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
	void Register() 
	{
		string phonenumber_re, phonenumber1, username, password,question=" ";
		bool not_register = true; //判断手机号是否被注册过 
		bool phonefind = true; //手机找到
		bool usernamefind = true; //昵称找到
		bool accept = true; //默认通过
		bool moment = true; //moment = true就是可以给朋友看 ; moment = false仅自己可见 
		cout << "请输入您的手机号码" << endl;
		cout << "注意 手机号码要11位 且首数字不能为0" << endl;
		while (not_register)
		{
			cin >> phonenumber1;
			if (phonenumber1.size() != 11 || phonenumber1[0] == '0')
			{
				cout << "手机号码有误，请您重新输入" << endl;
				not_register = true;
				continue; // 回到while循环
			}
			ifstream check_file("User_Information.txt");
			string laji;
			while (getline(check_file, laji))
			{
				istringstream iss(laji);
				string phonenumber, username, password,question;
				int phonefind, usernamefind, accept, moment;
				iss >> phonenumber >> username >> password >> phonefind >> usernamefind >> accept >> moment>>question;
				phonenumber_re = phonenumber;
				MyChat[phonenumber] = { username,password,to_string(phonefind),to_string(usernamefind),to_string(accept),to_string(moment),question };
				if (phonenumber1 == phonenumber) //有一样的
				{
					phonenumber_re = phonenumber;
					break;
				}
			}
			if (phonenumber1 == phonenumber_re) //如果没找到则返回 string::npos
			{
				cout << "改手机号已被注册，请重新输入" << endl;
				not_register = true;
				continue; //回到while循环
			}
			else
			{
				not_register = false;
			}
			check_file.close();
			not_register = false;
		}
		//手机号码没被注册，可以继续注册
		bool is_password = true;
		string doublepassword; //二次验证
		while (is_password)
		{
			cout << "请输入您的密码" << endl;
			cout << "注意 密码要超过8位，必须包含大小写字母和数字" << endl;
			cin >> password;
			if (password.size() < 8)
			{
				cout << "密码长度不足，请重新输入" << endl;
				continue;
			}
			bool has_upper = false, has_lower = false, has_digit = false;
			for (char c : password) //循环整个newpassword
			{
				if (isupper(c))
				{
					has_upper = true;
				}
				else if (islower(c))
				{
					has_lower = true;
				}
				else if (isdigit(c))
				{
					has_digit = true;
				}
			}
			if (has_upper == true && has_lower == true && has_digit == true)
			{
				bool wrong = true;
				while (wrong)
				{
					cout << "请二次输入密码" << endl;
					cin >> doublepassword;
					if (password != doublepassword)
					{
						cout << "二次输入密码跟第一次输入的密码不一样" << endl;
						wrong = true;
						continue;
					}
					else
					{
						cout << "密码设置成功！" << endl;
						wrong = false;
						is_password = false;
					}
				}
			}
			else
			{
				cout << "由于安全问题，请您重新设置一个新的密码" << endl;
				is_password = true;
			}
		}
		cout << "输入您想设置的用户名" << endl;
		cin >> username;
		bool vertification_code = true;
		int code;
		while (vertification_code)
		{
			srand((unsigned)time(NULL)); //设置时间种子，保证每次随机数不同
			int rand_num = rand() % 9000 + 1000; //生成1000~9999之间的数字
			cout << "这是四位随机的验证码：" << rand_num << endl;
			cout << "请您重新输入验证码" << endl;
			cin >> code;
			if (rand_num == code)
			{
				cout << "注册成功！" << endl;
				vertification_code = false;
				not_register = false;
			}
			else
			{
				cout << "验证码不一致" << endl;
				continue;
			}
		}
		ofstream user_file("User_Information.txt", ios::app);
		if (user_file.is_open())
		{
			user_file << phonenumber1 << " " << username << " " << password << " " << true << " " << true << " " << true << " " << true << " " << question << endl;
		}
		user_file.close();
	}
	void Login()
	{
		string newphonenumber, newpassword, newpassword2, phonenumber; //这里的Phonenumber是来赋值的
		bool flag = true;
		bool found = false;
		cout << "欢迎来到用户登录界面" << endl;
		cout << "输入您的手机号：" << endl;
		cin >> newphonenumber;
		cout << "请输入您的密码：" << endl;
		while (flag)
		{
			cin >> newpassword;
			ifstream user_file("User_information.txt");
			string laji;
			while (getline(user_file, laji))
			{
				istringstream iss(laji);
				string phonenumber, username, password, question;
				int phonefind, usernamefind, accept, moment;
				iss >> phonenumber >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
				MyChat[phonenumber] = { username,password,to_string(phonefind),to_string(usernamefind),to_string(accept),to_string(moment),question };
				if (newphonenumber == phonenumber)
				{
					if (password == newpassword)
					{
						found = true;
						cout << "登陆成功！" << endl;
						flag = false;
						User_Interface1(phonenumber);
					}
					else
					{
						cout << "密码错误，请重新输入" << endl;
						bool password_flag = true;
						while (password_flag)
						{
							cin >> newpassword2;
							if (password == newpassword2)
							{
								cout << "登陆成功！" << endl;
								password_flag = false;
								flag = false;
								User_Interface1(phonenumber);
							}
							else
							{
								cout << "密码有错误，请重新输入" << endl;
								password_flag = true;
							}
						}
					}
				}
			}
			if (found != true)
			{
				cout << "手机号码未被注册" << endl;
			}
		}
	}
	void Setting(string phonenumber)
	{
		cout << "#########################################################################################################################\n";
		cout << "*****     1.设置通过什么样的方式搜寻自己  2.设定通过好友请求的方式  3.朋友圈展示范围  4.修改密码或昵称  5.退出     *****\n";
		cout << "#########################################################################################################################\n\n";
		char choice;
		bool flag = true;
		cin >> choice;
		while (flag)
		{
			switch (choice)
			{
			case '1':
			{
				cout << "#############################################################################################################\n";
				cout << "*****     1.能不能通过手机号码寻找  2.能不能通过用户名寻找  3.能不能通过手机号码和用户名寻找  4.退出     *****\n";
				cout << "#############################################################################################################\n\n";
				cout << "请选择您要进入的服务" << endl;
				char choice1;
				cin >> choice1;
				bool flag1 = true;
				while (flag1)
				{
					switch (choice1)
					{
					case '1':
					{
						ChangePhoneFind(phonenumber);
						flag1 = false;
						break;
					}
					case '2':
					{
						ChangeUsernameFind(phonenumber);
						flag1 = false;
						break;
					}
					case '3':
					{
						ChangePhoneAndUsernameFind(phonenumber);
						flag1 = false;
						break;
					}
					case '4':
					{
						cout << "成功退出，欢迎下次再使用" << endl;
						flag1 = false;
						return;
					}
					default:
					{
						cout << "没有该选项 ，请您重新输入：" << endl;
						flag1 = true;
						cin >> choice1;
					}
					}
				}
				break;
			}
			case '2':
			{
				string ans;
				cout << "好友验证权限是否更改 ？" << endl;
				cout << " yes / no " << endl;
				cin >> ans;
				if (ans == "yes")
				{
					Accept(phonenumber);
					flag = false;
				}
				break;
			}
			case '3':
			{
				string ans;
				cout << "朋友圈权限是否更改 ？" << endl;
				cout << " yes / no " << endl;
				cin >> ans;
				if (ans == "yes")
				{
					Moment(phonenumber);
					flag = false;
				}
				break;
			}
			case '4': //修改密码成功 但是文件没有修改
			{
				cout << endl;
				cout << "######################################################\n";
				cout << "*****     1.修改密码  2.修改昵称  3.退出     *****\n";
				cout << "######################################################\n\n";
				cout << "请选择您要进入的服务" << endl;
				char choice2;
				cin >> choice2;
				bool flag2 = true;
				while (flag2)
				{
					switch (choice2)
					{
					case '1':
					{
						ChangePassword(phonenumber);
						flag2 = false;
						break;
					}
					case '2':
					{
						ChangeUsername(phonenumber);
						flag2 = false;
						break;
					}
					case '3':
					{
						cout << "成功退出，欢迎下次再使用" << endl;
						flag2 = false;
						return;
					}
					default:
					{
						cout << "没有该选项 ，请您重新输入：" << endl;
						flag2 = true;
						cin >> choice2;
					}
					}
				}
				break;
			}
			case '5':
			{
				cout << "成功退出，欢迎下次再使用" << endl;
				flag = false;
				return;
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
	void ChangePassword(string phonenumber)
	{
		string newpassword, doublepassword, oriphonenumber;
		bool is_password = true;
		while (is_password)
		{
			cout << "请输入您想更改的密码：" << endl;
			cout << "注意 密码要超过8位，必须包含大小写字母和数字" << endl;
			cin >> newpassword;
			if (newpassword.size() < 8)
			{
				cout << "密码长度不足，请重新输入" << endl;
				continue;
			}
			bool has_upper = false, has_lower = false, has_digit = false;
			for (char c : newpassword) //循环整个newpassword
			{
				if (isupper(c))
				{
					has_upper = true;
				}
				else if (islower(c))
				{
					has_lower = true;
				}
				else if (isdigit(c))
				{
					has_digit = true;
				}
			}
			if (has_upper == true && has_lower == true && has_digit == true)
			{
				bool wrong = true;
				while (wrong)
				{
					cout << "请二次输入新密码" << endl;
					cin >> doublepassword;
					if (newpassword != doublepassword)
					{
						cout << "二次输入密码跟第一次输入的密码不一样" << endl;
						wrong = true;
						is_password = false;
					}
					else
					{
						cout << "密码设置成功！" << endl;
						wrong = false;
						is_password = false;
					}
				}
			}
			else
			{
				cout << "由于安全问题，请您重新设置一个新的密码" << endl;
				is_password = true;
			}
		}
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info; //信息都存在这里了
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line)) 
		{
			istringstream iss(line);
			string phonenumber1, username, password, question; //phonenumber1 = file里面的
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end())
		{
			it->second[1] = newpassword;  // 更新密码
			cout << "密码更新完毕！" << endl;
		}
		else {
			cout << "该手机号码不存在！" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) { 
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void ChangeUsername(string phonenumber)
	{
		string newusername;
		cout << "输入您想更改的用户名：" << endl;
		cin >> newusername;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info; //信息都存在这里了
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question; //phonenumber1 = file里面的
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end())
		{
			it->second[0] = newusername;  // 更新密码
			cout << "用户名更新完毕！" << endl;
		}
		else {
			cout << "该手机号码不存在！" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void ChangePhoneFind(string phonenumber)
	{
		string ans;
		cout << "是否更改让别人通过手机号寻找您？" << endl;
		cout << "yes = 让别人能通过手机号寻找您 / no = 让别人不能通过手机号寻找您" << endl;
		cin >> ans;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info; 
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question; 
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end() && ans =="no")
		{
			it->second[2] = to_string(0);  // 更新密码
			cout << "其他用户不能使用手机号码寻找您！" << endl;
		}
		else 
		{
			it->second[2] = to_string(1);
			cout << "其他用户能使用手机号码寻找您" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void ChangeUsernameFind(string phonenumber)
	{
		string ans;
		cout << "是否更改让别人通过昵称寻找您？" << endl;
		cout << "yes = 让别人能通过昵称寻找您 / no = 让别人不能通过昵称寻找您" << endl;
		cin >> ans;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info;
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question;
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end() && ans == "no")
		{
			it->second[3] = to_string(0);  // 更新密码
			cout << "其他用户不能使用昵称寻找您！" << endl;
		}
		else
		{
			it->second[3] = to_string(1);
			cout << "其他用户能使用昵称寻找您" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void ChangePhoneAndUsernameFind(string phonenumber)
	{
		string ans, ans1;
		cout << "是否更改让别人通过手机号寻找您？" << endl;
		cout << "yes = 让别人能通过手机号寻找您 / no = 让别人不能通过手机号寻找您" << endl;
		cin >> ans;
		cout << "是否更改让别人通过昵称寻找您？" << endl;
		cout << "yes = 让别人能通过昵称寻找您 / no = 让别人不能通过昵称寻找您" << endl;
		cin >> ans1;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info;
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question;
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end() && ans == "no" && ans1 == "no")
		{
			it->second[2] = to_string(0); 
			it->second[3] = to_string(0);
			cout << "更改结束！别人不能通过您的手机号和昵称寻找到您了" << endl;
		}
		else if (it != user_info.end() && ans == "yes" && ans1 == "no")
		{
			it->second[2] = to_string(1);
			it->second[3] = to_string(0);
			cout << "更改结束！别人能通过您的手机号寻找您但不能通过您的昵称寻找到您了" << endl;
		}
		else if (it != user_info.end() && ans == "no" && ans1 == "yes")
		{
			it->second[2] = to_string(0);
			it->second[3] = to_string(1);
			cout << "更改结束！别人能通过您的昵称寻找您但不能通过您的手机号寻找到您了" << endl;
		}
		else if (it != user_info.end() && ans == "yes" && ans1 == "yes") //找到
		{
			it->second[2] = to_string(1);
			it->second[3] = to_string(1);
			cout << "更改结束！别人能通过您的手机号和昵称寻找到您了" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void Accept(string phonenumber)
	{
		string ans,question_str,input_str;
		vector<string> newquestion;
		cout << "是否更改让别人无需回答问题就能直接加上您？" << endl;
		cout << "yes = 默认自动通过 / no = 需回答您设的问题" << endl;
		cin >> ans;
		if (ans == "no")
		{
			cout << "更改结束！别人需要回答您的问题才能加上您" << endl;
			cout << "输入您想设的问题" << endl;
			cin.ignore();
			getline(cin, input_str); //从输入流读取一行 cin只读第一个单词
			istringstream iss(input_str);
			string word;
			while (iss >> word)
			{
				newquestion.push_back(word);
			}
			for (const auto& q : newquestion)
			{
				question_str += q + " ";
			}
		}
		else
		{
			question_str = " ";
		}
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info;
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question;
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end() && ans == "no")
		{
			it->second[4] = to_string(0);
			it->second[6] = question_str;
		}
		else
		{
			it->second[4] = to_string(1);
			cout << "更改结束！别人能自动加上您" << endl;
			cout << "您之前设置的问题将自动删除" << endl;
			it->second[6] = question_str;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //遍历用户信息 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()返回容器中的最后一个元素
		}
		outfile.close();
	}
	void Moment(string phonenumber)
	{ //1给别人看 0给自己看
		string ans;
		cout << "是否更改朋友圈权限？" << endl;
		cout << "yes = 朋友圈好友可见 / no = 朋友圈仅自己可见" << endl;
		cin >> ans;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info;
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line)) //User_information.txt
		{
			istringstream iss(line);
			string phonenumber1, username, password, question;
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		//要改变两个地方
		auto it = user_info.find(phonenumber); //查找用户信息中是否存在改手机号
		if (it != user_info.end() && ans == "no") //自己可见
		{
			it->second[5] = '0';
		}
		else if (it != user_info.end() && ans == "yes") //朋友可见
		{
			it->second[5] = '1';
		}
	}
	void AddFriendPhonenumber(string phonenumber) 
	{
		string phonenumber_friend;
		cout << "输入您想加好友的手机号" << endl;
		cin >> phonenumber_friend;
		string filename = "Add_friend.txt";
		unordered_map<string, vector<vector<string>>> friend_info;
		string line;
		bool add = true,sucess=true;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber_me, phonenumber_add, username_add, question, answer;
			int accept_add;
			iss >> phonenumber_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
			AddFriend[phonenumber_me] = { phonenumber_add , username_add , to_string(accept_add) , question , answer };
			if (phonenumber_me == phonenumber && phonenumber_add == phonenumber_friend) //找到当前用户
			{
				if (accept_add == 1)
				{
					cout << "已经是好朋友啦" << endl;
					add = false;
					sucess = false;
				}
				else if (accept_add == 0)
				{
					cout << "已经发送请求给他啦 等他回复嘛" << endl;
					add = false;
					sucess = false;
				}
			}
		}
		user_file.close();
		string input_str = " ",answer_str;
		vector<string> newanswer;
		while (add)
		{
			ifstream user_file("User_Information.txt");
			ofstream friend_file("Add_friend.txt",ios::app);
			string laji1;
			while (getline(user_file, laji1))
			{
				istringstream iss(laji1);
				string phonenumber1, username1, password1, question1;
				int phonefind1, usernamefind1, accept1, moment1;
				iss >> phonenumber1 >> username1 >> password1 >> phonefind1 >> usernamefind1 >> accept1 >> moment1 >> question1; //如果他是1通常question是" "
				//string phonenumber_me, phonenumber_add, username_add, question, answer;
				int accept_add = 1;//先设置他们是好友
				if (phonenumber_friend == phonenumber1 && phonefind1 == 1) //phonefind = 1的时候才可以找到
				{
					if (accept1 == 1)
					{ //iss >> phonenumber_me >> username_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
						cout << "默认通过..." << endl;
						istringstream iss(input_str);
						string word;
						while (iss >> word)
						{
							newanswer.push_back(word);
						}
						for (const auto& q : newanswer)
						{
							answer_str += q + " ";
						}
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(1) << " " << question1 << " " << answer_str << endl; //username_me实现不到
						sucess = false;
						break;
					}
					else  //accept1=0要通过他的问题
					{
						cout << "因对方设置了需回答问题才能加他为好友" << endl;
						cout << question1 << endl;
						cin.ignore();
						getline(cin, input_str); //从输入流读取一行 cin只读第一个单词
						istringstream iss(input_str);
						string word;
						while (iss >> word)
						{
							newanswer.push_back(word);
						}
						for (const auto& q : newanswer)
						{
							answer_str += q + " ";
						}
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(0) << " " << question1 << " " << answer_str << endl;
						cout << "正在发送请求给他..." << endl;
						sucess = false;
						break;
					}
				}
				else if (phonenumber_friend == phonenumber1 && phonefind1 == 0) //设置了不能搜寻
				{
					cout << "对方设置了别人不能通过手机号搜寻" << endl;
					sucess = false;
					break;
				}
			}
			add = false;//因为在while(add)里一直推不出去
			friend_file.close();
			user_file.close();
		}
		if (sucess) //找不到该手机号
		{
			cout << "找不到此手机号" << endl;
		}
	}
	void AddFriendUsername(string phonenumber) //使用append .. 直接添加而不是覆盖
	{
		string username_friend;
		cout << "输入您想加好友的昵称" << endl;
		cin >> username_friend;
		string filename = "Add_friend.txt";
		unordered_map<string, vector<vector<string>>> friend_info;
		string line;
		bool add = true, sucess = true;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber_me, phonenumber_add, username_add, question, answer;
			int accept_add;
			iss >> phonenumber_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
			AddFriend[phonenumber_me] = { phonenumber_add , username_add , to_string(accept_add) , question , answer };
			if (phonenumber_me == phonenumber && username_add == username_friend) //找到当前用户
			{
				if (accept_add == 1)
				{
					cout << "已经是好朋友啦" << endl;
					add = false;
					sucess = false;
				}
				else if (accept_add == 0)
				{
					cout << "已经发送请求给他啦 等他回复嘛" << endl;
					add = false;
					sucess = false;
				}
			}
		}
		user_file.close();
		string input_str = " ", answer_str;
		vector<string> newanswer;
		while (add)
		{
			ifstream user_file("User_Information.txt");
			ofstream friend_file("Add_friend.txt", ios::app);
			string laji1;
			while (getline(user_file, laji1))
			{
				istringstream iss(laji1);
				string phonenumber1, username1, password1, question1;
				int phonefind1, usernamefind1, accept1, moment1;
				iss >> phonenumber1 >> username1 >> password1 >> phonefind1 >> usernamefind1 >> accept1 >> moment1 >> question1; //如果他是1通常question是" "
				//string phonenumber_me, phonenumber_add, username_add, question, answer;
				int accept_add = 1;//先设置他们是好友
				if (username_friend == username1 && phonefind1 == 1) //phonefind = 1的时候才可以找到
				{
					if (accept1 == 1)
					{ //iss >> phonenumber_me >> username_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
						cout << "默认通过..." << endl;
						istringstream iss(input_str);
						string word;
						while (iss >> word)
						{
							newanswer.push_back(word);
						}
						for (const auto& q : newanswer)
						{
							answer_str += q + " ";
						}
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(1) << " " << question1 << " " << answer_str << endl; //username_me实现不到
						sucess = false;
						break;
					}
					else  //accept1=0要通过他的问题
					{
						cout << "因对方设置了需回答问题才能加他为好友" << endl;
						cout << question1 << endl;
						cin.ignore();
						getline(cin, input_str); //从输入流读取一行 cin只读第一个单词
						istringstream iss(input_str);
						string word;
						while (iss >> word)
						{
							newanswer.push_back(word);
						}
						for (const auto& q : newanswer)
						{
							answer_str += q + " ";
						}
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(0) << " "<< question1 << " " << answer_str << endl;
						cout << "正在发送请求给他..." << endl;
						sucess = false;
						break;
					}
				}
				else if (username_friend == username1 && usernamefind1 == 0) //设置了不能搜寻
				{
					cout << "对方设置了别人不能通过昵称搜寻" << endl;
					sucess = false;
					break;
				}
			}
			add = false;//因为在while(add)里一直推不出去
			friend_file.close();
			user_file.close();
		}
		if (sucess) //找不到该昵称
		{
			cout << "找不到此昵称" << endl;
		}
	}
	void FriendList(string phonenumber)
	{
		string filename = "Add_friend.txt";
		unordered_map<string, vector<vector<string>>> friend_info; //信息都存在这里了
		string line;
		ifstream friend_file(filename);
		while (getline(friend_file, line))
		{
			istringstream iss(line);
			string phonenumber_me, phonenumber_add, username_add, question, answer;
			int accept_add;
			iss >> phonenumber_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
			vector<string> friend_data = { phonenumber_add , username_add , to_string(accept_add) ,question , answer };
			friend_info[phonenumber_me].push_back(friend_data);
		}
		friend_file.close();
		bool friend_list = false;
		for (auto& item : friend_info) //遍历用户信息 
		{
			for (auto& friend_data : item.second) {
				if (friend_data[0] == phonenumber && friend_data[2] == "0") {
					cout << item.first << "想要添加您为好友" << endl;
					cout << "这是您的问题：" << friend_data[3] << endl;
					cout << "这是他的回答：" << friend_data[4] << endl;
					cout << "请问您是否同意" << endl;
					cout << "yes = 同意 / no = 不同意" << endl;
					string ans;
					cin >> ans;
					if (ans == "yes")
					{
						friend_data[2] = "1";
						cout << "您已同意他为好友" << endl;
						friend_list = false;
					}
					else
					{
						friend_data[2] = "0";
						cout << "您已拒绝他为好友" << endl;
						friend_list = false;
					}
				}
			}
		}

		if (friend_list)
		{
			cout << "没人添加您为好友" << endl;
		}

		ofstream outfile(filename);
		for (auto& item : friend_info) //遍历用户信息 
		{
			for (auto& friend_data : item.second) {
				outfile << item.first << " ";
				for (size_t i = 0; i < friend_data.size() - 1; ++i) {
					outfile << friend_data[i] << " ";
				}
				outfile << friend_data.back() << endl; //.back()返回容器中的最后一个元素
			}
		}
		outfile.close();
	}
	void Message(string phonenumber)
	{
		string phonenumber_receiver,input_str,message_str;
		bool can_chat = true;
		cout << "请输入您想发送信息的对象" << endl;
		cout << "手机号：" << endl;
		cin >> phonenumber_receiver;
		ifstream check_file("Add_friend.txt"); //phonenumber(自己的) username(自己的) phonenumber1(别人的) username（别人的）accept(别人要不要接受你) question(如果别人accept=0的话就cout question) answer（如果别人accept=0就会有answer)
		ofstream history_file("Chat_History.txt", ios::app); //sender receiver chat
		string laji; //如果两个人都等于1 就是加了好友 如果是0 就是没有加好友
		vector<string> message;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_me, phonenumber_add, username_add, question, answer;
			int accept_add;
			string phonenumber_sender, phonenumber_receiver_new;
			iss >> phonenumber_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
			AddFriend[phonenumber_me] = { phonenumber_add , username_add , to_string(accept_add) , question , answer };
			if (phonenumber_receiver == phonenumber_me && phonenumber_add == phonenumber && accept_add == 1 || phonenumber_receiver == phonenumber_add && phonenumber_me == phonenumber && accept_add == 1) //反正只要他们是好友 谁加谁不重要
			{
				cout << "输入您想发送的信息" << endl;
				cin.ignore();
				getline(cin, input_str);
				istringstream iss(input_str);
				string word;
				while (iss >> word)
				{
					message.push_back(word);
				}
				for (const auto& q : message)
				{
					message_str += q + " ";
				}
				history_file << phonenumber << " " << phonenumber_receiver << " " <<message_str << endl;
				Chat[phonenumber] = { phonenumber_receiver , message_str };
				can_chat = false;
			}
		}
		check_file.close();
		history_file.close();
		if (can_chat)
		{
			cout << "您还没添加他为好友 所以你不能发信息给他" << endl;
		}
	}
	void Check_History_Phone(string phonenumber) 
	{
		bool chat_history = true;
		string phonenumber_find; //phonenumber_receiver
		cout << "输入您想寻找聊天记录的手机号" << endl;
		cin >> phonenumber_find;
		ifstream check_file("Chat_History.txt");
		string laji;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_sender, phonenumber_receiver, chat;
			iss >> phonenumber_sender >> phonenumber_receiver >> chat;
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout的聊天记录 either one 只要和他聊天就直接cout
			if (phonenumber_receiver == phonenumber_find && phonenumber_sender == phonenumber || phonenumber_receiver == phonenumber && phonenumber_sender == phonenumber_find)
			{
				cout << phonenumber_sender << "：" << chat << endl;
				chat_history = false;
			}
		}
		check_file.close();
		if (chat_history)
		{
			cout << "没有聊天记录" << endl;
		}
	}
	void Check_History_Username(string phonenumber)
	{
		string username_find, phonenumber_find;
		bool chat_history = true;
		cout << "输入您想寻找聊天记录的昵称" << endl;
		cin >> username_find; //先找到对应的手机号
		ifstream check_file("User_Information.txt");
		string laji;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber1, username, password, question;
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			MyChat[phonenumber1] = { username,password,to_string(phonefind),to_string(usernamefind),to_string(accept),to_string(moment),question };
			if (username_find == username)
			{
				phonenumber_find = phonenumber1; //找到对应昵称的手机号码
				break;
			}
		}
		check_file.close();
		ifstream hit_file("Chat_History.txt");
		string laji1;
		while (getline(hit_file, laji1))
		{
			istringstream iss(laji1);
			string phonenumber_sender, phonenumber_receiver, chat;
			iss >> phonenumber_sender >> phonenumber_receiver >> chat;
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout的聊天记录 either one 只要和他聊天就直接cout
			if (phonenumber_receiver == phonenumber_find && phonenumber_sender == phonenumber || phonenumber_receiver == phonenumber && phonenumber_sender == phonenumber_find)
			{
				cout << phonenumber_sender << "：" << chat << endl;
				chat_history = false;
			}
		}
		hit_file.close();
		if (chat_history)
		{
			cout << "没有聊天记录" << endl;
		}
	}
	void Check_History_Highlight(string phonenumber)
	{
		bool chat_history = true;
		string highlight;
		cout << "输入您想寻找聊天记录的关键词" << endl;
		cin >> highlight;
		ifstream check_file("Chat_History.txt");
		string laji;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_sender, phonenumber_receiver, chat;
			iss >> phonenumber_sender >> phonenumber_receiver >> chat;
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout的聊天记录 either one 只要和他聊天就直接cout
			if (phonenumber == phonenumber_sender || phonenumber == phonenumber_receiver)
			{
				if (laji.find(highlight) != string::npos)
				{
					cout << phonenumber_sender << " " << phonenumber_receiver << " " << chat << endl;
					chat_history = false;
				}
			}
		}
		check_file.close();
		if (chat_history)
		{
			cout << "没有聊天记录" << endl;
		}
	}
	void Moment_Publish(string phonenumber)  //phonenumber(谁发) moment(自己看还是可以给别人看) accept(好朋友才能看) 打开Friend_list phonenumber跟自己是1才能看 likecount vector<string>comment -> phonenumber : comment (循环)
	{
		string input_str, moment_str,comment,laji;
		int likecount_seen=0;//like = 0 
		vector<string> moment;
		ifstream user_file("User_Information.txt");
		ofstream moment_file("Check_moment.txt", ios::app); 
		while (getline(user_file, laji))
		{
			istringstream iss(laji);
			string phonenumber1, username, password, question,answer;
			int phonefind, usernamefind, accept, moment_add;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment_add >> question>>answer;
			MyChat[phonenumber1] = { username,password,to_string(phonefind),to_string(usernamefind),to_string(accept),to_string(moment_add),question,answer };
			if (phonenumber == phonenumber1)
			{
				int moment_seen = moment_add;
				cout << "输入您想发布的朋友圈（仅文字）" << endl;
				cin.ignore();
				getline(cin, input_str);
				istringstream iss(input_str);
				string word;
				while (iss >> word)
				{
					moment.push_back(word);
				}
				for (const auto& q : moment)
				{
					moment_str += q + " ";
				}
				moment_file << phonenumber << " " << moment_str << " " << moment_seen << " " << likecount_seen << " " << comment <<endl; //只有moment=1/0 才可以被别人看到
				Moment_PYQ[phonenumber] = { moment_str,to_string(moment_seen),to_string(likecount_seen) ,comment };
			}
		}
	}
	void Moment_Check(string phonenumber) //需要查看是不是好友 所以你就要读入Add_Friend.txt ->
	{//1好友可见 0自己可见1 实现查看罢了
		string x = phonenumber;
		bool find = true;
		bool flag = true;
		while (flag) //用来进入这个的
		{
			cout << "##########################################################################\n";
			cout << "*****     1.查看自己的朋友圈  2.查看好友的朋友圈  3.退出     *****\n";
			cout << "##########################################################################\n\n";
			cout << "请选择您要进入的服务" << endl;
			char c;
			cin >> c;
			if (c == '1')//成功了
			{
				string laji;;
				ifstream momentfile("Check_moment.txt");
				while (getline(momentfile, laji))
				{
					istringstream iss(laji);
					string phonenumber_sender, moment_str,comment;
					//vector<string> comment;
					int moment_seen, likecount_seen;
					iss >> phonenumber_sender >> moment_str >> moment_seen >> likecount_seen;
					getline(iss,comment);
					Moment_PYQ[phonenumber_sender] = { moment_str,to_string(moment_seen),to_string(likecount_seen) ,comment };
					if (phonenumber == phonenumber_sender)
					{
						cout << phonenumber_sender << "：" << endl;
						cout << moment_str << " " << endl;
						cout << "点赞：" << likecount_seen << endl;
						cout << "留言：" << comment <<  endl;
					}
				}
				flag = false;
				momentfile.close();
			}
			else if (c == '2') // 有的没出来 没有的也没出来
			{
				bool friend_found = false;//4
				ifstream user_file("Add_friend.txt");
				string line;
				vector<string> friend_phonenumbers; 
				while (getline(user_file, line))
				{
					istringstream iss(line);
					string my_phonenumber, friend_phonenumber, friend_username, accept_status, moment_status,question, answer;
					iss >> my_phonenumber >> friend_phonenumber >> friend_username >> accept_status >> moment_status >> question >> answer;
					if ((my_phonenumber == phonenumber && accept_status == "1" && friend_phonenumber != phonenumber) ||
						(phonenumber == friend_phonenumber && accept_status == "1" && my_phonenumber != phonenumber))
					{
						friend_found = true;
						if (friend_phonenumber != phonenumber)
						{
							friend_phonenumbers.push_back(friend_phonenumber); //把全部信息丢进去
						}
						else
						{
							friend_phonenumbers.push_back(my_phonenumber); //把全部信息丢进去
						}
					} //12345678901 -> 18761675655 + 98765432101 + 11223344556
				} //对了
				user_file.close();
				ifstream moment_file("Check_moment.txt");
				string line1,new_tempphone=" ",temp=" ";
				int moment_seen1 = 0;
				bool moment_found = false;
				if (friend_found)
				{
					while (getline(moment_file, line1))
					{
						for (auto& friend_phonenumber : friend_phonenumbers) //找到朋友的电话号码
						{
							istringstream iss1(line1);
							string moment_phonenumber, moment_str, comment;
							int moment_seen, likecount_seen;
							iss1 >> moment_phonenumber >> moment_str >> moment_seen >> likecount_seen;
							temp = moment_phonenumber;
							getline(iss1, comment);
							//cout << moment_phonenumber << moment_str << moment_seen << likecount_seen << comment;
							if (friend_phonenumber == moment_phonenumber && moment_seen == 1) //成功进来
							{
								moment_seen1 = moment_seen; //moment_seen1从0变1
								moment_found = true;
								cout << moment_phonenumber << ":" << endl;
								cout << moment_str << endl;
								cout << "点赞：" << likecount_seen << endl;
								cout << "请问您是否想点赞？" << endl;
								string ans;
								cout << "yes/no" << endl;
								cin >> ans;
								if (ans == "yes")
								{
									Moment_Like(x,moment_phonenumber,moment_str);
								}
								cout << "留言：" << comment << endl;
								cout << "请问您是否想评论？" << endl;
								string ans1;
								cout << "yes/no" << endl;
								cin >> ans1;
								if (ans1 == "yes")
								{
									Moment_Comment(phonenumber, moment_phonenumber, moment_str); 
								}
								moment_found = true;
								break;
							}
						}//4 no没问题 yesyesnono也没问题 nonoyesyes
						if (!moment_found)
						{
							if (new_tempphone != temp )
							{
								new_tempphone = temp;
								cout << new_tempphone << "：已设置为仅自己可见" << endl;
							}
						}
					}
				}
				moment_file.close();
			}
			if (c == '3')
			{

				cout << "成功退出，欢迎下次再使用" << endl;
				flag = false;
				return;
			}
			else if (c != '1' && c != '2')
			{
				cout << "没有该选项 ，请您重新输入：" << endl;
				flag = true;
				continue;
			}
		}
	}
	void Moment_Comment(string phonenumber, string moment_phonenumber, string moment_str) //phonenumber=我自己 moment_phonenumber朋友圈的手机号
	{
		string laji, ans;
		fstream momentfile("Check_moment.txt", ios::in );
		unordered_map<string, vector<string>> Moment_PYQ;
		vector<string> cache;
		while (getline(momentfile, laji))  //还没设置条件 所以还不能实现
		{
			istringstream iss(laji);
			string phonenumber_sender, moment_sender, input_str, input1_str;
			string comment,comment_str;
			vector<string>comment1;
			int moment_seen, likecount_seen;
			iss >> phonenumber_sender >> moment_sender >> moment_seen >> likecount_seen;
			getline(iss,comment); //moment_phonenumber=phonenumber_sender , moment_str=moment_sender
			Moment_PYQ[phonenumber_sender] = { moment_sender,to_string(moment_seen),to_string(likecount_seen) ,comment};
			if (phonenumber_sender == moment_phonenumber && moment_str == moment_sender)
			{
				input_str = comment; //赋值给他
				cout << "输入您想对这条朋友圈的留言" << endl; //那你也要先找到对应的
				cin.ignore();
				input_str += " " + phonenumber + " ";
				getline(cin, input1_str); //phonenumber + comment
				input_str += input1_str;
				istringstream iss1(input_str);
				string word;
				while (iss1 >> word)
				{
					comment1.push_back(word);
				}
				for (const auto& q : comment1)
				{
					comment_str += q + " ";
				}
				cache.push_back(phonenumber_sender + " " + moment_sender + " " + to_string(moment_seen) + " " + to_string(likecount_seen) + " " + comment_str);
				cout << "评论成功！" << endl;
			}
			else
			{
				cache.push_back(laji);
			}
		}
		momentfile.close();
		momentfile.open("Check_moment.txt", ios::out | ios::trunc);
		for (const auto& line : cache)
		{
			momentfile << line << endl;
		}
		momentfile.close();
	}
	void Moment_Like(string phonenumber, string moment_phonenumber, string moment_str) //第一个赞没进去 第二个的moment被改变
	{
		fstream momentfile("Check_moment.txt", ios::in | ios::out);
		string laji;
		vector<string>cache;
		unordered_map <string, vector<string>> like;
		bool found = false;  
		while (getline(momentfile, laji)) //还没设置条件 所以还不能实现
		{
			istringstream iss(laji);
			string phonenumber_sender, moment_sender, comment;
			int moment_seen, likecount_seen;
			iss >> phonenumber_sender >> moment_sender >> moment_seen >> likecount_seen >> comment;
			like[phonenumber_sender] = { moment_sender,to_string(moment_seen),to_string(likecount_seen) ,comment };
			if (phonenumber_sender == moment_phonenumber && moment_str == moment_sender) //moment_str不改变
			{
				likecount_seen++;
				cache.push_back(phonenumber_sender + " " + moment_sender + " " + to_string(moment_seen) + " " + to_string(likecount_seen) + " " + comment);
				cout << "点赞成功！" << endl;
			}
			else
			{
				cache.push_back(laji);
			}
		}
		momentfile.close();
		momentfile.open("Check_moment.txt", ios::out | ios::trunc);
		for (const auto& line : cache)
		{
			momentfile << line << endl;
		}
		momentfile.close();
	}

private:
	map<string, vector<string>> MyChat; //用于user_file的
	map<string, vector<string>> AddFriend; //用于friend_file
	map<string, vector<string>> Chat;
	map<string, vector<string>> Moment_PYQ;
	ofstream user_file;
	ofstream friend_file;
	ofstream chat_file;
	ofstream moment_file;
}; 