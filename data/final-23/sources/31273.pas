program signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
    len=262144+1;
var
    T:array[1..len] of integer;
    n,i,m,l,r,s,c:integer;
procedure modify(x,v:integer);
begin
    x:=x+len div 2-1;
    T[x]:=v;
    while x>1 do
    begin
        x:=x div 2;
        T[x]:=T[2*x]+T[2*x+1];
    end;
end;
function gets(l,r:integer):integer;
var
    s:integer;
begin
    s:=0;
    l:=l+len div 2-1;
    r:=r+len div 2-1;
    while l<=r do
    begin
        if l mod 2 =1 then
        begin
            s:=s+T[l];
            inc(l);
        end;
        if r mod 2=0 then
        begin
            s:=s+T[r];
            dec(r);
        end;
        l:= l div 2;
        r:= r div 2;
    end;
    result:=s;
end;
begin
    assign(input,'signchange.in');reset(input);
    assign(output,'signchange.out');rewrite(output);
    read(n);
    for i:=1 to n do
    begin
        read(T[len div 2+i-1]);
        if i mod 2=0 then
            T[len div 2+i-1]:=-T[len div 2+i-1];
    end;
    for i:=len div 2+n to len do
        T[i]:=0;
    for i:=len div 2-1 downto 1 do
        T[i]:=T[2*i]+T[2*i+1];
    read(m);
    for i:=1 to m do
    begin
        read(c,l,r);
        if c=0 then
        begin
            if l mod 2=0 then
                r:=-r;
            modify(l,r)
        end
        else
        begin
            s:=gets(l,r);
            if l mod 2=0 then
                s:=-s;
            writeln(s);
        end;
    end;
    close(input);
    close(output);
end.
