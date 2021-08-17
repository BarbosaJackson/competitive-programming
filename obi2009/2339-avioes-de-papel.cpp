#include <iostream>
 
using namespace std;
 
int main() {
 
    int c, p, f;
    cin >> c >> p >> f;
    cout << ((c * f) <= p ? "S" : "N") << endl;
 
    return 0;
}