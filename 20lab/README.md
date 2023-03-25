# Отчёт по лабораторной работе №20 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Старостина Анна Андреевна, № по списку 18</ins>

<b>Контакты e-mail:</b> <ins>st4ro5tinaa@yandex.ru</ins>

<b>Работа выполнена:</b> «16» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «25» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Стандартные утилиты UNIX для обработки файлов
## 2. Цель работы
Изучить основные команды обработки текстовых файлов ОС UNIX
## 3. Задание (вариант № 18)
Подготовить нетривиальные текстовые файлы для иллюстрации работы 3-х утилит (16 - nroff, 27 - patch, 29 - du). Запротоколировать подготовленные примеры и иллюстрации работы для минимум 20-ти утилит пакетного режима с распечаткой используемых текстовых файлов
## 4. Оборудование:
<b>Ноутбук:</b> Macbook Pro M2

<b>ОП:</b> 8 gb

<b>SSD:</b> 512 gb SSD

<b>Монитор:</b> 2560x1600

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> MAC OS

<b>Интерпретатор команд:</b> 

<b>Система программирования:</b> -

<b>Редактор текстов:</b> -

<b>Утилиты операционной системы:</b> cmp, comm, wc, diff, grep, sort, tail, tee, sum, cut, tar, gzip, bzip2, head, iconv, touch, df, dd, paste, mktemp, nroff, du, patch

<b>Прикладные системы и программы:</b> -

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> annastarostina@MacBook-Pro-Anna 20lab

## 6. Идея, метод, алгоритм решения задачи (в формах: слове сной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

| Команда |  Базовый синтакис | Флаги | Описание |
| ------ | ------ | ------ | ------ |
| nroff | nroff [параметры] <файл> |  "-np" - Начало номера страницы (установить номер первой страницы = p); "-op" - Специальные страницы (распечатать только страницы с номерами, заданными в списке "-o7" - Напечатать только страницу 7, "-o3,9,18" - Напечатать страницы 3, 9 и 18, "-o11-13,22" - Напечатать страницы с 11-13 и 22, "-o-5" - Напечатать страницы с 1-5, "-o14-" - Напечатать страницы от 14 до конца документа); "-sn" - Остановка вывода между страницами (делать останов после печати каждых n- строк, "-s" - останавливать печать после каждой страницы, "-s3" - останавливать печать каждой 3-й страницы); "-Tname" - Определение печатающего устройства; ".pl" — Длина страницы; ".ll" — Длина строки; ".po" — Отступ страницы; ".pn" — Номер страницы; ".bp" — Смена страницы; ".ne" — Дополнительное требование (сохранение целостности строк); ".sp" — Вывод пустой строки; ".cen" — Центрировать строку или n строк; ".ul" — Подчеркнуть заголовок; ".cu" — Непрерывное подчеркивание; ".tin" — Временный отступ; ".br" — Переход на следующую строку; ".in n" — Сделать отступ на n позиций | команда позволяет управлять процессом форматирования текстов, в частности задавать размер страницы, длину строк и интервал между строками, а также делать отступы и выполнять табулирование. Можно также устанавливать режим с заполнением строк (с выравниванием по правому краю). Программа nroff предназначена для обычных печатающих устройств. Данные, передаваемые для обработки nroff содержат текст документа и инструкции (или запросы), описывающие, в каком виде должен быть распечатан этот текст. Запросы форматора nroff, начинаются со специальной -точки ( . ) и должны быть записаны строчными буквами в отдельной строке и с первой позиции. Форматирующие макрозапросы вставляются прямо в текст документа.|
| du | du [параметры] <путь/до/директории> |Использование с командой du опции -h предоставляет результаты в формате, понятном человеку. Имеется ввиду, что размеры будут представлены в байтах, килобайтах, мегабайтах, гигабайтах и т.д.;  чтобы узнать общий размера директории, т.е. сколько место занимает папка и её подпапки, используется опция -s;Использование с командой du флага -a отображает использование диска всеми файлами, а не только каталогами;Использование флага -a вместе с -h отображает использование диска всеми файлами и папками в понятном для человека формате. Вывод ниже легче для восприятия, поскольку он показывает размеры в килобайтах, мегабайтах и т.д.; для определения использования диска деревом директории с её поддеревьями в килобайтах, используйте опцию -k (отображает размер в единицах по 1024 байта); для получения суммарного использования диска деревом директории вместе с его поддиректориями в мегабайтах используйте -mh. Флаг -m считает блоки в единицах мегабайты, а -h здесь для понятного человеку формата;Флаг -c выводит последнюю строку с суммарным размером («итого»); для показа вместе с информацией о занимаемом месте информации о времени последней модификации любого файла в директории или в любых поддиректориях используется флаг --time | Команда используется для показа суммарной информации об использовании диска файлами и директориями. Команда du также отображает размеры файлов и директорий в рекурсивной манере |
| patch | patch [параметры] <оригинальный файл(файл, который необходимо «пропатчить» до актуального состояния)> <пэтч-файл(генерируется другой утилитой — diff, которая находит построчные различия между файлами)> |"-i patchfile " - Читает информацию из патч-файла, указываемого параметром patchfile(перенаправление потока, можно использовать '<'); "-o outputfile, —output=outputfile" - Отправляет вывод в указываемый в параметре outputfile файл. Не следует использовать эту опцию, если в качестве outputfile указывается файл, который должен быть пропатчен. Если в качестве outputfile указать символ дефиса «-», то вывод будет направляться в стандартный поток STD_OUT; "R" - отмена; "-E, —remove-empty-file" - Удаляет файлы, оказавшиеся пустыми после применения патча. Эта опция имеет смысл, когда используемые патчи имеют не контекстный формат; "-b, —backup" - Создаёт резервную копию оригинального файла вместо его удаления. | Команда предназначенная для переноса правок (изменений) между разными версиями текстовых файлов |


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

