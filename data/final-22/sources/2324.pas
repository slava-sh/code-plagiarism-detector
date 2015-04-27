{$o-}
const
    maxn=500000;

type
    int32=longint;
    bool=boolean;
    plist=^tlist;
    tlist=record
        key:int32;
        w:int32;
        next:plist;
    end;


var
    a:array [0..maxn] of plist;
    d:array [0..maxn] of int32; 
    head:array [0..12] of int32;
    tail:array [0..12] of int32;
    q:array [0..12,0..maxn] of int32;
    cur,n,m,i,u,v,w:int32;

    procedure list_insert(var l:plist; key:int32; w:int32);
    var x:plist;
    begin
        new(x);
        x^.key:=key;
        x^.w:=w;
        x^.next:=l;
        l:=x;
    end;

    procedure enq(key:int32; k:int32);
    begin
        q[k,tail[k]]:=key;
        tail[k]:=tail[k]+1;
        if tail[k]>maxn then tail[k]:=1;
    end;

    function deq:int32;
    begin
        deq:=q[cur,head[cur]];
        head[cur]:=head[cur]+1;
        if head[cur]>maxn then head[cur]:=1; 
    end;

    procedure bfs(st:int32);
    var i,v,kol:int32;
        x:plist;
    begin
        for i:=1 to n do d[i]:=maxlongint;
        d[st]:=0; cur:=0;
        {fillchar(tail,sizeof(tail),1);
        fillchar(head,sizeof(head),1);
        }
       { tail[0]:=1; tail[1]:=1; tail[2]:=1;
        head[0]:=1; head[1]:=1; head[2]:=1;}
        for i:=0 to 12 do
        begin
            head[i]:=1;
            tail[i]:=1;
        end;
        enq(st,cur); kol:=1;
        while kol>0 do
        begin
            v:=deq;
            kol:=kol-1;
            x:=a[v];
            while x<>nil do
            begin
                if d[x^.key]>d[v]+x^.w then
                begin
                    d[x^.key]:=d[v]+x^.w;
                    enq(x^.key,(cur+x^.w) mod 13);
                    kol:=kol+1;
                end;
                x:=x^.next;
            end;
            while (head[cur]=tail[cur])and(kol<>0) do
            begin
                cur:=cur+1;
                if cur>12 then cur:=0;
            end;
        end;
    end;


begin
    assign(input,'graph.in');
    reset(input);
    assign(output,'graph.out');
    rewrite(output);
    readln(n,m);
    for i:=1 to m do
    begin
        readln(u,v,w);
        list_insert(a[u],v,12 div w);
        list_insert(a[v],u,12 div w);
    end;
    bfs(1);
    for i:=2 to n do
        writeln((d[i]/12):0:12);
end.
