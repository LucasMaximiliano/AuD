SRCS=$(wildcard */*.cpp)
ELFS=$(patsubst %.cpp,%,$(SRCS))

all: $(ELFS)

%: %.cpp
	$(CXX) $(CFLAGS) -o bin/$@ $<


