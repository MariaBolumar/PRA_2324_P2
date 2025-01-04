#include "DyV.h"
#include <vector>
#include <iostream>
#include <ctime> 	
#include <chrono> 

template <typename T> void imprimirVector(std::vector<T>& vec){
	std::cout << "[";
	for (int i = 0; i < vec.size(); i++){
		std::cout << vec[i];
		if(i != vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
	std::cout << std::endl;
}

int main(){

	// Pruebas busquedaBinaria 	
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<char> b = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	std::vector<double> c = {1.22, 2.45, 3.76, 4.0, 5.92};
	int A;
        char B;
        double C;

	// Función para imprimir un vector de tipo genérico
	std::cout << "Vector de enteros ordenado de menor a mayor: " << std::endl;
	imprimirVector(a);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
        std::cin >> A;
        std::cout << std::endl;

	std::cout << "Vector de caractéres ordenado de menor a mayor: " << std::endl;
	imprimirVector(b);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
	std::cin >> B;
	std::cout << std::endl;

	std::cout << "Vector de flotantes ordenado de menor a mayor: " << std::endl;
	imprimirVector(c);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
	std::cin >> C;
	std::cout << std::endl;

	int posicion1 = busquedaBinaria(a, 0, a.size() -1 , A);	
	if(posicion1 == -1)
                std::cout << "No se ha encontrado el elemento " << A  << std::endl;
        else
                std::cout << "La posición del elemento " << A << " es: " << 1+posicion1 << std::endl;

	int posicion2 = busquedaBinaria(b, 0, b.size() -1 , B); 
	if(posicion2 == -1)
                std::cout << "No se ha encontrado el elemento " << B << std::endl;
        else
                std::cout << "La posición del elemento " << B << " es: " << 1+posicion2 << std::endl;


	int posicion3 = busquedaBinaria(c, 0, c.size() -1 , C); 
	if(posicion3 == -1)
		std::cout << "No se ha encontrado el elemento " << C << std::endl;
	else
		std::cout << "La posición del elemento " << C << " es: " << 1+posicion3 << std::endl;

	// Pruebas busquedaBinariai_INV

	std::vector<int> d = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<char> e = {'d', 'c', 'b', 'a'};
	std::vector<double> f = {5.25, 4.10, 3.0, 2.15, 1.99};
	int D;
        char E;
        double F;

	std::cout << "Vector de enteros ordenado de mayor a menor: " << std::endl;
	imprimirVector(d);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
        std::cin >> D;
	std::cout << std::endl;
	int posicion4 = busquedaBinaria_INV(d, 0, d.size() -1 , D);
	if(posicion4 == -1)
		std::cout << "No se ha encontrado el elemento " << D << std::endl;
	else
		std::cout << "La posición del elemento " << D << " es: " << 1+posicion4 << std::endl;

	
	std::cout << "Vector de caractéres ordenado de mayor a menor: " << std::endl;
	imprimirVector(e);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
	std::cin >> E;
	std::cout << std::endl;
	int posicion5 = busquedaBinaria_INV(e, 0, e.size() -1 , E);
	if(posicion5 == -1)
		std::cout << "No se ha encontrado el elemento " << E << std::endl;
	else
		std::cout << "La posición del elemento " << E << " es: " << 1+posicion5 << std::endl;

	
	std::cout << "Vector de flotantes ordenado de mayor a menor: " << std::endl;
	imprimirVector(f);
	std::cout << std::endl;
	std::cout << "Introduzca el elemento a buscar: ";
	std::cin >> F;
	std::cout << std::endl;
	int posicion6 = busquedaBinaria_INV(f, 0, f.size() -1 , F);
	if(posicion6 == -1)
		std::cout << "No se ha encontrado el elemento " << F << std::endl;
	else
		std::cout << "La posición del elemento " << F << " es: " << 1+posicion6 << std::endl;


	// Pruebas QuickSort

	std::vector<int> g = {11, 16, 2, 8, 1, 9, 4, 7};
	std::vector<double> h = {7.5, 1.3, 12.9, 5.2, 2.16, 9.92};
	std::vector<char> i = {'d', 'a', 'n', 'l', 'z'};

	// Vector g

	std::cout << "Vector de enteros desordenado: " << std::endl;
	imprimirVector(g);
	std::cout << std::endl;

	std::cout << "Tiempo de ejecución de quickSortFin(): " << std::endl;
	auto start = std::chrono::system_clock::now();	
	QuickSortFin(g, 0, g.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(g);
	std::cout << std::endl;
	
	std::cout << "Tiempo de ejecución de quickSortIni(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortIni(g, 0, g.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(g);
	std::cout << std::endl;
	
	srand(static_cast<unsigned int>(time(0)));
	std::cout << "Tiempo de ejecución de quickSortRandom(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortRandom(g, 0, g.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(g);
	std::cout << std::endl;

	// Vector h

	std::cout << "Vector de flotantes desordenado: " << std::endl;
	imprimirVector(h);
	std::cout << std::endl;

	std::cout << "Tiempo de ejecución de quickSortFin(): " << std::endl;
	start = std::chrono::system_clock::now();	
	QuickSortFin(h, 0, h.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(h);
	std::cout << std::endl;
	
	std::cout << "Tiempo de ejecución de quickSortIni(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortIni(h, 0, h.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(h);
	std::cout << std::endl;
	
	srand(static_cast<unsigned int>(time(0)));
	std::cout << "Tiempo de ejecución de quickSortRandom(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortRandom(h, 0, h.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(h);
	std::cout << std::endl;
	
	// Vector i

	std::cout << "Vector de caractéres desordenado: " << std::endl;
	imprimirVector(i);
	std::cout << std::endl;


	std::cout << "Tiempo de ejecución de quickSortFin(): " << std::endl;
	start = std::chrono::system_clock::now();	
	QuickSortFin(i, 0, i.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(i);
	std::cout << std::endl;
	
	std::cout << "Tiempo de ejecución de quickSortIni(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortIni(i, 0, i.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(i);
	std::cout << std::endl;
	
	srand(static_cast<unsigned int>(time(0)));	// Activamos la semilla de randoms
	std::cout << "Tiempo de ejecución de quickSortRandom(): " << std::endl;
	start = std::chrono::system_clock::now();	
	quickSortRandom(i, 0, i.size()-1);	// QuickSort() me pone en g el vector ordenado, luego después con imprimir g ya me sirve	
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time: " << duration.count() << "s" << std::endl;

	imprimirVector(i);

	return 0;
}
