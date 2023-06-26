# Отчёт по лабораторной работе №24 по курсу “Языки и методы программирования

<b>Студент группы:</b> <ins>М80-108Б-22 Старостина Анна Андреевна, № по списку 18</ins>

<b>Контакты e-mail:</b> <ins>st4ro5tinaa@yandex.ru</ins>

<b>Работа выполнена:</b> «9» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «12» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Арифметические выражения с применением деревьев.
## 2. Цель работы
Составить программу выполнения задашных преобразований арифметических выражений с применением деревьев. Преобразование выражения в дерево рекомендуется осуществлять одним из известных методов (Рутисхаузера, Дейкетры и др.). Операнды в обрабатываемых выражениях могут быть целого или веще- ствеппого типа ( п оусмотрепию преподавателя). Задапия могут быть переформулированы и для булевско- го типа. Преобразование выражения реализовать в виде набора подпрограмм. Программа должна вводить и печатать выражения в исходном (текстовом) виде, преобразовывать их в деревья, выполнять заданные преобразования путем обращения к подпрограммам и печатать результаты в виде дерева и в текстовом представлепии.
Для некоторых задач приводятся примеры, поясняющие постаповку задачи. В примерах слева от стрелки приводится фрагмент выражения до, а справа- после выполнения преобразования. Программа должна обрабатывать все вхождения сходных фрагмептов в апализируемых выражениях, а пе только те, что приведепы в примерах.
Программу пеобходимо проверить па пескольких выражениях, среди которых должны быть выра- жения, не содержащие преобразуемых элемептов, содержащие ровно один такой элемепт или песколько элемептов, подлежащих преобразованию, причем в «разных» местах дерева.
## 3. Задание (вариант № 18)
Вынести из произведений унарные минусы
## 4. Оборудование
<b>Ноутбук:</b> Macbook Pro M2

<b>ОП:</b> 8 gb

<b>SSD:</b> 512 gb SSD

<b>Монитор:</b> 2560x1600

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Ubuntu UTM 19.36.34

<b>Интерпретатор команд:</b> bash

<b>Система программирования:</b> -

<b>Редактор текстов:</b> -

<b>Утилиты операционной системы:</b> 

<b>Прикладные системы и программы:</b> -

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> ann@ann

## 6. Идея, метод, алгоритм решения задачи (в формах: слове сной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Будем использовать три обхода, печатать дерево выражений, размер дерева и выражение после преображений.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```
CC=gcc
RM=rm -fr
CFLAGS=-g
OBJECTS=tree.o
EXECUTABLE=program

all: tree.o
    $(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) -lm

tree.o: tree.c tree.h
    $(CC) $(CFLAGS) -c tree.c

clean:
    $(RM) $(EXECUTABLE) $(OBJECTS)
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 


```
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ make
gcc -g -c tree.c
gcc -g -o program tree.o -lm
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ valgrind --leak-check=full ./program
==10265== Memcheck, a memory error detector
==10265== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10265== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10265== Command: ./program
==10265== 
Enter the expression:
a*3
Expression tree:
    a
*
    3.00
Tree size: 3

Prefix traversal: * a 3.00 
Infix traversal: a * 3.00 
Postfix traversal: a 3.00 * 
Simplified expression:
a * 3.00
Input value:
3
Result: 9.00
==10265== 
==10265== HEAP SUMMARY:
==10265==     in use at exit: 0 bytes in 0 blocks
==10265==   total heap usage: 5 allocs, 5 frees, 2,168 bytes allocated
==10265== 
==10265== All heap blocks were freed -- no leaks are possible
==10265== 
==10265== For lists of detected and suppressed errors, rerun with: -s
==10265== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ make
gcc -g -c tree.c
gcc -g -o program tree.o -lm
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ valgrind --leak-check=full ./program
==10277== Memcheck, a memory error detector
==10277== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10277== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10277== Command: ./program
==10277== 
Enter the expression:
3*a*(-9)
Expression tree:
        3.00
    *
        a
*
    -9.00
Tree size: 5

Prefix traversal: * * 3.00 a -9.00 
Infix traversal: 3.00 * a * -9.00 
Postfix traversal: 3.00 a * -9.00 * 
Simplified expression:
-(3.00 * a * 9.00)
Input value:
1
Result: -27.00
==10277== 
==10277== HEAP SUMMARY:
==10277==     in use at exit: 0 bytes in 0 blocks
==10277==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==10277== 
==10277== All heap blocks were freed -- no leaks are possible
==10277== 
==10277== For lists of detected and suppressed errors, rerun with: -s
==10277== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ valgrind --leak-check=full ./program
==10278== Memcheck, a memory error detector
==10278== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10278== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10278== Command: ./program
==10278== 
Enter the expression:
-8*a*(-9)
Expression tree:
        -8.00
    *
        a
*
    -9.00
Tree size: 5

Prefix traversal: * * -8.00 a -9.00 
Infix traversal: -8.00 * a * -9.00 
Postfix traversal: -8.00 a * -9.00 * 
Simplified expression:
8.00 * a * 9.00
Input value:
1
Result: 72.00
==10278== 
==10278== HEAP SUMMARY:
==10278==     in use at exit: 0 bytes in 0 blocks
==10278==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==10278== 
==10278== All heap blocks were freed -- no leaks are possible
==10278== 
==10278== For lists of detected and suppressed errors, rerun with: -s
==10278== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ valgrind --leak-check=full ./program
==10279== Memcheck, a memory error detector
==10279== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10279== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10279== Command: ./program
==10279== 
Enter the expression:
a*(-9)*(2)
Expression tree:
        a
    *
        -9.00
*
    2.00
Tree size: 5

Prefix traversal: * * a -9.00 2.00 
Infix traversal: a * -9.00 * 2.00 
Postfix traversal: a -9.00 * 2.00 * 
Simplified expression:
-(a * 9.00 * 2.00)
Input value:
-2
Result: 36.00
==10279== 
==10279== HEAP SUMMARY:
==10279==     in use at exit: 0 bytes in 0 blocks
==10279==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==10279== 
==10279== All heap blocks were freed -- no leaks are possible
==10279== 
==10279== For lists of detected and suppressed errors, rerun with: -s
==10279== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
ann@ann:~/\u0417\u0430\u0433\u0440\u0443\u0437\u043a\u0438/fundamentals-of-computer-science-aannnssss/2sem/lab24$ 

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 09.06.23 | 08:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы 

[online div3 881А](https://codeforces.com/contest/1843/submission/210418396)  
[later div3 881B](https://codeforces.com/contest/1843/submission/210735894)  

## 11. Выводы

Благодаря лабораторной работе, были изучены деревья выражений в си, были реализованы 3 обхода и выполнено задание своего варианта.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


