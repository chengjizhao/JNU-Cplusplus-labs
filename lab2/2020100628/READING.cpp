#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>

//函数声明 
void menu();
void OpenFile();
void search();
void add();
void save();
 
//主函数 
int main()
{
	int choise =-1;
	while (choise !=0)
	{
		menu();
		std::cout<<"\t\t\t请选择:";
		std::cin>>choise;
		switch(choise)
		{
			case 1:
				 OpenFile();    //导入
			     break;
			case 2:
			     search();      //查询 
				 break;
			case 3:
			     add();        //添加 
			     break;
			default:
			     break; 
		}
		 std::cout << std::endl;		
	}
	return 0;
}

//主菜单
void menu()
{
	
	std::cout << "\t\t\t  1.导入显示学生信息   \n";
	std::cout << "\t\t\t  2.查询学生信息   \n";
	std::cout << "\t\t\t  3.添加学生信息   \n";
} 
//导入1 
void OpenFile()
{
	std::ifstream csv_data("text.csv", std::ios::in);
	std::string line;
	
	if (!csv_data.is_open())
	{
		std::cout << "Error: opening file fail" << std::endl;
		std::exit(1);
	}
	
	std::istringstream sin;
	std::vector<std::string> words;
	std::string word;
	
		while (std::getline(csv_data, line))
	 {
	 	sin.clear();
	 	sin.str(line);
	 	while (std::getline(sin, word, ','))
	 	{
	 		words.push_back(word);
	 		std::cout << word ;
		 }
		 std::cout << std::endl;
	 }
	 csv_data.close();
	 ;
}
//查询 2
void search()
{
	std::ifstream csv_data("text.csv", std::ios::in);
	std::string line;
	
	if (!csv_data.is_open())
	{
		std::cout << "Error: opening file fail" << std::endl;
		std::exit(1);
	}
	
	std::istringstream sin;
	std::vector<std::string> words;
	std::string word;
	
	std::cout << "请输入查找学号：";
	std::string num;std::cin >> num;
	std::getline(csv_data, line);
	while (std::getline(csv_data, line))
	 {
	 	sin.clear();
	 	sin.str(line);
	 	while (std::getline(sin, word, ','))
	 	{
	 		words.push_back(word);
	 		if ((word.compare(num)) == 0)
			{  std::cout << line;
			  }
			else
			break;
		 }
	 }
}
//添加3保存 
void add()
{
	std::ifstream csv_data("text.csv", std::ios::in);
	std::string line;
	std::ofstream outFile;
	
	
	if (!csv_data.is_open())
	{
		std::cout << "Error: opening file fail" << std::endl;
		std::exit(1);
	}
	
	std::istringstream sin;
	std::vector<std::string> words;
	std::string word;
		
	std::cout << "请输入学号：";
	std::string num;std::cin >> num;
	std::cout << "请输入成绩：";
	std::string sco;std::cin >> sco;
	
	outFile.open("text1.csv", std::ios::out | std::ios::trunc);
	
	std::getline(csv_data, line);
	while (std::getline(csv_data, line))
	 {
	 	sin.clear();
	 	sin.str(line);
	 	while (std::getline(sin, word, ','))
	 	{
	 		words.push_back(word);
	 		if ((word.compare(num)) == 0)
			{  line=line+','+sco;

			   sin.clear(); 
	           sin.str(line);
			  // std::cout << line;
	        while(std::getline(sin, word, ','))   
			{	           
			   words.push_back(word);
			   std::cout << word;
               outFile.open("text1.csv", std::ios::out | std::ios::app);
               outFile << word << ',';
	           outFile.close();
			}
			}

            outFile.open("text1.csv", std::ios::out | std::ios::app);
            outFile << word << ',';
	        outFile.close();
		 }
		    outFile.open("text1.csv", std::ios::out | std::ios::app);
            outFile << std::endl;
	        outFile.close();
	 }            
}
