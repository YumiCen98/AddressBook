CC = gcc
CFLAGS = -c -o
CFLAGSs = -o

OBJS = AddressBook.o Operation.o
TARGET = AddressBook

$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(CFLAGSs) $(TARGET)

%.o:%.C
	$(CC) $(OBJS) $(CFLAGS) $^ $@

.PHONY:clean
clean:
	rm $(OBJS) $(TARGET)