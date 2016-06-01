OBJS		=	core/tz_info.o core/wall_time.o
TEST_OBJS	=	core/date.o core/greg_date.o core/tz_info.o core/wall_time.o core/calculator.o

LIBS		=	libcore.a
TESTS		=	testCore

include ../include/Makefile

