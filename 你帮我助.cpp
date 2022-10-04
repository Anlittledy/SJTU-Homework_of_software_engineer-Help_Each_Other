#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

class HelpEachOther{
private:
	int number = 1;

public:
	bool rerun(bool newflag = true) {
		static bool flag = true;
		if (newflag);
		else flag = newflag;
		return flag;
	}
	void Add_Item();
	void Delete_Item();
	void All_Item();
	void Find_Item();
	int Get_Number();
};


int main()
{
	printf("��ӭʹ�á���������������\n\n");
	string go;
	HelpEachOther help;
	help.Get_Number();
	while (help.rerun())
	{
		printf("ʹ��˵����\n");
		printf("----------------------------\n");
		printf("1�������Ʒ��Ϣ\n");
		printf("2��ɾ����Ʒ��Ϣ\n");
		printf("3����ʾ��Ʒ�б�\n");
		printf("4��������Ʒ��Ϣ\n");
		printf("0���˳�����\n");
		printf("----------------------------\n");
		cin >> go;
		string nothing;
		getline(cin, nothing);
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		
		if (go == "1") help.Add_Item();
		else if (go == "2") help.Delete_Item();
		else if (go == "3") help.All_Item();
		else if (go == "4") help.Find_Item();
		else if (go == "0") return 0;
		else printf("\n�Ƿ����룡\n\n");
		
	}
}

void HelpEachOther::Add_Item()
{
	while (true)
	{
		ofstream file1;
		file1.open("items.txt", ios::app);      
		if (!file1.is_open())
		{
			cout << "�����ļ���ʧ�ܣ� " << endl;
			rerun(false);
			return;
		}

		string s;
		file1 << number << '\t';
		printf("������Ҫ��ӵ���Ʒ���ƣ�\n");
		getline(cin,s);
		file1 << s << '\t';
		printf("��������Ʒ���������硰1��������1��ȣ�\n");
		getline(cin, s);
		file1 << s << '\t';
		printf("��������Ʒ����ϸ��Ϣ�뱸ע��\n");
		getline(cin, s);
		file1 << s << '\t';
		printf("������������ϵ��ʽ��\n");	
		getline(cin, s);
		file1 << s << '\n';
		file1.close();
		string i;
		printf("Ҫ���������Ʒ��������1��Ҫ����������������0���������������ַ��˳�����\n");
		cin >> i;
		string nothing;
		getline(cin, nothing);
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		file1.close();
		number++;
		if (i == "1") continue;
		if (i == "0") return;
		rerun(false);
		return;

	}
	
}
void HelpEachOther::Delete_Item()
{

	
	string way;
	printf("���ձ��ɾ����Ʒ��������1��������Ʒ��ɾ����Ʒ��������2�����������ַ����ص���ҳ��\n");
	getline(cin, way);
	if (way == "1")
	{
		printf("��������Ʒ���\n");
		string Wanted_Item;
		getline(cin, Wanted_Item);


		ifstream file1;
		string line;
		char* tmp;
		int i = 0;
		char* Number_Of_Item;
		char* Name_Of_Item;
		bool finded = false;

		file1.open("items.txt");
		ofstream file2;
		file2.open("temp.txt", ios::out);
		const char* split = "\t";
		string s_Number_Of_Item;

		if (file1.is_open())
		{
			printf("��ɾ���������ݣ�\n");
			cout << "��Ʒ���--------��Ʒ����---------����---------��ע----------��ϵ��ʽ\n";
			while (getline(file1, line))
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}//stringת����char*
				Number_Of_Item = strtok(tmp, split);
				Name_Of_Item = strtok(NULL, split);

				s_Number_Of_Item = Number_Of_Item;
				if (Wanted_Item == s_Number_Of_Item)
				{
					cout << line << endl;
					finded = true;
				}
				else 
				{
					file2 << line << endl;
				}

				delete[]tmp;
				//delete[]Number_Of_Item;
				//delete[]Name_Of_Item;
			}
			if (!finded) printf("δɾ���κ���Ʒ\n\n");
			else
			{
				printf("ɾ��������Ʒ�����Զ�����������\n\n");
				file1.close();
				file2.close();
				fstream file1("items.txt", ios::out);
				fstream file2("temp.txt", ios::in);
				while (getline(file2, line))
				{
					file1 << line << "\n";
				}

				file1.close();//�ر���
				file2.close();
			}
		}

	}
	else if (way == "2")
	{
		printf("��������Ʒ��\n");
		string Wanted_Item;
		getline(cin, Wanted_Item);


		ifstream file1;
		string line;
		char* tmp;
		int i = 0;
		char* Number_Of_Item;
		char* Name_Of_Item;
		string s_Name_Of_Item;
		bool finded = false;

		file1.open("items.txt");
		ofstream file2;
		file2.open("temp.txt", ios::out);
		const char* split = "\t";


		if (file1.is_open())
		{
			printf("\n��ɾ���������ݣ�\n");
			cout << "��Ʒ���--------��Ʒ����---------����---------��ע----------��ϵ��ʽ\n";
			while (getline(file1, line))
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}

				Number_Of_Item = strtok(tmp, split);
				Name_Of_Item = strtok(NULL, split);

				s_Name_Of_Item = Name_Of_Item;
				if (Wanted_Item == s_Name_Of_Item)
				{
					cout << line << endl;
					finded = true;
				}
				else
				{
					file2 << line << endl;
				}

				s_Name_Of_Item = Name_Of_Item;
				delete[]tmp;
				//delete[]Number_Of_Item;
				//delete[]Name_Of_Item;
			}
			if (!finded) printf("δɾ���κ���Ʒ\n\n");
			else
			{
				printf("ɾ��������Ʒ�����Զ�����������\n\n");
				file1.close();
				file2.close();
				fstream file1("items.txt", ios::out);
				fstream file2("temp.txt", ios::in);
				while (getline(file2, line))
				{
					file1 << line << "\n";
				}

				file1.close();//�ر���
				file2.close();
			}
		}
	}
	else
	{
		return;
	}
	
}

