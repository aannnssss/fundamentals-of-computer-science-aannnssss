**Отчёт по лабораторной работе №10 по курсу** 

**«Фундаментальная информатика»** 

Студент группы: М80-108Б-22, Старостина Анна Андреевна, № по списку: 20 Контакты: <starostina-anuta@mail.ru> 

Работа выполнена: «12» ноября 2022 г. Преподаватель: Сахарин Никита Андреевич Входной контроль знаний с оценкой: 

Отчёт сдан: « 12 » ноября 2022 г. Итоговая оценка: 

Подпись преподавателя:    

1. **Тема:** Отладчик системы программирования OC UNIX.** 
1. **Цель  работы:**  Изучить  отладчик  программирования**  OC  UNIX  и  сделать  все описанные  действия  над  некоторой  программой  на  изучаемом  языке программирования, в том числе со специальными ошибками.** 
1. **Задание:** Найти некоторую программу и проделать все ниже описанные действия, тем самым знакомясь с отладчиком OC UNIX. 
1. **Оборудование:**  

**Ноутбук Macbook Pro  Процессор:** apple m2  **Монитор:** 2560х1600 

5. **Программное обеспечение:**  

Операционная система семейства: Linux Ubuntu 22.04.1 Интерпретатор команд: bash 5.0.17(1) 

Система программирования:  

Редактор текстов: emacs 

Утилиты операционной системы: команды gcc Прикладные системы и программы: 

Местонахождение и имена файлов программ и данных: 

6. **Идея, метод, алгоритм решения задачи** 

В  формах:  словесной,  псевдокода,  графической  [блок  схема,  диаграмма,  рисунок, таблица] или формальные спецификации с пред- и постусловиями. 

1. Была использована программа 09.с. Была запущена и правильно скомпилирована. 
1. Поставлена  точка  остановы  на  некоторых  строках,  запущена  программа,  затем выведено количество поставленных точек, затем их удалили. 
1. Выведено несколько переменных, опять поставлена точка остановы и выполнена очередная строка. 
7. **Сценарий выполнения работы:** 

[План работы, первоначальный текст программы в черновике ( можно на отдельном листе) и тесты либо соображения по тестированию] 

1.Была изучена теория по отладчику в OC UNIX. 2.Были протестированы навыки по изученному 3.Написание отчёта.* 

8. **Распечатка протокола**  

Подклеить  листинг  окончательного  варианта  программы  с  тестовыми  примерами, подписанный преподавателем. 
```
ann@ann:~$ gcc -g -o program 09.c 

ann@ann:~$ gdb ./program 

GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90 

Copyright (C) 2022 Free Software Foundation, Inc. 

License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> This is free software: you are free to change and redistribute it. 

There is NO WARRANTY, to the extent permitted by law. 

Type "show copying" and "show warranty" for details. 

This GDB was configured as "aarch64-linux-gnu". 

Type "show configuration" for configuration details. 

For bug reporting instructions, please see: <https://www.gnu.org/software/gdb/bugs/>. 

Find the GDB manual and other documentation resources online at: 

`    `<http://www.gnu.org/software/gdb/documentation/>. 

For help, type "help". 

Type "apropos word" to search for commands related to "word"... 

Reading symbols from ./program... 

(gdb) r 

Starting program: /home/ann/program  

[Thread debugging using libthread\_db enabled] 

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1". 

The point did not fall into the specified area. End coordinates: (1,0),dynamic motion parameter: 19, steps: 50. 

[Inferior 1 (process 7575) exited normally] 

(gdb) help 

List of classes of commands: 

aliases -- User-defined aliases of other commands. breakpoints -- Making program stop at certain points. data -- Examining data. 

files -- Specifying and examining files. 

internals -- Maintenance commands. 

obscure -- Obscure features. 

running -- Running the program. 

stack -- Examining the stack. 

status -- Status inquiries. 

support -- Support facilities. 

text-user-interface -- TUI is the GDB text based interface. 

tracepoints -- Tracing of program execution without stopping the program. user-defined -- User-defined commands. 

Type "help" followed by a class name for a list of commands in that class. Type "help all" for the list of all commands. 

Type "help" followed by command name for full documentation. 

Type "apropos word" to search for commands related to "word". 

Type "apropos -v word" for full documentation of commands related to "word". Command name abbreviations are allowed if unambiguous. 

(gdb) list 

5     return a - (a / b) \* b; 

6 } 

7      

8      

9 int min(int a, int b) { 

10     return a < b ?  a : b; 

11 } 

12  

13  

14 int max(int a, int b) { 

(gdb) break 20 if k=6 

Breakpoint 1 at 0xaaaaaaaa07f8: file 09.c, line 20. 

(gdb) break 31 if i=5 

Breakpoint 2 at 0xaaaaaaaa0870: file 09.c, line 31. 

(gdb) run 

Starting program: /home/ann/program  

[Thread debugging using libthread\_db enabled] 

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1". 

Breakpoint 1, main () at 09.c:20 

20     while (k <= 50) { 

(gdb) next 

21         if (k == 50) { 

(gdb) next 

25         if  ( (i + j + 10 <= 0) && (i + j + 20 >= 0)) { 

(gdb) next 

29         i1 = i; 

(gdb) run 

The program being debugged has been started already. 

Start it from the beginning? (y or n) y 

Starting program: /home/ann/program  

[Thread debugging using libthread\_db enabled] 

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1". 

Breakpoint 1, main () at 09.c:20 

20     while (k <= 50) { 

(gdb) step 

21         if (k == 50) { 

(gdb) step 

25         if  ( (i + j + 10 <= 0) && (i + j + 20 >= 0)) { 

(gdb) step 

29         i1 = i; 

(gdb) info breakpoints 

Num     Type           Disp Enb Address            What 

1       breakpoint     keep y   0x0000aaaaaaaa07f8 in main at 09.c:20 

` `stop only if k=6 

` `breakpoint already hit 1 time 

2       breakpoint     keep y   0x0000aaaaaaaa0870 in main at 09.c:31 

` `stop only if i=5 

(gdb) delete 1-2 

(gdb) run 

The program being debugged has been started already. 

Start it from the beginning? (y or n) y 

Starting program: /home/ann/program  

[Thread debugging using libthread\_db enabled] 

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1". 

The point did not fall into the specified area. End coordinates: (1,0),dynamic motion parameter: 19, steps: 50. 

[Inferior 1 (process 7704) exited normally] 

(gdb) print buffer 

$1 = '\000' <repeats 29 

(gdb) ptype k 

No symbol "k" in current context. 

(gdb) break 20 if k=6 

Breakpoint 3 at 0xaaaaaaaa07f8: file 09.c, line 20. 

(gdb) run 

Starting program: /home/ann/program  

[Thread debugging using libthread\_db enabled] 

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1". 

Breakpoint 3, main () at 09.c:20 

20     while (k <= 50) { 

(gdb) continue 

Continuing. 

The point did not fall into the specified area. End coordinates: (1,0),dynamic motion parameter: 19, steps: 50. 

[Inferior 1 (process 7836) exited normally] 

(gdb) quit 

ann@ann:~$
```
9. **Дневник отладки** 

