
(C)2023 Simon Aranda

  
typedef std::int_fast64_t SIF;

SIF SIFrootexact(const SIF p) {
double a= p;double b= sqrt(a);
SIF c=floor(b);
bool exact= (p==(c*c));if(exact)return c;
return 0;
}
int main(void) {
for(SIF m= 1;;m++) 
  {
  const SZ szm= m;
  int r= Rfunction(false,szm); // the function r(n).
  if(r<1)continue;

  bool unsolved= true;
  for(SIF c= 1;unsolved;c++)
    {
    SIF n= m*c*c;
    if(n<0)break; // Overflow
    for(SIF x=1;unsolved;x++)
      {
      SIF x2= x*x;
      SIF ds= n+x2;
      SIF dr= n-x2;
      if(dr<=0)break;
      
      SIF dif=ds*dr;
      const SIF r= SIFrootexact(dif);if(r==0)continue;
      //
      SIF y= x*r;
      cout<<"Solved: "<<m<<" (";
      cout<<"n= "<<n;
      cout<<", x= "<<(-x*x);
      cout<<", y= "<<y<<")"<<endl;
      unsolved=false; 
      }
    }
  if(unsolved) {
    cout<<"m-UNSOLVED= "<<m<<endl;
    getc(stdin);
    }
  }
return 0;
}