void HelpEachOther::All_Item()
{
	ifstream file1;
	string line;
	char* tmp;
	int i = 0;
	char* Number_Of_Item;
	char* Name_Of_Item;
	char* Count_Of_Item;
	char* Remark_Of_Item;
	char* Tel;
	const char* split = "\t\0 ";
	file1.open("items.txt");
	if (file1.is_open())
	{
		cout << "���\t��Ʒ����  ����\t\t\t��ע\t\t��ϵ��ʽ\n";
		while (getline(file1, line))
		{
			int a = line.length();
			tmp = new char[line.length()];
			i = 0;
			while (i < line.length())
			{
				tmp[i] = line[i];
				i++;
			}

			Number_Of_Item = strtok(tmp, split);
			Name_Of_Item = strtok(NULL, split);
			Count_Of_Item = strtok(NULL, split);
			Remark_Of_Item = strtok(NULL, split);
			Tel = strtok(NULL, split);
			
			printf("%4s%10s%8s%30s\t", Number_Of_Item, Name_Of_Item, Count_Of_Item, Remark_Of_Item);
			int j = 0;
			while (Tel[j] >= '0' && Tel[j] <= '9') 
			{
				cout << Tel[j];
				j++;
			}
			cout << endl;
		}
		cout << "------------------------------------------------------\n\n";
	}
}
void HelpEachOther::Find_Item()
{
	string way;
	printf("���ձ�Ų�����Ʒ��������1��������Ʒ��������Ʒ��������2�����������ַ����ص���ҳ��\n");
	getline(cin, way);
	if (way == "1") 
	{
		printf("��������Ʒ���\n");
		string Wanted_Item;
		getline(cin, Wanted_Item);


		ifstream file1;
		string line;
		char* tmp;
		int i = 0;
		char* Number_Of_Item;
		char* Name_Of_Item;
		bool finded = false;

		file1.open("items.txt");
		const char* split = "\t";
		string s_Number_Of_Item;

		if (file1.is_open())
		{
			printf("���ҵ����½����\n");
			cout << "��Ʒ���--------��Ʒ����---------����---------��ע----------��ϵ��ʽ\n";
			while (getline(file1, line))
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}//stringת����char*
				Number_Of_Item = strtok(tmp, split);
				Name_Of_Item = strtok(NULL, split);

				s_Number_Of_Item = Number_Of_Item;
				if (Wanted_Item == s_Number_Of_Item) 
				{ 
					cout << line << endl; 
					finded = true;
				}

				delete[]tmp;
				//delete[]Number_Of_Item;
				//delete[]Name_Of_Item;
			}
			if (!finded) printf("ʲô��û�ҵ�\n");
			else printf("���ҵ����Ͻ�������Զ�����������\n\n");
		}

	}
	else if (way == "2") 
	{
		printf("��������Ʒ��\n");
		string Wanted_Item;
		getline(cin, Wanted_Item);


		ifstream file1;
		string line;
		char* tmp;
		int i = 0;
		char* Number_Of_Item;
		char* Name_Of_Item;
		string s_Name_Of_Item;
		bool finded = false;

		file1.open("items.txt");
		const char* split = "\t";

	
		if (file1.is_open())
		{
			printf("���ҵ����½����\n");
			cout << "��Ʒ���--------��Ʒ����---------����---------��ע----------��ϵ��ʽ\n";
			while (getline(file1, line)) 
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}

			Number_Of_Item = strtok(tmp, split);
			Name_Of_Item = strtok(NULL, split);

			s_Name_Of_Item = Name_Of_Item;
			if (Wanted_Item == s_Name_Of_Item)
			{
				cout << line << endl;
				finded = true;
			}

			s_Name_Of_Item = Name_Of_Item;
			delete[]tmp;
			//delete[]Number_Of_Item;
			//delete[]Name_Of_Item;
			}
			if (!finded) printf("ʲô��û�ҵ�\n");
			else printf("���ҵ����Ͻ�������Զ�����������\n\n");
		}
	}
	else 
	{
		return;
	}
	

}

int HelpEachOther::Get_Number() {
	ifstream file1;
	string tmp;
	file1.open("items.txt");
	while (getline(file1, tmp))
	{
		number++;
	}
	file1.close();
	return number;
}
