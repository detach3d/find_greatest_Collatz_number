#include <iostream>
#include <vector>

using std::vector,std::cout;

vector<int> collatz(int n) {
    vector<int> v;
    while (n != 1) {
        if (n % 2 == 0) {
            v.push_back(n);
            n = n / 2;
        } else {
            v.push_back(n);
            n = n * 3 + 1;
        }
    }
    return v;
}

vector<int> find_greatest_collatz() {
    //
    size_t size = collatz(2).size();
    int max;
    for (int i = 3; i < 1'000; i++) {
        if (collatz(i).size() > size) {
            size = collatz(i).size();
            max = i;
        }
    }
    return collatz(max);
}

int main() {
    for (auto i: find_greatest_collatz()) {
        cout << i << " ";
    }
}
