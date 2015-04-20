program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  k2,q,k1,n,k,s,i,j:integer;
  a:array[1..2,1..1000]of integer;
begin
  assign(input, 'conquest.in');
  assign(output, 'conquest.out');
  read(n);
  readln;
  for i:=1 to n do
  for j:=1 to 2 do
  read(a[i,j]);
  s:=0;
  k:=n;
  k1:=0;
  k2:=0;
  q:=1;
  for i:=1 to n do
  k2:=k2+a[i,1];

  repeat
         k1:=k1+a[q,1]+1;
  for i:=1 to a[q,1]+1 do begin
  s:=s+a[k,2];
  k:=k-1;
  a[i,1]:=a[i,1]-1;
  end;




  a[q,1]:=0;
  q:=q+1;

  for j:=1 to n do
  if k1>a[j,1] then begin
    k1:=k1+a[j,1];
    a[j,1]:=0;
    end;

  until k1<=k2;
  write(s);
end.
