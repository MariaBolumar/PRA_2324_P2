#include "DyV.h"


int main() {
    	std::vector<int> V(5);
    	int X, resultado;

	std::cout << "Introduce el vector: ";
    	for(int i = 0; i< 5; i++){
		std::cin>> V[i];
	}
	std::cout << "\nIntroduce el valor a buscar: ";
	std::cin>>X;
	
	QuickSort(V, 0, V.size() - 1);
    	std::cout << "Vector ordenado: ";
    	for (int i = 0; i < V.size(); ++i) {
        	std::cout << V[i] << " ";
    	}
	std::cout << "\n";

	resultado = BusquedaBinaria(X, V, 0, V.size() - 1);
	
	if (resultado != -1) {
        	std::cout << "El valor " << X << " se encuentra en la posición " << resultado+1 << std::endl;
    	} else {
        	std::cout << "El valor " << X << " no se encuentra en el array" << std::endl;
	}


	return 0;
}
