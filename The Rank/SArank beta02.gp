
\\ SArank.gp
\\ GP program. PARI/GP. 
\\ (C)2023.Simon Aranda
\\
\\ beta. Uses ELL Ordinate.
\\
\\ set defaults
default(echo,1)
set echo=1          \\ 
\o    2             \\ nice output
\l log_sarank.txt   \\ log file

\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\ to be replaced soon
ELLisx(ellcur,x)=
{
my(y);
y=ellordinate(ellcur,x);
if(#y==2,return(1);,return(0););
}
\\ only to check C[n] rank values.
ELLrank(n)=
{
my(e,r);
e=ellinit([-n^2,0]);r=ellrank(e);
if(r[1]!=r[2],  print("W ELL range ");  );
return(r[1]);
};
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

\\ B->Divisors->Gamma. Alpha(Gamma)->(mod Q*2). Beta.
Beta1(n)=
{
B=  -n^2;BA=abs(B);
GAM=divisors(BA);ALP=vector(#GAM+ 4 ,i,oo); \\ extra
ellcur=ellinit([B,0]);
for(i=1,#GAM,
  x= GAM[i];
  if(x!=n,
    if(x<n,x= -x;);
    b=ELLisx(ellcur,x);
    if(b==1,ALP[i]=core(x););
    );
  );
\\ Because P inf, the +1.
\\ Because P (0,0), core(B), -1.
\\ Because P (-n,0), (+n,0), core(-n), core(+n). 
IL=#GAM;
ALP[IL+1]= +1;ALP[IL+2]= +1;
ALP[IL+3]= -core(n);ALP[IL+4]= +core(n);
\\
ALP=vecsort(ALP,,8);
qtr=0;for(i=1,#ALP,if(ALP[i]!=oo,qtr++;););
return(qtr);
}

\\ B->Divisors->Gamma. Alpha(Gamma)->(mod Q*2). Beta.
Beta2(n)=
{
B=  +(2*n)^2;
GAM=divisors(B);ALP=vector(#GAM+ 1 ,i,oo); \\ extra
ellcur=ellinit([B,0]);
for(i=1,#GAM,
  x= GAM[i];
  b=ELLisx(ellcur,x);if(b==1,ALP[i]=core(x););
  );
\\ Because P inf, the +1.
\\ Because (0,0), core(B>0), also +1.
\\ nothing here for (-n,0) (+n,0).
IL=#GAM;ALP[IL+1]= +1;
\\
ALP=vecsort(ALP,,8);
qtr=0;for(i=1,#ALP,if(ALP[i]!=oo,qtr++;););
return(qtr);
}

sarank(n)=
{
my(b1,b2,rr);

\\ compute beta values
b1= Beta1(n);b2= Beta2(n);

\\ compute the rank
for(i=0,9,if(b1<=2^i,b1=i;break;););
for(i=0,9,if(b2<=2^i,b2=i;break;););
rr=b1+b2-2;
\\ print("n= " n " SArank= " rr "= " b1 "+" b2 "-2" );
return(rr);
}

ispqrs(n)=
{
my(p,q,r,s);
qf=0;
fordiv(n,r,               \\ r|n
  s=n/r;if(s<r,break;);
  for(p=r+1,s-r,
    q=n/p;
    if(p*q==n && q<=p,break;); \\ p<q
    if(p*q==n && s==p+q+r,
      qf++;
      \\ print(n "=" p "*" q "=" r "*" s);
      );
    );
  );
return(qf);
}

\\ main
{
for(n= 1,1300,
  qf= ispqrs(n);
  rr=sarank(n);
  \\ Check
  ellrk=ELLrank(n);
  print1("n=" n " qf=" qf " SArank=" rr);
  if(rr!=ellrk,print(" (" ellrk ")");,print;);
  );
}
