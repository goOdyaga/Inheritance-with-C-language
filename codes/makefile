ALL: Compile Execute

Compile:Uretim Taktik Koloni Oyun Test
Test:
	gcc -I ./include/ -o ./bin/Test ./lib/Uretim.o ./lib/AUretim.o ./lib/BUretim.o ./lib/Taktik.o ./lib/Ataktik.o ./lib/Btaktik.o ./lib/Koloni.o ./lib/Oyun.o ./src/Test.c
# 	gcc -I ./include -c ./src/Test.c -o ./lib/Test.o	
Uretim:
	gcc -I ./include -c ./src/Uretim.c -o ./lib/Uretim.o
	gcc -I ./include -c ./src/AUretim.c -o ./lib/AUretim.o
	gcc -I ./include -c ./src/BUretim.c -o ./lib/BUretim.o
Taktik:
	gcc -I ./include -c ./src/Taktik.c -o ./lib/Taktik.o
	gcc -I ./include -c ./src/Ataktik.c -o ./lib/Ataktik.o
	gcc -I ./include -c ./src/Btaktik.c -o ./lib/Btaktik.o
Koloni:
	gcc -I ./include -c ./src/Koloni.c -o ./lib/Koloni.o
Oyun:
	gcc -I ./include -c ./src/Oyun.c -o ./lib/Oyun.o

Execute:
	./bin/Test