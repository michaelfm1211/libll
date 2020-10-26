SRC=ll.c
OBJ=${SRC:.c=.o}

.PHONY: all
all: libll.a

libll.a: ${OBJ}
	${AR} rcs $@ ${OBJ}

.PHONY: test
test: test.o libll.a
	${CC} ${CFLAGS} -g -L. -lll -lm -o $@ $<
	./test

.PHONY: clean
clean:
	rm -f ${OBJ} test.o

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@