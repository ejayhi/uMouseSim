APP		= maze_test

SRCS    = src/env/maze.c test/env/MazeTest.c
OBJS    = $(SRCS:.c=.o)

CUNIT   = $(HOME)/local

CFLAGS  = -Wall -I$(CUNIT)/include
LDFLAGS = -L$(CUNIT)/lib
LIBS    = -lcunit

.PHONY: clean

$(APP) : $(OBJS)
	$(CC) $^ $(LDFLAGS) $(LIBS) -o $@

clean :
	$(RM) $(OBJS) $(APP)
