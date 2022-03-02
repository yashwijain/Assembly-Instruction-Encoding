#
EXECS = assemble 
HEADER = project1.h
OBJS = project1.o methods.o

#### use next two lines for Mac
##CC = clang++
##CCFLAGS = -std=gnu++2a -stdlib=libc++

#### use next two lines for mathcs* machines:
CC = g++
CCFLAGS = -std=c++17 -g

all: $(EXECS)

.SUFFIXES: .cpp .o

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

assemble:${OBJS}
	$(CC) $(CCFLAGS) -o $@ ${OBJS}

project1.o: project1.h methods.h

methods.o: methods.h

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
