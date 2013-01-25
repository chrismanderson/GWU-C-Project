OBJS=server.o simple_http.o content.o main.o util.o ring_buffer.o
CFLAGS=-g -I. -std=c99 -Wall -Wextra -lpthread
#DEFINES=-DTHINK_TIME
BIN=server
CC=gcc

%.o:%.c
	$(CC) $(DEFINES) -o $@ -c $< $(CFLAGS)

$(BIN): $(OBJS)
	$(CC) $(DEFINES) -o $(BIN) $^ $(CFLAGS)

clean:
	rm $(BIN) $(OBJS)

test0:
	./server 8082 0 &
	httperf --port=8082 --server=localhost --num-conns=1
	killall server

test1:
	./server 8080 1 &
	httperf --port=8080 --server=localhost --num-conns=1000 --burst-len=100
	killall server

test2:
	./server 8095 1 &
	httperf --port=8095 --server=localhost --num-conns=1000 --burst-len=100
	killall server
