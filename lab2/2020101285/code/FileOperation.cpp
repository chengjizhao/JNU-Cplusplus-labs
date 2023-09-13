#include "FileOperation.h"

/* 
@func   编码转换，GBK转UTF-8
@remark 由于vscode 终端显示字符编码格式为UTF-8，而csv数据文件字符编码格式为GBK，
        所以在vscode终端显示中文字符时需要转码,若在powershell终端编译运行，则不需要转码
@para   GBK编码字符(串)
@ret    UTF-8编码字符(串)
*/
string GbkToUtf8(const char *src_str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}

/* 
@func   编码转换，UTF-8转GBK
@remark 若将vscode输入的中文字符写入csv文件，要先转为GBK编码格式
@para   UTF-8编码字符(串)
@ret    GBK编码字符(串)
*/
string Utf8ToGbk(const char *src_str)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}

/*
@func    字符串分割
@para1   待分割长字符串
@para2   分割标志字符
@ret     分割后子字符串数组，不包含标志字符delim
*/
vector<string>stringSplit(const string str,char delim){
    stringstream ss;
    ss<<str;
    string item;
    vector<string>elems;
    while (getline(ss,item,delim))
    {
        if(!item.empty()){
            elems.push_back(item);
        }
    }
    return elems;
}

/*
@func   读取文件
@para   链表头Head(以链表数据结构接收存储数据)
@ret    success：0    fail:other value
*/
int readFile(linkstudent Head){

    if(Head==NULL){
        cout<<"Head is NULL!"<<endl;
        return 1;
    }
    linkstudent N,p;
    p=Head;
    ifstream ifs;
    ifs.open("student_data.csv",ios::in);
    if(ifs.is_open()){
        string buf;
        int count=0;
        ifs>>buf;
        while (ifs>>buf)
        {            
            //buf=GbkToUtf8(buf.c_str());
            vector<string>strArray=stringSplit(buf,',');    
            N=new student;
            if (N==NULL)
            {
                cout<<"malloc failed!"<<endl;
                return 1;
            }
            p->Next=N;
            p=N;
            p->id=stoi(strArray[0]);//string to int
            p->name=strArray[1];
            p->major=strArray[4];
            p->labScore=new score_t[LABNUM];
            for (int i = 0; i < LABNUM; i++)
            {
                *(p->labScore+i)=stof(strArray[10+i]);
            }
            p->totalScore=stof(strArray[28]);
            p->Next=NULL;
        } 

    }else{
        cout<<"failed to open the file"<<endl;
        return 1;
    }
    return 0;
}

/*
@func   打印出所有学生的所有信息(文件数据)
@ret    success: 0    failed: 1
*/
int viewAll(){
    ifstream ifs;
    ifs.open("student_data.csv",ios::in);
    if(ifs.is_open()){
        string buf;
        while (ifs>>buf)
        {            
            buf=GbkToUtf8(buf.c_str());
            cout<<buf<<endl; 
        }
    }else{
        cout<<"viewAll() : failed to open the file"<<endl;
        return 1;
    }
    return 0;
}

/*
@func    根据学生学号查询对应的实验课成绩和总成绩
@para1   数据链表头
@para2   学号
@para3   接收数组
@ret     success: 0    failed: 1
*/
int viewScore(linkstudent H,id_t id,score_t* labscore){
    linkstudent p=H->Next;
    while ( p != NULL )
    {
        if (p->id == id)
        {
            for (int i = 0; i < LABNUM; i++)
            {
                labscore[i]=p->labScore[i];
            }
            labscore[LABNUM]=p->totalScore;
            return 0;
        }
        p=p->Next;        
    }
    cout<<"该学号不存在！"<<endl;
    return 1;
}

/*
@func    按学号写入指定实验课的成绩
@para1   学号
@para2   第几次实验课
@para3   待录入成绩
@ret     success: 0    failed: 1
*/
int writelabScore(id_t id , int courseNum , score_t score){

    if (courseNum<1||courseNum>LABNUM)
    {
        cout<<"请选择范围为1~18的实验课次"<<endl;
        return 1;
    }
    
    //把文件读取出来，修改后放到容器vector<string> buf中
    ifstream ifs;
    vector<string> buf;
    ifs.open("student_data.csv",ios::in);
    if(ifs.is_open())
    {
        string line;
        ifs>>line;
        //line=GbkToUtf8(line.c_str());        
        buf.push_back(line);
        bool flag =false;
        while (ifs>>line)
        {
            //line=GbkToUtf8(line.c_str());
            vector<string>strArray;
            strArray = stringSplit(line,',');
 
            if (stoi(strArray[0]) == id){
                flag = true;
                ostringstream temp;
                temp << fixed << setprecision(2) << score;//保留2位小数
                strArray[9+courseNum]=temp.str();
                line="";
                for (const auto& s : strArray) {
                    line +=s+",";
                }
                buf.push_back(line);
            }else{
                buf.push_back(line);
            }
        }
        if (!flag)
        {
            cout<<"该学号不存在！"<<endl;
            return 1;
        }      
    }
    else
    {
        cout<<"failed to open the file for read"<<endl;
        return 1;
    }
    ifs.close();

    //把buf数据一次性写入
    ofstream ofs;
    ofs.open("student_data.csv",ios::trunc);
    if(ofs.is_open()){
        for (const auto& b : buf) {
            ofs<<b<<endl;
        }
    }else
    {
        cout<<"failed to open the file for write"<<endl;
        return 1;
    }
    ofs.close();
    return 0;
}

/*
@func   按每次实验课平均分求总成绩，更新文件
@para   链表头地址
*/
void calculateScore(linkstudent H){

    linkstudent p;
    p=H->Next;
    //把文件读取出来，修改后放到容器vector<string> buf中
    ifstream ifs;
    vector<string> buf;
    ifs.open("student_data.csv",ios::in);
    if(ifs.is_open())
    {       
        string line;
        ifs>>line;
        //line=GbkToUtf8(line.c_str());        
        buf.push_back(line);
        while (ifs>>line)
        {
            score_t totalScore=0;
            for (int i = 0; i < LABNUM; i++)
            {
                totalScore =totalScore + p->labScore[i];
            }
            p->totalScore = totalScore/LABNUM;
            cout<<GbkToUtf8((p->name).c_str())<<"最终成绩："<<p->totalScore<<endl;             
            //line=GbkToUtf8(line.c_str());
            vector<string>strArray;
            strArray = stringSplit(line,',');
            ostringstream temp;
            temp << fixed << setprecision(2) << p->totalScore;//保留2位小数
            strArray[28]=temp.str();
            line="";
            for (const auto& s : strArray) {
                line +=s+",";
            }
            buf.push_back(line); 
            p = p->Next;
        }
    }
    else
    {
        cout<<"failed to open the file for read"<<endl;
        return;
    }
    ifs.close();

    //把buf数据一次性写入
    ofstream ofs;
    ofs.open("student_data.csv",ios::trunc);
    if(ofs.is_open()){
        for (const auto& b : buf) {
            ofs<<b<<endl;
        }
    }else
    {
        cout<<"failed to open the file for write"<<endl;
        return;
    }
    ofs.close();    

}