#include<iostream>
using namespace std;
int main() {
    int n, i, a, b;
    cout << "enter a number to check whether it's prime " << endl;
    cin >> n;
    for (i = 2; i < n;i++) {
        if (n % i == 0) {
            cout << "it's not a prime number" << endl;
            break;
        }
    }
    if (i == n) {
        cout << "it's a prime number" << endl;
    }
    return 0;
}