var
  f1,f2:text;
  N,i,a:integer;
begin
assign(f1,'abcd.in');
assign(f2,'abcd.out');
reset(f1);
rewrite(f2);
read(f1,N); 
for i:=1 to N do begin
readln(f1, a);
if(((sqr(a mod 100) + sqr(a div 100)) mod 7) = 1) then writeln(f2,'YES')
else writeln(f2,'NO');
end;
close(f1);
close(f2);
end.