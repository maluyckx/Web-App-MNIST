FLAG = -Wall -lPocoFoundation -lPocoUtil -lPocoNet -lpython3.9 -I/usr/include/python3.9 -I/usr/include/cpython/initconfig.h


output: Handler.o HTTPserver.o
	g++ Handler.o HTTPserver.o -o Httpserver $(FLAG)

*.o: *.ccp *.hpp
	g++ *.ccp *.hpp -c $(FLAG)

clean: 
	rm *.o Httpserver

restart: 
	clean
	output
