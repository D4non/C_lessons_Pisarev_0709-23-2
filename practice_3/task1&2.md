# Задание 1, 2

### 1. global_var
Секция: .data
global_var — это инициализированная глобальная переменная. Инициализированные глобальные переменные размещаются в секции .data.

### 2. uninitialized_global_var
Секция: .bss
uninitialized_global_var — это неинициализированная глобальная переменная. Неинициализированные глобальные переменные размещаются в секции .bss (Block Started by Symbol).

### 3. static_var
Секция: .data
static_var — это статическая переменная с инициализацией. Статические переменные с инициализацией размещаются в секции .data.

### 4. global_point
Секция: .data
global_point — это инициализированная глобальная структура. Инициализированные глобальные данные размещаются в секции .data.

### 5. local_var из функции print_message
Секция: Стек (stack)
local_var — это локальная переменная функции. Локальные переменные размещаются на стеке во время выполнения программы.

### 6. static_local_var из функции print_message
Секция: .data
static_local_var — это статическая локальная переменная с инициализацией. Статические локальные переменные с инициализацией размещаются в секции .data.

### 7. auto_var из функции main
Секция: Стек (stack)
auto_var — это автоматическая (локальная) переменная функции. Локальные переменные размещаются на стеке во время выполнения программы.

### 8. dynamic_var
Секция: Куча (heap)
dynamic_var — это указатель на динамически выделенную память. Динамически выделенная память размещается в куче (heap) во время выполнения программы.

### 9. stack_point
Секция: Стек (stack)
stack_point — это локальная переменная структуры, размещенная на стеке. Локальные переменные размещаются на стеке во время выполнения программы.