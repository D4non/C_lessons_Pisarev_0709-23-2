# Задание 4

## Исследование через nm

### Файл file1.o
0000000000000000 D global_var <br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf <br>
0000000000000000 T print_from_file1 <br>
0000000000000004 d static_var <br>

- global_var — глобальная переменная, видна в других файлах (символ D — секция .data).
- static_var — статическая переменная, видна только в file1.c (символ d — локальный символ в секции .data).
- print_from_file1 — функция, видна в других файлах (символ T — секция .text).
- printf — неопределённый символ (символ U), который будет разрешён при линковке.

### Файл file2.o
0000000000000000 D global_var<br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf<br>
0000000000000000 T print_from_file2<br>
&nbsp;&nbsp;&nbsp;&nbsp;U static_var<br>

- global_var — объявлена как extern, но не определена в этом файле (символ U).
- print_from_file2 — функция, видна в других файлах (символ T).
- printf — неопределённый символ (символ U).
- static_var — объявлена как extern, но не определена в этом файле (символ U).

### Файл main.o
&nbsp;&nbsp;&nbsp;&nbsp;U global_var<br>
0000000000000000 T main<br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf<br>
&nbsp;&nbsp;&nbsp;&nbsp;U print_from_file1<br>
&nbsp;&nbsp;&nbsp;&nbsp;U print_from_file2<br>

- global_var — объявлена как extern, но не определена в этом файле (символ U).
- main — функция, видна в других файлах (символ T).
- print_from_file1, print_from_file2, printf — неопределённые символы (символ U).

## Попытка сборки
Если в file2.c оставить строку int global_var = 30;, то возникнет ошибка линковки:

multiple definition of `global_var`

Это происходит из-за того, что global_var определена в file1.c и повторно определена в file2.c.

## Исследование через nm после исправления ошибок

### Файл file1.o
0000000000000000 D global_var <br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf <br>
0000000000000000 T print_from_file1 <br>
0000000000000004 d static_var <br>

- global_var — глобальная переменная, видна в других файлах (символ D — секция .data).
- static_var — статическая переменная, видна только в file1.c (символ d — локальный символ в секции .data).
- print_from_file1 — функция, видна в других файлах (символ T — секция .text).
- printf — неопределённый символ (символ U), который будет разрешён при линковке.

### Файл file2.o
0000000000000000 D global_var<br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf<br>
0000000000000000 T print_from_file2<br>

- global_var — объявлена как extern, но не определена в этом файле (символ U).
- print_from_file2 — функция, видна в других файлах (символ T).
- printf — неопределённый символ (символ U).

### Файл main.o
&nbsp;&nbsp;&nbsp;&nbsp;U global_var<br>
0000000000000000 T main<br>
&nbsp;&nbsp;&nbsp;&nbsp;U printf<br>
&nbsp;&nbsp;&nbsp;&nbsp;U print_from_file1<br>
&nbsp;&nbsp;&nbsp;&nbsp;U print_from_file2<br>

- global_var — объявлена как extern, но не определена в этом файле (символ U).
- main — функция, видна в других файлах (символ T).
- print_from_file1, print_from_file2, printf — неопределённые символы (символ U).


## Исследование таблицы символов через objdump
### Файл file1.o
SYMBOL TABLE:<br>
0000000000000000 l    df *ABS*  0000000000000000 file1.c<br>
0000000000000000 l    d  .text  0000000000000000 .text<br>
0000000000000000 l    d  .data  0000000000000000 .data<br>
0000000000000004 l     O .data  0000000000000004 static_var<br>
0000000000000000 l    d  .rodata        0000000000000000 .rodata<br>
0000000000000000 g     O .data  0000000000000004 global_var<br>
0000000000000000 g     F .text  0000000000000043 print_from_file1<br>
0000000000000000         *UND*  0000000000000000 printf<br>

- global_var — в секции .data (глобальная переменная).
- static_var — в секции .data (локальная переменная).
- print_from_file1 — в секции .text (функция).

### Файл file2.o
SYMBOL TABLE:<br>
0000000000000000 l    df *ABS*  0000000000000000 file2.c<br>
0000000000000000 l    d  .text  0000000000000000 .text<br>
0000000000000000 l    d  .rodata        0000000000000000 .rodata<br>
0000000000000000 g     F .text  0000000000000027 print_from_file2<br>
0000000000000000         *UND*  0000000000000000 printf<br>
0000000000000000         *UND*  0000000000000000 global_var<br>

- print_from_file2 — в секции .text (функция).

### Файл main.o
SYMBOL TABLE:<br>
0000000000000000 l    df *ABS*  0000000000000000 main.c<br>
0000000000000000 l    d  .text  0000000000000000 .text<br>
0000000000000000 l    d  .rodata        0000000000000000 .rodata<br>
0000000000000000 g     F .text  000000000000003f main<br>
0000000000000000         *UND*  0000000000000000 global_var<br>
0000000000000000         *UND*  0000000000000000 printf<br>
0000000000000000         *UND*  0000000000000000 print_from_file1<br>
0000000000000000         *UND*  0000000000000000 print_from_file2<br>

- main — в секции .text (функция).

## Проверка строк в бинарнике
file1.c -> global_var = %d<br>
file1.c -> static_var = %d<br>
file2.c -> global_var = %d<br>
main.c -> global_var = %d<br>

Строки из printf видны в бинарнике.

## Дополнительные шаги
- начальный адрес 0x0000000000001060
- .text         00000192  0000000000001060  0000000000001060  00001060  2**4 <br>
&nbsp;&nbsp;&nbsp;&nbsp;CONTENTS, ALLOC, LOAD, READONLY, CODE<br>
- .rodata       00000073  0000000000002000  0000000000002000  00002000  2**2<br>
&nbsp;&nbsp;&nbsp;&nbsp;CONTENTS, ALLOC, LOAD, READONLY, DATA<br>
- .data         00000018  0000000000004000  0000000000004000  00003000  2**3<br>
&nbsp;&nbsp;&nbsp;&nbsp;CONTENTS, ALLOC, LOAD, DATA<br>
- .bss          00000008  0000000000004018  0000000000004018  00003018  2**0<br>
&nbsp;&nbsp;&nbsp;&nbsp;ALLOC<br>
- NEEDED               libc.so.6

## Дополнительный вопрос
global_var — глобальная переменная, которая видна в других файлах. Она размещается в секции .data, так как инициализирована ненулевым значением.

static_var — статическая переменная, видимая только в пределах file1.c. Она также размещается в секции .data, но её символ помечен как локальный (l), поэтому она не видна в таблице символов других файлов.