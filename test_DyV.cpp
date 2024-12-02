#include "DyV.h"


int main() {
    	std::vector<int> V(6);
    	int X, resultado;

	std::cout << "Introduce el vector: ";
    	for(int i = 0; i< 6; i++){
		std::cin>> V[i];
	}
	std::cout << "\nIntroduce el valor a buscar: ";
	std::cin>>X;

	resultado = BusquedaBinaria(X, V, 0, V.size() - 1);
	
	if (resultado != -1) {
        	std::cout << "El valor " << X << " se encuentra en la posición " << resultado << std::endl;
    	} else {
        	std::cout << "El valor " << X << " no se encuentra en el array" << std::endl;
	}
	QuickSort(V, 0, V.size() - 1);
    	std::cout << "Vector ordenado: ";
    	for (int i = 0; i < V.size(); ++i) {
        	std::cout << V[i] << " ";
    	}
    	std::cout << std::endl;

	return 0;
}
