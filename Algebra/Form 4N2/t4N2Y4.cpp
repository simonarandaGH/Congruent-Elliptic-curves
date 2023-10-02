

// Example of the use of a quick form prior to 
// the possible call for a more robust form.
// (C)2023.Simon Aranda

#pragma pack(16)

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include "boost/multiprecision/cpp_int.hpp"
//
using namespace boost::multiprecision;
typedef 
number<cpp_int_backend<256,256,signed_magnitude,unchecked,void>> SZ;
using namespace std;

//
SZ SZroot(const SZ p) {
SZ e=0;
SZ r= sqrt(p,e);if(e==0)return r;
return 0;
}

void tryXYWform(const SZ n) {
const SZ nn= n*n;
for(SZ x= 1;x<n;x++)
	{
	if((nn%x)>0)continue;
	SZ w= nn/x;
  SZ d= (w-x);if(d<1)break;
  const SZ y= SZroot(d);
	if(y>0) {
    cout<<setw(6)<<n;
    cout<<" XYW: "<<setw(12)<<x<<setw(8)<<y<<setw(14)<<w<<endl;
    }
  }
}

bool test4N2Y4(SZ n) {
const SZ v= 2*n;
const SZ vv= v*v;
bool solved=false;
for(SZ y= 1;y<n;y++)
	{
  SZ y2= y*y;
  SZ y4= y2*y2;
  SZ s= vv + y4;
  const SZ r= SZroot(s);
	if(r>0) {
    cout<<"4N2Y4 test: nyr: "<<n<<" "<<y<<" "<<r<<endl;
    solved=true;
    }
  }
return solved;
}

int main(void) {
for(SZ n= 5;n< 5000;n++) 
  {
  bool b= test4N2Y4(n);
  if(b)tryXYWform(n);
  }

return 0;
}


