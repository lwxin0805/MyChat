#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include <ctime>
#include<cstdlib> //����rand��srand������ͷ�ļ�
using namespace std;
//interface������ 
class mychat
{
public:
	mychat()
	{
		//user_file.open("User_Information.txt", ios::app); //���û�оʹ��������ڵĻ������ļ�ĩβ׷��������
	}
	void User_Interface()
	{
		cout << "####################################################################\n";
		cout << "*****     1.ע���˻�  2.��½�˻�  3.�˳�     *****\n";
		cout << "####################################################################\n\n";
	}
	void User_Interface1(string phonenumber)
	{
		cout << "#########################################################################\n";
		cout << "*****     1.��Ӻ���  2.�鿴�����¼  3.����Ȧ  4.����  5.�˳�     *****\n";
		cout << "#########################################################################\n\n";
		cout << "��ѡ����Ҫ����ķ���" << endl;
		char choice;
		bool flag = true;
		cin >> choice;
		while (flag)
		{
			switch (choice)
			{
			case '1':
			{
				cout << "�ɹ�������Ӻ��ѷ���" << endl;
				flag = false;
				User_Interface2(phonenumber);
				break;
			}
			case '2':
			{
				cout << "�ɹ������������" << endl;
				flag = false;
				User_Interface3(phonenumber);
				break;
			}
			case '3':
			{
				cout << "�ɹ���������Ȧ����" << endl;
				flag = false;
				User_Interface5(phonenumber);
				break;
			}
			case '4':
			{
				cout << "�ɹ�����鿴���÷���" << endl;
				Setting(phonenumber);
				flag = false;
				break;
			}
			case '5':
			{
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
				break;
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
	void User_Interface2(string phonenumber)
	{
		cout << "##############################################################################\n";
		cout << "*****     1.ͨ���ֻ�������Ӻ���  2.ͨ���ǳ���Ӻ���  3.�鿴��������  4.�˳�     *****\n";
		cout << "##############################################################################\n\n";
		cout << "��ѡ����Ҫ����ķ���" << endl;
		bool flag = true;
		char choice;
		string ans1,ans2,ans3;
		cout << "��ѡ������Ҫ����ķ���" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "�ɹ�����ͨ���ֻ�������Ӻ��ѷ���" << endl;
				AddFriendPhonenumber(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ�����ͨ���ǳ���Ӻ��ѷ���" << endl;
				AddFriendUsername(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ�����鿴�����������" << endl;
				FriendList(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return ;
				break;
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
	void User_Interface3(string phonenumber)
	{
		cout << "##############################################################################\n";
		cout << "*****     1.����  2.�鿴�����¼  3.�˳�     *****\n";
		cout << "##############################################################################\n\n";
		cout << "��ѡ����Ҫ����ķ���" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2;
		cout << "��ѡ������Ҫ����ķ���" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "�ɹ��������Է���" << endl;
				Message(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ�����鿴�����¼����" << endl;
				User_Interface4(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
				break;
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
	void User_Interface4(string phonenumber)
	{
		cout << "####################################################################################################\n";
		cout << "*****     1.�����ֻ��Ų鿴�����¼  2.�����ǳƲ鿴�����¼  3.���ùؼ��ʲ鿴�����¼  4.�˳�     *****\n";
		cout << "####################################################################################################\n\n";
		cout << "��ѡ����Ҫ����ķ���" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2, ans3;
		cout << "��ѡ������Ҫ����ķ���" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "�ɹ����������ֻ��Ų鿴�����¼����" << endl;
				Check_History_Phone(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ����������ǳƲ鿴�����¼����" << endl;
				Check_History_Username(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ��������ùؼ��ʲ鿴�����¼����" << endl;
				Check_History_Highlight(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
				break;
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
	void User_Interface5(string phonenumber)
	{
		cout << "##########################################################\n";
		cout << "*****     1.��������Ȧ  2.�鿴����Ȧ  3.�˳�     *****\n";
		cout << "##########################################################\n\n";
		cout << "��ѡ����Ҫ����ķ���" << endl;
		bool flag = true;
		char choice;
		string ans1, ans2, ans3,ans4;
		cout << "��ѡ������Ҫ����ķ���" << endl;
		while (flag)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
			{
				cout << "�ɹ����뷢������Ȧ����" << endl;
				Moment_Publish(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ�����鿴����Ȧ����" << endl;
				Moment_Check(phonenumber);
				cout << "����Ҫ���������" << endl;
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
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
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
	void Register() 
	{
		string phonenumber_re, phonenumber1, username, password,question=" ";
		bool not_register = true; //�ж��ֻ����Ƿ�ע��� 
		bool phonefind = true; //�ֻ��ҵ�
		bool usernamefind = true; //�ǳ��ҵ�
		bool accept = true; //Ĭ��ͨ��
		bool moment = true; //moment = true���ǿ��Ը����ѿ� ; moment = false���Լ��ɼ� 
		cout << "�����������ֻ�����" << endl;
		cout << "ע�� �ֻ�����Ҫ11λ �������ֲ���Ϊ0" << endl;
		while (not_register)
		{
			cin >> phonenumber1;
			if (phonenumber1.size() != 11 || phonenumber1[0] == '0')
			{
				cout << "�ֻ���������������������" << endl;
				not_register = true;
				continue; // �ص�whileѭ��
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
				if (phonenumber1 == phonenumber) //��һ����
				{
					phonenumber_re = phonenumber;
					break;
				}
			}
			if (phonenumber1 == phonenumber_re) //���û�ҵ��򷵻� string::npos
			{
				cout << "���ֻ����ѱ�ע�ᣬ����������" << endl;
				not_register = true;
				continue; //�ص�whileѭ��
			}
			else
			{
				not_register = false;
			}
			check_file.close();
			not_register = false;
		}
		//�ֻ�����û��ע�ᣬ���Լ���ע��
		bool is_password = true;
		string doublepassword; //������֤
		while (is_password)
		{
			cout << "��������������" << endl;
			cout << "ע�� ����Ҫ����8λ�����������Сд��ĸ������" << endl;
			cin >> password;
			if (password.size() < 8)
			{
				cout << "���볤�Ȳ��㣬����������" << endl;
				continue;
			}
			bool has_upper = false, has_lower = false, has_digit = false;
			for (char c : password) //ѭ������newpassword
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
					cout << "�������������" << endl;
					cin >> doublepassword;
					if (password != doublepassword)
					{
						cout << "���������������һ����������벻һ��" << endl;
						wrong = true;
						continue;
					}
					else
					{
						cout << "�������óɹ���" << endl;
						wrong = false;
						is_password = false;
					}
				}
			}
			else
			{
				cout << "���ڰ�ȫ���⣬������������һ���µ�����" << endl;
				is_password = true;
			}
		}
		cout << "�����������õ��û���" << endl;
		cin >> username;
		bool vertification_code = true;
		int code;
		while (vertification_code)
		{
			srand((unsigned)time(NULL)); //����ʱ�����ӣ���֤ÿ���������ͬ
			int rand_num = rand() % 9000 + 1000; //����1000~9999֮�������
			cout << "������λ�������֤�룺" << rand_num << endl;
			cout << "��������������֤��" << endl;
			cin >> code;
			if (rand_num == code)
			{
				cout << "ע��ɹ���" << endl;
				vertification_code = false;
				not_register = false;
			}
			else
			{
				cout << "��֤�벻һ��" << endl;
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
		string newphonenumber, newpassword, newpassword2, phonenumber; //�����Phonenumber������ֵ��
		bool flag = true;
		bool found = false;
		cout << "��ӭ�����û���¼����" << endl;
		cout << "���������ֻ��ţ�" << endl;
		cin >> newphonenumber;
		cout << "�������������룺" << endl;
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
						cout << "��½�ɹ���" << endl;
						flag = false;
						User_Interface1(phonenumber);
					}
					else
					{
						cout << "�����������������" << endl;
						bool password_flag = true;
						while (password_flag)
						{
							cin >> newpassword2;
							if (password == newpassword2)
							{
								cout << "��½�ɹ���" << endl;
								password_flag = false;
								flag = false;
								User_Interface1(phonenumber);
							}
							else
							{
								cout << "�����д�������������" << endl;
								password_flag = true;
							}
						}
					}
				}
			}
			if (found != true)
			{
				cout << "�ֻ�����δ��ע��" << endl;
			}
		}
	}
	void Setting(string phonenumber)
	{
		cout << "#########################################################################################################################\n";
		cout << "*****     1.����ͨ��ʲô���ķ�ʽ��Ѱ�Լ�  2.�趨ͨ����������ķ�ʽ  3.����Ȧչʾ��Χ  4.�޸�������ǳ�  5.�˳�     *****\n";
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
				cout << "*****     1.�ܲ���ͨ���ֻ�����Ѱ��  2.�ܲ���ͨ���û���Ѱ��  3.�ܲ���ͨ���ֻ�������û���Ѱ��  4.�˳�     *****\n";
				cout << "#############################################################################################################\n\n";
				cout << "��ѡ����Ҫ����ķ���" << endl;
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
						cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
						flag1 = false;
						return;
					}
					default:
					{
						cout << "û�и�ѡ�� �������������룺" << endl;
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
				cout << "������֤Ȩ���Ƿ���� ��" << endl;
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
				cout << "����ȦȨ���Ƿ���� ��" << endl;
				cout << " yes / no " << endl;
				cin >> ans;
				if (ans == "yes")
				{
					Moment(phonenumber);
					flag = false;
				}
				break;
			}
			case '4': //�޸�����ɹ� �����ļ�û���޸�
			{
				cout << endl;
				cout << "######################################################\n";
				cout << "*****     1.�޸�����  2.�޸��ǳ�  3.�˳�     *****\n";
				cout << "######################################################\n\n";
				cout << "��ѡ����Ҫ����ķ���" << endl;
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
						cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
						flag2 = false;
						return;
					}
					default:
					{
						cout << "û�и�ѡ�� �������������룺" << endl;
						flag2 = true;
						cin >> choice2;
					}
					}
				}
				break;
			}
			case '5':
			{
				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
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
	void ChangePassword(string phonenumber)
	{
		string newpassword, doublepassword, oriphonenumber;
		bool is_password = true;
		while (is_password)
		{
			cout << "������������ĵ����룺" << endl;
			cout << "ע�� ����Ҫ����8λ�����������Сд��ĸ������" << endl;
			cin >> newpassword;
			if (newpassword.size() < 8)
			{
				cout << "���볤�Ȳ��㣬����������" << endl;
				continue;
			}
			bool has_upper = false, has_lower = false, has_digit = false;
			for (char c : newpassword) //ѭ������newpassword
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
					cout << "���������������" << endl;
					cin >> doublepassword;
					if (newpassword != doublepassword)
					{
						cout << "���������������һ����������벻һ��" << endl;
						wrong = true;
						is_password = false;
					}
					else
					{
						cout << "�������óɹ���" << endl;
						wrong = false;
						is_password = false;
					}
				}
			}
			else
			{
				cout << "���ڰ�ȫ���⣬������������һ���µ�����" << endl;
				is_password = true;
			}
		}
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info; //��Ϣ������������
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line)) 
		{
			istringstream iss(line);
			string phonenumber1, username, password, question; //phonenumber1 = file�����
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end())
		{
			it->second[1] = newpassword;  // ��������
			cout << "���������ϣ�" << endl;
		}
		else {
			cout << "���ֻ����벻���ڣ�" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) { 
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void ChangeUsername(string phonenumber)
	{
		string newusername;
		cout << "����������ĵ��û�����" << endl;
		cin >> newusername;
		string filename = "User_Information.txt";
		unordered_map<string, vector<string>> user_info; //��Ϣ������������
		string line;
		ifstream user_file(filename);
		while (getline(user_file, line))
		{
			istringstream iss(line);
			string phonenumber1, username, password, question; //phonenumber1 = file�����
			int phonefind, usernamefind, accept, moment;
			iss >> phonenumber1 >> username >> password >> phonefind >> usernamefind >> accept >> moment >> question;
			user_info[phonenumber1] = { username, password, to_string(phonefind), to_string(usernamefind), to_string(accept), to_string(moment), question };
		}
		user_file.close();
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end())
		{
			it->second[0] = newusername;  // ��������
			cout << "�û���������ϣ�" << endl;
		}
		else {
			cout << "���ֻ����벻���ڣ�" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void ChangePhoneFind(string phonenumber)
	{
		string ans;
		cout << "�Ƿ�����ñ���ͨ���ֻ���Ѱ������" << endl;
		cout << "yes = �ñ�����ͨ���ֻ���Ѱ���� / no = �ñ��˲���ͨ���ֻ���Ѱ����" << endl;
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
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end() && ans =="no")
		{
			it->second[2] = to_string(0);  // ��������
			cout << "�����û�����ʹ���ֻ�����Ѱ������" << endl;
		}
		else 
		{
			it->second[2] = to_string(1);
			cout << "�����û���ʹ���ֻ�����Ѱ����" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void ChangeUsernameFind(string phonenumber)
	{
		string ans;
		cout << "�Ƿ�����ñ���ͨ���ǳ�Ѱ������" << endl;
		cout << "yes = �ñ�����ͨ���ǳ�Ѱ���� / no = �ñ��˲���ͨ���ǳ�Ѱ����" << endl;
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
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end() && ans == "no")
		{
			it->second[3] = to_string(0);  // ��������
			cout << "�����û�����ʹ���ǳ�Ѱ������" << endl;
		}
		else
		{
			it->second[3] = to_string(1);
			cout << "�����û���ʹ���ǳ�Ѱ����" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void ChangePhoneAndUsernameFind(string phonenumber)
	{
		string ans, ans1;
		cout << "�Ƿ�����ñ���ͨ���ֻ���Ѱ������" << endl;
		cout << "yes = �ñ�����ͨ���ֻ���Ѱ���� / no = �ñ��˲���ͨ���ֻ���Ѱ����" << endl;
		cin >> ans;
		cout << "�Ƿ�����ñ���ͨ���ǳ�Ѱ������" << endl;
		cout << "yes = �ñ�����ͨ���ǳ�Ѱ���� / no = �ñ��˲���ͨ���ǳ�Ѱ����" << endl;
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
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end() && ans == "no" && ans1 == "no")
		{
			it->second[2] = to_string(0); 
			it->second[3] = to_string(0);
			cout << "���Ľ��������˲���ͨ�������ֻ��ź��ǳ�Ѱ�ҵ�����" << endl;
		}
		else if (it != user_info.end() && ans == "yes" && ans1 == "no")
		{
			it->second[2] = to_string(1);
			it->second[3] = to_string(0);
			cout << "���Ľ�����������ͨ�������ֻ���Ѱ����������ͨ�������ǳ�Ѱ�ҵ�����" << endl;
		}
		else if (it != user_info.end() && ans == "no" && ans1 == "yes")
		{
			it->second[2] = to_string(0);
			it->second[3] = to_string(1);
			cout << "���Ľ�����������ͨ�������ǳ�Ѱ����������ͨ�������ֻ���Ѱ�ҵ�����" << endl;
		}
		else if (it != user_info.end() && ans == "yes" && ans1 == "yes") //�ҵ�
		{
			it->second[2] = to_string(1);
			it->second[3] = to_string(1);
			cout << "���Ľ�����������ͨ�������ֻ��ź��ǳ�Ѱ�ҵ�����" << endl;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void Accept(string phonenumber)
	{
		string ans,question_str,input_str;
		vector<string> newquestion;
		cout << "�Ƿ�����ñ�������ش��������ֱ�Ӽ�������" << endl;
		cout << "yes = Ĭ���Զ�ͨ�� / no = ��ش����������" << endl;
		cin >> ans;
		if (ans == "no")
		{
			cout << "���Ľ�����������Ҫ�ش�����������ܼ�����" << endl;
			cout << "���������������" << endl;
			cin.ignore();
			getline(cin, input_str); //����������ȡһ�� cinֻ����һ������
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
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end() && ans == "no")
		{
			it->second[4] = to_string(0);
			it->second[6] = question_str;
		}
		else
		{
			it->second[4] = to_string(1);
			cout << "���Ľ������������Զ�������" << endl;
			cout << "��֮ǰ���õ����⽫�Զ�ɾ��" << endl;
			it->second[6] = question_str;
		}
		ofstream outfile(filename);
		for (auto& item : user_info) //�����û���Ϣ 
		{
			outfile << item.first << " ";
			for (size_t i = 0; i < item.second.size() - 1; ++i) {
				outfile << item.second[i] << " ";
			}
			outfile << item.second.back() << endl; //.back()���������е����һ��Ԫ��
		}
		outfile.close();
	}
	void Moment(string phonenumber)
	{ //1�����˿� 0���Լ���
		string ans;
		cout << "�Ƿ��������ȦȨ�ޣ�" << endl;
		cout << "yes = ����Ȧ���ѿɼ� / no = ����Ȧ���Լ��ɼ�" << endl;
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
		//Ҫ�ı������ط�
		auto it = user_info.find(phonenumber); //�����û���Ϣ���Ƿ���ڸ��ֻ���
		if (it != user_info.end() && ans == "no") //�Լ��ɼ�
		{
			it->second[5] = '0';
		}
		else if (it != user_info.end() && ans == "yes") //���ѿɼ�
		{
			it->second[5] = '1';
		}
	}
	void AddFriendPhonenumber(string phonenumber) 
	{
		string phonenumber_friend;
		cout << "��������Ӻ��ѵ��ֻ���" << endl;
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
			if (phonenumber_me == phonenumber && phonenumber_add == phonenumber_friend) //�ҵ���ǰ�û�
			{
				if (accept_add == 1)
				{
					cout << "�Ѿ��Ǻ�������" << endl;
					add = false;
					sucess = false;
				}
				else if (accept_add == 0)
				{
					cout << "�Ѿ�������������� �����ظ���" << endl;
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
				iss >> phonenumber1 >> username1 >> password1 >> phonefind1 >> usernamefind1 >> accept1 >> moment1 >> question1; //�������1ͨ��question��" "
				//string phonenumber_me, phonenumber_add, username_add, question, answer;
				int accept_add = 1;//�����������Ǻ���
				if (phonenumber_friend == phonenumber1 && phonefind1 == 1) //phonefind = 1��ʱ��ſ����ҵ�
				{
					if (accept1 == 1)
					{ //iss >> phonenumber_me >> username_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
						cout << "Ĭ��ͨ��..." << endl;
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
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(1) << " " << question1 << " " << answer_str << endl; //username_meʵ�ֲ���
						sucess = false;
						break;
					}
					else  //accept1=0Ҫͨ����������
					{
						cout << "��Է���������ش�������ܼ���Ϊ����" << endl;
						cout << question1 << endl;
						cin.ignore();
						getline(cin, input_str); //����������ȡһ�� cinֻ����һ������
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
						cout << "���ڷ����������..." << endl;
						sucess = false;
						break;
					}
				}
				else if (phonenumber_friend == phonenumber1 && phonefind1 == 0) //�����˲�����Ѱ
				{
					cout << "�Է������˱��˲���ͨ���ֻ�����Ѱ" << endl;
					sucess = false;
					break;
				}
			}
			add = false;//��Ϊ��while(add)��һֱ�Ʋ���ȥ
			friend_file.close();
			user_file.close();
		}
		if (sucess) //�Ҳ������ֻ���
		{
			cout << "�Ҳ������ֻ���" << endl;
		}
	}
	void AddFriendUsername(string phonenumber) //ʹ��append .. ֱ����Ӷ����Ǹ���
	{
		string username_friend;
		cout << "��������Ӻ��ѵ��ǳ�" << endl;
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
			if (phonenumber_me == phonenumber && username_add == username_friend) //�ҵ���ǰ�û�
			{
				if (accept_add == 1)
				{
					cout << "�Ѿ��Ǻ�������" << endl;
					add = false;
					sucess = false;
				}
				else if (accept_add == 0)
				{
					cout << "�Ѿ�������������� �����ظ���" << endl;
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
				iss >> phonenumber1 >> username1 >> password1 >> phonefind1 >> usernamefind1 >> accept1 >> moment1 >> question1; //�������1ͨ��question��" "
				//string phonenumber_me, phonenumber_add, username_add, question, answer;
				int accept_add = 1;//�����������Ǻ���
				if (username_friend == username1 && phonefind1 == 1) //phonefind = 1��ʱ��ſ����ҵ�
				{
					if (accept1 == 1)
					{ //iss >> phonenumber_me >> username_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
						cout << "Ĭ��ͨ��..." << endl;
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
						friend_file << phonenumber << " " << phonenumber1 << " " << username1 << " " << to_string(1) << " " << question1 << " " << answer_str << endl; //username_meʵ�ֲ���
						sucess = false;
						break;
					}
					else  //accept1=0Ҫͨ����������
					{
						cout << "��Է���������ش�������ܼ���Ϊ����" << endl;
						cout << question1 << endl;
						cin.ignore();
						getline(cin, input_str); //����������ȡһ�� cinֻ����һ������
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
						cout << "���ڷ����������..." << endl;
						sucess = false;
						break;
					}
				}
				else if (username_friend == username1 && usernamefind1 == 0) //�����˲�����Ѱ
				{
					cout << "�Է������˱��˲���ͨ���ǳ���Ѱ" << endl;
					sucess = false;
					break;
				}
			}
			add = false;//��Ϊ��while(add)��һֱ�Ʋ���ȥ
			friend_file.close();
			user_file.close();
		}
		if (sucess) //�Ҳ������ǳ�
		{
			cout << "�Ҳ������ǳ�" << endl;
		}
	}
	void FriendList(string phonenumber)
	{
		string filename = "Add_friend.txt";
		unordered_map<string, vector<vector<string>>> friend_info; //��Ϣ������������
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
		for (auto& item : friend_info) //�����û���Ϣ 
		{
			for (auto& friend_data : item.second) {
				if (friend_data[0] == phonenumber && friend_data[2] == "0") {
					cout << item.first << "��Ҫ�����Ϊ����" << endl;
					cout << "�����������⣺" << friend_data[3] << endl;
					cout << "�������Ļش�" << friend_data[4] << endl;
					cout << "�������Ƿ�ͬ��" << endl;
					cout << "yes = ͬ�� / no = ��ͬ��" << endl;
					string ans;
					cin >> ans;
					if (ans == "yes")
					{
						friend_data[2] = "1";
						cout << "����ͬ����Ϊ����" << endl;
						friend_list = false;
					}
					else
					{
						friend_data[2] = "0";
						cout << "���Ѿܾ���Ϊ����" << endl;
						friend_list = false;
					}
				}
			}
		}

		if (friend_list)
		{
			cout << "û�������Ϊ����" << endl;
		}

		ofstream outfile(filename);
		for (auto& item : friend_info) //�����û���Ϣ 
		{
			for (auto& friend_data : item.second) {
				outfile << item.first << " ";
				for (size_t i = 0; i < friend_data.size() - 1; ++i) {
					outfile << friend_data[i] << " ";
				}
				outfile << friend_data.back() << endl; //.back()���������е����һ��Ԫ��
			}
		}
		outfile.close();
	}
	void Message(string phonenumber)
	{
		string phonenumber_receiver,input_str,message_str;
		bool can_chat = true;
		cout << "���������뷢����Ϣ�Ķ���" << endl;
		cout << "�ֻ��ţ�" << endl;
		cin >> phonenumber_receiver;
		ifstream check_file("Add_friend.txt"); //phonenumber(�Լ���) username(�Լ���) phonenumber1(���˵�) username�����˵ģ�accept(����Ҫ��Ҫ������) question(�������accept=0�Ļ���cout question) answer���������accept=0�ͻ���answer)
		ofstream history_file("Chat_History.txt", ios::app); //sender receiver chat
		string laji; //��������˶�����1 ���Ǽ��˺��� �����0 ����û�мӺ���
		vector<string> message;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_me, phonenumber_add, username_add, question, answer;
			int accept_add;
			string phonenumber_sender, phonenumber_receiver_new;
			iss >> phonenumber_me >> phonenumber_add >> username_add >> accept_add >> question >> answer;
			AddFriend[phonenumber_me] = { phonenumber_add , username_add , to_string(accept_add) , question , answer };
			if (phonenumber_receiver == phonenumber_me && phonenumber_add == phonenumber && accept_add == 1 || phonenumber_receiver == phonenumber_add && phonenumber_me == phonenumber && accept_add == 1) //����ֻҪ�����Ǻ��� ˭��˭����Ҫ
			{
				cout << "�������뷢�͵���Ϣ" << endl;
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
			cout << "����û�����Ϊ���� �����㲻�ܷ���Ϣ����" << endl;
		}
	}
	void Check_History_Phone(string phonenumber) 
	{
		bool chat_history = true;
		string phonenumber_find; //phonenumber_receiver
		cout << "��������Ѱ�������¼���ֻ���" << endl;
		cin >> phonenumber_find;
		ifstream check_file("Chat_History.txt");
		string laji;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_sender, phonenumber_receiver, chat;
			iss >> phonenumber_sender >> phonenumber_receiver >> chat;
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout�������¼ either one ֻҪ���������ֱ��cout
			if (phonenumber_receiver == phonenumber_find && phonenumber_sender == phonenumber || phonenumber_receiver == phonenumber && phonenumber_sender == phonenumber_find)
			{
				cout << phonenumber_sender << "��" << chat << endl;
				chat_history = false;
			}
		}
		check_file.close();
		if (chat_history)
		{
			cout << "û�������¼" << endl;
		}
	}
	void Check_History_Username(string phonenumber)
	{
		string username_find, phonenumber_find;
		bool chat_history = true;
		cout << "��������Ѱ�������¼���ǳ�" << endl;
		cin >> username_find; //���ҵ���Ӧ���ֻ���
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
				phonenumber_find = phonenumber1; //�ҵ���Ӧ�ǳƵ��ֻ�����
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
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout�������¼ either one ֻҪ���������ֱ��cout
			if (phonenumber_receiver == phonenumber_find && phonenumber_sender == phonenumber || phonenumber_receiver == phonenumber && phonenumber_sender == phonenumber_find)
			{
				cout << phonenumber_sender << "��" << chat << endl;
				chat_history = false;
			}
		}
		hit_file.close();
		if (chat_history)
		{
			cout << "û�������¼" << endl;
		}
	}
	void Check_History_Highlight(string phonenumber)
	{
		bool chat_history = true;
		string highlight;
		cout << "��������Ѱ�������¼�Ĺؼ���" << endl;
		cin >> highlight;
		ifstream check_file("Chat_History.txt");
		string laji;
		while (getline(check_file, laji))
		{
			istringstream iss(laji);
			string phonenumber_sender, phonenumber_receiver, chat;
			iss >> phonenumber_sender >> phonenumber_receiver >> chat;
			Chat[phonenumber_sender] = { phonenumber_receiver , chat }; //cout�������¼ either one ֻҪ���������ֱ��cout
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
			cout << "û�������¼" << endl;
		}
	}
	void Moment_Publish(string phonenumber)  //phonenumber(˭��) moment(�Լ������ǿ��Ը����˿�) accept(�����Ѳ��ܿ�) ��Friend_list phonenumber���Լ���1���ܿ� likecount vector<string>comment -> phonenumber : comment (ѭ��)
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
				cout << "�������뷢��������Ȧ�������֣�" << endl;
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
				moment_file << phonenumber << " " << moment_str << " " << moment_seen << " " << likecount_seen << " " << comment <<endl; //ֻ��moment=1/0 �ſ��Ա����˿���
				Moment_PYQ[phonenumber] = { moment_str,to_string(moment_seen),to_string(likecount_seen) ,comment };
			}
		}
	}
	void Moment_Check(string phonenumber) //��Ҫ�鿴�ǲ��Ǻ��� �������Ҫ����Add_Friend.txt ->
	{//1���ѿɼ� 0�Լ��ɼ�1 ʵ�ֲ鿴����
		string x = phonenumber;
		bool find = true;
		bool flag = true;
		while (flag) //�������������
		{
			cout << "##########################################################################\n";
			cout << "*****     1.�鿴�Լ�������Ȧ  2.�鿴���ѵ�����Ȧ  3.�˳�     *****\n";
			cout << "##########################################################################\n\n";
			cout << "��ѡ����Ҫ����ķ���" << endl;
			char c;
			cin >> c;
			if (c == '1')//�ɹ���
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
						cout << phonenumber_sender << "��" << endl;
						cout << moment_str << " " << endl;
						cout << "���ޣ�" << likecount_seen << endl;
						cout << "���ԣ�" << comment <<  endl;
					}
				}
				flag = false;
				momentfile.close();
			}
			else if (c == '2') // �е�û���� û�е�Ҳû����
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
							friend_phonenumbers.push_back(friend_phonenumber); //��ȫ����Ϣ����ȥ
						}
						else
						{
							friend_phonenumbers.push_back(my_phonenumber); //��ȫ����Ϣ����ȥ
						}
					} //12345678901 -> 18761675655 + 98765432101 + 11223344556
				} //����
				user_file.close();
				ifstream moment_file("Check_moment.txt");
				string line1,new_tempphone=" ",temp=" ";
				int moment_seen1 = 0;
				bool moment_found = false;
				if (friend_found)
				{
					while (getline(moment_file, line1))
					{
						for (auto& friend_phonenumber : friend_phonenumbers) //�ҵ����ѵĵ绰����
						{
							istringstream iss1(line1);
							string moment_phonenumber, moment_str, comment;
							int moment_seen, likecount_seen;
							iss1 >> moment_phonenumber >> moment_str >> moment_seen >> likecount_seen;
							temp = moment_phonenumber;
							getline(iss1, comment);
							//cout << moment_phonenumber << moment_str << moment_seen << likecount_seen << comment;
							if (friend_phonenumber == moment_phonenumber && moment_seen == 1) //�ɹ�����
							{
								moment_seen1 = moment_seen; //moment_seen1��0��1
								moment_found = true;
								cout << moment_phonenumber << ":" << endl;
								cout << moment_str << endl;
								cout << "���ޣ�" << likecount_seen << endl;
								cout << "�������Ƿ�����ޣ�" << endl;
								string ans;
								cout << "yes/no" << endl;
								cin >> ans;
								if (ans == "yes")
								{
									Moment_Like(x,moment_phonenumber,moment_str);
								}
								cout << "���ԣ�" << comment << endl;
								cout << "�������Ƿ������ۣ�" << endl;
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
						}//4 noû���� yesyesnonoҲû���� nonoyesyes
						if (!moment_found)
						{
							if (new_tempphone != temp )
							{
								new_tempphone = temp;
								cout << new_tempphone << "��������Ϊ���Լ��ɼ�" << endl;
							}
						}
					}
				}
				moment_file.close();
			}
			if (c == '3')
			{

				cout << "�ɹ��˳�����ӭ�´���ʹ��" << endl;
				flag = false;
				return;
			}
			else if (c != '1' && c != '2')
			{
				cout << "û�и�ѡ�� �������������룺" << endl;
				flag = true;
				continue;
			}
		}
	}
	void Moment_Comment(string phonenumber, string moment_phonenumber, string moment_str) //phonenumber=���Լ� moment_phonenumber����Ȧ���ֻ���
	{
		string laji, ans;
		fstream momentfile("Check_moment.txt", ios::in );
		unordered_map<string, vector<string>> Moment_PYQ;
		vector<string> cache;
		while (getline(momentfile, laji))  //��û�������� ���Ի�����ʵ��
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
				input_str = comment; //��ֵ����
				cout << "�����������������Ȧ������" << endl; //����ҲҪ���ҵ���Ӧ��
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
				cout << "���۳ɹ���" << endl;
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
	void Moment_Like(string phonenumber, string moment_phonenumber, string moment_str) //��һ����û��ȥ �ڶ�����moment���ı�
	{
		fstream momentfile("Check_moment.txt", ios::in | ios::out);
		string laji;
		vector<string>cache;
		unordered_map <string, vector<string>> like;
		bool found = false;  
		while (getline(momentfile, laji)) //��û�������� ���Ի�����ʵ��
		{
			istringstream iss(laji);
			string phonenumber_sender, moment_sender, comment;
			int moment_seen, likecount_seen;
			iss >> phonenumber_sender >> moment_sender >> moment_seen >> likecount_seen >> comment;
			like[phonenumber_sender] = { moment_sender,to_string(moment_seen),to_string(likecount_seen) ,comment };
			if (phonenumber_sender == moment_phonenumber && moment_str == moment_sender) //moment_str���ı�
			{
				likecount_seen++;
				cache.push_back(phonenumber_sender + " " + moment_sender + " " + to_string(moment_seen) + " " + to_string(likecount_seen) + " " + comment);
				cout << "���޳ɹ���" << endl;
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
	map<string, vector<string>> MyChat; //����user_file��
	map<string, vector<string>> AddFriend; //����friend_file
	map<string, vector<string>> Chat;
	map<string, vector<string>> Moment_PYQ;
	ofstream user_file;
	ofstream friend_file;
	ofstream chat_file;
	ofstream moment_file;
}; 