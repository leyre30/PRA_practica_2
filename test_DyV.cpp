#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "DyV.h"

using namespace std;

// Función auxiliar para imprimir vectores
template <typename T>
void printVector(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Función para generar vector aleatorio
vector<int> generarVectorAleatorio(int size, int maxValue = 1000) {
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        v[i] = rand() % maxValue;
    }
    return v;
}

void testBusquedaBinaria() {
    cout << "\n=== PRUEBAS DE BÚSQUEDA BINARIA ===" << endl;
    
    // Test con enteros
    vector<int> vInt = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "\nVector de enteros (ascendente): ";
    printVector(vInt);
    
    int buscar = 7;
    int pos = BusquedaBinaria(buscar, vInt, 0, vInt.size() - 1);
    cout << "Buscando " << buscar << ": ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    
    buscar = 8;
    pos = BusquedaBinaria(buscar, vInt, 0, vInt.size() - 1);
    cout << "Buscando " << buscar << ": ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    
    // Test con floats
    vector<float> vFloat = {1.5f, 2.3f, 3.7f, 4.2f, 5.9f};
    cout << "\nVector de floats (ascendente): ";
    printVector(vFloat);
    
    float buscarF = 3.7f;
    pos = BusquedaBinaria(buscarF, vFloat, 0, vFloat.size() - 1);
    cout << "Buscando " << buscarF << ": ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    
    // Test con chars
    vector<char> vChar = {'a', 'c', 'e', 'g', 'i', 'k'};
    cout << "\nVector de chars (ascendente): ";
    printVector(vChar);
    
    char buscarC = 'e';
    pos = BusquedaBinaria(buscarC, vChar, 0, vChar.size() - 1);
    cout << "Buscando '" << buscarC << "': ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
}

void testBusquedaBinaria_INV() {
    cout << "\n=== PRUEBAS DE BÚSQUEDA BINARIA INVERSA ===" << endl;
    
    // Test con enteros descendentes
    vector<int> vInt = {20, 18, 15, 12, 9, 6, 3, 1};
    cout << "\nVector de enteros (descendente): ";
    printVector(vInt);
    
    int buscar = 12;
    int pos = BusquedaBinaria_INV(buscar, vInt, 0, vInt.size() - 1);
    cout << "Buscando " << buscar << ": ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    
    buscar = 10;
    pos = BusquedaBinaria_INV(buscar, vInt, 0, vInt.size() - 1);
    cout << "Buscando " << buscar << ": ";
    if (pos != -1) {
        cout << "Encontrado en posición " << pos << endl;
    } else {
        cout << "No encontrado" << endl;
    }
}

void testQuickSort() {
    cout << "\n=== PRUEBAS DE QUICKSORT ===" << endl;
    
    // Test con enteros
    vector<int> vInt = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17, 28, 63, 72, 41};
    cout << "\nVector original: ";
    printVector(vInt);
    
    QuickSort(vInt, 0, vInt.size() - 1);
    cout << "Después de QuickSort: ";
    printVector(vInt);
    
    // Test con floats
    vector<float> vFloat = {3.5f, 1.2f, 4.8f, 2.1f, 5.9f, 0.3f};
    cout << "\nVector de floats original: ";
    printVector(vFloat);
    
    QuickSort(vFloat, 0, vFloat.size() - 1);
    cout << "Después de QuickSort: ";
    printVector(vFloat);
}

void testComparacionQuickSort() {
    cout << "\n=== COMPARACIÓN DE VARIANTES DE QUICKSORT ===" << endl;
    
    srand(time(NULL));
    
    const int SIZE = 10000;
    vector<int> original = generarVectorAleatorio(SIZE);
    
    cout << "\nOrdenando vector de " << SIZE << " elementos..." << endl;
    
    // QuickSort con pivote al final
    vector<int> v1 = original;
    auto start = chrono::system_clock::now();
    QuickSort(v1, 0, v1.size() - 1);
    auto end = chrono::system_clock::now();
    chrono::duration<float, milli> duration = end - start;
    cout << "QuickSort (pivote final): " << duration.count() << " ms" << endl;
    
    // QuickSort con pivote al inicio
    vector<int> v2 = original;
    start = chrono::system_clock::now();
    QuickSortFirst(v2, 0, v2.size() - 1);
    end = chrono::system_clock::now();
    duration = end - start;
    cout << "QuickSort (pivote inicial): " << duration.count() << " ms" << endl;
    
    // QuickSort con pivote central
    vector<int> v3 = original;
    start = chrono::system_clock::now();
    QuickSortMiddle(v3, 0, v3.size() - 1);
    end = chrono::system_clock::now();
    duration = end - start;
    cout << "QuickSort (pivote central): " << duration.count() << " ms" << endl;
    
    // QuickSort con pivote aleatorio
    vector<int> v4 = original;
    start = chrono::system_clock::now();
    QuickSortRandom(v4, 0, v4.size() - 1);
    end = chrono::system_clock::now();
    duration = end - start;
    cout << "QuickSort (pivote aleatorio): " << duration.count() << " ms" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "  PRUEBAS DE ALGORITMOS DIVIDE Y VENCERÁS" << endl;
    cout << "========================================" << endl;
    
    testBusquedaBinaria();
    testBusquedaBinaria_INV();
    testQuickSort();
    testComparacionQuickSort();
    
    cout << "\n========================================" << endl;
    cout << "  TODAS LAS PRUEBAS COMPLETADAS" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
