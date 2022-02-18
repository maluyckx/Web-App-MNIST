FLAG = -lPocoFoundation -lPocoUtil -lPocoNet


output: Handler.o HTTPserver.o
	g++ Handler.o HTTPserver.o -o Httpserver $(FLAG)

*.o: *.ccp *.hpp
	g++ *.ccp *.hpp -c $(FLAG)

clean: 
	rm *.o Httpserver

restart: 
	clean
	output