#* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#*                                                                         *
#*  Parallel Fully logic algoritm demo                                     *
#*  Copyright (C) 2016  Łukasz "Kuszki" Dróżdż  l.drozdz@openmailbox.org   *
#*                                                                         *
#*  This program is free software: you can redistribute it and/or modify   *
#*  it under the terms of the GNU General Public License as published by   *
#*  the  Free Software Foundation, either  version 3 of the  License, or   *
#*  (at your option) any later version.                                    *
#*                                                                         *
#*  This  program  is  distributed  in the hope  that it will be useful,   *
#*  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
#*  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
#*  GNU General Public License for more details.                           *
#*                                                                         *
#*  You should have  received a copy  of the  GNU General Public License   *
#*  along with this program. If not, see http://www.gnu.org/licenses/.     *
#*                                                                         *
#* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

QT			+=	core concurrent
QT			-=	gui

TARGET		=	Parallel-Fuzzy-Demo

CONFIG		+=	console c++14
CONFIG		-=	app_bundle

TEMPLATE		=	app

SOURCES		+=	main.cpp \
				membershipfunction.cpp \
				sigmoidfunction.cpp \
				gaussfunction.cpp \
				fuzzyvariable.cpp \
				fuzzyalgorithm.cpp

HEADERS		+=	membershipfunction.hpp \
				sigmoidfunction.hpp \
				gaussfunction.hpp \
				fuzzyvariable.hpp \
				fuzzyalgorithm.hpp

LIBS			+=	-fopenmp

QMAKE_CXXFLAGS	+=	-fopenmp
