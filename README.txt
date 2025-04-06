MANERA DE COMPILAR EL CODIGO Y EJECUTAR//Ayuda de chat para esta solucion

//COMPILAR
gcc -c src/sqlite3.c -o obj/sqlite3.o -DSQLITE_THREADSAFE=0
gcc -c src/reserva.c -o obj/reserva.o -Iinclude
gcc -c src/db.c -o obj/db.o -Iinclude
gcc -c src/cliente.c -o obj/cliente.o -Iinclude
gcc -c src/config.c -o obj/config.o -Iinclude
gcc -c src/main.c -o obj/main.o -Iinclude
gcc obj/sqlite3.o obj/reserva.o obj/db.o obj/cliente.o obj/config.o obj/main.o -o bin/cliente_deustorante.exe

//EJECUTAR

.\bin\cliente_deustorante.exe