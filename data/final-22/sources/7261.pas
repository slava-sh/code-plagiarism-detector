uses math;

const inf = maxlongint div 2;

var next,edge,w                         : array [0..2000000] of longint;
    f,d					: array [0..500000] of longint;
    u                                   : array [0..2000000] of boolean;
    q                                   : array [0..12,0..500000] of longint;
    m,n,x,y,z,i                         : longint;

procedure bfs(v : longint);
var i,h,k,x,r : longint;
begin
  for i:=1 to n do
    d[i]:=inf;
  
  q[0,0]:=1; q[0,1]:=v;
  h:=0; k:=0;
  d[v]:=0;
  while h <= q[k,0] do begin
    x:=0;
    for i:=0 to 12 do
      if (q[i,0] <> 0) then x:=1;
    if x = 0 then break;
    inc(h);
    if h > q[k,0] then begin
      q[k,0]:=0;
      h:=0; inc(k);
      k:=k mod 13;
      continue;
    end;
    if not u[q[k,h]] then begin
      u[q[k,h]]:=true;
      x:=f[q[k,h]];
      while x>0 do begin
        if (not u[edge[x]]) then begin
          r:=(k + w[x])mod 13;
          inc(q[r,0]);
          q[r,q[r,0]]:=edge[x];
          d[edge[x]]:=min(d[edge[x]],d[q[k,h]]+w[x]);
        end;
        x:=next[x];
      end;
    end;
  end;
end;

begin
  assign(input,'graph.in'); reset(input);
  assign(output,'graph.out'); rewrite(output);
    read(n,m);
    for i:=1 to m do begin
      read(x,y,z);
      if z = 4 then z:=3 else
      if z = 3 then z:=4 else
      if z = 2 then z:=6 else z:=12;
      
      next[i]:=f[x]; 
      f[x]:=i; 
      edge[i]:=y; 
      w[i]:=z;
      next[m+i]:=f[y]; 
      f[y]:=m+i; 
      edge[m+i]:=x; 
      w[m+i]:=z;
    end;

    bfs(1);

    for i:=2 to n do
      writeln(d[i]/12 :0:8);
  close(input); close(output);
end.
