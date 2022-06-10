 #-*- Makefile -*-

atm: print main.o acc.o log.o user.o
	gcc -g -pthread main.o acc.o log.o user.o -o output/atm
	rm *.o
# print the messege in the screen that the app is start building
print:
	@echo "Start building the app...."
# compile main.c 
main.o: src/main.c
	gcc -c src/main.c

acc.o: man/signUp/acc.c man/signUp/acc.h
	gcc -c man/signUp/acc.c

log.o: man/logIn/log.c man/logIn/log.h
	gcc -c man/logIn/log.c

user.o: user/user.c user/user.h
	gcc -c user/user.c

clean:
	rm output/atm

delete:
	rm -r gen/accounts/

