OBJS = main.0 McodeMod.o
CC = gcc
DEBUG = 
CFLAGS = =Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Mcode: $(OBJS)
  $(CC) $(LFLAGS) $(OBJS) -o Mcode

main.o: main.c McodeMod.h
  $(CC) $(CFLAGS) main.c
McodeMod.o: McodeMod.c McodeMod.h
  $(CC) $(CFLAGS) McodeMod.c
clean:
  \rm *.o *~ Mcode
tar:
  tar cfv Mcode.tar main.c McodeMod.c McodeMod.h
