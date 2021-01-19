# Домашнее задание 1.

## Описание задания 
Программа из стандартного ввода (файла) читает данные. 
Данные хранятся построчно. Каждая строка состоит из трех полей, разделенных одним символом табуляции, и завершается символом конца строки.
Формат строки:text1 \ttext2 \ttext3 \n Поля text2 и text3 игнорируются. 
Поле text1 имеет следующую структуру (ip4 address):n1.n2.n3.n4где n1..4 –целое число от 0 до 255.
Требуетсязагрузить список ip-адресов в памятьи отсортировать их в обратном лексикографическом порядке. 
Пример лексикографической сортировки (по первому числу, затем по второму и так далее):1.1.1.11.2.1.11.10.1.1.Соответственно, обратная:1.10.1.11.2.1.11.1.1.1
Далее выводим в стандартный вывод следующее:
1.Полный список адресов после сортировки.Одна строка -один адрес.
2.Сразу следомсписок адресов, первый байт которых равен 1. Порядок сортировки не меняется. Одна строка -один адрес. Списки ничем не разделяются.
3.Сразу продолжается список адресов, первый байт которых равен 46, а второй 70.
Порядок сортировки не меняется. Одна строка -один адрес. Списки ничем не разделяются.4.Сразу продолжается список адресов, любой байт которых равен 46. Порядок сортировки не меняется. Одна строка -один адрес. Списки ничем не разделяются.Требования к реализацииВ приложенном к заданию исходном файле необходимо заменить, где это возможно, конструкции на аналогичные из стандарта С++14. Реализовать недостающий функционал.