1. ```cmp``` – сравнение двух файлов байт за байтом 
2. ```wc``` – обработка входного потока или файла
3. ```diff``` – определеяет изменения в файлах, которые необходимо сделать, чтобы они стали идентичными 
4. ```grep``` – позволяет фильтровать и сортировать содержимое текстовых файлов 
5. ```sort``` – сортировка текста
6. ```tail``` – выводит последние N строк файла 
7. ```tee``` – запись вывода любой команды в один или несколько файлов
9. ```sum``` – подсчет контрольной суммы и блоков в файлe
8. ```comm``` - поиск одинаковых и разных строк в файлах, отсортированных в лексикографическом порядке 
10. ```cut``` – позволяет вырезать части строк из указанных файлов
11. ```tar``` – распаковка архива tar Linux с выводом файлов на экран
12. ```gzip``` – архивирование файлов
13. ```dd``` – выполняет копирование данных из одного места в другое на двоичном уровне
14. ```bzip2``` – архивирование файлов, более эффективная, но работает медленнее
15. ```head``` – выводит первые N строк файла (по умолчанию - первые 10 строк)
16. ```iconv``` – преобразование текстового файла из одной кодировки в другую
17. ```touch``` – создание пустого файла, изменение модификации и времени доступа для любого файла
18. ```df``` – получение полной сводной информации об использовании доступного и используемого дискового пространства файловой системы
19. ```paste``` – объединение соответствующих строк файлов по горизонтали
20. ```mktemp``` – создание временных файлов или каталогов

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
annastarostina@MacBook-Pro-Anna 20lab % cat f1.txt
001
002
003
004
005
annastarostina@MacBook-Pro-Anna 20lab % cat f2.txt
001
002
004
006
010
annastarostina@MacBook-Pro-Anna 20lab % comm f1.txt f2.txt
        001
        002
003
        004
005
    006
    010
annastarostina@MacBook-Pro-Anna 20lab % comm -1 f1.txt f2.txt
    001
    002
    004
