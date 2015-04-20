program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
 var n,d,c,s,i,k,res:integer; a:array[0..100000] of integer;
begin
{assign(input,'sochi.in');
reset(input);
assign(output,'sochi.out');
rewrite(output);  }
s:=0;
k:=0;
read(n,d);
if n>1 then
begin
for i:=1 to n do
begin
read(c);
if c>2*d then
begin
k:=k+1;
a[k]:=c;
end;
end;
res:=2;
if k>2 then
begin
for i:=1 to k do
if (a[i]<=3*d)and(res<>0) then
begin
s:=s+a[i]-d;
res:=res-1;
end else
s:=s+a[i]-2*d;
end else if k=1 then
begin
write(a[1]);
flush(output);
exit;
end else
begin
write(a[1]+a[2]-2*d);
flush(output);
exit;
end;
end else
begin
read(s);
end;
write(s);
flush(output);




end.
 