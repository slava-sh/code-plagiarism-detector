uses math;

const inf = maxlongint div 2;

var nx,g,a                              : array [0..2000000] of longint;
    f,d					: array [0..500000] of longint;
    u                                   : array [0..2000000] of boolean;
    q                                   : array [0..12,0..500000] of longint;
    m,n,x,y,z                           : longint;

procedure BFS(v : longint);
var i,h,cur,x,r : longint;
begin
  for i:=1 to n do
    d[i]:=inf;

  q[0,0]:=1; q[0,1]:=v;
  h:=0; cur:=0;
  d[v]:=0;

  while h <= q[cur,0] do begin

    x:=0;
    for i:=0 to 12 do
      if (q[i,0] <> 0) then x:=1;
    if x = 0 then break;

    inc(h);
    if h > q[cur,0] then begin
      q[cur,0]:=0;
      h:=0; inc(cur);
      cur:=cur mod 13;
      continue;
    end;

    if not u[q[cur,h]] then begin
      u[q[cur,h]]:=true;

      x:=f[q[cur,h]];
      while x>0 do begin
        if (not u[g[x]]) then begin
          r:=(cur + a[x])mod 13;
          inc(q[r,0]);
          q[r,q[r,0]]:=g[x];
          d[g[x]]:=min(d[g[x]],d[q[cur,h]]+a[x]);
        end;
        x:=nx[x];
      end;

    end;

  end;
end;

var i   				: longint;

begin
  assign(input,'graph.in'); reset(input);
  assign(output,'graph.out'); rewrite(output);
    read(n,m);
    for i:=1 to m do begin
      read(x,y,z);
      if z = 4 then z:=3 else
      if z = 3 then z:=4 else
      if z = 2 then z:=6 else z:=12;
      
      nx[i]:=f[x]; f[x]:=i; g[i]:=y; a[i]:=z;
      nx[m+i]:=f[y]; f[y]:=m+i; g[m+i]:=x; a[m+i]:=z;
    end;

    bfs(1);

    for i:=2 to n do
      writeln(d[i]/12 :0:8);
  close(input); close(output);
end.
