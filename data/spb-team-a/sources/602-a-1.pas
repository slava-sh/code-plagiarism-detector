program A;
var
t,s,tc,m: integer;
f1,f2: text;
begin
assign(f1,'abcd.in');
assign(f2,'abcd.out');
rewrite(f2);
reset(f1);
readln(f1,t);
for tc:=1 to t do begin
  read(f1,s);
  m:=((s mod 100)*(s mod 100) + (s div 100)*(s div 100)) mod 7;
  if m=1 then
    writeln(f2,'YES')
  else
    writeln(f2,'NO');
end;
close(f1);
close(f2);
end.  