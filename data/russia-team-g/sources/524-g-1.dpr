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

  if m < 3 then
    begin
      if m = 1 then
      begin
        if n < 3 then write(0)
        else
          write((n - 3) div 4 + 1);
      end
      else
        write(0);
      close(output);
      exit;
    end;
  write((m - 3) div 4 + 1);
  close(output);
end.


