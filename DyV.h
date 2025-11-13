#ifndef DYV_H
#define DYV_H

#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Búsqueda Binaria en vector ordenado ascendentemente
template <typename T>
int BusquedaBinaria(T x, std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No se encuentra en el array
    }
    
    int medio = (ini + fin) / 2;
    
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] > x) {
        return BusquedaBinaria(x, v, ini, medio - 1);
    } else {
        return BusquedaBinaria(x, v, medio + 1, fin);
    }
}

// Búsqueda Binaria en vector ordenado descendentemente
template <typename T>
int BusquedaBinaria_INV(T x, std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No se encuentra en el array
    }
    
    int medio = (ini + fin) / 2;
    
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] < x) {
        return BusquedaBinaria_INV(x, v, ini, medio - 1);
    } else {
        return BusquedaBinaria_INV(x, v, medio + 1, fin);
    }
}

// Función auxiliar para intercambiar dos elementos
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Partition: coloca el pivote en su posición correcta
template <typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
    T x = v[fin]; // Pivote: último elemento
    int i = ini;
    
    for (int j = ini; j < fin; j++) {
        if (v[j] <= x) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

// QuickSort con pivote al final
template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(v, ini, fin);
        QuickSort(v, ini, pivot - 1);
        QuickSort(v, pivot + 1, fin);
    }
}

// Partition con pivote al inicio
template <typename T>
int PartitionFirst(std::vector<T>& v, int ini, int fin) {
    swap(v[ini], v[fin]); // Mover primer elemento al final
    return Partition(v, ini, fin);
}

// QuickSort con pivote al inicio
template <typename T>
void QuickSortFirst(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionFirst(v, ini, fin);
        QuickSortFirst(v, ini, pivot - 1);
        QuickSortFirst(v, pivot + 1, fin);
    }
}

// Partition con pivote central
template <typename T>
int PartitionMiddle(std::vector<T>& v, int ini, int fin) {
    int medio = (ini + fin) / 2;
    swap(v[medio], v[fin]); // Mover elemento central al final
    return Partition(v, ini, fin);
}

// QuickSort con pivote central
template <typename T>
void QuickSortMiddle(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionMiddle(v, ini, fin);
        QuickSortMiddle(v, ini, pivot - 1);
        QuickSortMiddle(v, pivot + 1, fin);
    }
}

// Partition con pivote aleatorio
template <typename T>
int PartitionRandom(std::vector<T>& v, int ini, int fin) {
    int random = ini + rand() % (fin - ini + 1);
    swap(v[random], v[fin]); // Mover elemento aleatorio al final
    return Partition(v, ini, fin);
}

// QuickSort con pivote aleatorio
template <typename T>
void QuickSortRandom(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionRandom(v, ini, fin);
        QuickSortRandom(v, ini, pivot - 1);
        QuickSortRandom(v, pivot + 1, fin);
    }
}

#endif // DYV_H
