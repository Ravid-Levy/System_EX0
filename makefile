CC = gcc
FLAGS = -Wall -g

run1: main1_1
	./$<

run2: main1_2
	./$<

run3: main1_3
	./$<

run4: main1_4
	./$<

log:
	grep myDaemon /var/log/syslog

all: main1_4

main1_4: main1_1 main1_2 main1_3 main1_4 main1_4.c
	$(CC) $(FLAGS) -o main1_4 main1_4.c

main1_1: main1_2.c
	$(CC) $(FLAGS) -o main1_1 main1_1.c

main1_2: main1_2.c
	$(CC) $(FLAGS) -o main1_2 main1_2.c

main1_3: main1_3.c 
	$(CC) $(FLAGS) -o main1_3 main1_3.c

.PHONY: clean all

clean:
	rm -f *.o *.a main1_2 main1_3 main1_1 main1_4