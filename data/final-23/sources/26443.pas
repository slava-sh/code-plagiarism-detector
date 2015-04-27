uses Math;

var

        b, a : array[0..2000001] of int64;
        m, lvl, x, l, r, n, i : longint;

Procedure modify(x, y : longint);
begin
        a[x] := y;
        x := x div 2;
        while x <> 0 do begin
                a[x] := a[2 * x] + a[2 * x + 1];
                x := x div 2;
        end;
end;

Procedure update(x, y : longint);
begin
        b[x] := y;
        x := x div 2;
        while x <> 0 do begin
                b[x] := b[2 * x] + b[2 * x + 1];
                x := x div 2;
        end;
end;

Function FindAns(l, r, a1, b, t : longint) : int64;
begin
        if (l > b) or (r < a1) then begin
                FindAns := 0;
                exit;           
        end;
        if (l >= a1) and (r <= b) then begin
                        FindAns := a[t];
                        exit;
        end;
        Findans := FindAns(l, (l + r) div 2, a1, b, 2 * t) + FindAns((l + r) div 2 + 1, r, a1, b, 2 * t + 1);
end;

Function FindAns1(l, r, a1, b1, t : longint) : int64;
begin
        if (l > b1) or (r < a1) then begin
                FindAns1 := 0;
                exit;           
        end;
        if (l >= a1) and (r <= b1) then begin
                        FindAns1 := b[t];
                        exit;
        end;
        Findans1 := FindAns1(l, (l + r) div 2, a1, b1, 2 * t) + FindAns1((l + r) div 2 + 1, r, a1, b1, 2 * t + 1);
end;

begin
        assign(input,'signchange.in'); reset(input);
        assign(output,'signchange.out'); rewrite(output);
        readln(n);
        lvl := 1;
        while lvl < n do lvl := lvl + lvl;
        for i := 1 to n do begin
                read(x);
                if i mod 2 = 0 then 
                        modify(lvl + i - 1, x)
                else
                        update(lvl + i - 1, x);
        end;
        readln(m);
        for i := 1 to m do begin
                readln(x, l, r);
                if x = 0 then begin
                        if l mod 2 = 0 then 
                                modify(lvl + l - 1, r)
                        else
                                Update(lvl + l - 1, r);
                end
                else begin
                        if l mod 2 = 1 then 
                                writeln(findans1(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1) - findans(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1))
                        else
                                writeln(findans(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1) - findans1(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1));
                end;                        
        end;
        close(output);
end.