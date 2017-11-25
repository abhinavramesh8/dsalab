#include <iostream>
#include <cstdio>

using namespace std;

#define rep(n) for(int i=0; i<n; i++)

class NameArray{
public:
	int arr[100];
	int n;
	NameArray(int sz) {
		n = sz;
		for(int i=1; i<=n; i++) arr[i] = i;
	}
	void unionOp(int, int);
	int find(int);
};

void NameArray::unionOp(int x, int y) {
	int minOfBoth = min(x,y);
	for(int i=1; i<=n; i++) {
		if(arr[i]==x || arr[i]==y) arr[i] = minOfBoth;
	}
}

int NameArray::find(int x) {
	if(x<=n) return arr[x];
	return -1;
}

class Forest{
public:
	int arr[100];
	int size[100];
	Forest(int sz) {
		for(int i=1; i<=sz; i++) {
			arr[i] = i;		
			size[i] = 1;
		}
	}
	void basicUnion(int ,int);
	void betterUnion(int, int);
	int find(int);
	int betterfind(int);
};

void Forest::basicUnion(int x, int y) {
	if(x<y) arr[y] = x;
	else arr[x] = y;
}

void Forest::betterUnion(int x, int y) {
	if(size[x]<=size[y]) {
		arr[x] = y;
		size[y] += size[x];
		size[x] = 0;
	}
	else {
		arr[y] = x;
		size[x] += size[y];
		size[y] = 0;
	}

}

int Forest::find(int x) {
	int y = arr[x];
	while(y != arr[y]) y = arr[y];
	return y;
}

int Forest::betterfind(int x) {
	// I have used recursion instead of stack
	if(arr[x]!=x) arr[x] = betterfind(arr[x]);
	return arr[x];
}

int main() {
	NameArray part1(9);
	rep(2) part1.unionOp(1,i+2);
	rep(2) part1.unionOp(4,i+5);
	rep(2) part1.unionOp(7,i+8);
	for(int i=1; i<=9; i++) {
		cout<<i<<" belongs to "<<part1.find(i)<<endl;
	}
	Forest part2(10);
	part2.betterUnion(1, 2);
	part2.betterUnion(part2.find(2),3);
	part2.betterUnion(part2.find(3),5);
	part2.betterUnion(4, 6);
	part2.betterUnion(part2.find(6),7);
	part2.betterUnion(8,9);
	for(int i=1; i<=10; i++) {
		cout<<i<<" belongs to "<<part2.betterfind(i)<<endl;
	}
	return 0;
}