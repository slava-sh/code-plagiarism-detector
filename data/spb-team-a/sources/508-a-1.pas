var a,i,t:int64;
begin
assign(input,'abcd.in');
assign(output,'abcd.out');
reset(input);
rewrite(output);
read(t);
For i:=1 to t do
   begin
   read(a);
   if (sqr(a div 100)+sqr(a mod 100)) mod 7 = 1 then writeln('YES')
                                                else writeln('NO');
   
   end;
close(input);
close(output);
end.