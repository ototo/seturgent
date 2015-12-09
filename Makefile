CC=gcc
CFLAGS=-O2 -Wall
LIBS=`pkg-config --cflags --libs x11`

OUTPUT=seturgent

$(OUTPUT): seturgent.o
	$(CC) $(CFLAGS) -o $(OUTPUT) seturgent.o $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o $(OUTPUT)
