# Задание 3

### Символы объектного файла navigation.o до связывания
0000000000000000 T calculate_distance

### Символы объектного файла fuel.o до связывания
0000000000000000 T check_fuel <br>
U printf

### Символы объектного файла main.o до связывания
U calculate_distance <br>
U check_fuel <br>
U __isoc99_scanf <br>
0000000000000000 T main <br>
U printf <br>
U __stack_chk_fail <br>

### Символы в исполняемом файле после связывания
000000000000038c r __abi_tag<br>
0000000000004010 B __bss_start<br>
0000000000001189 T calculate_distance<br>
00000000000011a7 T check_fuel<br>
0000000000004010 b completed.0<br>
                 w __cxa_finalize@GLIBC_2.2.5<br>
0000000000004000 D __data_start<br>
0000000000004000 W data_start<br>
00000000000010d0 t deregister_tm_clones<br>
0000000000001140 t __do_global_dtors_aux<br>
0000000000003db0 d __do_global_dtors_aux_fini_array_entry<br>
0000000000004008 D __dso_handle<br>
0000000000003db8 d _DYNAMIC<br>
0000000000004010 D _edata<br>
0000000000004018 B _end<br>
0000000000001308 T _fini<br>
0000000000001180 t frame_dummy<br>
0000000000003da8 d __frame_dummy_init_array_entry<br>
0000000000002258 r __FRAME_END__<br>
0000000000003fa8 d _GLOBAL_OFFSET_TABLE_<br>
                 w __gmon_start__<br>
000000000000212c r __GNU_EH_FRAME_HDR<br>
0000000000001000 T _init<br>
0000000000002000 R _IO_stdin_used<br>
                 U __isoc99_scanf@GLIBC_2.7<br>
                 w _ITM_deregisterTMCloneTable<br>
                 w _ITM_registerTMCloneTable<br>
                 U __libc_start_main@GLIBC_2.34<br>
00000000000011d3 T main<br>
                 U printf@GLIBC_2.2.5<br>
0000000000001100 t register_tm_clones<br>
                 U __stack_chk_fail@GLIBC_2.4<br>
00000000000010a0 T _start<br>
0000000000004010 D __TMC_END__<br>


### Сравнение
До связывания все функции имели формат Т, только в файле main.o все функции кроме main имели формат U, т.к. ещё не было процесса линкинга.<br>
После связывания все функции определены и имеют формат T, кроме функции printf. 