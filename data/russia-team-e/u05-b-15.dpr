program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var n,r,l:int64; a:array[0..300000] of longint;   i,j,b:integer;

begin
assign(input,'che.in');
reset(input);
assign(output,'che.out');
rewrite(output);
read(n,r);
for i:=1 to n do
read(a[i]);
if a[n]-a[1]>r then
begin
b:=1;
for i:=1 to n-1 do
for j:=b+1 to n do
begin
if a[j]-a[i]>r then
begin
l:=l+(n-j)+1;
b:=j-1;
break;
end;
end;
end;
write(l);



end.
