#include <iostream>
using namespace std;

struct Vector {
  int sz; // Number of elements
  double* elem; // Pointer to elements
};

void vector_init(Vector& v, int sz) {
  // `v.elem` gets a pointer produced by the `new` operator
  v.elem = new double[sz]; // allocate an array of sz doubles in the dynamic memory/heap
  v.sz = sz;
}

double read_and_sum(int s){
  Vector v;
  vector_init(v, s);
  for (int i = 0; i != v.sz; ++i) {
    if (i == 0) {
      cout << "Enter a number: ";
    } else if (i == v.sz - 1) {
      cout << "Enter FINAL number: ";
    } else {
      cout << "Enter another number: ";
    }

    cin >> v.elem[i]; // read into elements
  }

  double sum = 0;
  for (int i = 0; i != s; ++i) {
    sum += v.elem[i];
  }
  delete [] v.elem;

  return sum;
};

int main() {
  constexpr int count = 5;
  cout << "Please enter a number below "<<count<<" times:" << endl;
  double result = read_and_sum(count);

  cout << "The sum of numbers entered is: " << result << endl;
}
