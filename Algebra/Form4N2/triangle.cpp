

// (C)2023.Simon Aranda


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include "boost/multiprecision/cpp_int.hpp"

// 128bit
using namespace boost::multiprecision;
typedef number<cpp_int_backend<128, 128, signed_magnitude, unchecked, void> >    SZ;
typedef cpp_rational    SQ;
using namespace std;

//
SZ SZroot(const SZ p) {
SZ e=0;
SZ r= sqrt(p,e);if(e==0)return r;
return 0;
}

static array<SQ,32>VP; // p tg
static array<SZ,32>VD; // denominators

SZ tryXYWform(const SZ n) {
const SZ nn= n*n;
int qf=0; // cntr
VP.fill(0);VD.fill(0);
for(SZ fx= 1;fx<n;fx++)
	{
	if((nn%fx)>0)continue;
	const SZ fw= nn/fx;
  const SZ t5= (fw-fx);if(t5<1)break;
  const SZ fy= SZroot(t5);
	if(fy>0) 
    {
    const SZ t1= (fx+fw);
    const SQ tp  (t1,fy);
    bool pdup=false;
    for(int i=0;i<qf;i++){if(VP[i]==tp)pdup=true;}
    if(!pdup) {
      assert(qf<(int)VP.size());
      VP[qf]=tp;VD[qf]=(SZ)denominator(tp);
      qf++;
      }
    if(pdup)cout<<"duo:"; else cout<<"p=  ";
    cout<<setw(8)<<tp<<"  ";
    cout<<"xyw("<<fx<<","<<fy<<","<<fw<<")  ";
    cout<<"TR("<<fy<<",*, "<<tp<<")"<<endl;
    }
  }

SZ prod=1;
for(int i=0;i<qf;i++) {
  SZ deno= VD[i];   // get deno case
  if(prod==1){prod=deno;continue;}
  if(prod==deno)continue;
  if(prod>deno) {
    if(prod%deno !=0)prod=prod*deno;
    continue;
    }
  if(prod<deno) {
    bool b= (deno%prod==0);
    if(b)prod=deno; else prod=prod*deno;
    }
  }
VP.fill(0);VD.fill(0);
if(qf<1)return (SZ)0; // nothing here
if(prod>1) {
  SZ nxt= n*prod*prod;
  cout<<"(prod="<<prod<<")-> "<<nxt<<endl;
  return prod; // to next
  }
assert(qf>0 && prod==1);
return (SZ)(-qf); // end of chain
}

int main(void)
{
for(int i=5;i< 1000;i++) {
  SZ nw= i;
  while(true)
    {
    const SZ prod= tryXYWform(nw);
    if(prod==0)break; // nothing
    if(prod< 0) { // end of chain
      int numt= (int)(-prod);
      cout<<"n= "<<i<<" #triangles= "<<numt<<endl<<endl;
      break;
      }
    nw= nw*prod*prod; // next number
    }
  }
  
return 0;
}

