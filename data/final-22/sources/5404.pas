program PrB;

{$APPTYPE CONSOLE}

var
way,len:array [1..500001] of array of integer;
x1,y1,l1:array [1..800001] of integer;
lenv,last,kol:array [1..500001] of integer;
b:array [1..500001] of boolean;
que:array [1..5,0..800001] of integer;
c1,c2,c3,c4,c5,i,j,x,y,r,l,n,m:integer;


procedure add(x,y,l:integer);
begin
way[x,last[x]]:=y;
len[x,last[x]]:=l;
inc(last[x]);
end;

procedure addtoque(v,l:integer);
begin
if l=3
then
 begin
 inc(que[c1,0]);
 inc(r);
 que[c1,que[c1,0]]:=v;
 end;
if l=4
then
 begin
 inc(que[c2,0]);
 que[c2,que[c2,0]]:=v;
 end;
if l=6
then
 begin
 inc(que[c3,0]);
 que[c3,que[c3,0]]:=v;
 end;
if l=12
then
 begin
 inc(que[c4,0]);
 que[c4,que[c4,0]]:=v;
 end;
end;



procedure bfs(v:integer);
var
t:integer;
begin
c1:=1;
c2:=2;
c3:=3;
c4:=4;
l:=0;
r:=1;
que[c1,r]:=v;
que[c1,0]:=1;
while l<r do
 begin
 inc(l);
 v:=que[c1,l];
// if not b[v]
// then
  for i:=0 to high(way[v]) do
   begin
   if lenv[way[v,i]]>lenv[v]+len[v,i]
   then
    begin
    lenv[way[v,i]]:=lenv[v]+len[v,i];
    addtoque(way[v,i],len[v,i]);
    end;
   end;
// b[v]:=true;
 j:=0;
 while (l=r) and (j<4) do
  begin
  que[c1,0]:=0;
  t:=c4;
  c4:=c3;
  c3:=c2;
  c2:=c1;
  c1:=t;
  r:=que[c1,0];
  l:=0;
  inc(j);
  end;
 end;
end;

begin
reset(input,'graph.in');
rewrite(output,'graph.out');
readln(n,m);
{for i:=2 to n do
 lenv[i]:=1000000000;}
fillchar(lenv,sizeof(lenv),127);
lenv[1]:=0;
for i:=1 to m do
 begin
 readln(x1[i],y1[i],l1[i]);
 if l1[i]=1 then l1[i]:=12
 else
  if l1[i]=2 then l1[i]:=6
  else
   if l1[i]=3 then l1[i]:=4
   else
    if l1[i]=4 then l1[i]:=3;
 inc(kol[x1[i]]);
 inc(kol[y1[i]]);
 end;
for i:=1 to n do
 begin
 setlength(way[i],kol[i]);
 setlength(len[i],kol[i]);
 end;
fillchar(last,sizeof(last),0);
for i:=1 to m do
 begin
 add(x1[i],y1[i],l1[i]);
 add(y1[i],x1[i],l1[i]);
 end;
bfs(1);
for i:=2 to n do
 writeln(lenv[i]/12:0:9);

end.
