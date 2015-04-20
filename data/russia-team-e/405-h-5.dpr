{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O+,P+,Q-,R-,S-,T-,U-,V+,W-,X+,Y+,Z1}
program sol;

uses
  SysUtils,math;

Var m1,m3:array[1..5000,0..5000]of int64;
    mass:array[1..5000] of int64;
    F:array[1..5000] of Boolean;
    F1:Boolean;
    n,i,l,m,I1,J1,J,minI,minJ,c,l1,l2,d,a:longint;
    k,kend,minimum,minSum:int64;
{Procedure QSort(L,R:LongInt);
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
end;}
Procedure Poisk(I1,J1:LongInt;Sum:Int64);
Var I:longint;
begin
   If mass[J1]=2
   then begin
        If minSum>Sum
        then begin
             minSum:=Sum;
             minI:=I1;
             minJ:=J1;
             F1:=True;
             end;
        end
   else
   For I:=1 to m1[J1,0] do
   If ((not F[m1[J1,I]]) and (mass[m1[J1,I]]=0)) or (mass[m1[J1,I]]=2)
   then begin
        F[m1[J1,I]]:=True;
        Poisk(I1,m1[J1,I],Sum+m3[J1,m1[J1,I]]);
        F[m1[J1,I]]:=False;
        end;
end;
begin
  ///assign(input,'input.txt');
  assign(input,'secure.in');
  reset(input);
  ////assign(output,'output.txt');
  assign(output,'secure.out');
  rewrite(output);
  readln(N,M);
  For I:=1 to N do
  read(mass[I]);
  readln;
  F1:=False;
  For I:=1 to m do
  begin
  readln(I1,J1,c);
  Inc(m1[I1,0]);
  m1[I1,m1[I1,0]]:=J1;
  Inc(m1[J1,0]);
  m1[J1,m1[J1,0]]:=I1;
  m3[I1,J1]:=c;
  m3[J1,I1]:=c;
  end;
  minSum:=100000000000;
  FillChar(F,SizeOf(F),False);
  For I:=1 to N do
  If mass[I]=1
  then begin
       F[I]:=True;
       Poisk(I,I,0);
       end;
  If not F1
  then write('-1')
  else write(minI,' ',minJ,' ',minSum);
  {writeln(5000, 100000);
  write('1 ');
  For I:=2 to 4999 do
  write('0 ');
  writeln('2');
  For I:=1 to 4999 do
     For J:=4900 to 5000 do
     writeln(I,' ',J,' 1');}
end.
