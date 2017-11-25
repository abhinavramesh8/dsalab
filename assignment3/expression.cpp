#include<iostream>
#include<cstring>
#include "stack.h"
using namespace std;

char infix[100];
char postfix[100];

bool unary = false;

// for non-operators, return 0 

int precedence(char ch) {
   switch (ch) {
      case '/':
      case '%':
      case '*': return 6;
      case '+':
      case '-': return 5;
      case 'l': 
      case 'r': return 4;
      case '&': return 3;
      case '^': return 2;
      case '|': return 1;
      default : return 0;
   }
}

char doubleoperand(char c) {
	switch(c) {
		case '<': return 'l'; // for <<
		case '>': return 'r'; // for >> 
		case '+': return '+'; // for ++
		case '-': return '-'; // for --
	}
}


void infixToPostfix() {
	Stack<char> s;
	int weight;
    int i = 0;
    int k = 0;
    char ch;
	while (infix[i]!='\0') {
    	ch = infix[i];
      	if(ch == '(') {
        	s.push(ch);
         	i++;
         	continue;
      	}
      	if (ch == ')') {
        	while ((s.top)->data != '(') {
            	postfix[k++] = s.pop();
         	}
            s.pop();
         	i++;
        	continue;
      	}
      	if(ch == infix[i+1]) {
      		ch = doubleoperand(ch);
      		if(ch=='+') {
      			unary = true;
      			char numAft = infix[i+2];
      			bool isNumAft = numAft>='0' && numAft<='9';
      			if(isNumAft) {
      				infix[i+2]++;
      				i+=2;
      				continue;
      			}
      			else {
      				postfix[k-1]++;
      				i+=2;
      				continue;
      			}
      		}
      		else if(ch=='-') {
      			unary = true;
      			char numAft = infix[i+2];
      			bool isNumAft = numAft>='0' && numAft<='9';
      			if(isNumAft) {
      				infix[i+2]--;
      				i+=2;
      				continue;
      			}
      			else {
      				postfix[k-1]--;
      				i+=2;
      				continue;
      			}
      		}
      		i++;
      	}
      	weight = precedence(ch);
      	if (weight == 0) {
        	postfix[k++] = ch;
      	}
      	else {
        	if (s.isEmpty())
            	s.push(ch);
        	else {
            	while (!s.isEmpty() && (s.top)->data != '(' && weight <= precedence((s.top)->data)) {
               		postfix[k++] = s.pop();
				}
        		s.push(ch);
         	}
      	}
      	i++;
      	
	}
   	while (!s.isEmpty()) {
    	postfix[k++] = s.pop();
   	}
   	postfix[k] = '\0';
}

int evaluate(int op1, int op2, char operate) {
   switch (operate) {
      case '*': return op2 * op1;
      case '/': return op2 / op1;
      case '+': return op2 + op1;
      case '-': return op2 - op1;
      case '%': return op2 % op1;
      case '&': return op2 & op1;
      case '|': return op2 & op1;
      case '^': return op2 ^ op1;
      case 'l': return op2 << op1;
      case 'r': return op2 >> op1;
   }
}
int evalPostfix() {
	int i=0;
	Stack<int> s;
	char ch;
	int val, op1, op2;
	while((ch=postfix[i])!='\0') {
		if(ch>='0' && ch<='9')
			s.push(ch-'0');
		else {
			op1 = s.pop();
			op2 = s.pop();
			val = evaluate(op1, op2, ch);
			s.push(val);
		}
		i++;	
	}
	return val;
}

void threesymun() {
	int i;
	for(i=0; infix[i]!='\0'; i++);
	if(i==3) {
		if(infix[0]=='+') {
			cout<<(infix[2]-'0')+1<<endl;
			unary = true;
		}
		else if(infix[0]=='-') {
			cout<<(infix[2]-'0')-1<<endl;
			unary = true;
		}
		else if(infix[2]=='+') {
			cout<<(infix[0]-'0')+1<<endl;
			unary = true;
		}
		else if(infix[2]=='-') {
			cout<<(infix[0]-'0')-1<<endl; 
			unary = true;
		}
	}
}

int main() {
	scanf("%s", infix);
	threesymun();
	if(!unary) {
	infixToPostfix();
	cout<<postfix<<endl;
	cout<<evalPostfix()<<endl;
	}
	return 0;
}