build/entidades/Pessoa.o: src/entidades/Pessoa.o include/Pessoa.o 
	${CC} -c -o src/entidades/Pessoa.cpp

build/entidades/Funcionario.o: src/entidades/Funcionario.cpp
	${CC} -c src/entidades/Funcionario.cpp include/Funcionario.hpp

build/entidades/Professor.o: src/entidades/Professor.cpp 
	${CC} -c src/entidades/Professor.cpp 

build/main.o: src/main.cpp build/Funcionario.o build/Professor.o
	${CC} -c -o /main.cpp

