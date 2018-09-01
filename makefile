CXX = clang++
OBJS =  tests.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o testkitchen

clean:
	$(RM) main $(OBJS) core *~