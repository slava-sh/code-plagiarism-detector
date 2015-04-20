program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var a : array of integer;
n,i : integer;

begin
reset(input,'chess.in');
rewrite(output,'chess.out');
read(n);
setlength(a,n);
i := 0;
while i < n do
begin
read(a[i]);
i := i+1;
end;
i := 0;
while a[i] > i do i := i+1;
writeln(i);
n := i;
i := 0;
while i < n do
begin
writeln(i+1,' ',i+1);
i := i+1;
end;
  { TODO -oUser -cConsole Main : Insert code here }
end.
 