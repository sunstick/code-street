#include <iostream>

using namespace std;

bool checkMiddle(int a, int b, int c) {
	return (a <= b && b <= c) || (c <= b && b <= a);
}

int main() {
	int t; cin >> t;
	int i = 1; 


	while(i <= t) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Case " << i++ << ": ";
		if(checkMiddle(a, b, c)) cout << b << endl;
		else if(checkMiddle(b, a, c)) cout << a << endl;
		else cout << c << endl;
	}
	return 0;
}