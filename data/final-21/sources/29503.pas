program Project2;

{$APPTYPE CONSOLE}
{$R-,O-,Q-}

uses
    SysUtils;

var
    p: array[0..1000001] of int64;
    p1, i, j, k, st1, st2, f1, f2, n, ls1, ls: integer;
    pref, suf: array[0..1000000] of int64;
    s, s1: string;
    f: boolean;

begin
    reset(input, 'inventory.in');
    rewrite(output, 'inventory.out');
    readln(n);
    p[0]:=1;
    p1:=31;
    pref[0]:=0;
    for i:=1 to 1000000 do
        p[i]:=p[i-1]*p1;
    for i:=1 to n do
    begin
        readln(s);
        s1:=s+s;
        ls1:=length(s1);
        ls:=length(s);
        suf[length(s1)+1]:=0;
        for j:=1 to ls1 do
        begin
            pref[j]:=pref[j-1]+ord(s1[j])*p[j-1];
            suf[ls1-j+1]:=suf[ls1-j+2]+ord(s1[ls1-j+1])*p[j-1];
        end;
        k:=length(s) mod 2;
        f:=false;
        for j:=1 to length(s) do
        begin
            st1:=j-1;
            f1:=j+length(s) div 2-1;
            f2:=f1+k+1;
            st2:=f2+length(s) div 2;
            if ls1-f2-f1+1 > 0 then
            begin
                if (pref[f1]-pref[st1])*p[ls1-f2-f1+1]=(suf[f2]-suf[st2]) then
                begin
                    writeln(j-1);
                    f:=true;
                    break;
                end;
            end
            else
                if (pref[f1]-pref[st1])=(suf[f2]-suf[st2])*p[abs(ls1-f2-f1+1)] then
                begin
                    writeln(j-1);
                    f:=true;
                    break;
                end;
        end;
        if not f then
            writeln(-1);
    end;
end.
 
