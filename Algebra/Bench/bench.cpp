

//(C)2023.Author Simon Aranda
//
// GNP vs XYW
/////////////

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
// #include <array>

// types
using namespace std;
typedef int_fast64_t I64;

/////////////////////////////////
/////// pkg
I64 mxq(I64 p) {
long double a= p;a= sqrt(a);
I64 k= ceil(a);
for(I64 i= k;i>0;i--) {
	I64 c= i*i;
  if((p%c)==0)return i;
	}
return 1;
}
I64 core(I64 p) {
I64 q=mxq(p);
I64 qq=q*q;assert(p%qq==0);
I64 c=p/qq;
return c;
}
I64 Arange(I64 vv,int comin) {
double a= (double)vv;
a= a/(double)comin;a= sqrt(a);
I64 r= (I64)a;r++;return r;
}
// the function r()
int rfun(I64 p) {
I64 n= core(p);
I64 nt= n;
const bool even=(nt%2 ==0);if(even)nt= nt/2;
const I64 vv= nt;
//
I64 limx= Arange(vv,2);I64 limy= Arange(vv,1);
I64 limz= Arange(vv,8);
int a=0,b=0; // the counters
for(I64 x= 0;x<limx;x++)  
  {
  I64 tx= 0;
  if(even) tx= +4*x*x;else tx= +2*x*x;
  if(tx>vv)break;
  for(I64 y= 0;y<limy;y++)  
    {
    const I64 ty= +tx +y*y;
    if(ty>vv)break;
    for(I64 z= 0;z<limz;z++)  
      {
      const I64 tza = +ty + 8*z*z;
      const I64 tzb = +ty + 32*z*z;
      bool ba= (tza==vv);bool bb= (tzb==vv);
      if(ba || bb) {
        int ee=1;
        if(x!=0)ee*=2;
        if(y!=0)ee*=2;
        if(z!=0)ee*=2;
        if(ba)a+=ee;
        if(bb)b+=ee;
        }
      if(tza>vv)break;
      }
    }
  }
// decode a,b to m,q.
int q=-1,m=-1;
if(b>0) {
  m=a%b;if(m==0)q=a/b;
  }
// function value
int rn=0;
if(a==0 && b==0)rn= 1;
else if(q==2)rn= 2;
return rn;
}

////////////
//////// gnp
I64 root(I64 p) {
if(p<1)return 0;
else if(p==1)return 1;
//
long double a= p;a= sqrt(a);
I64 up=ceil(a);
I64 ff= up*up;
bool exact= (ff==p);if(exact)return up;
return 0;
}
// gnp
bool gnp(I64 m,I64 a) {
const I64 n= m*(a*a);
for(I64 p= 1;;p++) // 1 ++
  {
  I64 p2= (p*p);if(p2>=n)break;
  I64 ds= (n+p2);if(ds<1)break;
  I64 dr= (n-p2);
  I64 t= ds*dr;if(t<1)break;
  I64 g=root(t);if(g==0)continue;
  ///
  cout<<setw(4)<<m<<setw(6)<<a;
  cout<<"    gnp: ";
  cout<<setw(12)<<g<<setw(12)<<n<<setw(12)<<p<<endl;
  I64 cs= core(ds);I64 cr= core(dr);
  assert(cs==cr);
  return true;
  }
return false;
}
// XYW
bool xyw(const I64 m,const I64 a) {
const I64 n= m*(a*a);
const I64 n2= (n*n);
for(I64 x=1;x<n;x++) 
  {
  const bool bx= (n2%x==0);if(!bx)continue;
  const I64 w= n2/x;
  const I64 y2= (w-x);if(y2<1)continue;
  const I64 y= root(y2);if(y==0)continue;
  
  cout<<setw(4)<<m<<setw(6)<<a;
  cout<<"  x[y]w: ";
  cout<<setw(12)<<x<<setw(12)<<y<<setw(12)<<w<<endl;
  return true;
  }
return false;
}
int main(void) {

for(I64 m= 1;m< 100;m++)  // Objective 
  {
  I64 cre=core(m);if(cre<m)continue;
  int r= rfun(m);if(r< 1)continue;
  bool solved=false;
  for(I64 a= 1;a< 500;a++) // low limit
    {
    solved= gnp(m,a);if(solved)break;
    solved= xyw(m,a);if(solved)break;
    }
  if(!solved)cout<<"Unsolved: "<<m<<endl;
  }
return 0;
}

