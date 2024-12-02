#include <vector>
#include <iostream>

int BusquedaBinaria(int X, const std::vector<int>& V, int ini, int fin) {
    if (ini > fin) {
        return -1; // No se encuentra en el array
    }
    int medio = (ini + fin) / 2;
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return BusquedaBinaria(X, V, ini, medio - 1);
    } else {
        return BusquedaBinaria(X, V, medio + 1, fin);
    }
}