006
010
annastarostina@MacBook-Pro-Anna 20lab % cmp f1.txt f2.txt
f1.txt f2.txt differ: char 11, line 3
annastarostina@MacBook-Pro-Anna 20lab % cat >> f3.txt
001
002
003
004
005
^C
annastarostina@MacBook-Pro-Anna 20lab % cmp f1.txt f3.txt
annastarostina@MacBook-Pro-Anna 20lab % diff f1.txt f2.txt
3d2
< 003
5c4,5
< 005
---
> 006
> 010
annastarostina@MacBook-Pro-Anna 20lab % diff -q f1.txt f2.txt
Files f1.txt and f2.txt differ
annastarostina@MacBook-Pro-Anna 20lab % grep -c 00 f2.txt            
4
annastarostina@MacBook-Pro-Anna 20lab % grep -n 00 f2.txt
1:001
2:002
3:004
4:006
annastarostina@MacBook-Pro-Anna 20lab % touch f4.txt
annastarostina@MacBook-Pro-Anna 20lab % cat f4.txt
-89
0
1326478
39
329200
0000
-64783928
annastarostina@MacBook-Pro-Anna 20lab % sort -n f4.txt
-64783928
-89
0
0000
39
329200
1326478
annastarostina@MacBook-Pro-Anna 20lab % tail -2 f4.txt 
0000
-64783928
annastarostina@MacBook-Pro-Anna 20lab % head -2 f4.txt
-89
0
annastarostina@MacBook-Pro-Anna 20lab % cat f1.txt
001
002
003
004
005
annastarostina@MacBook-Pro-Anna 20lab % tee -a f1.txt
hahaha
hahaha
^C
annastarostina@MacBook-Pro-Anna 20lab % cat f1.txt
001
002
003
004
005
hahaha
annastarostina@MacBook-Pro-Anna 20lab % sum f2.txt
27068 1 f2.txt
annastarostina@MacBook-Pro-Anna 20lab % cut -c 3 f1.txt
1
2
3
4
5
h
annastarostina@MacBook-Pro-Anna 20lab % cut -c 1 f1.txt
0
0
0
0
0
h
annastarostina@MacBook-Pro-Anna 20lab % gzip f4.txt   
annastarostina@MacBook-Pro-Anna 20lab % ls
f1.txt        f2.txt        f3.txt        f4.txt.gz
annastarostina@MacBook-Pro-Anna 20lab % gzip -d f4.txt
annastarostina@MacBook-Pro-Anna 20lab % ls
f1.txt    f2.txt    f3.txt    f4.txt
annastarostina@MacBook-Pro-Anna 20lab % tar --totals -cvf ar.tar f1.txt f2.txt
a f1.txt
a f2.txt
Total bytes written: 3072
annastarostina@MacBook-Pro-Anna 20lab % ls
ar.tar    f1.txt    f2.txt    f3.txt    f4.txt
annastarostina@MacBook-Pro-Anna 20lab % tar -tf ar.tar
f1.txt
f2.txt
annastarostina@MacBook-Pro-Anna 20lab % tar -xvf ar.tar
x f1.txt
x f2.txt
annastarostina@MacBook-Pro-Anna 20lab % ls
ar.tar    f1.txt    f2.txt    f3.txt    f4.txt
annastarostina@MacBook-Pro-Anna 20lab % iconv -f ascii -t UTF8 f5.txt


fghj
tyifgh
atujs
345
fgdksssvks
annastarostina@MacBook-Pro-Anna 20lab % cat f5.txt
fghj
tyifgh
atujs
345
fgdksssvks
annastarostina@MacBook-Pro-Anna 20lab % wc -m f5.txt
      33 f5.txt
annastarostina@MacBook-Pro-Anna 20lab % wc -l f5.txt
       5 f5.txt
annastarostina@MacBook-Pro-Anna 20lab % wc -w f5.txt
       5 f5.txt
annastarostina@MacBook-Pro-Anna 20lab % df
Filesystem     512-blocks      Used Available Capacity iused      ifree %iused  Mounted on
/dev/disk3s1s1  965595304  17462696 529788648     4%  349475 2648943240    0%   /
devfs                 395       395         0   100%     684          0  100%   /dev
/dev/disk3s6    965595304   4194344 529788648     1%       2 2648943240    0%   /System/Volumes/VM
/dev/disk3s2    965595304   9472136 529788648     2%    1502 2648943240    0%   /System/Volumes/Preboot
/dev/disk3s4    965595304     22392 529788648     1%      42 2648943240    0%   /System/Volumes/Update
/dev/disk1s2      1024000     12328    988320     2%       1    4941600    0%   /System/Volumes/xarts
/dev/disk1s1      1024000     12592    988320     2%      30    4941600    0%   /System/Volumes/iSCPreboot
/dev/disk1s3      1024000      1040    988320     1%      50    4941600    0%   /System/Volumes/Hardware
/dev/disk3s5    965595304 402807880 529788648    44% 1882337 2648943240    0%   /System/Volumes/Data
map auto_home           0         0         0   100%       0          0  100%   /System/Volumes/Data/home
annastarostina@MacBook-Pro-Anna 20lab % paste f1.txt f2.txt  
001    001
002    002
003    004
004    006
005    010
hahaha    
annastarostina@MacBook-Pro-Anna 20lab % paste -d '_' f1.txt f2.txt 
001_001
002_002
003_004
004_006
005_010
hahaha_
annastarostina@MacBook-Pro-Anna 20lab % ls
f1.txt    f2.txt    f3.txt    f4.txt    f5.txt    f6.txt
annastarostina@MacBook-Pro-Anna 20lab % bzip2 f1.txt f2.txt
annastarostina@MacBook-Pro-Anna 20lab % ls
f1.txt.bz2    f3.txt        f5.txt
f2.txt.bz2    f4.txt        f6.txt
annastarostina@MacBook-Pro-Anna 20lab % bzip2 -d f1.txt.bz2 f2.txt.bz2
annastarostina@MacBook-Pro-Anna 20lab % ls
f1.txt    f2.txt    f3.txt    f4.txt    f5.txt    f6.txt
annastarostina@MacBook-Pro-Anna 20lab % mktemp
/var/folders/0j/blcncf4s5nn1lpf7y8vm6dzr0000gn/T/tmp.SkoWcRCm
annastarostina@MacBook-Pro-Anna 20lab % mktemp -d
/var/folders/0j/blcncf4s5nn1lpf7y8vm6dzr0000gn/T/tmp.bvCsUqRA
annastarostina@MacBook-Pro-Anna 20lab % ls -al /tmp
lrwxr-xr-x@ 1 root  wheel  11  9 фев 12:39 /tmp -> private/tmp
annastarostina@MacBook-Pro-Anna 20lab % cat f1.txt
001
002
003
004
005
hahaha
annastarostina@MacBook-Pro-Anna 20lab % cat f5.txt
fghj
tyifgh
atujs
345
fgdksssvks
annastarostina@MacBook-Pro-Anna 20lab %  dd if=f5.txt of=f1.txt
0+1 records in
0+1 records out
33 bytes transferred in 0.000649 secs (50847 bytes/sec)
annastarostina@MacBook-Pro-Anna 20lab % cat f1.txt
fghj
tyifgh
atujs
345
fgdksssvks
annastarostina@MacBook-Pro-Anna 20lab % cat f5.txt
fghj
tyifgh
atujs
345
fgdksssvks
annastarostina@MacBook-Pro-Anna 20lab % du -h
 28K    .
