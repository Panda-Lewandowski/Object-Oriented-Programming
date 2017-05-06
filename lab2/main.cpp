#include <iostream>
#include "list.hpp"
#include "listitem.hpp"
#include "iteratorlist.hpp"
#include "_errors.h"

using namespace std;

int main()
{
    cout << "-------------------------------------------------------\n"
            "Тестирование класса ListItem\n"
            "-------------------------------------------------------\n";

    /*cout << "√ Тестирование контсрукторов √\n\n";

    listItem<int> item1;
    //item1.data = 10;
    cout << "• Конструктор по умолчанию • \n";
    cout << item1 << "\n";

    listItem<int> item2(10);
    listItem<double> item3(10.5);
    cout << "• Конструктор c параметрами • \n";
    cout << item2 << "\n";
    cout << item3 << "\n";

    listItem<double> item4(item3);
    cout << "• Конструктор копирования • \n";
    cout << item4 << "\n";

    cout << "√ Тестирование методов √\n\n";

    cout << "• Связываем первый и второй экземляры класса ListItem с помощью ф-ции set_next...\n";
    item1.set_next(item2);
    cout << item1 << "\n";

    cout << "• Связываем третий и четвертый экземляры \n";
    item3.set_next(item4);
    cout << item3 << "\n";

    cout << "• Какой же теперь экземпляр после первого?(ф-ция get_next)\n";
    cout << item1.get_next() << "\n";

    cout << "• Какой же теперь экземпляр после третьего?(ф-ция get_next)\n";
    cout << item3.get_next() << "\n";

    cout << "√ Тестирование операторов сравнения √\n\n";

    cout << "• Добавим еще пару экземпляров с типом int \n";
    listItem<int> item5(20);
    listItem<int> item6(0);
    listItem<int> item7(10);

    cout << "\nИтак, сравнивать будем: \n";
    cout << item2 << item5 << item6 << item7;

    cout << "\nitem#1 == item#4 ?\n";
    cout << (item2 == item7) << "\n\n";

    cout << "item#2 == item#4 ?\n";
    cout << (item5 == item7) << "\n\n";

    cout << "item#1 != item#4 ?\n";
    cout << (item2 != item7) << "\n\n";

    cout << "item#2 != item#3 ?\n";
    cout << (item5 != item6) << "\n\n";

    cout << "item#1 > item#3 ?\n";
    cout << (item2 > item6) << "\n\n";

    cout << "item#3 > item#1 ?\n";
    cout << (item6 > item2) << "\n\n";

    cout << "item#2 < item#3 ?\n";
    cout << (item5 < item6) << "\n\n";

    cout << "item#3 < item#2 ?\n";
    cout << (item6 < item5) << "\n\n";

    cout << "item#1 >= item#4?\n";
    cout << (item2 >= item7) << "\n\n";

    cout << "item#1 <= item#4 ?\n";
    cout << (item2 <= item7) << "\n\n";*/

    cout << "-------------------------------------------------------\n"
            "Тестирование класса List\n"
            "-------------------------------------------------------\n";
    try
    {
        cout << "√ Тестирование контсрукторов √\n\n";

        list<int> l1;
        cout << "• Конструктор по умолчанию • \n";
        cout << l1 << "\n";

        cout << "• Конструктор c параметрами • \n";
        list<double> l2((size_t) 5);
        list<int> l3(9, 5);
        cout << l2 << "\n" << l3 << "\n";
        int arr[5] = {5, 1, 7, 4, 0};
        list<int> l4(arr, 4);
        cout << l4 << "\n";


        cout << "• Конструктор копирования • \n";
        list<int> l5(l3);
        iterator_list<int> j(l4);
        iterator_list<int> k(l4);
        k += 3;
        list<int> l6(j, k);
        cout << l5 << "\n";
        cout << l6 << "\n";

        cout << "√ Тестирование методов √\n\n";

        cout << "• Размер списка из 4 элементов : "<< l4.size() << "\n" ;
        cout << "• Длина списка из 4 элементов : "<< l4.length() << "\n" ;

        cout << "• Пустой ли список, созданный конструктором по умолчанию?  "<< l1.is_empty() << "\n" ;
        l1.append(2);
        cout << "• Пустой ли он после добовления элемента? "<< l1.is_empty() << "\n" ;
        cout << l1;
        cout << "• Добавим к нему еще список •\n";
        l1.append(l4);
        cout << l1;


        cout << "• Вставим в начало поочередно число и список •\n";
        l1.insert_front(6);
        l1.insert_front(l4);
        cout << l1;

        cout << "• С помощью итератора вставим на 3 позицию элемент(10) и на 5 позицию список•\n";
        iterator_list<int> i(l1);
        i += 2;
        l1.insert_after(i, 10);
        cout << l1;

        i += 2;
        l1.insert_after(i, l4);
        cout << l1;

        cout << "• С помощью итератора вставим перед 6 позицией элемент(8) и список перед 7 позицией •\n";
        i += 1;
        l1.insert_before(i, 8);
        cout << l1;
        i += 1;
        l1.insert_before(i, l3);
        cout << l1;

        cout << "• Отсортируем список •\n";
        l1.sort();
        cout << l1;
        cout << "• ...И перевернем •\n";
        l1.reverse();
        cout << l1;

        cout << "• Превратим последний список в массив •\n";
        int* mass = l1.to_array();
        for(size_t i = 0; i < l1.length();  i++)
        {
            cout << mass[i] << " ";
        }

        cout << "\n";

        cout << "• Заменим в уникальном списке(множестве) второй элемент •\n";
        iterator_list<int> m(l4);
        m += 1;
        l4.reset(m, 777);
        cout << l4;
    }
    catch(baseError& e)
    {
        cout << endl << endl << e.what() << endl << endl;
    }

    return 0;
}
