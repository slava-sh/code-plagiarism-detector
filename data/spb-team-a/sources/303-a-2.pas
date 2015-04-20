var x,t,i:longint;
begin
   assign(input,'abcd.in');
   assign(output,'abcd.out');
   reset(input);
   rewrite(output);
   read(t);
   for i:=1 to t do begin
                       read(x);
                       if (sqr(x mod 100) + sqr(x div 100)) mod 7 = 1 then writeln('YES')
                       else writeln('NO');
                    end;
   close(input);
   close(output);
end.