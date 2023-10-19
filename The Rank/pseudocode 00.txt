Computing the rank
pseudocode 

procedure
rank(n)
begin
- Let C[n] be: y^2 = x^3 -n^2*x

- Define +b = -(n^2).  
- Apply the procedure "Cardinality" to the integer b. 
- Get the value c1.

- Define +b = (-4)*(-n^2).  
- Apply the procedure "Cardinality" to the integer b. 
- Get the value c2.

- find the minor power of two "p1" 
  that is at least equal or major than "c1".
- find the minor power of two "p2" 
  that is at least equal or major than "c1".
- p1, p2: 2,4,8,16,32, etc.
- Set pr= (p1*p2)/4. pr >= 1.
- It is proved that: [2^rank(n)] == pr.
- rank >= 0.
end

Procedure 
Cardinality(input b)
begin
- create a set D with all the positive divisors of +b: (1,...,b)
- duplicate every divisor in the set but with the sign negative.
- Apply the core() function to Each element of D and discard the duplicates.

- Apply the procedure "Test a divisor" to every element of D.
  Discard those that do not pass the test.

- Let c= cardinality(D). It will invariably be two or more.
- return this value.
end

procedure
test a divisor(d)
begin
- If d is "+1 or +b" then always accepted.
- For all the other divisors:
  - apply the procedure "The related point".
    Only if it is positive, accept that d. 
    Otherwise continue the test of d.
  - Apply the procedure "The related equation". 
    It will give positive or negative.
end

procedure
The related equation
begin.
  - look for a solution to the equation. // to be defined
  - verify that the solution overcomes all restrictions.
  - if there are any solutions give positive. 
    Negative if no solution.
end

procedure 
The related point
begin
If the given curve has some point P(x,y) with 
"x related to d"   // to de defined
then give positive. 
If it doesn't give negative.
end
