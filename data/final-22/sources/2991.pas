program B_graph;

{$APPTYPE CONSOLE}
{$D-,L-,I-,Q-,R-,S-,O+}

uses
  SysUtils;

const
  inf = 100030000;  

var
  i,m,n,size,a,b,w: integer;
  q,nx,go,wt: array [0..1600000] of integer;
  d,f: array [0..500000] of integer;
  rmq: array [1..1000000] of integer;
  mark: array [1..500000] of boolean;
  weight: array [1..4] of integer = (12,6,4,3);

procedure add(a,b,w: integer);
begin
  inc(size);
  go[size] := b;
  wt[size] := weight[w];
  nx[size] := q[a];
  q[a] := size
end;

procedure update(i: integer);
begin
  rmq[i+n-1] := i;
  i := i+n-1;
  i := i shr 1;
  while i > 0 do
    begin
      if d[rmq[2*i]] < d[rmq[2*i+1]]
      then rmq[i] := rmq[2*i]
      else rmq[i] := rmq[2*i+1];
      i := i shr 1
    end
end;

procedure Dijkstra(v: integer);
var
  i,k,t,j: integer;
begin
  d[v] := 0;
  update(v);
  for k := 1 to n do
    begin
      j := rmq[1];
      if d[j] >= inf then exit;
      mark[j] := true;
      t := q[j];
      while t > 0 do
        begin
          if (not mark[go[t]])and(d[go[t]] > d[j]+wt[t]) then
            begin
              d[go[t]] := d[j]+wt[t];
              update(go[t])
            end;
          t := nx[t]
        end;
      f[j] := d[j];
      d[j] := inf;
      update(j)
    end;
end;

begin
  reset(input,'graph.in');
  rewrite(output,'graph.out');
  read(n,m); if n =1 then halt;
  size := 0;
  fillchar(q,sizeof(q),0);
  fillchar(nx,sizeof(nx),0);
  for i := 1 to m do
    begin
      read(a,b,w);
      add(a,b,w);
      add(b,a,w)
    end;

  for i := 0 to n do
    begin
      f[i] := inf;
      d[i] := inf;
      update(i)
    end;

  fillchar(mark,sizeof(mark),0);

  Dijkstra(1);

  for i := 2 to n do
    writeln(f[i]/12:0:8)
end.
