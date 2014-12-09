CC      := gcc
LD		:= ld
CFLAGS  := -I./include
LIB     := -L./lib
SRCS	:= LatLng.c LatLngBounds.c
OBJS	:= ${SRCS:.c=.o}

%.o : %.c
	$(CC) $(CFLAGS) -c *.c 

all : $(OBJS)
	$(LD) -lc $(OBJS) -o LatLngBounds.a

clean :
	rm *.o
