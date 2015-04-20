Var n,i,k:longint;
j,l,r,z:longint;
zz,sum:int64;
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
  Assign(input,'fence.in'); reset(input);
  Assign(output,'fence.out'); rewrite(output);
  read(n,k);
  sum:=0;
  for i:=1 to n do
  begin
    read(m[i]);
    sum:=sum+m[i];
  end;
  sort(1,n);
  if sum<=k
  then begin writeln(m[1]); halt(0); end;
  l:=0; r:=m[1]+1;
  for j:=1 to 40 do
  begin
    z:=(l+r) div 2;
    zz:=m[1];
    for i:=2 to n do
    if m[i]-zz>=z
    then zz:=m[i]
    else zz:=zz+z;
    if zz>k
    then r:=z
    else l:=z; 
  end;
  writeln(l);
end.
 