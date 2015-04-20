program Project2;

{$APPTYPE CONSOLE}

{%File 'gcm.in'}
{%File 'gcm.out'}

uses
  SysUtils;

var
x1,y1,a,a1,b1,q,j,i,nod,min,nok,b,x,y,p:longint;
begin
assign(input,'gcm.in');
assign(output,'gcm.out'); 
readln(a,b);
min:=abs(a-b);
a1:=a;
b1:=b;
while b <> 0 do
begin
if b<a then begin q:=a; a:=b; b:=q;end;
b:=b mod a;
end;
nod:=a;
nok:= a1*b1 div nod;
p:=nok*nod;
for i:=1 to p do
  for j:=1 to p do
  if (i*j=p) and (abs(j-i)<= min)
   then begin x:=i;y:=j;min:=abs(j-i);end;
if y<x then begin p:=x; x:=y; y:=p; end; 
writeln(x,' ',y);
end.
