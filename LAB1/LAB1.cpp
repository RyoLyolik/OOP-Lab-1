// LAB1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Complex.h"
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "RUS");
    Complex x{2,3};
    Complex y{ -3,-2 };
    cout << "Числа: \n";
    x.write();
    y.write();

    cout << "\nУмножение: ";
    x.multiple(y).write();
    cout << "\nСумма: ";
    x.sum(y).write();
    cout << "\nВычитание: ";
    x.substract(y).write();
    cout << "\nДеление: ";
    x.devide(y).write();
    cout << endl << endl;
    ifstream fin("complex_numbers.txt");
    int n;
    if (!(fin >> n))
    {
        cout << "Error!";
        return 0;
    }
    Complex* p = new Complex[n];
    string temp;
    int temp_size;
    string temp_re;
    string temp_im;
    getline(fin, temp);
    bool check = false;
    string alphabet = "1234567890-.";
    for (int i = 0; i < n; i++)
    {
        check = false;
        getline(fin, temp);
        temp_size = temp.length();
        

        int temp_size = temp.length();
        int space_count = 0;
        string temp_re;
        string temp_im;
        double re;
        double im;
        bool first = false;
        bool second = false;
        for (int j = 0; j < temp_size; j++)
        {
            if (temp[j] == ' ')
            {
                space_count++;
            }
            if (space_count > 1)
            {
                break;
            }
        }
        if (space_count == 1)
        {
            bool move_to_im = false;
            for (int j = 0; j < temp_size; j++)
            {

                if (!move_to_im)
                {
                    if (temp[j] != ' ') {
                        temp_re += temp[j];
                    }
                    else
                    {
                        move_to_im = true;
                        continue;
                    }
                }
                else
                {
                    temp_im += temp[j];
                }
            }
        }
        if (temp_re.length() <= 0 || temp_im.length() <= 0)
        {
            continue;
        }
        else
        {
            int re_size = temp_re.length();
            bool is_num = true;
            bool dot = false;
            bool neg = false;
            for (int j = 0; j < re_size; j++)
            {
                if (alphabet.find(temp_re[j]) == string::npos)
                {
                    is_num = false;
                    break;
                }
                else if (temp_re[j] == '-' && j == 0 && !neg && j != re_size - 1)
                {
                    neg = true;
                    continue;
                }
                else if ((temp_re[j] == '-' && (j > 0 || j == re_size - 1)))
                {
                    is_num = false;
                    break;
                }

                else if (temp_re[j] == '.' && j > 0 && !dot && j != re_size - 1 && temp_re[j - 1] != '-')
                {
                    dot = true;
                }
                else if (temp_re[j] == '.' && dot)
                {
                    is_num = false;
                    break;
                }
                else if (temp_re[j] == '.' && (j == 0 || j == re_size - 1 || temp_re[j - 1] == '-'))
                {
                    is_num = false;
                    break;
                }
            }
            if (is_num)
            {
                first = true;
                re = stod(temp_re);
            }
            is_num = true;
            dot = false;
            neg = false;
            int im_size = temp_im.length();
            for (int j = 0; j < im_size; j++)
            {
                if (alphabet.find(temp_im[j]) == string::npos)
                {
                    is_num = false;
                    break;
                }
                else if (temp_im[j] == '-' && j == 0 && !neg && j != im_size - 1)
                {
                    neg = true;
                    continue;
                }
                else if ((temp_im[j] == '-' && (j > 0 || j == im_size - 1)))
                {
                    is_num = false;
                    break;
                }
                else if (temp_im[j] == '.' && j > 0 && !dot && j != im_size - 1 && temp_im[j - 1] != '-')
                {
                    dot = true;
                }
                else if (temp_im[j] == '.' && dot)
                {
                    is_num = false;
                    break;
                }
                else if (temp_im[j] == '.' && (j == 0 || j == im_size - 1 || temp_im[j - 1] == '-'))
                {
                    is_num = false;
                    break;
                }
            }

            if (is_num)
            {
                second = true;
                im = stod(temp_im);
            }

        }
        if (first && second)
        {
            p[i] = { re, im };
        }
    }
    Complex max_mod = p[0];
    for (int i = 0; i < n; i++)
    {
        if (max_mod.mod() < p[i].mod())
        {
            max_mod = p[i];
        }
    }
    max_mod.write();
    delete p;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
