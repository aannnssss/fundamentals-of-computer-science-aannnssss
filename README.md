Отчёт по лабораторной работе №3 по курсу «Фундаментальная информатика»

Студент группы: М80-108Б-22, Старостина Анна Андреевна, № по списку: 20

Контакты: starostina-anuta@mail.ru

Работа выполнена: «05 » октября  2022 г.

Преподаватель: Сахарин Никита Андреевич

Входной контроль знаний с оценкой:

Отчёт сдан: « 8»  октября 2022 г. Итоговая оценка:

Подпись преподавателя:

Тема: Сети и телекоммуникации в ОС Unix

Цель работы: изучение различных команд для взаимодействия с удалённой машиной

Задание: изучить удалённые команды UNIX, удаленное копирование файлов и директорий, передачу файлов.

Оборудование:

Ноутбук Macbook Pro

Процессор: apple m2

Монитор: 2560х1600

\5. Программное обеспечение:

Операционная система семейства: Linux Ubuntu 22.04.1

Интерпретатор команд: bash 5.0.17(1)

Система программирования:

Редактор текстов: emacs

Утилиты операционной системы: ssh, sftp, hostname, ftp

Прикладные системы и программы:

Местонахождение и имена файлов программ и данных: /home/ann

\6. Идея, метод, алгоритм решения задачи

В формах: словесной, псевдокода, графической [блок схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями.

Необходимые команды:

Scp - копировать файлы удалённо

Ssh - команда для подключения к другой (виртуальной) машине

Tar -tvf  (имя архива).tar - просмотр оглавления архива

Tar -xf -  разархивировать

Tar -cf - (имя-архива).tar (имя-директории) - создает архив и помещает в него все файлы и поддиректории указанной директории

Tar -zcf - (имя-архива).tar.gz (имя-сжим-файлов)

Ping - убедиться в доступности сервера в сети

Ftp - запустить улилиту-клиент для подсоединения к узлу сети, с которым надо осуществить обмен файлами

ftp binary - внутренняя команда, которую предварительно необходимо выполнить для передачи нетекстовые файлов

ftp ascii - команда, восстанавливающая режим передачи текстовых файлов

Dos2unix - преобразование символов расширенного набора символов DOS в соответствующие символы стандарта ISO

Xxd - вывод в шестнадцатеричный системе

Hostname -I - узнать ip адрес текущего терминала

Sftp>  get - получить файл с удалённой машины

Sftp>  put - передать файл на удалённую машину

Iconv - преобразовать текст из одной кодировки в другую, конвертация файлов

Ls -a, ls -l, ls-F - посмотреть содержимое директории

Cat - создать новый файл, посмотреть его, что-то записать в него

Rm - удалить файл

Mkdir - создать директорию

Rmdir - удалить директорию

Exit - выход

\7. Сценарий выполнения работы:

[План работы, первоначальный текст программы в черновике ( можно на отдельном листе) и тесты либо соображения по тестированию]

Изучить справочный материал

Изучить удалённое копирование файлов и директорий

Изучить передачу фалов

Изучить архивацию и упаковку

Изучить удалённый доступ к лабораторной системе UNIX

Запротоколировать сеанс

\8. Распечатка протокола

Подклеить листинг окончательного варианта программы с тестовыми примерами, подписанный преподавателем.

ann@ann:~$ hostname -I

192.168.128.2

ann@ann:~$ ls

d1   gnuplot   snap    Документы   Изображения   Общедоступные   Шаблоны

d2   set       Видео   Загрузки    Музыка       'Рабочий стол'

ann@ann:~$ cat > f1.txt

privet

^C

ann@ann:~$ ls

d1   f1.txt    set    Видео       Загрузки      Музыка         'Рабочий стол'

d2   gnuplot   snap   Документы   Изображения   Общедоступные   Шаблоны

ann@ann:~$ mkdir dir

ann@ann:~$ ls

d1    f1.txt    snap        Загрузки      Общедоступные

d2    gnuplot   Видео       Изображения  'Рабочий стол'

dir   set       Документы   Музыка        Шаблоны

ann@ann:~$ cp f1.txt dir

ann@ann:~$ ls

d1    f1.txt    snap        Загрузки      Общедоступные

d2    gnuplot   Видео       Изображения  'Рабочий стол'

dir   set       Документы   Музыка        Шаблоны

ann@ann:~$ cd dir

ann@ann:~/dir$ ls

f1.txt

ann@ann:~/dir$ cd ..

ann@ann:~$ ssh ann1@192.168.128.3

ann1@192.168.128.3's password:

Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic aarch64)

* Documentation:  https://help.ubuntu.com
* Management:     https://landscape.canonical.com
* Support:        https://ubuntu.com/advantage

System information as of Сб 08 окт 2022 09:04:03 UTC

System load:  0.0               Processes:               119

Usage of /:   27.4% of 9.75GB   Users logged in:         1

Memory usage: 5%                IPv4 address for enp0s6: 192.168.128.3

Swap usage:   0%


40 updates can be applied immediately.

To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings


Last login: Sat Oct  8 08:46:45 2022 from 192.168.128.2

ann1@ann1:~$ ls

ann1@ann1:~$ cat > f2.txt

kuku

^C

ann1@ann1:~$ ls

f2.txt

ann1@ann1:~$ scp /home/ann1/f2.txt ann@192.168.128.2:/home/ann

