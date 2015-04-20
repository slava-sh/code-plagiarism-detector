var i, j, k, l, r1, x, m, n, r: longint;
a: array [1..300001] of longint;
begin
        assign(input, 'che.in');
        assign(output, 'che.out');
        reset(input);
        rewrite(output);
        readln(n, r);
        for i := 1 to n do
          read(a[i]);
        k := 0;
        for i := 1 to n do
        begin
            l := i;
            r1 := n + 1;
            while r1 <> l + 1 do
                begin
                m := (r1 + l) div 2;
                x := abs(a[i] - a[m]);
                if x <= r then
                        l:= m
                else
                        r1 := m;
                end;
           // writeln(r1);
            inc(k, n - l);

         // end;
        end;

 writeln(k);
 close(input);
 close(output);
end.
