{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O+,P+,Q-,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}
program ololo;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
i,j,t,m,k,baget,s,l,mini,lol,geronimo,slol:integer;
a,c,n:array[1..100000] of integer;
b:array[1..100000] of boolean;


begin
{ reset(input,'input.txt');
 rewrite(output,'output.txt');}
 readln(t);
 for i:=1 to t do begin
  read(m,k);
  for j:=1 to k do  begin
   read(a[j]);
   c[j]:=a[j];
   b[j]:=false;
  end;
  s:=0;
  lol:=0;
  for j:=1 to m-1 do begin
   read(n[j],baget);
   if (lol=0) and (baget=1) then  begin
    lol:=j;
    slol:=s;
   end;
   if n[j]>0 then
    dec(a[n[j]])
   else inc(s);
  end;
  if lol<>0 then begin
   for j:=1 to lol-1 do
    if n[j]>0 then
     dec(c[n[j]]);
   mini:=10000000;
   for j:=1 to k do
    if (c[j]=a[j]) then begin
     if a[j]<=slol then
      b[j]:=true;
     if (c[j]<mini) then begin
      geronimo:=j;
      mini:=c[j];
     end;
    end;
   s:=s-mini;
   a[geronimo]:=0;
  end;
  for j:=1 to k do
   if a[j]<=s then
    b[j]:=true;
  for j:=1 to k do
   if b[j] then
    write('Y')
   else write('N');
  writeln;
 end;
 end.
