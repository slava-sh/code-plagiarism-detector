program sol;

uses
  SysUtils;

Var I,J,N,R:LongInt; Kol:Int64; m:array[1..350001] of LongInt;
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
begin
  ///assign(input,'input.txt');
  assign(input,'che.in');
  reset(input);
  ///assign(output,'output.txt');
  assign(output,'che.out');
  rewrite(output);
  readln(N,R);
  For I:=1 to N do
  read(m[I]);
  J:=1;
  Kol:=0;
  For I:=1 to N do
  begin
  While (m[J]-m[I]<=R) and (J<=N) do
  Inc(J);
  Kol:=Kol+N-J+1;
  end;
  write(Kol);
end.
 