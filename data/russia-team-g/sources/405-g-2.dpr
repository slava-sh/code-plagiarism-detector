program sol;

uses
  SysUtils,math;

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
function F(x:int64):int64;
begin
  result:=x div 4;
  if x mod 4 =3
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
  if (n=1)or(m=1)
  then writeln(f(max(n,m)))
   else if min(n,m)<3
        then writeln(0)
        else writeln(1);
end.
