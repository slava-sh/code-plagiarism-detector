program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var t, i: integer;
  K: array of integer;
begin
  assignfile (input, 'abcd.in');
  assignfile (output, 'abcd.out');
  readln (t);
  setlength (K, t);
  for i:=1 to t do read (K[i]);

  for i:=1 to t do begin
    if ((K[i]div 100) * (K[i]div 100) + (K[i] mod 100) * (K[i] mod 100)) mod 7 = 1 then
    writeln ('YES') else writeln ('NO');
  end;
  close (input);
  close (output);
end.
