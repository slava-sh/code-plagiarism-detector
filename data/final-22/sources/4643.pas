program island_ek;
//{$mode delphi}
{$apptype console}
const kk=12;
      maxn=500000;
      maxm=1000000;
      inf=1 shl 30;
type Edge=
      record
        u,v:longint;
        w:byte;
      end;
var n,m,i,cur,kol,p,k:longint;
//    town:array[1..maxn]of byte;
    use:array[1..maxn]of Boolean;
    ed:array[1..maxm shl 1]of Edge;
    list:array[0..kk,0..maxn]of longint;
    d:array[1..maxn]of longint;
    first:array[1..maxn]of longint;
    next:array[1..maxm shl 1]of longint;
//    path:array[1..maxn]of longint;
begin
  assign(input,'graph.in'); reset(input);
  assign(output,'graph.out'); rewrite(output);

  read(n,m);
  for i:=1 to m do
  begin
    read(ed[i].u,ed[i].v,k);
    ed[i].w:=12 div k;
    ed[i+m].w:=ed[i].w;
    ed[i+m].u:=ed[i].v;
    ed[i+m].v:=ed[i].u;
  end;

  fillchar(first,sizeof(first),0);
  for i:=1 to m shl 1 do
  begin
    next[i]:=first[ed[i].u];
    first[ed[i].u]:=i;
  end;

  cur:=0;
  kol:=1;
  fillchar(list,sizeof(list),0);
  list[0,0]:=1;
  list[0,1]:=1;
  d[1]:=0;
  for i:=2 to n do
    d[i]:=inf;
  fillchar(use,sizeof(use),false);

  while kol<>0 do
  begin
    while list[cur,0]=0 do
      cur:=(cur+1) mod (kk+1);
    p:=list[cur,list[cur,0]];
    dec(list[cur,0]);
    dec(kol);
    if not use[p] then
    begin
      use[p]:=true;
      i:=first[p];
      while i<>0 do
      begin
        if (not use[ed[i].v]) and (d[ed[i].v]>d[ed[i].u]+ed[i].w) then
        begin
          d[ed[i].v]:=d[ed[i].u]+ed[i].w;
          inc(list[(cur+ed[i].w) mod (kk+1),0]);
          list[(cur+ed[i].w) mod (kk+1),list[(cur+ed[i].w) mod (kk+1),0]]:=ed[i].v;
          inc(kol);
        end;
        i:=next[i];
      end;
    end;
  end;
  for i:=2 to n do
    writeln(d[i]/12:0:8);

  close(input);
  close(output);
end.