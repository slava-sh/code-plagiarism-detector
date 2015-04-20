Program A;
var t,i,kod: longint;
begin
readln(t);
   assign(input, 'abcd.in');
   assign(output, 'abcd.out');
   reset(input);
   reset(output);
        for i:=1 to t do begin
          readln(kod);
          if ((((kod div 1000)*10+(kod div 100 mod 10)) + ((kod mod 10) + (kod mod 100 div 10)*10)) mod 7 = 1) then writeln('YES')
           else writeln('NO');
        end;
   close(input);
   close(output);
end.