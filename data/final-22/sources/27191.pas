{$q+,r+,i+,o-,s+}
type
    bool=boolean;
    int32=longint;
    tarr=array of int32;
var
    q:array[0..12,0..500010] of int32;
    dist:array[0..500010] of int32;
    was:array[0..500010] of bool;
    a,b,v,first,ne:array[0..1600010] of int32;
    n,m,i,j,k,tx,w,k1   :int32;
procedure next(var  tx   :int32);
begin
    while (tx<12)and(q[tx,0]=0) do inc(tx);
    if q[tx,0]=0 then tx:=0;
    while (tx<12)and(q[tx,0]=0) do inc(tx);
    if q[tx,0]=0 then
        begin
            for i:=2 to n do
                writeln(dist[i]/12:0:9);
            halt(0);
        end;
end;
function min(x,y    :int64):int64;
begin
    if x<y then min:=x
        else min:=y;
end;
procedure push(x    :int32);
begin
    inc(q[dist[x] mod 13,0]);
    q[dist[x] mod 13,q[dist[x] mod 13,0]]:=x;
end;
procedure bfs(s :int32);
var
    u,i   :int32;
begin
    q[0,0]:=1;q[0,1]:=s;tx:=0;
    while 1=1 do
        begin
            next(tx);
            u:=q[tx,q[tx,0]];
            dec(q[tx,0]);
            if not(was[u]) then
            begin
                was[u]:=true;i:=first[u];
                repeat
                        if not(was[b[i]]) then
                            begin
                                dist[b[i]]:=min(dist[b[i]],dist[u]+v[i]);
                                push(b[i]);
                            end;
                            i:=ne[i];
                        if (i>0)and(ne[i]=0) then
                            begin

                        if not(was[b[i]]) then
                            begin
                                dist[b[i]]:=min(dist[b[i]],dist[u]+v[i]);
                                push(b[i]);
                            end;
                            end;  
                until ne[i]=0;
            end;
        end;
end;
begin
    reset(input,'graph.in');
    rewrite(output,'graph.out');
    readln(n,m);
    k:=1;
    for k1:=1 to m do
        begin
            readln(a[k],b[k],w);
                v[k]:=12 div w;
                ne[k]:=first[a[k]];
                first[a[k]]:=k;
            inc(k);
                a[k]:=b[k-1];
                b[k]:=a[k-1];
                v[k]:=v[k-1];
                ne[k]:=first[a[k]];
                first[a[k]]:=k;
            inc(k);
        end;
    for i:=2 to n do
        dist[i]:=maxlongint div 2;
    bfs(1);
end.
