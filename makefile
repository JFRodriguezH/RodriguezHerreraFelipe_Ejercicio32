onda.png : onda.dat onda.py
	python onda.py

onda.dat : onda.out
	./onda.out 0.0001 0.1

onda.out : onda.cpp
	c++ onda.cpp -o onda.out
	
clean : 
	rm onda.out onda.dat onda.png