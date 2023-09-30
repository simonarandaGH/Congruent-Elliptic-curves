
//(C)2023.Author:Simon Aranda. 

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <array>

// types
using namespace std;
typedef int_fast64_t I64;
typedef __int128_t I128;
typedef long double REAL16;


#define MXAQ 1000000
array<I64,MXAQ> Q;

/////// the function r pkg
//////////////////////////
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
I64 Arange(I64 vv,int comin) {
double a= (double)vv;
a= a/(double)comin;
a= sqrt(a);
I64 r= (I64)a;r++;
return r;
}
// The function r
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

I64 pwr(I64 p) {
I64 v=0;
if(p<MXAQ) 
  {
  v=Q[p];
  if(v==0) {
    v= p*p;Q[p]=v;
    }
  }
else v= p*p;
return v;
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
I64 root128(I128 p) {
REAL16 d=p;
REAL16 a= sqrt(d);
I128 e= a;
I64  b= (I64)e;
I128 c= b*b;
bool exact= (c==p);
if(exact)return b;
return 0;
}


#define MAXI64 (LLONG_MAX-8)
#define MAXI32 (LONG_MAX -4)

int main(void) {
Q.fill(0);

for(I64 m= 5;m<100;m++)
  {
  int r= rfun(m);
  if(r<  1  )continue;
  int solved= 0;
  for(I64 a= 1;  a<9999  ;a+=2)
    {
    int imode=64;
    const I64 n= m*pwr(a);
    if(n<0) {solved=-1;break;}
    if(n>MAXI32)imode=128;
    for(I64 p=1;;p++)  // era =1
      {
      if(a>1 && p>1) {
        if(p%a==0)continue;
        }
      I64 p2= pwr(p);if(p2>=n)break;
      I64 ds= n+p2;
      if(ds<0) {solved=-3;break;}
      I64 dr= n-p2; 
      if(dr<0) {solved=-32;break;}
      I64 rr=0;
      if(imode==64) {
        I64 t= ds*dr;rr=root(t);
        }
        else {
        I128 t= ds;t= t*dr;
        rr= root128(t);
        }
      I64 g= (I64)rr;
      if(g==0)continue;
      ///
        {
        I64 gc=core(g);
        I64 gq=mxq(g);
        cout<<"g("<<gc<<","<<gq<<").2 =";
        cout<<"n("<<m<<","<<a<<").2 - ";
        cout<<"p("<<p<<").4";
        }
        {
        I64 cs= core(ds);I64 cr= core(dr);
        I64 qs= mxq(ds);I64 qr=mxq(dr);
        cout<<" = ("<<cs<<","<<qs<<")*";
        cout<<"("<<cs<<","<<qr<<")"<<endl;
        assert(cs==cr);
        }
      solved= 1;
      break;
      }
    if(solved!=0)break;
    }
  }
return 0;
}

