Var i,n,d:longint;
sum,rez:longint;
m:array [1..1000000] of longint;
procedure sort(l,r:longint);
Var i,j,k,x,b:longint;
begin
  i:=l; j:=r; k:=l+random(r-l+1); x:=m[k];
  repeat
    while m[i]<x do inc(i);
    while m[j]>x do dec(j);
    if i<=j
    then begin
          b:=m[i]; m[i]:=m[j]; m[j]:=b;
          inc(i); dec(j);
         end;
  until i>j;
  if i<r
  then sort(i,r);
  if j>l
  then sort(l,j);
end;
begin
  Assign(input,'sochi.in'); reset(input);
  Assign(output,'sochi.out'); rewrite(output);
  read(n,d);
  for i:=1 to n do
  read(m[i]);
  sort(1,n);
  rez:=m[n];
  sum:=m[n];
  for i:=n-1 downto 1 do
  begin
    if m[i]<=d
    then break;
    if (i<>n-1)and(m[i+2]<3*d)
    then break;
    sum:=sum+m[i];
    if i=n-1
    then begin
          if rez<sum-2*d
          then rez:=sum-2*d;
         end
    else begin
          if rez<sum-d*(n-i+1)-d*(n-i+1-2)
          then rez:=sum-d*(n-i+1)-d*(n-i+1-2);
         end;
  end;
  writeln(rez);
end.
 