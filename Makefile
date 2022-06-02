 #-*- Makefile -*-

atm: print main.o acc.o clear_memory.o log.o
	gcc -g -pthread main.o acc.o clear_memory.o log.o -o output/atm
	rm *.o
# print the messege in the screen that the app is start building
print:
	@echo "Start building the app...."
# compile main.c 
main.o: src/main.c
	gcc -c src/main.c

generate.o: gen/generate.c gen/generate.h
	gcc -c gen/generate.c

acc.o: man/signUp/acc.c man/signUp/acc.h
	gcc -c man/signUp/acc.c

clear_memory.o: mem/clear_memory.c mem/clear_memory.h
	gcc -c mem/clear_memory.c

log.o: man/logIn/log.c man/logIn/log.h
	gcc -c man/logIn/log.c

clean:
	rm output/atm

delete:
	rm -r gen/accounts/

