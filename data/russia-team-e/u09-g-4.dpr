program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s,n,m,min,max:integer;
begin
  assign(input,'prizes.in');
  reset(input);
  assign(output,'prizes.out');
  rewrite(output);
  read(n,m);
  max:=n;
  min:=m;
  if m>=max then begin max:=m; min:=n end;

    s:=max div 2;
    s:=s+s div 2;
    Writeln((max-s)-1);

end.