Должен  содержать  дату  и  время  сеансов  отладки  и  основные  события  (ошибки  в сценарии и программе, нестандартные ситуации) и краткие комментария к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании отладки программы. 



|**№**|**Лаб. Или дом.**|**Дата**|**Время**|**Событие**|**Действие по направлению**|**Примечание**|
| - | - | - | - | - | - | - |
|1|Дом|12.11|21:00|Сдача лабораторной работы|интернет||
10. **Замечания автора по существу работы:** 

Была запущена программа, правильно скомпилирована, поставелена точка остановы на определенной строке под определенным условием** 
```
ann@ann:~$ gcc -g -o program 09.c

ann@ann:~$ gdb ./program

GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90

Copyright (C) 2022 Free Software Foundation, Inc.

License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> This is free software: you are free to change and redistribute it.

There is NO WARRANTY, to the extent permitted by law.

Type "show copying" and "show warranty" for details.

This GDB was configured as "aarch64-linux-gnu".

Type "show configuration" for configuration details.

For bug reporting instructions, please see: <https://www.gnu.org/software/gdb/bugs/>.

Find the GDB manual and other documentation resources online at:

`    `<http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".

Type "apropos word" to search for commands related to "word"... Reading symbols from ./program...

(gdb) break 20 if k=10

Breakpoint 1 at 0x7f8: file 09.c, line 20.

(gdb) run

Starting program: /home/ann/program 

[Thread debugging using libthread\_db enabled]

Using host libthread\_db library "/lib/aarch64-linux-gnu/libthread\_db.so.1".

Breakpoint 1, main () at 09.c:20 20     while (k <= 50) {

(gdb) quit

A debugging session is active.

` `Inferior 1 [process 6648] will be killed.

Quit anyway? (y or n) y ann@ann:~$
```
11. **Выводы:** 

Благодаря лабораторной работе был изучен отладчик OC UNIX и приобретено умение выполнять  с  помощью  него  базовые  операции  по  проверке  работоспособности программы,  что  может  очень  помочь  в  будущем.  Им  действительно  удобно пользоваться, ведь если программа очень большая, а специалист не видит ошибку, то он  может  проверять  работы  своей  программы  по  маленьким  пунктам,  и  таким образом он сможет заметить свою ошибку. 

Недочёты  при  выполнении  задания  могут  быть  выполнены  следующим  образом: использовать интерпретаторы. 

Подпись студета: 
