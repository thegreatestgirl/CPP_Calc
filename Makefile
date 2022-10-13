CC=g++
CFLAGS=
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
  LDFLAGS= -lgtest -lgtest_main -pthread -lm
else
  LDFLAGS=-lgtest -lgtest_main -pthread -lsubunit -lrt -lpthread -lm
endif
LIBSRC=$(filter-out test.cpp, $(wildcard *.cpp))
LIBOBJ=$(LIBSRC:.c=.o)
EXECUTABLE=result_file
LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report
MAINCPP=try.cpp
TST_LBS=$(shell pkg-config --libs check)
ARCHIVE_DIR=CalcDist
ARCHIVE_NAME=CalcArchive.tgz
APP = Calc/Calc.app


all:
	$(CC) test.cpp $(MAINCPP) -o $(EXECUTABLE) -lgtest -lgtest_main -pthread

tests:
	$(CC) test.cpp $(MAINCPP) -o $(EXECUTABLE) -lgtest -lgtest_main -pthread
	./$(EXECUTABLE)

lcov:
	$(CC) --coverage test.cpp $(MAINCPP) -o $(EXECUTABLE) -lgtest -lgtest_main -pthread
	./$(EXECUTABLE)
	lcov -t "Calc_test" -o $(EXECUTABLE).info -c -d .
	genhtml -o report $(EXECUTABLE).info
	open report/$(shell pwd)/index.html

gcov_report: lcov

clean:
	rm -rf *.o $(EXECUTABLE) *.gcno *.gcda *.gcov $(LCOVEXEC) $(REPORTDIR)
	rm -rf $(HOME)/Desktop/$(ARCHIVE_NAME)
	cd Calc/; make clean

leaks: test
	CK_FORK=no leaks --atExit -- ./$(EXECUTABLE)

style:
	python3 ../materials/linters/cpplint.py try.cpp try.h test.cpp


install:
	rm -rf $(HOME)/Desktop/Calc/
	cd ./Calc; qmake Calc.pro
	cd ./Calc; make
	@mkdir $(HOME)/Desktop/Calc/
	@cp -rf $(APP) $(HOME)/Desktop/Calc/
	make clean
	
uninstall:
	@rm -rf $(HOME)/Desktop/Calc/

dvi:
	open dvi.html

dist:
	rm -f $(HOME)/$(ARCHIVE_NAME)
	mkdir -p $(ARCHIVE_DIR)
	@cp -r Makefile *.cpp *.h Calc $(ARCHIVE_DIR)
	tar cvzf $(ARCHIVE_NAME) $(ARCHIVE_DIR)
	mv $(ARCHIVE_NAME) $(HOME)/Desktop/
	rm -rf $(ARCHIVE_DIR)
