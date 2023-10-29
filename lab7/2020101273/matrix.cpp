#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
public:
    Matrix(vector<vector<int>> d) : data(d){}

        Matrix operator+(Matrix& other) {
            vector<int> one;
            vector<vector<int>> two;
            for (int i = 0; i < data.size(); i ++)
            {
                for (int j = 0; j < data[i].size(); j ++)
                {
                    one.push_back(data[i][j] + other.data[i][j]);
                }
                two.push_back(one);
                one.clear();
            }
            return Matrix(two);
        }
        
        Matrix operator-(Matrix& other) {
            vector<int> one;
            vector<vector<int>> two;
            for (int i = 0; i < data.size(); i ++)
            {
                for (int j = 0; j < data[i].size(); j ++)
                {
                    one.push_back(data[i][j] - other.data[i][j]);
                }
                two.push_back(one);
                one.clear();
            }
            return Matrix(two);
        }
        
        Matrix operator*(Matrix& other) {
            vector<int> one;
            vector<vector<int>> two;
            for (int i = 0; i < data.size(); i ++)
            {
                for (int k = 0; k < data.size(); k ++)
                {
                    int sum = 0;
                    for (int j = 0; j < data[i].size(); j ++)
                    {
                        sum += data[i][j] * other.data[j][k];
                    }
                    one.push_back(sum);
                }
                two.push_back(one);
                one.clear();
            }
            return Matrix(two);
        }

        friend ostream& operator<<(ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.data.size(); i ++)
            {   os << "{" ;
                for (int j = 0; j < matrix.data[i].size(); j ++)
                {
                    os << matrix.data[i][j] << " ";
                }
				os << "}" << endl;
            }
            return os;
        }


private:
    vector< vector<int> >data;
};

int main()
{
    vector< vector<int> >data1 ={{5, 2},{7, 4},{5, 6}};
	vector< vector<int> >data2 ={{1, 2, 3},{4, 5, 6}};
    vector< vector<int> >data3 ={{1, 2},{2, 5},{5, 6}};

	Matrix D1(data1);
	Matrix D2(data2);
	Matrix D3(data3);
    cout << D1 << endl ; cout << D2 << endl;
    
	Matrix sum = D1 + D3;
    cout << "D1 + D3:" << endl;
    cout << sum << endl;

    Matrix divide = D1 -D3;
    cout << "D1 - D3:" << endl;
    cout << divide << endl;

    Matrix multiplies = D1 * D2;
    cout << "D1 * D2:" << endl;
    cout << multiplies << endl;
}