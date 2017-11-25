# include <climits>
# include <cstring>
# include <cstdio>
# include <iostream>
 
# define MAX 256
 
using namespace std;

char str[MAX];
char pat[MAX];
int badchar[MAX];

// Boyer Moore is based on bad character heuristic and good suffix heuristic
void badCharHeuristic(int size)
{
    int i;
    for (i = 0; i < MAX; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) pat[i]] = i;
}
 
void search()
{
    int m = strlen(pat);
    int n = strlen(str);
  
    badCharHeuristic(m);
 
    int t = 0;
    while (t <= (n - m))
    {
        int j = m - 1;
        while (j>=0 && pat[j]==str[t+j]) j--;
        if (j<0)
        {
        	cout<<"Pattern found at index "<<t<<endl;
            t += (t+m < n) ? m-badchar[str[t+m]] : 1;
        }
        else
            t += max(1, j-badchar[str[t+j]]);
    }
}
 
int main()
{	
	cout<<"Enter string: ";
    scanf("%s", str);
    cout<<"Enter pattern: ";
    scanf("%s", pat);
    search();
    return 0;
}