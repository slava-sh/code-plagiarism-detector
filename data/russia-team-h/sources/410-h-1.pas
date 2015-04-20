program h;
const
    nmax = 5009;
    mmax = 2*100009;
    kmax = 4*mmax;
type
    tar = array [0..nmax] of longint;
    edge = record
        a,b,c:longint;
    end;
    dj = record
        v, ves : longint;
    end;

    edgetar = array [0..mmax] of edge;

var n, m, i, k, mn, node, p : longint;
cnt, t : tar;
e : edgetar;
a : array [1..kmax] of dj;
d : tar;
iz : tar;
used : array [0..nmax] of boolean;
k1, k2 : longint;
begin
    Assign(input,'secure.in'); Reset(input);
    Assign(output,'secure.out'); Rewrite(output);
    Readln(n,m);
    //0 n+1
    k:=0;
    for i:=1 to n do begin
        Read(t[i]);
        if t[i]=1 then begin
            inc(k);
            e[k].a:=0; e[k].b:=i; e[k].c:=0;
        end else if t[i]=2 then begin
            inc(k);
            e[k].a:=n+1; e[k].b:=i; e[k].c:=0;
        end;
    end;
    readln();
    m:=m+k;
    for i:=k+1 to m do begin
        Readln(e[i].a,e[i].b,e[i].c);
    end;

    //input ends
    // n from 0 to n
    Inc(n);
    Fillchar(cnt,sizeof(cnt),0);
    for i:=1 to m do begin
        Inc(cnt[e[i].a]); Inc(cnt[e[i].b]);
    end;
    for i:=1 to n do begin
        cnt[i]:=cnt[i-1]+cnt[i];
    end;
    cnt[n+1]:=cnt[n]+1;
    for i:=1 to m do begin
        a[cnt[e[i].a]].v:=e[i].b; a[cnt[e[i].a]].ves:=e[i].c;
        a[cnt[e[i].b]].v:=e[i].a; a[cnt[e[i].b]].ves:=e[i].c;
        Dec(cnt[e[i].a]); Dec(cnt[e[i].b]);
    end;
    for i:=0 to n do inc(cnt[i]);
    //
    for i:=0 to n do d[i]:=maxlongint;
    d[0]:=0;
    iz[0]:=0;
    Fillchar(used,sizeof(used),false);
    while true do begin
        mn:=maxlongint;
        for i:=0 to n do begin
            if (not used[i]) and (mn > d[i]) then begin
                mn:=d[i];
                node:=i;
            end;
        end;
        if mn = maxlongint then break;
        used[node]:=true;
        //writeln('Node = ',node,' Distance = ',d[node]);
        //readln;
        for i:=cnt[node] to (cnt[node+1]-1) do begin
            if (d[a[i].v] > (d[node] + a[i].ves)) then begin
                d[a[i].v]:=d[node] + a[i].ves;
                iz[a[i].v]:=node;
                //Writeln(' to = ',a[i].v,' d new = ',d[a[i].v]);
                //readln;
            end;
        end;
        //if (node = n) then break;
    end;
    if d[n] = maxlongint then begin
        Writeln('-1');
    end else begin
        i:=n;
        k2:=iz[n];
        while iz[i]<>0 do i:=iz[i];
        k1:=i;
        Writeln(k1,' ',k2,' ',d[n]);
    end;
    Close(input); Close(output);
end.
