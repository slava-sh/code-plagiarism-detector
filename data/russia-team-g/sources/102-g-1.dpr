program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

var
  n, m: integer;

begin
  reset(input, 'prizes.in');
  rewrite(output, 'prizes.out');

  readln(n, m);

  if (n = 2) or (m = 2) then begin
    writeln(0);
    halt;
  end;

  if (n > 1) and (m > 1) then begin
    writeln(1);
    halt;
  end;

  writeln((max(n, m) + 1) div 4);
end.
 