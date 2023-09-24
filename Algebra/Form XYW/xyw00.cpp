

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
typedef number<cpp_int_backend<256, 256, signed_magnitude, unchecked, void> >    SZ;
using namespace std;

//
SZ SZroot(const SZ p) {
SZ e=0;
SZ r= sqrt(p,e);if(e==0)return r;
return 0;
}

void tryXYWform(SZ m) {
SZ n= m;
SZ nn= n*n;
for(SZ x= 1;x<n;x++)
	{
	if((nn%x)>0)continue;
	SZ w= nn/x;
  SZ d= (w-x);if(d<1)break;
  SZ y= SZroot(d);
	if(y>0) {
    cout<<setw(6)<<m;
    cout<<" xyw: "<<setw(8)<<x<<setw(8)<<y<<setw(8)<<w<<endl;
    }
  }
}


int main(void)
{
for(SZ n= 1;n< 10000;n++) {
  tryXYWform(n);
  }

return 0;
}

