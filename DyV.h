#include <vector>
#include <iostream>

template <typename T> int busquedaBinaria(std::vector<T>& V, int ini, int fin, T X) {
    if (ini > fin) {
        return -1; // No se encuentra en el array
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return busquedaBinaria(V, ini, medio - 1, X);
    } else {
        return busquedaBinaria(V, medio + 1, fin, X);
    }
}
template <typename T> int busquedaBinaria_INV(std::vector<T>& V, int ini, int fin, T x){
	// NO lo encontramos en el vector
	if(ini > fin){
		return -1;
	}
	// Caso recursivo
	int medio = (ini + fin) / 2;	// Usamos esto y no (ini + fin) / 2 porque así evitamos que se den problemas de overflow en casos extremos

	if(V[medio] == x){
		return medio;
	} else if (V[medio] < x){// Si el valor del medio del array es < x, buscamos x en el lado izquierdo
		return busquedaBinaria_INV(V, ini, medio-1, x);
	} else {			// Si el valor del medio del array es > x, buscamos x en el subarray derecho
		return busquedaBinaria_INV(V, medio+1, fin, x);
	}
}

template <typename T> int ParticionFin(std::vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;
    for (int j = ini; j < fin-1; j++) {
        if (V[j] <= x) {
            std::swap(V[i], V[j]);
	    i++;
        }
    }
    std::swap(V[i], V[fin]);
    return i;
}

template <typename T> void QuickSortFin(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = ParticionFin(V, ini, fin);
        QuickSortFin(V, ini, pivot - 1);
        QuickSortFin(V, pivot + 1, fin);
    }
}
template <typename T> int particionIni(std::vector<T>& V, int ini, int fin){
	int i = fin;
	for(int j = fin; j >= ini+1; j--){
		if(V[j] >= V[ini]){
			std::swap(V[i], V[j]);
			i--;
		}
	}
	std::swap(V[i], V[ini]);

	return i;
}
template <typename T> void quickSortIni(std::vector<T>& V, int ini, int fin){
	if (ini < fin){
		int pivote = particionIni(V, ini, fin);
		quickSortIni(V, ini, pivote-1);
		quickSortIni(V, pivote+1, fin);
	}
}

template <typename T> int particionRandom(std::vector<T>& V, int ini, int fin){
	int pivoteIndex = ini + rand() % (fin - ini + 1);
	std::swap(V[pivoteIndex], V[fin]);		
	int i = ini;
	for(int j = ini; j <= fin-1; j++){
		if(V[j] <= V[fin]){
			std::swap(V[i], V[j]);
			i++;
		}
	}
	std::swap(V[i], V[fin]);
 
	return i;
}

template <typename T> void quickSortRandom(std::vector<T>& V, int ini, int fin){
	if (ini < fin){

		int pivote = particionRandom(V, ini, fin);
		quickSortRandom(V, ini, pivote-1);
		quickSortRandom(V, pivote+1, fin);
	}
}
