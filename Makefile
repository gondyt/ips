# name declarations 
TARGET = project
TESTBUILD = testbuild
TESTEXEC = testexec

# parameters
CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Wextra -Werror
LAFLAGS = -O1 -larmadillo
CXXTEST = -cxxtestgen --error-printer

# directory definitions
SRCDIR = src
HEADDIR = headers
TESTDIR = tests
OBJDIR = obj
GARBAGE = $(OBJDIR)/Nld.o $(OBJDIR)/main.o

ASTYLE_STYLE = google

# important rules
all : $(TARGET)

# building TARGET
$(TARGET) : $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o $(OBJDIR)/Nld.o $(OBJDIR)/main.o
	$(CXX) -o $(OBJDIR)/$(TARGET) $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o $(OBJDIR)/Nld.o $(OBJDIR)/main.o

$(OBJDIR)/Nld.o : $(SRCDIR)/NuclearLocalDensity.cpp
	$(CXX) -o $(OBJDIR)/Nld.o -c $(SRCDIR)/NuclearLocalDensity.cpp $(CXXFLAGS) $(LAFLAGS)

$(OBJDIR)/Fact.o : $(SRCDIR)/Fact.cpp
	$(CXX) -o $(OBJDIR)/Fact.o -c $(SRCDIR)/Fact.cpp $(CXXFLAGS) $(LAFLAGS)

$(OBJDIR)/Basis.o : $(SRCDIR)/Basis.cpp
	$(CXX) -o $(OBJDIR)/Basis.o -c $(SRCDIR)/Basis.cpp $(CXXFLAGS) $(LAFLAGS)

$(OBJDIR)/Poly.o : $(SRCDIR)/Poly.cpp
	$(CXX) -o $(OBJDIR)/Poly.o -c $(SRCDIR)/Poly.cpp $(CXXFLAGS) $(LAFLAGS)

$(OBJDIR)/main.o : $(HEADDIR)/Poly.h $(HEADDIR)/Basis.h
	$(CXX) -o $(OBJDIR)/main.o -c $(SRCDIR)/main.cpp $(CXXFLAGS)





# Cleaning
clean :
	rm -rf $(GARBAGE)
	rm -rf $(OBJDIR)/*.cpp
	rm -rf $(OBJDIR)/$(TARGET)
	

fclean: clean
	rm -rf $(TARGET)
	rm -rf $(OBJDIR)
	make -C $(DOCDIR) fclean
	make -C $(TESTDIR) fclean


# Building tests

mdtest0 : $(OBJDIR)/Poly.o
	$(CXXTEST) -o $(OBJDIR)/mdtest0.cpp $(TESTDIR)/MandatoryTest0.h
	$(CXX) -o $(OBJDIR)/mdtest0.o -c $(OBJDIR)/mdtest0.cpp $(CXXFLAGS)
	$(CXX) -o $(OBJDIR)/mdtest0 $(OBJDIR)/mdtest0.o $(OBJDIR)/Poly.o

mdtest1 : $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o
	$(CXXTEST) -o $(OBJDIR)/mdtest1.cpp $(TESTDIR)/MandatoryTest1.h
	$(CXX) -o $(OBJDIR)/mdtest1.o -c $(OBJDIR)/mdtest1.cpp $(CXXFLAGS)
	$(CXX) -o $(OBJDIR)/mdtest1 $(OBJDIR)/mdtest1.o $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o

mdtest2 : $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o
	$(CXXTEST) -o $(OBJDIR)/mdtest2.cpp $(TESTDIR)/MandatoryTest2.h
	$(CXX) -o $(OBJDIR)/mdtest2.o -c $(OBJDIR)/mdtest2.cpp $(CXXFLAGS)
	$(CXX) -o $(OBJDIR)/mdtest2 $(OBJDIR)/mdtest2.o $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o

mdtest3 : $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o
	$(CXXTEST) -o $(OBJDIR)/mdtest3.cpp $(TESTDIR)/MandatoryTest3.h
	$(CXX) -o $(OBJDIR)/mdtest3.o -c $(OBJDIR)/mdtest3.cpp $(CXXFLAGS)
	$(CXX) -o $(OBJDIR)/mdtest3 $(OBJDIR)/mdtest3.o $(OBJDIR)/Poly.o $(OBJDIR)/Fact.o $(OBJDIR)/Basis.o

factorial : $(OBJDIR)/Fact.o
	$(CXXTEST) -o $(OBJDIR)/factorial.cpp $(TESTDIR)/FactTest.h
	$(CXX) -o $(OBJDIR)/factorial.o -c $(OBJDIR)/factorial.cpp $(CXXFLAGS)
	$(CXX) -o $(OBJDIR)/factorial $(OBJDIR)/factorial.o $(OBJDIR)/Fact.o

$(TESTBUILD) : mdtest0 mdtest1 mdtest2 mdtest3 factorial

$(TESTEXEC) : $(TESTBUILD)
	./$(OBJDIR)/mdtest0
	./$(OBJDIR)/mdtest1
	./$(OBJDIR)/mdtest2
	./$(OBJDIR)/mdtest3
	./$(OBJDIR)/factorial

astyle:
	astyle --style=$(ASTYLE_STYLE) $(shell find $(SRCDIR) $(HEADDIR) $(TESTDIR) -name '*.cpp' -o -name '*.hpp' -o -name '*.c' -o -name '*.h') -n

help:
	@echo '$(bold)Règles du Makefile$(normal)'
	@echo "\t$(bold)$(TARGET)$(normal) \tCompile le programme dans $(TARGET)"
	@echo "\t$(bold)clean$(normal) \t\tSupprime les fichiers objets (.cpp compilés en .o)"
	@echo "\t$(bold)fclean$(normal) \t\t'clean' puis supprime le programme"
	@echo "\t$(bold)$(DOCDIR)$(normal) \t\tGénère la documentation dans le dossier $(DOCDIR)"
	@echo "\t$(bold)help$(normal) \t\tAffiche ce message d'aide"
	@echo "\t$(bold)$(TESTDIR)$(normal) \t\tLance les tests unitaires"
	@echo "\t$(bold)astyle$(normal) \t\tFormatte, indente et beautifie le code source"

	
.PHONY: all clean docs tests astyle
