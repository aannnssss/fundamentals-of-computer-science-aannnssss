﻿**Отчёт по лабораторной работе №6 по курсу** 

**«Фундаментальная информатика»** 

Студент группы: М80-108Б-22, Старостина Анна Андреевна, № по списку: 20 Контакты: <starostina-anuta@mail.ru> 

Работа выполнена: «20» октября 2022 г. Преподаватель: Сахарин Никита Андреевич Входной контроль знаний с оценкой: 

Отчёт сдан: « 22 » октября 2022 г. Итоговая оценка: 

Подпись преподавателя:    

1. **Тема:** Конструирование диаграмм Тьюринга.** 
1. **Цель  работы:**  Разработать  диаграмму  Тьюринга  для  решения  задачи  в  среде интерпретатора  VTM  или  jdt  (или  VisualTuring  2.0!)  с  использованием стандартных машин (r, l, R, L, Kn, a ) и вспомогательных машин, определяемых 

i 

поставленной задачей.** 

3. **Задание:**  (вариант  27)  Вычисление  поразрядной  дизъюнкции  двух  двоичных чисел (слова одинаковой длины).**  
3. **Оборудование:**  

**Ноутбук Macbook Pro  Процессор:** apple m2  **Монитор:** 2560х1600 

5. **Программное обеспечение:**  

Операционная система: Mac OS monterey 12.6 

Интерпретатор команд: jdt** 

Был  скачан  файл  jdt\_mod.zip  на  сайте  http://faq8.ru/read.php?2,15200,  затем  в терминале было запущено java -jar jdt\_mod.jar. 

6. **Идея, метод, алгоритм решения задачи** 

В  формах:  словесной,  псевдокода,  графической  [блок  схема,  диаграмма,  рисунок, таблица] или формальные спецификации с пред- и постусловиями. 

1. Копирование с помощью вспомогательной машины (copy). 
1. Удаление посимвольно 1 или 0 из второго слова и замена на + (если хотя бы в одном числе в этом разряде есть 1) или - (если нет ни одной 1 в обоих числах в этом разряде). 
1. Когда второе число полностью удалилось, используется еще одна вспомогательная машина (obratno), которая заменяет + на 1 и - на 0, а затем приходит к концу ответа. 

**7. Сценарий выполнения работы:** 

[План работы, первоначальный текст программы в черновике ( можно на отдельном листе) и тесты либо соображения по тестированию] 

1. Установка диаграммы Тьюринга. 
1. Знакомство с диаграммой Тьюринга, тестирование. 
1. Выполнение поставленной задачи. 
1. Оформление отчёта. 
8. **Распечатка протокола**  

8.Подклеить  листинг  окончательного  варианта  программы  с  тестовыми  примерами, подписанный преподавателем. 
https://github.com/mai-806-1st-year/fundamentals-of-computer-science-aannnssss/blob/master/lab6/1.png (диаграмма по выполнению главной задачи - вычисление  поразрядной  дизъюнкции  двух  двоичных чисел (слова одинаковой длины))

https://github.com/mai-806-1st-year/fundamentals-of-computer-science-aannnssss/blob/master/lab6/2.png (вспомогательная машина copy, она копирует два задаваемых числа, чтобы исходные данные не затирались)

https://github.com/mai-806-1st-year/fundamentals-of-computer-science-aannnssss/blob/master/lab6/3.png (вспомогательная машина obratno, она, находясь справка от ответа, идет пошагово влево и заменяет + на 1 и - на 0. Когда она дойдет до начала слова, она вернется в его конец и программа завершится )

9. **Дневник отладки** 

Должен  содержать  дату  и  время  сеансов  отладки  и  основные  события  (ошибки  в сценарии и программе, нестандартные ситуации) и краткие комментария к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании отладки программы. 



|**№**|**Лаб. Или дом.**|**Дата**|**Время**|**Событие**|**Действие по направлению**|**Примечание**|
| - | - | - | - | - | - | - |
|1|Лаб|22.10|12:00|Защита лабораторной работы|||


10. **Замечания автора по существу работы:** 
https://github.com/mai-806-1st-year/fundamentals-of-computer-science-aannnssss/blob/master/lab6/4.png (вычисление  поразрядной  дизъюнкции  двух  двоичных чисел (слова разной длины))
11. **Выводы:** 

Были  приобретены  основные  навыки  по  работе  с  диаграммами  Тьюринга.  Были выполнены определенные задачи.  

Недочёты при выполнении задания могут быть выполнены следующим образом: Подпись студета: 
