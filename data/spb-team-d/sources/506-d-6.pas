program nd;
const w=10000;
var
a:array[1..w] of longint;
i,n,m,j,l,r,f:longint;
x:integer;
begin
for i:=1 to w do a[i]:=0;
assign(output,'dunes.out');
assign(input,'dunes.in');
rewrite(output);
reset(input);
readln(n,m);
for i:=1 to n do
 begin
 x:=0;
 readln(l,r,f);
 for j:=l to r do
  begin
  if x=0 then a[j]:=a[j]+f else a[j]:=a[j]-f;
  x:=(x+1) mod 2;
  end;
 end; 
for i:=1 to m do
begin
readln(l);
if l<=10000 then
writeln(a[l]) else writeln(0);
end;
close(input);
close(output);
end. 