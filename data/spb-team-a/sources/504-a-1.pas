var a,b,c,cod:integer;
    i,t:longint;
    f,f1:text;
    s,s1,s2:string;

begin
assign(f,'abcd.in');
assign(f1,'abcd.out');
reset(f);
rewrite(f1);
readln(f,t);
for i:=1 to t do begin
  readln(f,s);
  s1:=s[1]+s[2];
  s2:=s[3]+s[4];
  val(s1,a,cod);
  val(s2,b,cod);
  a:=a*a;
  b:=b*b;
  c:=a+b;
  if (c mod 7=1) then writeln(f1,'YES')
                 else writeln(f1,'NO');
                 end;
close(f); close(f1)
end.
