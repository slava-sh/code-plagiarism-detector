program Project2;

{$APPTYPE CONSOLE}


{%File 'chess.in'}
{%File 'chess.out'}
{%File 'gcm.in'}
{%File 'gcm.out'}

uses
  SysUtils;

var
a,a1,b1,q,j,i,nod,min,nok,b,x,y,p:longint;
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
  for j:=i to p do
  if (i*j=p) and ((j-i)<= min)
   then begin x:=i;y:=j;min:=j-i;end;
write(x,' ',y);
end.