annastarostina@MacBook-Pro-Anna 20lab % du -s
56    .
annastarostina@MacBook-Pro-Anna 20lab % du -a
0    ./f6.txt
8    ./f5.txt
8    ./f4.txt
16    ./.DS_Store
8    ./f1.txt
8    ./f3.txt
8    ./f2.txt
56    .
annastarostina@MacBook-Pro-Anna 20lab % du -ah
  0B    ./f6.txt
4,0K    ./f5.txt
4,0K    ./f4.txt
8,0K    ./.DS_Store
4,0K    ./f1.txt
4,0K    ./f3.txt
4,0K    ./f2.txt
 28K    .
annastarostina@MacBook-Pro-Anna 20lab % du -k 
28    .
annastarostina@MacBook-Pro-Anna 20lab % du -mh
 28K    .
annastarostina@MacBook-Pro-Anna 20lab % du -c 
56    .
56    total
ann@ann:~/Загрузки$ du --exclude .c
80 .
ann@ann:~/Загрузки$ du --time
80 2023-03-25 10:39 .
annastarostina@MacBook-Pro-Anna 20lab % cat >> file
001
002
003
004
^C
annastarostina@MacBook-Pro-Anna 20lab % cat >> file 1
cat: 1: No such file or directory
annastarostina@MacBook-Pro-Anna 20lab % cat >> file1 
001
002
005
009
^C
annastarostina@MacBook-Pro-Anna 20lab % diff -u file file1 > file.patch
annastarostina@MacBook-Pro-Anna 20lab % cat file.patch               
--- file    2023-03-25 16:51:50
+++ file1    2023-03-25 16:52:13
@@ -1,4 +1,4 @@
 001
 002
-003
-004
+005
+009
annastarostina@MacBook-Pro-Anna 20lab % patch < file.patch
patching file file
annastarostina@MacBook-Pro-Anna 20lab % cat file
001
002
005
009
annastarostina@MacBook-Pro-Anna 20lab % cat file1
001
002
005
009
annastarostina@MacBook-Pro-Anna 20lab % cat file.patch
--- file    2023-03-25 16:51:50
+++ file1    2023-03-25 16:52:13
@@ -1,4 +1,4 @@
 001
 002
-003
-004
+005
+009
annastarostina@MacBook-Pro-Anna 20lab % patch -b < file.patch
patching file file
Reversed (or previously applied) patch detected!  Assume -R? [y] y
annastarostina@MacBook-Pro-Anna 20lab % cat file.patch
--- file    2023-03-25 17:05:07
+++ file1    2023-03-25 16:52:13
@@ -1,4 +1,4 @@
 001
 002
-003
-004
+005
+009
annastarostina@MacBook-Pro-Anna 20lab % cat file
001
002
003
004
annastarostina@MacBook-Pro-Anna 20lab % cat file1
001
002
005
009
annastarostina@MacBook-Pro-Anna 20lab % patch -R < file.patch
patching file file
annastarostina@MacBook-Pro-Anna 20lab % cat file
001
002
003
004
annastarostina@MacBook-Pro-Anna 20lab % cat file1
001
002
005
009

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 16.03.23 | 19:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы 

Защита:
https://codeforces.com/contest/1806/submission/197939180 (онлайн див 2)

## 11. Выводы

Благодаря лабораторной работе, были изучены основные утилите по работе с файлами в OC UNIX. Можно изменять, сравнивать, печатать, анализировать и многое другое. И причем используя лишь командную строку. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ, курсовых проектов и далее.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


