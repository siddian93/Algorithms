/*
// Pass by Reference

void process_2d_array_template(int (&array)[rows][cols])
{
    cout << __func__ << std::endl;
    for (size_t i = 0; i < rows; ++i)
    {
        cout << i << ": ";
        for (size_t j = 0; j < cols; ++j)
            cout << array[i][j] << '\t';
        cout << std::endl;
    }
}

//Pass by Pointer 
void process_2d_array_pointer(int (*array)[5][10])
{
    cout << __func__ << endl;
    for (size_t i = 0; i < 5; ++i)
    {
        cout << i << ": ";
        for (size_t j = 0; j < 10; ++j)
            cout << (*array)[i][j] << '\t';
        cout << std::endl;
    }    
}

//Pass by a (value) a pointer in case of Variable Size

void process_2d_array(int (*array)[10], size_t rows)
{
    cout << __func__ << std::endl;
    for (size_t i = 0; i < rows; ++i)
    {
        cout << i << ": ";
        for (size_t j = 0; j < 10; ++j)
            cout << array[i][j] << '\t';
        cout << std::endl;
    }
}

*/


#include<iostream>

using namespace std;

void foo3(char D[3][5], int rows){
    cout<<D[2][1]<< "Inside foo3" <<endl;
    D[2][1]  = 'V';

    cout<<sizeof(D)/sizeof(*D)<< " Rows" << endl;
    cout<<sizeof(*D)/sizeof(char)<< " Columns" << endl;
}

void foo1(char D[][5], int rows){ // Also Applicable in (*D)[N]
    //
    //cout<<"Inside Foo"<<endl;
    //cout<<A[2][3]<<endl;

    cout<<D[2][1]<< "Inside foo1" <<endl;
    D[2][1]  = 'F';

    //cout<<sizeof(D)/sizeof(*D)<< " Rows" << endl;
    //cout<<sizeof(*D)/sizeof(char)<< " Columns" << endl;

}


void foo(char (&D)[3][5], int rows){
    //
    //cout<<"Inside Foo"<<endl;
    //cout<<A[2][3]<<endl;

    cout<<D[2][1]<< "Inside foo" <<endl;
    D[2][1]  = 'U';
    //cout<<sizeof(D)/sizeof(*D)<< " Rows" << endl;
    //cout<<sizeof(*D)/sizeof(char)<< " Columns" << endl;

}

int main(){
    char A[][5] = {{'A', '2', '3', 'a', 'X'},
                  {'4', '5', '6', 'C', 'w'},
                  {'7', '8', '9', 'D', 'z'}
                  //{'R', 'Q', 'S', 'P'}
                 };
    for (int i = 0; i< 3; i++){
        for (int j = 0; j< 5; j++){
            cout<<A[i][j]<< " ";
        }
        cout<< endl;
    }
    
    //char A[3][10];
    //char** A;
    //A = new char*[3];
    //cout<<sizeof(A)/sizeof(*A)<< " Rows" << endl;
    //for (int i = 0; i< 3; i++){
    //    A[i] = new char[5];
    //}
    //A[10][15] = '1';
    //cout<< A[2][4] << endl;
    //cout<<sizeof(A)/sizeof(*A)<< " Rows" << endl;
    //cout<<sizeof(*A)/sizeof(**A)<< " Columns" << endl;
    foo(A, 3);
    for (int i = 0; i< 3; i++){
        for (int j = 0; j< 5; j++){
            cout<<A[i][j]<< " ";
        }
        cout<< endl;
    }
    foo1(A, 3);
    for (int i = 0; i< 3; i++){
        for (int j = 0; j< 5; j++){
            cout<<A[i][j]<< " ";
        }
        cout<< endl;
    }

    foo3(A, 3);
    for (int i = 0; i< 3; i++){
        for (int j = 0; j< 5; j++){
            cout<<A[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;

}