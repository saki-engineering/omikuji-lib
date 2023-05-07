NAME = libomikuji.a
SRC = omikuji.cpp
OBJS = omikuji.o

CPP = g++
CPPOPTS = -std=c++11
CPPFLAGS = -g -I.

%.o : %.CPP
	$(CPP) $(CPPOPTS) $(CPPFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

sample-run:
	$(CPP) $(CPPFLAGS) -lomikuji -L. sample/main.cpp -o sample/a.out
	sample/a.out
	rm sample/a.out
	rm -rf sample/a.out.dSYM