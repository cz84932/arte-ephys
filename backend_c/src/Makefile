CC = g++
LD = $(CC)

LDFLAGS = -D__STDC_LIMIT_MACROS -std=c++0x -ldl -lzmq `pkg-config yaml-cpp --libs`
LNIDAQ  = -lnidaqmx

NIDAQMX_PATH = /usr/local/include/NIDAQmx.h

CFLAGS  = -D__STDC_LIMIT_MACROS -pthread -std=c++0x -O2

SRCS = dataSource.cpp 
OBJS = dataSource.o   

ifeq ($(wildcard $(NIDAQMX_PATH)),)
	LDFLAGS := $(LDFLAGS) $(LNIDAQ)
	CFLAGS  := $(CFLAGS)  -DUSE_NIDAQMX
else
	CFLAGS  := $(CFLAGS)  -DUSE_MOCK_NIDAQMX
endif

.SUFFIXES:
.SUFFIXES: .o .c .cpp .cc

dataSource : $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean

clean :
	rm -f dataSource
	rm -f dataSource.o