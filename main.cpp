#include <iostream>
#include <chrono>                               // Funkcja stopera, pozwoli zmierzyć czas działania
using namespace std;                            // poszczególnych algorytmów.
using namespace std::chrono;

//Algorytm QuickSort
long partition(long array[], long p, long r) {
    long x = array[p];
    long i = p;
    long j = r;

    while (true) {
        while (array[j] > x)
            j--;
        while (array[i] < x)
            i++;
        if (i < j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
        else
            return j;
    }
}

void quicksort(long array[], long p, long r) {
    long q;

    if (p < r) {
        q = partition(array,p,r);
        quicksort(array, p, q);
        quicksort(array, q+1, r);
    }
}
//Algorytm QuickSort

//Algorytm ReverseQuickSort
long reversePartition(long array[], long p, long r) {
    long x = array[p];
    long i = p;
    long j = r;
    long w;

    while (true) {
        while(array[i] > x) {
            i++;
        }

        while (array[j] < x) {
            j--;
        }

        if (i < j) {
            swap(array[i], array[j]);
            i++;
            j--;
        } else {
            return j;
        }
    }
}

void reverseQuickSort(long array[], long p, long r) {
    long q;

    if (p < r) {
        q = reversePartition(array, p, r);
        reverseQuickSort(array, p, q);
        reverseQuickSort(array, q + 1, r);
    }
}
//Algrotym ReverseQuickSort


//Algorytm HeapSort
void heapify(long array[], long n, long i) {
    long largest = i;                                           // deklaracja największego elementu
    long leftChild = 2*i+1;                                     // deklaracja lewego dziecka
    long rightChild = 2*i+2;                                    // deklaracja prawego dziecka

    if (leftChild < n && array[leftChild] > array[largest]) {   // sprawdzenie, czy lewe dziecko > największego elementu
        largest = leftChild;
    }

    if (rightChild < n && array[rightChild] > array[largest]) { // sprawdzenie, czy prawe dziecko > największego elementu
        largest = rightChild;
    }

    if (largest != i) {
        swap(array[i], array[largest]);                  // zamiana elementów w przypadku, gdy największy element
        heapify(array, n, largest);                             // różny od i
    }
}

void heapSort(long array[], long arrayLength) {

    for ( long i = arrayLength/2-1; i >= 0; i--) {
        heapify(array, arrayLength, i);
    }

    for (long i = arrayLength-1; i>=0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
//Algorytm HeapSort

//Algorytm ReverseQuickSort                             // algorytm HeapSort sortujący elementy od największego do najmniejszego
void reverseHeapify(long array[], long n, long i) {
    long smallest = i;
    long leftChild = 2 * i + 1;
    long rightChild = 2 * i + 2;

    if (leftChild < n && array[leftChild] < array[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < n && array[rightChild] < array[smallest]) {
        smallest = rightChild;
    }

    if (smallest != i) {
        swap(array[i], array[smallest]);
        reverseHeapify(array, n, smallest);
    }
}

void reverseHeapSort(long array[], long arrayLength) {
    for (long  i = arrayLength / 2-1; i >= 0; i--) {
        reverseHeapify(array, arrayLength, i);
    }

    for(long i = arrayLength - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        reverseHeapify(array, i, 0);
    }
}
//Algorytm ReverseQuickSort

//Algorytm BubbleSort
void bubbleSort(long array[], long arrayLength) {

    for (long i = 0; i < arrayLength-1; i++) {
        for (long j = 0; j < arrayLength-i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}
//Algorytm BubbleSort

//Algorytm ReverseBubbleSort ( nie działa )
void reverseBubbleSort(long array[], long arrayLength) {

    for (long i = 0; i < arrayLength-1; i++) {
        for (long j = 0; j < arrayLength-i-1; j++) {
            if (array[j] < array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}
//Algorytm ReverseBubbleSort ( nie działa )

//Algorytm InsertionSort
void insertionSort(long array[], long arrayLength) {
    long j;

    for (long i = 1; i < arrayLength; i++) {
        long key = array[i];                        // jako key deklarujemy drugi element tablicy
        j = i - 1;                                  // j jest pierwszym elementem tablicy

        while (j >= 0 && array[j] > key) {          // dopoóki elemnt j jest większy od klucza
            array[j+1] = array[j];                  // to zamieniamy te elementy ze sobą
            j -= 1;                                 // zmniejsząc j o 1
        }
        array[j + 1] = key;
    }
}
//Algorytm InsertionSort

//Algorytm ReverseInsertionSort
void reverseInsertionSort(long array[], long arrayLength) {
    long j;

    for (long i = 1; i < arrayLength; i++) {
        long key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] < key) {
            array[j+1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
}
//Algorytm ReverseInsertionSort

int main() {
    long numbersToSort [100000];
    long randomNumber;
    long arrayLength = sizeof(numbersToSort) / sizeof(numbersToSort[0]);


    for (long i = 0; i <= 100000; i++) {
        randomNumber = rand();
        numbersToSort[i] = randomNumber;
    }

    auto start = high_resolution_clock::now();
    quicksort(numbersToSort, 0, 99999);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "QuickSort time: " << duration.count() << endl;

    start = high_resolution_clock::now();
    heapSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "HeapSort time: " << duration.count() << endl;

    start = high_resolution_clock::now();
    bubbleSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "BubbleSort time: " << duration.count() << endl;

    start = high_resolution_clock::now();
    insertionSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "InsertionSort time: " << duration.count() << endl;

    start = high_resolution_clock::now();
    reverseHeapSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Reverse HeapSort time: " << duration.count() << endl;

    /*start = high_resolution_clock::now();
    reverseQuickSort(numbersToSort, 0, 99999);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Reverse QuickSort time: " << duration.count() << endl;*/

    start = high_resolution_clock::now();
    reverseBubbleSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Reverse BubbleSort time: " << duration.count() << endl;

    start = high_resolution_clock::now();
    reverseInsertionSort(numbersToSort, arrayLength);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Reverse InsertionSort time: " << duration.count() << endl;

    return 0;
}
