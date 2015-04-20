const nmax = 100009;
type tar = array [1..nmax] of longint;

        Procedure Sort(var a : tar; l, r : longint);
        var mid, w : longint;
        k, j : longint;
        begin
            k:=l;
            j:=r;
            mid:=a[l+random(r-l+1)];
            while k<=j do begin
                while (a[k] < mid) do inc(k);
                while (a[j] > mid) do dec(j);
                if k<=j then begin
                    w:=a[k]; a[k]:=a[j]; a[j]:=w;
                    inc(k); dec(j);
                end;
            end;
            if l<j then Sort(a,l,j);
            if r>k then Sort(a,k,r);
        end;

var n, d, i : longint;
a : tar;
cnt, res : longint;
cntgood : longint;
begin
    randseed:=435345;
    Assign(input,'sochi.in'); reset(input);
    Assign(output,'sochi.out'); rewrite(output);
    Readln(n,d);
    for i:=1 to n do begin
        Read(a[i]);
    end;
    Sort(a,1,n);
    cnt:=0;
    res:=0;
    cntgood:=0;
    for i:=n downto 1 do begin
        if a[i]>=3*d then begin
            Inc(res,a[i]-2*d);
            inc(cntgood);
        end else if (a[i]<3*d) and (a[i]>=d) and (cnt<2) then begin
            inc(cnt);
            Inc(res,a[i]-d);
        end;
    end;
    if (cnt=0) then begin
        if (cntgood = 1) or (cntgood = 0) then res:=a[n]
        else if cntgood = 2 then res:=a[n] + a[n-1] - 2*d
        else res:= res + 2*d;
    end else if cnt=1 then begin
        if (cntgood = 0) then res:=a[n]
        else if cntgood = 1 then res:=a[n]+a[n-1] - 2*d
        else res:= res + 2*d;
    end else begin
        if (cntgood = 0) then res:= a[n] + a[n-1] - 2*d;
    end;
    Writeln(res);
    Close(input); Close(output);
end.
