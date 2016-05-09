OBJS		=	core/tzfile.o
TEST_OBJS	=	core/date.o core/greg_date.o core/tzfile.o

LIBS		=	libcore.a
TESTS		=	testCore

include ../include/Makefile

