program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var n,r,i,j,k,c:longint; a:array[0..300000] of longint;

begin
assign(input,'che.in');
reset(input);
assign(output,'che.out');
rewrite(output);
read(n,r);
k:=0;
c:=0;
for i:=1 to n do
begin
read(a[i]);
c:=c+a[i]-a[i-1];
if c>r then
begin
for j:=i-1 downto 1 do
if (a[i]-a[j])>r then
begin
k:=k+j;
break;
end;
end;
end;
write(k);
{$N+.E-}

end.
