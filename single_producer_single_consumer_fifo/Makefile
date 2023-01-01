NAME=singlepc_fifo
all:
	g++ -I/home/nicko/implementations/systemc-2.3.3/include main_sc.cpp -o $(NAME) -L/home/nicko/implementations/systemc-2.3.3/lib-linux64  -lsystemc  -fpermissive

view:
	gtkwave my_db.vcd
run:
	./$(NAME)
clean:
	rm $(NAME) my_db.vcd
