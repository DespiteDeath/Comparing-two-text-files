#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file1,file2;
    file1.open("INSERT_FULL_PATH_TO_YOUR_TEXTFILE_ONE.txt",ios::binary);
    file2.open("INSERT_FULL_PATH_TO_YOUR_TEXTFILE_TWO.txt",ios::binary);

    int c1,c2;
    c1 = 0; c2 = 0;
    string str;
    while(!file1.eof())
    {
        getline(file1,str);
        c1++;
    }

    file1.clear();
    file1.seekg(0,ios::beg);

    while(!file2.eof())
    {
        getline(file2,str);
        c2++;
    }
    file2.clear();
    file2.seekg(0,ios::beg);

    if(c1 != c2)
    {
        cout << "Разница в кол-ве строк файлов!" << "\n";
        cout << "У 1-ого файла " << c1 << " строки, а у 2-ого "
             << c2 << " строки" << "\n";
    }

    char string1[256], string2[256];
    int i = 0;
    while(!file1.eof())
    {
        file1.getline(string1,256);
        file2.getline(string2,256);
        i++;
        if(strcmp(string1,string2) != 0)
        {
            cout << i << "-ая строка отличается" << "\n";
            cout << "   " << string1 << " - в первом файле \n";
            cout << "   " << string2 << " - во втором файле\n";
        }
    }

    return 0;
}