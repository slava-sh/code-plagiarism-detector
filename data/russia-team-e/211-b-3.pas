var n, h, i, j, l, r, m, x: longint;
a: array [1..300001] of longint;
k: int64;
begin
       assign(input, 'che.in');
        assign(output, 'che.out');
        reset(input);
        rewrite(output);
        readln(n, h);
  //      n := 300000;
   //     h := 1;
        for i := 1 to n do
                read(a[i]);
            //    a[i] := 2 * i - 1;
        k := 0;
        for i := 1 to n do
             //   if a[i] <= h then
                        begin
                                l := i;
                                r := n + 1;
                                while l <> r - 1 do
                                        begin
                                                m := (l + r) div 2;
                                                x := abs(a[i] - a[m]);
                                                if x <= h then
                                                        l := m
                                                        else
                                                r := m;
                                        end;
                                inc(k, n - l);
                        end;
        writeln(k);
close(input);
close(output);
end.
