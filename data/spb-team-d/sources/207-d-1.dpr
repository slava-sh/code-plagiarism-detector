program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

  var a:array of integer;
  i,j,m,n,q  :integer;
  l,r,x,h :int64;


begin
h:=99999999 ;
setlength(a,h+1);
assignfile(input,'dunes.in');
assignfile(output,'dunes.out');

readln(n,m);

for i:=1 to n do
begin
  readln(l,r,x);
  for j:=l to r do
  begin
    a[j]:= a[j] + x;
    x:=0-x;
  end;
end;

for i:=1 to m do
begin
  readln(q);
  writeln(a[q]);
end;



close(input);
close(output);
end.
