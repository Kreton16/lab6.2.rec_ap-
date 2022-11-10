#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int Number(int* a, const int size, int& num, int i) {
    if (i < size) {
        if (!(i % 2 == 0))
            num++; i++;
        Number(a, size, num, i);
    }
    return num;
}
void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        i++;
        Create(a, size, Low, High, i);
    }
}
void Print(int* a, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << a[i];
        i++;
        Print(a, size, i);
    }
}

int Sum(int* a, const int size, int& sum, int i) {
    if (i < size) {
        if (!(i % 2 == 0)) {
            sum += a[i];
        }
        i++;
        Sum(a, size, sum, i);
    }
    return sum;
}

double Avg(int num, int sum) {

    return 1. * sum / num;

}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 21;
    int a[n];
    int i = 0;
    int num = 0;
    int sum = 0;
    int Low = 15;
    int High = 85;
    Create(a, n, Low, High, i);
    Print(a, n, i);
    cout << endl;
    int number = Number(a, n, num, i);
    int suma = Sum(a, n, sum, i);
    cout << "Avg: ";
    double avg = Avg(number, suma);
    cout << avg;

    return 0;

}