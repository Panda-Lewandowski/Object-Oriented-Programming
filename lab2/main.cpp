#include <iostream>
#include "list.h"
#include "listitem.h"

using namespace std;

int main()
{
    cout << "-------------------------------------------------------\n"
            "Тестирование класса ListItem\n"
            "-------------------------------------------------------\n";

    cout << "√ Тестирование контсрукторов √\n\n";

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
    cout << (item2 <= item7) << "\n\n";

    cout << "-------------------------------------------------------\n"
            "Тестирование класса List\n"
            "-------------------------------------------------------\n";

    cout << "√ Тестирование контсрукторов √\n\n";

    list<int> l1;
    cout << "• Конструктор по умолчанию • \n";
    cout << l1 << "\n";

    cout << "• Конструктор c параметрами • \n";
    list<double> l2((size_t) 5);
    list<int> l3(9, 5);
    cout << l2 << "\n" << l3 << "\n";
    int arr[5] = {5, 1, 7, 4, 0};
    list<int> l4(arr, 5);
    cout << l4 << "\n";


    cout << "• Конструктор копирования • \n";
    list<int> l5(l3);
    list<int> l6(l3, 3);
    cout << l5 << "\n" << l6 << "\n";

    l4.sort();
    cout << l4;


    return 0;
}
