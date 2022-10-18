//《软件工程》课程项目“你帮我助”
//姓名：杨其伟
//学号：520020910111
//程序使用items.txt文件存储物品信息，每行一个物品，并为物品编号，物品的不同属性用\t分隔。

#include<iostream>
#include<fstream>
#include<string>

#define _CRT_SECURE_NO_WARNINGS 1   //防止vs对某些函数报错
using namespace std;

//该类中包括主程序需要调用的功能
//程序会为每一个物品添加一个编号作为唯一标识符，为了确保其唯一性，将物品删除后其编号不会重复利用。
class HelpEachOther{
private:
	int number = 1;  //记录当前列表中有多少条数据

public:
	bool rerun(bool newflag = true) {//根据返回值确定是否需要继续循环
		static bool flag = true;
		if (newflag);
		else flag = newflag;
		return flag;
	}           
	void Add_Item();//添加物品函数声明
	void Delete_Item();//删除物品函数声明
	void All_Item();//显示所有物品函数声明
	void Find_Item();//查找物品函数声明
	int Get_Number();//获取当前列表中有多少物品
};


int main()
{
	printf("欢迎使用“你帮我助”软件！\n\n");
	string go;   //记录想调用的功能
	HelpEachOther help;
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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		help.Get_Number();
		
		if (go == "1") help.Add_Item();
		else if (go == "2") help.Delete_Item();
		else if (go == "3") help.All_Item();
		else if (go == "4") help.Find_Item();
		else if (go == "0") return 0;
		else printf("\n非法输入！\n\n");
		
	}
}


//添加物品，包括物品名称、数量、信息、提供者联系方式
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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		file1.close();
		number++;
		if (i == "1") continue;
		if (i == "0") return;
		rerun(false);
		return;

	}
	
}


//删除物品，可以根据物品编号或是物品名删除物品。若选择物品名，会把同一物品名的所有物品全部删除。
void HelpEachOther::Delete_Item()
{

	
	string way;//用于记录删除物品的方式
	printf("按照编号删除物品，请输入1，按照物品名删除物品，请输入2，输入其他字符返回到主页面\n");
	getline(cin, way);
	if (way == "1")
	{
		printf("请输入物品编号\n");
		string Wanted_Item;  //想查找的物品的编号
		getline(cin, Wanted_Item);


		ifstream file1;
		string line;
		char* tmp;
		int i = 0;
		char* Number_Of_Item;//记录物品编号
		char* Name_Of_Item;//记录物品名称
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
				}  //string转换成char*
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

				file1.close();
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



//显示所有物品
void HelpEachOther::All_Item()
{
	ifstream file1;
	string line;
	char* tmp;
	int i = 0;

	//以下变量用来存储要输出的内容
	char* Number_Of_Item;
	char* Name_Of_Item;
	char* Count_Of_Item;
	char* Remark_Of_Item;
	char* Tel;
	//以上变量用来存储要输出的内容

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



//查找物品，可以按照编号查找物品，也可以输入物品名查找物品。
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


//获取当前物品数
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
