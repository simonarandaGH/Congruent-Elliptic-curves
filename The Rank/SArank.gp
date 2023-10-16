

\\ SArank.gp
\\ PARI/GP Script
\\ (C)2023.Simon Aranda
\\
\\ no call is made to the PARI library on elliptic curves.


\\ set default's
default(echo,1)
set echo=1          \\ 
\o    2             \\ nice output
\l log_rank.txt     \\ log file


\\ check if (x,-) is a curve rational point
\\ check if (x,-) is a curve integral point
Yfrom(B,x)=
{
my(rv,y,ok);             \\ never my a input parameter
rv= x^3 + B*x;           \\ eqn right side
if(rv<=0,return(0););
y=0;ok=issquare(rv,&y);  \\ eqn left side
if(ok==0,return(0););
if(y<1,return(0););
return(y);
}


\\ B->Divisors->Gamma. Alpha(Gamma)->(mod Q*2). Beta.
Beta(opt,n)=
{
my(B,nea,nd,v,iv);
if(n<1,return(0););    \\ wrong parameter
B=0;
if(opt==1,B=  -n^2;);  \\ Cn B
if(opt==2,B= 4*n^2;);  \\ Assoc curve B
if(B==0,return(0););   \\ wrong option

nea=abs(B);nd=numdiv(nea);   \\ total divisors
v=vector(2*nd,iv,+oo);       \\ Gamma set. init oo

iv=1;                \\ vector empty point
v[iv]=1;iv++;        \\ +1 always in Alpha set
v[iv]=core(B);iv++;  \\ also the squarefree part of "B"

fordiv(nea,d,         \\ +d|abs(B)
  my(x,xc,y);
  x= d;xc=core(x);    \\ divisor mod Q*2
  y=Yfrom(B,x);               \\ n is PQRS form
  if(y>0,v[iv]=xc;iv++;);     \\ to set
  if(opt==1,                  \\ case B<0 Left points.
    y=Yfrom(B,-x);            \\ n..
    if(y>0,v[iv]=-xc;iv++;);  \\ to..
    );
  );
v=vecsort(v,,8);  \\ sort and remove duplicate values
my(crd);          \\ Beta ~ card(Alpha(Gamma))
crd=(#v-1);       \\ discard the ending oo
for(beta=0,7,
  if(crd== (2^beta),return(beta););
  );
\\ stillnot powtwo
for(beta=0,7,
  if(crd<  (2^beta),return(beta););
  );
return(0);
}


ispqrs(n)=
{
fordiv(n,r,               \\ r|n
  s=n/r;if(s<r,break;);
  for(p=r+1,s-r,
    q=n/p;
    if(p*q==n && q<=p,break;); \\ p<q
    if(p*q==n && s==p+q+r,return(1););
  );
);
return(0);
}

\\ main
{
forstep(n=6,250,6,   \\ PQRS Z always multiple 6.
  if(ispqrs(n),
    b1= Beta(1,n);   \\ Cn
    b2= Beta(2,n);   \\ Assoc. curve
    bn= (b1+b2)-2;   \\ beta power two
print("pqrs n=" n "(" core(n) ") rank= " bn "=" b1 "+" b2 "-2");
    );
  );
};

