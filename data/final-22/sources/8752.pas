program zachetF;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const inf=1000000000;
type edge2=record
           u:longint;
           v:longint;
           w:longint;
           end;
     edge=record
          h:array of edge2;
          deg:longint;
          end;
var n,m,u,v,i,w,c,k,p:longint;
    a:array [1..1600000] of edge2;
    use,d:array [1..500000] of longint;
    f,nex:array [1..1600000] of longint;
    l:array [0..12,0..500000] of longint;
begin
reset(input,'graph.in');
rewrite(output,'graph.out');

read(n,m);

for i:=1 to m do
  begin
    read(u,v,w);
    a[i].u:=u;
    a[i].v:=v;
    a[i].w:=12 div w;
  end;
for i:=m+1 to m*2 do
  begin
    a[i].u:=a[i-m].v;
    a[i].v:=a[i-m].u;
    a[i].w:=a[i-m].w;
  end;
for i:=1 to m*2 do
  begin
    nex[i]:=f[a[i].u];
    f[a[i].u]:=i;
  end;

c:=0;
k:=1;
l[0,0]:=1;
l[0,1]:=1;
for i:=2 to n do
  d[i]:=inf;
d[1]:=0;

while k<>0 do
  begin
    while l[c,0]=0 do
      c:=(c+1) mod 13;
    p:=l[c,l[c,0]];
    dec(l[c,0]);
    dec(k);
    if use[p]=0 then
      begin
        use[p]:=1;
        i:=f[p];
        while i<>0 do
          begin
            if use[a[i].v]=0 then
              if d[a[i].v]>d[a[i].u]+a[i].w then
                begin
                  d[a[i].v]:=d[a[i].u]+a[i].w;
                  inc(l[(c+a[i].w) mod 13,0]);
                  l[(c+a[i].w) mod 13,l[(c+a[i].w) mod 13,0]]:=a[i].v;
                  inc(k);
                end;
            i:=nex[i];
          end;
      end;
  end;
for i:=2 to n do
  writeln(d[i]/12:0:8);

close(input);
close(output);
end.