ann@192.168.128.2's password:

f2.txt                                        100%    5     4.3KB/s   00:00

ann1@ann1:~$ mkdir ddir

ann1@ann1:~$ cat > m.txt

mmm

^C

ann1@ann1:~$ ls

ddir  f2.txt  m.txt

ann1@ann1:~$ cp m.txt ddir

ann1@ann1:~$ cd ddir

ann1@ann1:~/ddir$ ls

m.txt

ann1@ann1:~/ddir$ cd ..

ann1@ann1:~$ scp -r /home/ann1/ddir ann@192.168.128.2:/home/ann

ann@192.168.128.2's password:

m.txt                                         100%    4     4.1KB/s   00:00

ann1@ann1:~$ ssh ann@192.168.128.2 "ls -1 ~"

ann@192.168.128.2's password:

d1

d2

ddir

dir

f1.txt

f2.txt

gnuplot

set

snap

Видео

Документы

Загрузки

Изображения

Музыка

Общедоступные

Рабочий стол

Шаблоны

ann1@ann1:~$ ssh ann@192.168.128.2 "ls -1 ~/ddir"

ann@192.168.128.2's password:

m.txt

ann1@ann1:~$ mkdir aaa

ann1@ann1:~$ tar -cf archive.tar aaa

ann1@ann1:~$ ls

aaa  archive.tar  ddir  f2.txt  m.txt

ann1@ann1:~$ tar -tvf archive.tar

drwxrwxr-x ann1/ann1         0 2022-10-08 09:12 aaa/

ann1@ann1:~$ scp /home/ann1/archive.tar ann@192.168.128.2:/home/ann

ann@192.168.128.2's password:

archive.tar                                   100%   10KB   9.1MB/s   00:00

ann1@ann1:~$ exit

logout

Connection to 192.168.128.3 closed.

ann@ann:~$ ls

archive.tar   ddir     f2.txt    snap        Загрузки      Общедоступные

d1            dir      gnuplot   Видео       Изображения  'Рабочий стол'

d2            f1.txt   set       Документы   Музыка        Шаблоны

ann@ann:~$ cat f1.txt

privet

ann@ann:~$ rm f1.txt

ann@ann:~$ cat f2.txt

kuku

ann@ann:~$ rm f2.txt

ann@ann:~$ cd dir

ann@ann:~/dir$ ls

f1.txt

ann@ann:~/dir$ rm f1.txt

ann@ann:~/dir$ cd ..

ann@ann:~$ rmdir dir

ann@ann:~$ tar -xf archive.tar

ann@ann:~$ ls

aaa           d2        set     Документы     Музыка          Шаблоны

archive.tar   ddir      snap    Загрузки      Общедоступные

d1            gnuplot   Видео   Изображения  'Рабочий стол'

ann@ann:~$ cd aaa

ann@ann:~/aaa$ ls

ann@ann:~/aaa$ cd ..

ann@ann:~$ rmdir aaa

ann@ann:~$ cd ddir

ann@ann:~/ddir$ ls

m.txt

ann@ann:~/ddir$ rm m.txt

ann@ann:~/ddir$ cd ..

ann@ann:~$ rmdir ddir

ann@ann:~$ rm archive.tar

ann@ann:~$ ls

d1   gnuplot   snap    Документы   Изображения   Общедоступные   Шаблоны

d2   set       Видео   Загрузки    Музыка       'Рабочий стол'

ann@ann:~$ ssh ann1@192.168.128.3

ann1@192.168.128.3's password:

Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic aarch64)

* Documentation:  https://help.ubuntu.com
* Management:     https://landscape.canonical.com
* Support:        https://ubuntu.com/advantage

System information as of Сб 08 окт 2022 09:27:40 UTC

System load:  0.00341796875     Processes:               119

Usage of /:   27.4% of 9.75GB   Users logged in:         1

Memory usage: 5%                IPv4 address for enp0s6: 192.168.128.3

Swap usage:   0%


40 updates can be applied immediately.

To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings


Last login: Sat Oct  8 09:04:03 2022 from 192.168.128.2

ann1@ann1:~$ ls

aaa  archive.tar  ddir  f2.txt  m.txt

ann1@ann1:~$ rm m.txt

ann1@ann1:~$ rm f2.txt

ann1@ann1:~$ cd aaa

ann1@ann1:~/aaa$ ls

ann1@ann1:~/aaa$ cd ..

ann1@ann1:~$ rmdir aaa

ann1@ann1:~$ cd ddir

ann1@ann1:~/ddir$ ls

m.txt

ann1@ann1:~/ddir$ rm m.txt

ann1@ann1:~/ddir$ cd ..

ann1@ann1:~$ rm archive.tar

ann1@ann1:~$ ls

ddir

ann1@ann1:~$ rmdir ddir

ann1@ann1:~$ ls

ann1@ann1:~$ exit

logout

Connection to 192.168.128.3 closed.

ann@ann:~$


\9. Дневник отладки

Должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментария к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании отладки программы.




\10. Замечания автора по существу работы:



\11. Выводы:

Я узнала, что в OC UNIX можно удаленно подключаться к другим машинам. Я изучила команды, необходимые мне для манипуляций с файлами. Данные навыки мне пригодятся в будущем.

Недочёты при выполнении задания могут быть выполнены следующим образом:


Подпись студета:
