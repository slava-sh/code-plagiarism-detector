program nd;
const o=1000;
var
a:array[1..o] of longint;
i,n,m,j,l,r,f:longint;
x:integer;
begin
for i:=1 to o do a[i]:=0;
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
writeln(a[l]);
end;
close(input);
close(output);
end.
