uses math;
const
        fi='';
var
        f:text;
        n,l,r,mid,kq,s:longint;
        a,b:array [1..100010] of longint;
        g:array [1..3,1..100010] of longint;
procedure sort(l,r:longint);
var
        i,j,p,t:longint;
begin
        if l>=r then exit;
        i:=l; j:=r;
        p:=a[random(r-l+1)+l];
        repeat
                while a[i]<p do inc(i);
                while a[j]>p do dec(j);
                if i<=j then
                begin
                        t:=a[i]; a[i]:=a[j]; a[j]:=t;
                        inc(i); dec(j);
                end;
        until i>=j;
        sort(l,j);
        sort(i,r);
end;
procedure nhap;
var
        i:longint;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        randomize;
        sort(1,n);
        close(f);
end;
procedure cb;
var
        i,u:longint;
begin
        u:=1;
        a[n+1]:=-1;
        for i:=2 to n+1 do
        if a[i]<>a[i-1] then
        begin
                inc(s);
                a[s]:=a[i-1];
                b[s]:=u;
                u:=1;
        end
        else inc(u);
end;
function ck(u:longint):boolean;
var
        i,x,y,t:longint;
begin
        x:=0; t:=1;
        for i:=1 to s do
        begin
                if b[i]>u then y:=u
                else y:=b[i];
                x:=x+y;
                if x>u then
                begin
                        inc(t);
                        x:=x-u;
                end;
                if (t>3) or ((t=3) and (x>=u)) then exit(true);
        end;
        exit(false);
end;
procedure xuly;
begin
        l:=1; r:=n;
        repeat
                mid:=(l+r) div 2;
                if ck(mid) then
                begin
                        kq:=math.max(kq,mid);
                        l:=mid+1;
                end
                else r:=mid-1;
        until l>r;
        writeln(kq);
end;
procedure xuat;
var
        i,x,y,t,j,u:longint;
begin
        if kq=0 then exit;
        u:=kq;
        x:=0; t:=1;
        for i:=1 to s do
        begin
                if b[i]>u then y:=u
                else y:=b[i];
                x:=x+y;
                if x<=u then
                begin
                        for j:=x-y+1 to x do g[t,j]:=a[i];
                        if (t=3) and (x>=u) then break;
                end
                else
                if x>u then
                begin
                        for j:=x-y+1 to u do g[t,j]:=a[i];
                        inc(t);
                        if t>3 then break;
                        x:=x-u;
                        for j:=1 to x do g[t,j]:=a[i];
                end;
                if (t>3) or ((t=3) and (x>=u)) then break;
        end;
        for i:=1 to u do
        begin
                for x:=1 to 2 do
                for y:=x+1 to 3 do
                if g[y,i]>g[x,i] then
                begin
                        t:=g[y,i]; g[y,i]:=g[x,i]; g[x,i]:=t;
                end;
        end;
        for i:=1 to u do writeln(g[1,i],' ',g[2,i],' ',g[3,i]);
end;
begin
        nhap;
        cb;
        xuly;
        xuat;
end.