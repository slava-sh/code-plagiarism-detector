program graph;

{$APPTYPE CONSOLE}
{$O+,D-,I-,L-,Q-,R-,S-}
//{$O-,D+,I+,L+,Q+,R+,S+}

uses
  SysUtils;

const inf = 120000000;
var
  n, m, i, sz, u, v, t : integer;
  go, nx, vl : array [1..1600000] of integer;
  q, d, f : array [0..500000] of integer;
  mark : array [0..500000] of boolean;
  rmq : array [1..1000100] of integer;

procedure Add(v, u, w : integer);
begin
  inc(sz);
  go[sz] := u;
  vl[sz] := w;
  nx[sz] := q[v];
  q[v] := sz
end;

procedure Put(pos : integer);
begin
  rmq[pos+n-1] := pos;
  inc(pos,n-1);
  pos := pos shr 1;
  while (pos>0) do
  begin
    rmq[pos] := rmq[2*pos];
    if (d[rmq[pos]]>d[rmq[2*pos+1]]) then rmq[pos] := rmq[2*pos+1];
    pos := pos shr 1
  end;
end;

procedure Dijkstra(s : integer);
var i, j, minj, t : integer;
begin
  for i:=0 to n do
  begin
    d[i] := inf;
    f[i] := d[i];
    Put(i)
  end;
  d[s] := 0; Put(s);
  fillchar(mark,sizeof(mark),0);
  for i:=1 to n do
  begin
    minj := rmq[1];
    if (d[minj]=inf) then break;
    mark[minj] := true;
    t := q[minj];
    while (t>0) do
    begin
      if (not mark[go[t]])and(d[go[t]]>d[minj]+vl[t]) then
      begin
        d[go[t]] := d[minj] + vl[t];
        Put(go[t]);
      end;
      t := nx[t]
    end;
    f[minj] := d[minj];
    d[minj] := inf;
    put(minj)
  end;
end;

begin
  reset(input, 'graph.in');
  rewrite(output, 'graph.out');

  fillchar(q, sizeof(q), 0);
  sz := 0;
  readln(n,m);
  for i:=1 to m do
  begin
    readln(u,v,t);
    Add(u,v,12 div t);
    Add(v,u,12 div t)
  end;

  Dijkstra(1);

  for i:=2 to n do writeln((f[i]*1.0/12):0:10)

end.
