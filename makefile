onda.png : onda.dat onda.py
	python onda.py

onda.dat : onda.out
	./onda.out 0.001 2.0

onda.out : onda.cpp
	c++ onda.cpp -o onda.out