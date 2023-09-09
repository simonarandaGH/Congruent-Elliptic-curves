
//(C)2023.Author:Simon Aranda. 


#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

// types
using namespace std;
typedef int_fast64_t I64;
typedef long double REAL16;

/////////////////////////////////
/////// the function pkg
/////////////////////////////////
I64 mxq(I64 p) {
REAL16 a= p;a= sqrt(a);
I64 k= ceil(a);
for(I64 i= k;i>0;i--) {
	I64 c= i*i;
  if((p%c)==0)return i;
	}
return 1;
}
I64 core(I64 p) {
I64 q=mxq(p);
I64 qq=q*q;
assert(p%qq==0);
I64 c=p/qq;
return c;
}
I64 root(I64 p) {
assert(p>0);
REAL16 a= p;a= sqrt(a);
I64 up=ceil(a);
I64 dw=floor(a);
if(up > dw)return 0;
I64 ff= up*dw;
bool exact= (ff==p);
if(exact)return up;
return 0;
}


int main(void) {

for(I64 n= 1;n<1000;n++)
  {
  I64 g=0;
  for(I64 p=1;g==0;p++) // g break
    {
    I64 p2= p*p;if(p2>=n)break;
    I64 ds= n+p2;
    I64 dr= n-p2; 
    I64 cs= core(ds);
    I64 cr= core(dr);
    if(cs!=cr)continue;
    ///
    cout<<"n, p.2    : "<<n<<",  "<<p2<<endl;
    cout<<"r, s, core: "<<dr<<", "<<ds<<",  "<<cs<<endl;
    cout<<
      "Center at n, +- p.2: two numbers with equal core, example:"
      <<endl;
    cout<<dr<<" ..(p.2).. "<<n;
    cout<<" ..(p.2).. "<<ds<<", core= "<<cs<<endl;

    I64 g2= ds*dr;
    g= root(g2);  // for variable
    assert(g>0); // same core, mustbe square.
    cout<<"n= "<<n<<" GNP: "<<g<<","<<n<<","<<p<<endl;
    cout<<" g.2= n.2 - p.4; then n is CN (see doc). "<<endl;
    cout<<endl;
    assert(g*g == (n*n -p*p*p*p));  
    }
  }
return 0;
}

