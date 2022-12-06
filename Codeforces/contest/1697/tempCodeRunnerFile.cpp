#include <iostream>
using namespace std;
int main() {
freopen("1.txt","w",stdout);
cout << "1\n";
int n = 100000;
int m = n / 4;
cout << n << "\n";
for(int i = 0; i < m; i ++ ) cout << 'a';
for(int i = 0; i < m; i ++ ) cout << 'c';
for(int i = 0; i < m; i ++ ) cout << 'b';
for(int i = 0; i < m; i ++ ) cout << 'b';
cout << "\n";
for(int i = 0; i < m; i ++ ) cout << 'b';
for(int i = 0; i < m; i ++ ) cout << 'b';
for(int i = 0; i < m; i ++ ) cout << 'a';
for(int i = 0; i < m; i ++ ) cout << 'c';
return 0;
}