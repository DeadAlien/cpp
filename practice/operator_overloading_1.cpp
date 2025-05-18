/*write a program to overload [ ] behave like an array*/
#include<iostream>
using namespace std;

class aarray{
	int* arr;
	int size;
public:
	aarray(int s){
		size = s;
		arr = new int[s];
	}

	int& operator [](int index) {
		if(index < 0 || index >= size) {
			cout << "Index out of bounds" << endl;
			exit(1);
		}
		return arr[index];
	}

	void display(){
		for(int i = 0; i < size; i++){
			cout << arr[i] << endl;
		}
	}
};


int main(){
	aarray a(5);

	a[0] = 1;
	a[1] = 2;

	a.display();
}