program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const k = 1 shl 19;

type tree = array[1..2*k-1] of integer;

var H:tree;
    l:array[1..500000] of integer;
    d:array[0..500000] of integer;
    used:array[1..500000] of boolean;
    g:array[1..500000] of array of record x,w:integer; end;
    r:array[1..800000] of record x,y,w:integer; end;
    n,m,i,t,q:integer;

function Min(x,y:integer):integer;
begin
 if d[x] < d[y] then
  result:=x
 else
  result:=y;
end;

procedure Add(x:integer);
var cur:integer;
begin
 cur:=k+x-1;
 H[cur]:=x; cur:=cur shr 1;
 while cur > 0 do
  begin
   H[cur]:=Min(H[2*cur],H[2*cur+1]);
   cur:=cur shr 1;
  end;
end;

procedure Del(x:integer);
var cur:integer;
begin
 cur:=k+x-1;
 H[cur]:=0; cur:=cur shr 1;
 while cur > 0 do
  begin
   H[cur]:=Min(H[2*cur],H[2*cur+1]);
   cur:=cur shr 1;
  end;
end;


begin
reset(input,'graph.in');
rewrite(output,'graph.out');
readln(n,m);
fillchar(d,4*n+4,127);
d[0]:=maxint;
for i:=1 to m do
 begin
  readln(r[i].x,r[i].y,r[i].w);
  r[i].w:=12 div r[i].w;
  inc(l[r[i].x]);
  inc(l[r[i].y]);
 end;
for i:=1 to n do
 setlength(g[i],l[i]+1);
for i:=1 to m do
 begin
  t:=r[i].x;
  inc(g[t][0].x);
  g[t][g[t][0].x].x:=r[i].y;
  g[t][g[t][0].x].w:=r[i].w;
  t:=r[i].y;
  inc(g[t][0].x);
  g[t][g[t][0].x].x:=r[i].x;
  g[t][g[t][0].x].w:=r[i].w;
 end;
used[1]:=true;
t:=1; q:=1; d[1]:=0;
while q <> n do
 begin
  for i:=1 to g[t][0].x do
   if not(used[g[t][i].x]) then
    begin
     if d[g[t][i].x] > d[t]+ g[t][i].w then
      begin
       d[g[t][i].x] := d[t] + g[t][i].w;
       add(g[t][i].x);
      end;
    end;
  t:=H[1];
  Del(t);
  used[t]:=true;
  inc(q);
 end;
for i:=2 to n do
 writeln(d[i]/12:0:9)
end.
