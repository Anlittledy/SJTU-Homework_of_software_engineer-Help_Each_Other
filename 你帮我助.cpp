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
	printf("欢迎使用“你帮我助”软件！\n\n");
	string go;
	HelpEachOther help;
	help.Get_Number();
	while (help.rerun())
	{
		printf("使用说明：\n");
		printf("----------------------------\n");
		printf("1：添加物品信息\n");
		printf("2：删除物品信息\n");
		printf("3：显示物品列表\n");
		printf("4：查找物品信息\n");
		printf("0：退出程序\n");
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
		else printf("\n非法输入！\n\n");
		
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
			cout << "数据文件打开失败！ " << endl;
			rerun(false);
			return;
		}

		string s;
		file1 << number << '\t';
		printf("请输入要添加的物品名称：\n");
		getline(cin,s);
		file1 << s << '\t';
		printf("请输入物品数量：（如“1个”、“1斤”等）\n");
		getline(cin, s);
		file1 << s << '\t';
		printf("请输入物品的详细信息与备注：\n");
		getline(cin, s);
		file1 << s << '\t';
		printf("请输入您的联系方式：\n");	
		getline(cin, s);
		file1 << s << '\n';
		file1.close();
		string i;
		printf("要继续添加物品，请输入1，要返回主界面请输入0，输入其他任意字符退出程序\n");
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
	printf("按照编号删除物品，请输入1，按照物品名删除物品，请输入2，输入其他字符返回到主页面\n");
	getline(cin, way);
	if (way == "1")
	{
		printf("请输入物品编号\n");
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
			printf("已删除以下内容：\n");
			cout << "物品编号--------物品名称---------数量---------备注----------联系方式\n";
			while (getline(file1, line))
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}//string转换成char*
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
			if (!finded) printf("未删除任何物品\n\n");
			else
			{
				printf("删除以上物品，将自动返回主界面\n\n");
				file1.close();
				file2.close();
				fstream file1("items.txt", ios::out);
				fstream file2("temp.txt", ios::in);
				while (getline(file2, line))
				{
					file1 << line << "\n";
				}

				file1.close();//关闭流
				file2.close();
			}
		}

	}
	else if (way == "2")
	{
		printf("请输入物品名\n");
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
			printf("\n已删除以下内容：\n");
			cout << "物品编号--------物品名称---------数量---------备注----------联系方式\n";
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
			if (!finded) printf("未删除任何物品\n\n");
			else
			{
				printf("删除以上物品，将自动返回主界面\n\n");
				file1.close();
				file2.close();
				fstream file1("items.txt", ios::out);
				fstream file2("temp.txt", ios::in);
				while (getline(file2, line))
				{
					file1 << line << "\n";
				}

				file1.close();//关闭流
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
		cout << "编号\t物品名称  数量\t\t\t备注\t\t联系方式\n";
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
	printf("按照编号查找物品，请输入1，按照物品名查找物品，请输入2，输入其他字符返回到主页面\n");
	getline(cin, way);
	if (way == "1") 
	{
		printf("请输入物品编号\n");
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
			printf("查找到以下结果：\n");
			cout << "物品编号--------物品名称---------数量---------备注----------联系方式\n";
			while (getline(file1, line))
			{
				tmp = new char[line.length()];
				i = 0;
				while (i < line.length())
				{
					tmp[i] = line[i];
					i++;
				}//string转换成char*
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
			if (!finded) printf("什么都没找到\n");
			else printf("查找到以上结果，将自动返回主界面\n\n");
		}

	}
	else if (way == "2") 
	{
		printf("请输入物品名\n");
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
			printf("查找到以下结果：\n");
			cout << "物品编号--------物品名称---------数量---------备注----------联系方式\n";
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
			if (!finded) printf("什么都没找到\n");
			else printf("查找到以上结果，将自动返回主界面\n\n");
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
