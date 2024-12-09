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

int Partition(std::vector<int>& V, int ini, int fin) {
    int x = V[fin];
    int i = ini - 1;
    for (int j = ini; j < fin; ++j) {
        if (V[j] <= x) {
            ++i;
            std::swap(V[i], V[j]);
        }
    }
    std::swap(V[i + 1], V[fin]);
    return i + 1;
}

void QuickSort(std::vector<int>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}
