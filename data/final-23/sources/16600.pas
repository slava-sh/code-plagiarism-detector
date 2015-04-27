{$o-,q+,r+}
program Project2;

{$APPTYPE CONSOLE}
uses
  SysUtils,
  Math;

type
  integer=longint;

var i,j,x,y,n,m,k,q,z:longint;
    b:array [0..500000] of int64;
    t : int64;

procedure swap(x1:integer);
begin
  while x1>=1 do
  begin
    b[x1]:=b[2*x1]+b[2*x1+1];
    x1:=x1 div 2;
  end;
end;

function getmin(v,l,r,x1,y1:integer):longint;
begin
  if (l>=x1) and (r<=y1)
    then getmin:=b[v]
    else
      if (r<x1) or (l>y1)
        then getmin:=0
        else
          getmin:=getmin(v*2,l,(l+r) div 2,x1,y1)+getmin(v*2+1,(l+r) div 2+1,r,x1,y1);

end;

begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  read(n);
  q:=131072;
  for i:=1 to q do
  begin
    t := i;
    if t<=n
    then
    begin
      read(x);
      b[i+q-1]:=x;
    end
    else b[t+q-1]:=0;
  end;
  for i:=q-1 downto (q-1) div 2 do
   b[i]:=b[2*i]-b[2*i+1];
  for i:=(q-1) div 2 downto 1 do
    b[i]:=b[2*i]+b[2*i+1];
  read(k);
  for i:=1 to k do
  begin
    read(z,x,y);
    if z=1
    then
    begin
      if x mod 2=1 then m:=getmin(1,q,2*q-1,x+q-1,y+q-1)
                   else m:=b[x+q-1]-getmin(1,q,2*q-1,x+q,y+q-1);
      writeln(m);
    end
    else
    begin
      t:=(x+q-1) div 2;
      b[x+q-1]:=y;
      b[t]:=b[2*t]-b[2*t+1];
      t:=t div 2;
      swap(t);
    end;
  end;
end.
