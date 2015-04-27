const
  maxe = 1000000;
  maxq = maxe;
  edges = 8000000;
  maxn = 1000;

var
  f,t,p:array[0..edges] of longint;
  a:array[0..maxn, 0..maxn] of longint;
  cl,q,d:array[0..maxe] of longint;
  t1,t2,h1,h2:array[0..maxn] of longint;
  ch,ct,qq,vn,vv,q1,q2,draw,nh,nt,k,cc,i,j,ii,n,m,r:longint;

procedure addedge(const x, y:longint);
begin
  inc(ii);
  t[ii]:=y;
  p[ii]:=f[x];
  f[x]:=ii;
end;

procedure add(const vn, vv:longint);
begin
  if (vn = cc) then exit;
  if (d[vn]<=vv) then exit;
  q[q1]:=vn;
  inc(q1);
  if q1>maxq then q1:=0;
  d[vn]:=vv;
end;

procedure add2(const vn, vv:longint);
begin
  if (d[vn]>=vv) then exit;
  if vn <> cc then
  begin
    q[q1]:=vn;
    inc(q1);
    if q1>maxq then q1:=0;
  end;
  d[vn]:=vv;
end;

procedure out_zmey;
begin
  q1:=0; q2:=0;
  fillchar(d, sizeof(d), 0);
  add2(a[n, m], 1);
  while q1<>q2 do
  begin
    vn:=q[q2];
    qq:=f[vn];
    while qq>0 do
    begin
      add2(t[qq], d[vn]+1);
      qq:=p[qq];
    end;
    inc(q2);
    if q2>maxq then q2:=0;
  end;
  writeln(d[cc]-1);
  halt;
end;

function dfs(const k:longint):longint;
var
  y,qq:longint;
begin
  cl[k]:=1;
  qq:=f[k];
  while qq>0 do
  begin
    y:=t[qq];
    if cl[y] = 0 then
    begin
      if dfs(y) = 1 then
      begin
        dfs:=1;
        exit;
      end;
    end else if (cl[y] = 1) then
    begin
      dfs:=1;
      exit;
    end;
    qq:=p[qq];
  end;
  cl[k]:=2;
  dfs:=0;
end;

begin
{  assign(input, 'input.txt');
  reset(input);
  assign(output, 'output.txt');
  rewrite(output);}
  fillchar(a, sizeof(a), 0);
  cc:=0; ii:=0;
  read(n, m, r);
  read(ch);
  for i:=1 to ch do read(h1[i], t1[i]);
  read(ct);
  for i:=1 to ct do read(h2[i], t2[i]);
  for i:=0 to r do for j:=0 to r do if i+j<=r then
  begin
    inc(cc);
    a[i, j]:=cc;
  end;
  inc(cc);
  for i:=0 to maxn do for j:=0 to maxn do if a[i, j] = 0 then a[i, j]:=cc;
  fillchar(d, sizeof(d), 63);
  for i:=0 to r do for j:=0 to r do if i+j<=r then
  begin
    for k:=1 to ch do if k<=i then
    begin
      nh:=i-k+h1[k];
      nt:=j+t1[k];
      if (nh<0) then nh:=0;
      if (nt<0) then nt:=0;
      if (nt+nh>r) then addedge(a[i, j], cc) else addedge(a[i, j], a[nh, nt]);
    end;
    for k:=1 to ct do if k<=j then
    begin
      nh:=i+h2[k];
      nt:=j-k+t2[k];
      if (nh<0) then nh:=0;
      if (nt<0) then nt:=0;
      if (nt+nh>r) then addedge(a[i, j], cc) else addedge(a[i, j], a[nh, nt]);
    end;
  end;
  q1:=0; q2:=0;
  add(a[n, m], 0);
  while q1<>q2 do
  begin
    vn:=q[q2];
    qq:=f[vn];
    while qq>0 do
    begin
      add(t[qq], d[vn]+1);
      qq:=p[qq];
    end;
    inc(q2);
    if q2>maxq then q2:=0;
  end;
  if dfs(a[n, m]) = 1 then draw:=1;
  if d[1] > 1000000000 then
  begin
    if draw = 1 then writeln('Draw') else
    begin
      writeln('Zmey');
      out_zmey;
    end;
    halt;
  end;
  writeln('Ivan');
  writeln(d[1]);
  close(output);
end.

