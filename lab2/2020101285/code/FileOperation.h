#ifndef _IOFILEDATA_H
#define _IOFILEDATA_H

#define LABNUM 18

#include<sstream>
#include <iostream>
#include<fstream>
#include<vector>
#include <iomanip>
#include<windows.h>


using namespace std;

//定义数据类型
typedef int    id_t;
typedef string   name_t;
typedef float  score_t;
typedef string   major_t;

//定义学生信息结构体节点
typedef struct node{
    id_t id;
    name_t name;
    major_t major;
    score_t* labScore;
    score_t totalScore;
    struct node* Next;
}*linkstudent,student;

int readFile(linkstudent Head);
int viewAll();
int viewScore(linkstudent H,id_t id,score_t* labscore);
int writelabScore(id_t id , int courseNum , score_t score);
void calculateScore(linkstudent H);


#endif