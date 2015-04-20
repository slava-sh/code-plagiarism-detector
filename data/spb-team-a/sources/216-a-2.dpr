program A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var t,i,kod: longint;
begin
 readln(t);
   reset(input, 'abcd.in');
   rewrite(output, 'abcd.out');
        for i:=1 to t do begin
          readln(kod);
          if ((((kod div 1000)*10+(kod div 100 mod 10)) + ((kod mod 10) + (kod mod 100 div 10)*10)) mod 7 = 1) then writeln('YES')
           else writeln('NO');
        end;
   close(output);
end.
 