program
  graph;
{$APPTYPE CONSOLE}
const
  inf=100000000;
  maxn=500001;
  maxm=800001;
type
  re=record
    x,y,k:longint;
  end;
  mas=array[1..maxn] of longint;
  arr=array[1..maxm] of re;
  www=array of longint;
  mas_www=array[1..maxn] of www;
var
  i,n,m:longint;
  nn,c,res:mas;
  r:arr;
  a,b:mas_www;
  o:array[1..12] of www;
  top,t:array[1..12] of longint;
procedure o12;
var
  i:longint;
begin
  inc(top[12]);
  for i:=1 to nn[o[12,top[12]]] do
    if res[o[12,top[12]]]+b[o[12,top[12]],i]<res[a[o[12,top[12]],i]] then
    begin
      inc(t[b[o[12,top[12]],i]]);
      o[b[o[12,top[12]],i],t[b[o[12,top[12]],i]]]:=a[o[12,top[12]],i];
      res[a[o[12,top[12]],i]]:=res[o[12,top[12]]]+b[o[12,top[12]],i];
    end;
end;
procedure o6;
var
  i:longint;
begin
  inc(top[6]);
  for i:=1 to nn[o[6,top[6]]] do
    if res[o[6,top[6]]]+b[o[6,top[6]],i]<res[a[o[6,top[6]],i]] then
    begin
      inc(t[b[o[6,top[6]],i]]);
      o[b[o[6,top[6]],i],t[b[o[6,top[6]],i]]]:=a[o[6,top[6]],i];
      res[a[o[6,top[6]],i]]:=res[o[6,top[6]]]+b[o[6,top[6]],i];
    end;
end;
procedure o4;
var
  i:longint;
begin
  inc(top[4]);
  for i:=1 to nn[o[4,top[4]]] do
    if res[o[4,top[4]]]+b[o[4,top[4]],i]<res[a[o[4,top[4]],i]] then
    begin
      inc(t[b[o[4,top[4]],i]]);
      o[b[o[4,top[4]],i],t[b[o[4,top[4]],i]]]:=a[o[4,top[4]],i];
      res[a[o[4,top[4]],i]]:=res[o[4,top[4]]]+b[o[4,top[4]],i];
    end;
end;
procedure o3;
var
  i:longint;
begin
  inc(top[3]);
  for i:=1 to nn[o[3,top[3]]] do
    if res[o[3,top[3]]]+b[o[3,top[3]],i]<res[a[o[3,top[3]],i]] then
    begin
      inc(t[b[o[3,top[3]],i]]);
      o[b[o[3,top[3]],i],t[b[o[3,top[3]],i]]]:=a[o[3,top[3]],i];
      res[a[o[3,top[3]],i]]:=res[o[3,top[3]]]+b[o[3,top[3]],i];
    end;
end;
procedure bfs;
begin
  while not((top[12]=t[12])and(top[6]=t[6])and(top[3]=t[3])and(top[4]=t[4])) do
  begin
    if top[12]<>t[12] then
      o12;
    if top[6]<>t[6] then
      o6;
    if top[4]<>t[4] then
      o4;
    if top[3]<>t[3] then
      o3;
  end;
end;
procedure sett;
begin
  setlength(o[3],400002);
  setlength(o[4],400002);
  setlength(o[6],400002);
  setlength(o[12],400002);
end;
begin
  assign(input,'graph.in');
  assign(output,'graph.out');
  readln(n,m);
  for i:=1 to m do
  begin
    readln(r[i].x,r[i].y,r[i].k);
    case r[i].k of
      1: r[i].k:=12;
      2: r[i].k:=6;
      3: r[i].k:=4;
      4: r[i].k:=3;
    end;
    inc(nn[r[i].x]);
    inc(nn[r[i].y]);
  end;
  for i:=1 to n do
  begin
    setlength(a[i],(nn[i]+1));
    setlength(b[i],(nn[i]+1));
  end;
  for i:=1 to m do
  begin
    inc(c[r[i].x]);
    a[r[i].x,c[r[i].x]]:=r[i].y;
    b[r[i].x,c[r[i].x]]:=r[i].k;
  end;
  for i:=m+1 to 2*m do
  begin
    inc(c[r[i-m].y]);
    a[r[i-m].y,c[r[i-m].y]]:=r[i-m].x;
    b[r[i-m].y,c[r[i-m].y]]:=r[i-m].k;
  end;
  sett;
  for i:=2 to n do
    res[i]:=inf;
  for i:=1 to nn[1] do
    if b[1,i]<res[a[1,i]] then
    begin
      inc(t[b[1,i]]);
      o[b[1,i],t[b[1,i]]]:=a[1,i];
      res[a[1,i]]:=0+b[1,i];
    end;
  bfs;
  for i:=2 to n do
    writeln(res[i]/12);
end.
