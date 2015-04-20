program na;
var
a,n,i:longint;
begin
assign(output,'abcd.out');
assign(input,'abcd.in');
rewrite(output);
reset(input);
readln(n);
for i:=1 to n do
Begin
readln(a);
if ((sqr(a div 100)+sqr(a mod 100)) mod 7 = 1) then writeln('YES') else writeln('NO');
end;
close(input);
close(output);
end.