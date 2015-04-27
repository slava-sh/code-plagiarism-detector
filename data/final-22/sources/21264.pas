program main2;

{$APPTYPE CONSOLE}

{$O+,D+,Q+,R+,S+}

uses
  SysUtils;

const maxN = 524288;

const inf = 1000000000;

type graph = record
  v, w:longint;
end;

type node = record
  v, next, w:longint;
end;

var d:array[1..maxN] of longint;
rmin:array[1..maxN * 2] of longint;
list:array[1..maxN * 4] of node;
last:array[1..maxN * 4] of longint;
n, m, i, j, aa, b, c, w, ind, bj, bd, size, t:longint;
e:array[1..maxN] of array of graph;

procedure add(a, b, c:longint);                                                    
begin
  inc(size);
  list[size].v:=b;
  list[size].next:=last[a];
  last[a]:=size;
  list[size].w:=c;
end;

function min(a, b:longint):longint;
begin
  if (a = inf) then min:=b
  else
  if (b = inf) then min:=a
  else
  if (d[a] < d[b]) then min:=a
  else min:=b;
end;

procedure update(i, x:longint);
begin
  i:=i + maxN - 1;
  rmin[i]:=x;
  while (i > 1) do begin
    i:=i div 2;
    rmin[i]:=min(rmin[i * 2], rmin[i * 2 + 1]);
  end;
end;

begin
  reset(input, 'graph.in');
  rewrite(output, 'graph.out');
  readln(n, m);
  for i:=1 to n do
    d[i]:=inf;
  for i:=1 to maxN * 2 do
    rmin[i]:=inf;
  size:=0;
  d[1]:=0;
  for i:=1 to m do begin
    readln(aa, b, c);
    add(aa, b, 12 div c);
    add(b, aa, 12 div c);
  end;
  
  update(1, 1);
  for i:=1 to n do begin
    bj:=rmin[1];
    bd:=d[bj];
    if (bd = inf) then break;
    update(bj, inf);
    t:=last[bj];
    while t <> 0 do begin
      if (bd + list[t].w < d[list[t].v]) then begin
        d[list[t].v]:=bd + list[t].w;
        update(list[t].v, list[t].v);
      end;
      t:=list[t].next;
    end;
  end;
  for i:=2 to n do
    writeln(d[i] / 12 : 0 : 10);
end.
 