program sol;

uses
  SysUtils,math;
var n,k,l,r,x:int64;
    i:longint;
    m:array[1..100002]of int64;
Procedure QSort(L,R:LongInt);
Var I,J,b,k,x:LongInt;
begin
   I:=L;
   J:=R;
   k:=L+Random(R-L);
   x:=m[k];
   Repeat
      While m[I]<x do
      Inc(I);
      While m[J]>x do
      Dec(J);
      If I<=J
      then begin
           b:=m[I];
           m[I]:=m[J];
           m[J]:=b;
           Inc(I);
           Dec(J);
           end;
   Until I>J;
   If I<=R
   then QSort(I,R);
   If J>=L
   then QSort(L,J);
end;
function F(x:int64):int64;
var i:longint;
    color:int64;
begin
  color:=0;
  for i:=1 to n do
  begin
    if m[i]<x
    then begin
           result:=-1;
           exit;
         end;
    color:=max(color+x,m[i]);
    if (color>k)
    then begin
           result:=-1;
           exit;
         end;
  end;
  result:=k-color;
end;
begin
  //assign(input,'input.txt');
  assign(input,'fence.in');
  reset(input);
  //assign(output,'output.txt');
  assign(output,'fence.out');
  rewrite(output);
  readln(n,k);
  for i:=1 to n do
  read(m[i]);
  qsort(1,n);
  l:=0;
  r:=k+1;
  for i:=1 to 40 do
  begin
    x:=(l+r) div 2;
    if f(x)<0
    then r:=x
    else l:=x;
  end;
  writeln(l);
end.
