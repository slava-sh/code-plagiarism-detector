program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var n,r,i,j,k:longint; a,c:array[0..300000] of longint;

begin
assign(input,'che.in');
reset(input);
assign(output,'che.out');
rewrite(output);
read(n,r);
k:=0;
for i:=1 to n do
read(a[i]);
for i:=n downto 1 do
for j:=i-1 downto 1 do
if (a[i]-a[j])>r then
begin
k:=k+j;
break;
end;
write(k);

end.
