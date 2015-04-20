program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,m,min,max:integer;
begin
  assign(input,'prizes.in');
  reset(input);
  assign(output,'prizes.out');
  rewrite(output);
  read(n,m);
  max:=n;
  min:=m;
  if m>max then begin max:=m; min:=n end;
  if (max+min)mod 2=0 then Writeln(max div min) else
    Writeln((min mod max)-min);
end.
