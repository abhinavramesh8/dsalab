#include <iostream>
#include <cstring>

using namespace std;

class Shape  {
   public:
      void setWidth(int w) {
         width = w;
      }
		
      void setHeight(int h) {
         height = h;
      }
      
      int getHeight() {return height;}
      
      int getWidth() {return width;}
		
   private:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (getWidth() * getHeight()); 
      }
};

void arrTest(int (&n)[3]) {
	n[0] = 8;
}

int main() {
	/*char str[22] = "hihow";
	char *yes = "man";
	cout<<strcat(str, yes); */
	Rectangle rect;
	rect.setWidth(3);
	rect.setHeight(10);
	cout<<rect.getArea()<<endl;
	int a[] = {1,2,3};
	arrTest(a);
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	int (&j)[3] = a;
	return 0;
}