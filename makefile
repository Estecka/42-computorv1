HDRS = \
	Polynomial.hpp

SRCS = main.cpp \
	ptoa.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME =  computor
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME}

${NAME}: ${HDRS} ${OBJS}
	${CXX} ${OBJS} -o ${NAME} ${CPPFLAGS}

${OBJS}: ${HDRS}

%.a: lib
	make $(@F) -C $(@D)

headers_test: ${HDRS:.hpp=.hpp.o}
%.hpp.o: ${HDRS}
	${CXX} ${CPPFLAGS} ${@:.o=} -c -o $@
%.hpp:

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
