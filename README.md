# Simple Bash Utils

Разработка утилит Bash по работе с текстом: cat, grep.

## Глава I

### Введение

В этом проекте необходимо разработать базовые утилиты Bash по работе с текстами на языке программирования Си. Эти утилиты (cat и grep) достаточно часто используются при работе в терминале Linux. В рамках этого проекта предполагается знакомство с организацией утилит Bash и закрепление структурного подхода.  


## Глава II

## Информация

### cat Использование

Cat - одна из наиболее часто используемых команд в Unix-подобных операционных системах. Команда имеет три взаимосвязанные функции в отношении текстовых файлов: отображение, объединение их копий и создание новых.

`cat [OPTION] [FILE]...`

### cat Опции

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | нумерует только непустые строки |
| 2 | -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $  |
| 3 | -n (GNU: --number) | нумерует все выходные строки |
| 4 | -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| 5 | -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

### grep Использование

`grep [options] template [file_name]`

### grep Опции

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -e | Шаблон |
| 2 | -i | Игнорирует различия регистра.  |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. |
| 5 | -l | Выводит только совпадающие файлы.  |
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. |
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. |


## Глава III

- Программы должны быть разработаны на языке Си стандарта C11 с использованием компилятора gcc 
- Код программ cat и grep должен находиться в папках src/cat/ и src/grep/ соответственно  
- Не использовать устаревшие и выведенные из употребления конструкции языка и библиотечные функции.
- Программы должны представлять собой исполняемый файл с аргументами командной строки
- Сборка программ должна быть настроена с помощью Makefile с соответствующими целями: s21_cat, s21_grep  
- Если используются сторонние библиотеки, в Makefile должны быть заложены сценарии сборки, предусматривающие их подключение/загрузку 
- Необходимо покрытие интеграционными тестами для всех вариантов флагов и входных значений, на базе сравнения с поведением реальных утилит Bash
- Программа должна быть разработана в соответствии с принципами структурного программирования
- Необходимо исключить дублирование кода
- Можно использовать стандартные и нестандартные библиотеки языка Си, можно использовать собственноручно разработанные библиотеки
- Формулировка сообщения при возникновении ошибочной ситуации не имеет значения
- Ввод через stdin обрабатывать не обязательно


## Часть 1. Работа с утилитой cat

Необходимо разработать утилиту cat:
- Поддержка всех флагов (включая GNU версии), указанных [выше](#cat-опции)
- Исходные, заголовочные и сборочный файлы должны располагаться в директории src/cat/
- Итоговый исполняемый файл должен располагаться в директории src/cat/ и называться s21_cat

## Часть 2. Работа с утилитой grep

Необходимо разработать утилиту grep:
- Поддержка следующих флагов: `-e`, `-i`, `-v`, `-c`, `-l`, `-n`
- Для регулярных выражений можно использовать только библиотеки pcre или regex  
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep

## Часть 3. Дополнительно. Реализация некоторых флагов утилиты grep

Необходимо разработать утилиту grep:
- Поддержка всех флагов, включая: `-h`, `-s`, `-f`, `-o`
- Для регулярных выражений можно использовать только библиотеки pcre или regex  
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep

## Часть 4. Дополнительно. Реализация комбинаций флагов утилиты grep

 Необходимо разработать утилиту grep:
- Поддержка всех флагов, включая их _парные_ комбинации (например, `-iv`, `-in`)
- Для регулярных выражений можно использовать только библиотеки pcre или regex
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep
