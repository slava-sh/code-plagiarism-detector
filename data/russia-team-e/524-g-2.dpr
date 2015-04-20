program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  m,n,c:int64;
begin
  assign (input,'prizes.in');
  reset(input);
  read(m,n);
  close(input);
  assign(output,'prizes.out');
  rewrite(output);
  
  if m > n then
    begin
      c:=m;
      m:=n;
      n:=c;
    end;
  if m>2 then
    write((m+1) div 4)
  else
    if m=1 then
      write((n+1) div 4)
    else
      write(0);
  close(output);
end.


