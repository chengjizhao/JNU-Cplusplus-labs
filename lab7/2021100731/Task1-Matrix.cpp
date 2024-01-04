#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


class Matrix
{
private:
    int row_;       //行数
    int column_;    //列数
    bool dimension_error_flag = 0;   //出现维度错误则此项置1
    vector<float> mat_;

    /***************************************************
    *初始化:当出现维度错误的计算时,用此重载实例化对象,将维度错误标志位置1
    ***************************************************/
    Matrix(int flag)
    {
        dimension_error_flag = 1;
        row_ =    0;
        column_ = 0;
    }

public:
    /***************************************************
    *初始化:row*column的矩阵,矩阵元素的值由一个数组传入
    ***************************************************/
    Matrix(int row, int column , float* mat)
    {   
            row_    = row;
            column_ = column ;
            for(int i=0; i<row_*column_; i++)
            {
                mat_.push_back(mat[i]);
                //cout << mat_[i] << endl;
            }
    }

    /***************************************************
    *初始化:2*2的零矩阵
    ***************************************************/
    Matrix()
    {
        row_    = 2;
        column_ = 2;
        for(int i=0; i<4; i++){
        mat_.push_back(0);}
    }

    /***************************************************
    *功能简介：加法重载
    ***************************************************/
    Matrix operator+(Matrix& other)
    {
        if((row_ == other.row_) && (column_ == other.column_))
        {
            float save[row_*column_];
            for(int i=0; i<row_*column_; i++)
            {
                save[i] = mat_[i] + other.mat_[i];
            }

            return Matrix(row_, column_, save);
        }
        else
        {
            cout << "dimension ERROR!" << endl;
            return Matrix(1);
        }
    }

    /***************************************************
    *功能简介：减法重载
    ***************************************************/
    Matrix operator-(Matrix& other)
    {
        if((row_ == other.row_) && (column_ == other.column_))
        {
            float save[row_*column_];
            for(int i=0; i<row_*column_; i++)
            {
                save[i] = mat_[i] - other.mat_[i];
            }

            return Matrix(row_, column_, save);
        }
        else
        {
            cout << "dimension ERROR!" << endl;
            return Matrix(1);
        }
    }

    /***************************************************
    *功能简介：乘法重载
    ***************************************************/
    Matrix operator*(Matrix& other)
    {
        if(other.row_ == column_)
        {
            float save[row_*other.column_];
            float element = 0;
            int array = 0;
            vector<float> buffer;

            for(int row1=0; row1<row_; row1++)
            {
                for(int column1=0; column1<column_; column1++)
                {
                    buffer.push_back(mat_[column1+column_*row1]);
                }
            
                for(int column2=0; column2<other.column_; column2++)
                {
                    for(int row2=0; row2<other.row_; row2++)
                    {
                        element = element + buffer[row2] * other.mat_[column2+other.column_*row2];
                    }
                    save[array] = element;
                    element = 0;
                    array++;
                }
                buffer.clear();
            }
            return Matrix(row_, other.column_, save);
        }
        else
        {
            cout << "dimension ERROR!" << endl;
            return Matrix(1);
        }
    }

    /***************************************************
    *功能简介：友员重载<<实现cout直接输出矩阵
    ***************************************************/
    friend ostream& operator<<(ostream &cout, Matrix &mat)
    {
	    if(mat.dimension_error_flag == 0)
            {
                int arr = 0;
                for(int row=0; row<mat.row_; row++)
                {
                    cout << left << setw(3) << "|";
                    for(int column=0; column<mat.column_; column++)
                    {
                        cout << left << setw(3) << mat.mat_[arr] << "  ";
                        arr++;
                    }
                    cout << left << setw(3) << "|" << endl;
                }
            }
            else if(mat.dimension_error_flag == 1)
            {
                cout << "dimension ERROR! Could not print!" << endl;
            }
	    return cout;
    }

};


int main()
{
    float dummy1[] = {1,2,3,4,5,6,7,8,9,10};
    float dummy2[] = {1,1,1,1,1,1,1,1,1,1};
    float dummy3[] = {1,9,2,8,3,7,4,6,5,5,1,3};
    Matrix A(5,2,dummy1);
    Matrix B(5,2,dummy2);
    Matrix C(2,6,dummy3);
    cout << "MatrixA:" << endl;
    cout << A;
    cout << "MatrixB:" << endl;
    cout << B;
    cout << "MatrixC:" << endl;
    cout << C;

    Matrix plus = A+B;
    Matrix minus = A-B;
    Matrix multiply = A*C;
    cout << "A+B=" << endl;
    cout << plus;
    cout << "A-B=" << endl;
    cout << minus;
    cout << "A*C=" << endl;
    cout << multiply;
    
    return 0;
}


