uses math;
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

var n, d, i, cnt : longint;
res, cur : longint;
a : tar;
begin
    randseed:=435345;
    Assign(input,'sochi.in'); reset(input);
    Assign(output,'sochi.out'); rewrite(output);
    Readln(n,d);
    for i:=1 to n do Read(a[i]);
    Sort(a,1,n);
    res:=a[n];
    cur:=a[n];
    cnt:=0;
    for i:=n-1 downto 1 do begin
        if cnt=2 then break;
        if a[i] < d then break;
        if a[i] >= 3*d then begin
            cur:=cur + a[i] - 2*d;
        end else begin
            cur:=cur + a[i] - 2*d;
            inc(cnt);
        end;
        res:=max(res,cur);
    end;
    Writeln(res);
    Close(input); Close(output);
end.
