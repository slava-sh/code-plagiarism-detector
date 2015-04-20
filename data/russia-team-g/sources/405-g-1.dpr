program sol;

uses
  SysUtils;

Var m,n:int64;
{Procedure QSort(L,R:LongInt);
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
end; }
function F(x,y:int64):int64;
var k:int64;
begin
  if x>y
  then k:=y
  else k:=x;
  result:=k div 4;
  if k mod 4 =3
  then inc(result);
end;
begin
  //assign(input,'input.txt');
  assign(input,'prizes.in');
  reset(input);
  //assign(output,'output.txt');
  assign(output,'prizes.out');
  rewrite(output);
  readln(n,m);
  if (n=1)and(m=1)
  then begin
         writeln(0);
         halt(0);
       end;
  if n=1
  then n:=m+100;
  if m=1
  then m:=n+100;
  writeln(f(n,m));
end.
 