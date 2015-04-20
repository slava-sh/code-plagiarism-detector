program sol;

uses
  SysUtils,math;

Var m:array[1..100001]of longint;
    n,i,l,l1,l2,d,a:longint;
    k,kend,minimum:int64;
Procedure QSort(L,R:LongInt);
Var I,J,b,k,x:LongInt;
begin
   I:=L;
   J:=R;
   k:=L+Random(R-L);
   x:=m[k];
   Repeat
      While m[I]>x do
      Inc(I);
      While m[J]<x do
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
begin
  result:=x div 4;
  if x mod 4 =3
  then inc(result);
end;
begin
  ///assign(input,'input.txt');
  assign(input,'sochi.in');
  reset(input);
  ///assign(output,'output.txt');
  assign(output,'sochi.out');
  rewrite(output);
  readln(n,d);
  for i:=1 to n do
  begin
   read(m[i]);
  end;
  qsort(1,n);
  l:=m[1];
  l1:=m[1];
  l2:=m[1]-d;
  For I:=2 to n do
  begin
     If m[I]<=2*d
     then Break;
     If m[I]+l1-2*d>=d
     then begin
          If l<>l1
          then begin
               l:=l+m[I]-2*d;
               a:=l1;
               l1:=l2;
               l2:=a-d;
               end
          else begin
               l:=l+m[I]-2*d;
               l1:=l2;
               l2:=m[I]-d;
               end;
          end
     else Break;
  end;
  write(l);
end.
