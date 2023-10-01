

// PQRS.cpp
//(C)2023.Simon Aranda

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <array>
#include "boost/multiprecision/cpp_int.hpp"
//
using namespace boost::multiprecision;
typedef cpp_int       SZ;
typedef cpp_rational  SQ;
using namespace std;

// default parameters
#define maxnumdvsrs 999  // max number of divisors
static std::array<SZ,maxnumdvsrs> pleft;
static std::array<SZ,maxnumdvsrs> prigh; 
static std::array<SZ,maxnumdvsrs> psum; 
static std::array<SZ,maxnumdvsrs> pdif; 

// 1 pqrs -> 4 Curve Points
void displayPOINTS(const SZ n,SZ p,SZ q,SZ r,SZ s) { 
for(unsigned ite=0;ite< 4;ite++)
  {
  SQ x,y;
  if(ite==0) {
    x= (-p*r);y= (p*r*(q+r));
    } 
  if(ite==1) {
    x= (-q*r);y= (q*r*(p+r));
    }
  if(ite==2) {
    x= (q*s);y= (q*s*(q+r));
    }
  if(ite==3) {
    x= (p*s);y= (p*s*(p+r));
    }
  cout<<"P("<<x<<","<<y<<")"<<endl;
  }
}

// return: number of pqrs forms
int tryPQRSform(SZ n) {
if(n%6>0)return 0;
pleft.fill(0);prigh.fill(0);psum.fill(0);pdif.fill(0);
unsigned numdiv=0;
// fill arrays
for(SZ p= 1;p<=n;p++)
	{
	if(n%p >0)continue;
	SZ q= n/p;if(q < p)break;
	assert(numdiv < pleft.size());
	pleft[numdiv]=p;prigh[numdiv]=q;
  psum[numdiv]= p+q;pdif[numdiv]= q-p;
	numdiv++;
	}
// counter
int qq= 0;
for(unsigned i= 0;i<numdiv;i++)
	{
	SZ r=pleft[i];SZ s=prigh[i];
	SZ smr=pdif[i];
	for(unsigned j=(i+1);j<numdiv;j++)
		{
		SZ p=pleft[j]; SZ q=prigh[j];
		SZ pmq=psum[j]; // =l*r, pmq=l+r.
    if(pmq < smr)break; // no more chances.
		if(pmq > smr)continue;
    // is pqrs form
    assert(p*q==r*s);assert(p+q+r==s);
    qq++; // cntr
    if(n<100) {
      cout<<"PQRS:  "<<n<<"="<<p<<"*"<<q<<"="<<r<<"*"<<s<<endl;
      displayPOINTS(n,p,q,r,s);
      }
		}
	}
return qq;
}


int main(void)
{

int qx=0; // search for n with max number of forms

for(SZ n= 6;;n+=6)    // always
  {
  int q= tryPQRSform(n);
  if(q>qx) {      // new level
    cout<<"n= "<<n<<" "<<"#forms= "<<q<<endl<<endl;
    qx=q;
    }
  }

return 0;
}

