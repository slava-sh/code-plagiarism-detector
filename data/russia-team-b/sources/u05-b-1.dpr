program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var n,r,i,k:integer; a:array[0..300000] of longint;
  function check(var a:array of longint; n,r:integer): integer;
  var j,k:integer;
  begin
  k:=0;
  for j:=1 to n-1 do
  if abs(a[n]-a[j])>r then k:=k+1;
  check:=k;
  end;

begin
assign(input,'input.txt');
reset(input);
assign(output,'output.txt');
rewrite(output);
read(n,r);
k:=0;
for i:=1 to n do
begin
read(a[i]);
k:=k+check(a,i,r);
end;
write(k);

end.
 