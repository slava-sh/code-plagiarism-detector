program abcd;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  t, i, current : Integer;

begin
  reset(input, 'abcd.in');
  rewrite(output, 'abcd.out');
  Read(t);

  for i:=1 to t do
  begin
    Read(current);
    if (sqr(current div 100) + sqr(current mod 100)) mod 7 = 1 then
      WriteLn('YES') else
      WriteLn('NO'); 
  end;



  close(output);
end.
 