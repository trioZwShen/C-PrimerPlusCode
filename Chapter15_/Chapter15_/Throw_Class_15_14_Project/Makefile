useSales : useSales.o Sales.o
	g++ useSales.o Sales.o -o useSales

useSales.o : useSales.cpp Sales.hpp
	g++ -c useSales.cpp

Sales.p : Sales.cpp Sales.hpp
	g++ -c Sales.cpp


clean:
	@echo "CLEAN BEGIN"
	-rm *.o useSales	#Delete .o file AND useSales
	@echo "CLEAN END"
.PHONY: clean
