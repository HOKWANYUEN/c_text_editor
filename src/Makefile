CFLAGS=-Wall

all:$(subst .c,.o,$(wildcard *.c))

%.o : %.c
	@gcc $(CFLAGS) -c $< -o ../obj/$@