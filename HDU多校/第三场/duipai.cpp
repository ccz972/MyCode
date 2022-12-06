#include <bits/stdc++.h>
using namespace std;


int main() {
  int T = 100;
  bool flag = true;
  while(T -- ) {
    system("data.exe > data.txt");
    system("L.exe < data.txt > A.txt");
    system("LL.exe < data.txt > B.txt");
    if(system("fc A.txt B.txt")) {
      flag = false;
      cout << "Error\n";
      break;
    }
  }
  if(flag) {
    cout << "No Error\n";
  }
}