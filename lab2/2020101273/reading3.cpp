#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>

//�������� 
void menu();
void OpenFile();
void search();
void add();
void save();
 
//������ 
int main()
{
	int choise =-1;
	while (choise !=0)
	{
		menu();
		std::cout<<"\t\t\t��ѡ��:";
		std::cin>>choise;
		switch(choise)
		{
			case 1:
				 OpenFile();    //����
			     break;
			case 2:
			     search();      //��ѯ 
				 break;
			case 3:
			     add();        //��� 
			     break;
			default:
			     break; 
		}
		 std::cout << std::endl;		
	}
	return 0;
}

//���˵�
void menu()
{
	
	std::cout << "\t\t\t  1.������ʾѧ����Ϣ   \n";
	std::cout << "\t\t\t  2.��ѯѧ����Ϣ   \n";
	std::cout << "\t\t\t  3.���ѧ����Ϣ   \n";
} 
//����1 
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
//��ѯ 2
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
	
	std::cout << "���������ѧ�ţ�";
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
//���3���� 
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
		
	std::cout << "������ѧ�ţ�";
	std::string num;std::cin >> num;
	std::cout << "������ɼ���";
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
