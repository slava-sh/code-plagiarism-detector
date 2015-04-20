type d=record
     l,r:int64;
     x:integer
     end;
var n,m,i,j,cod:integer;
    t,tz:int64;
    s:array[1..1000] of d;
    f,f1:text;
    ch:string;

begin
assign(f,'dunes.in');
assign(f1,'dunes.out');
reset(f);
rewrite(f1);
readln(f,n,m);

for i:=1 to n do
 readln(f,s[i].l,s[i].r,s[i].x);
for i:=1 to m do begin
 readln(f,ch); val(ch,t,cod);
 tz:=0;
 for j:=1 to n do
  if (t>=s[j].l) and (t<=s[j].r) then
   if ((t-s[j].l)mod 2=0) then tz:=tz+s[j].x
                     else tz:=tz-s[j].x;
  writeln(f1,tz);
 end;
close(f);
close(f1)
end.