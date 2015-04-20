program A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var t,i,kod: longint;
begin

   reset(input, 'abcd.in');
   rewrite(output, 'abcd.out');
   readln(t);
        for i:=1 to t do begin
          readln(kod);
          if ((sqr((kod div 100)) + sqr((kod mod 100))) mod 7 = 1) then writeln('YES')
           else writeln('NO');
        end;
   close(output);
end.
 