# Copyright 2016 Helm Solutions Ltd
#
# This file is part of the Kentside Core Utilities Library
#
# The Kentside Core Utilities Library is free software: you can
# redistribute it and/or modify it under the terms of the GNU General
# Public License as published by the Free Software Foundation, either
# version 3 of the License, or (at your option) any later version.
#
# The Kentside Core Utilities Library is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
# the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with the Kentside Core Utilities Library.  If not, see
# <http://www.gnu.org/licenses/>.

OBJS		=	core/tz_info.o core/wall_time.o
TEST_OBJS	=	core/date.o core/greg_date.o core/y10kx.o core/tz_info.o core/wall_time.o core/calculator.o

LIBS		=	libcore.a
TESTS		=	testCore

include ../include/Makefile

