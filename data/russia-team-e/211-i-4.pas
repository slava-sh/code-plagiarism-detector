uses math;
var n, d, max1, max2, i, max3: longint;
a: array [1..100003] of longint;
sum : int64;
fl2, fl1: boolean;
used: array [1..100003] of boolean;
begin
      assign(input, 'sochi.in');
      assign(output, 'sochi.out');
      reset(input);
      rewrite(output);
        readln(n, d);
        for i := 1 to n do
                read(a[i]);
        a[n + 1] := 2 * d;
        a[n + 2] := 2 * d;
        sum := 0;
        for i := 1 to n do
                if a[i] - (3 * d) >= 0 then
                        begin
                                inc(sum, a[i] - (2 * d));
                                used[i] := true;
                        end;
       max1 := 0;
       max2 := 0;
{       fl1 := true;
       fl2 := true;
 }       for i := 1 to n do
                if (a[i] - (d) > 0) and (not used[i]) then
                        if a[i] - (d) > max1 then
                          begin
                        {    if i = n + 1 then fl1 := false;
                            if i = n + 2 then fl2 := false;
                         }   max2 := max1;
                            max1 := a[i];
                          end
                        else
                        if a[i] - d > max2 then
                                begin
                                 max2 := a[i];
                          {       if i = n + 1 then fl1 := false;
                                 if i = n + 2 then fl2 := false;
                           }     end;
      { if (sum <> 0) or (fl1 and fl2) then
        sum := sum + max1 + max2 - 2 * d;
        //writeln(sum, ' ', max1, ' ', max2);
        if sum <= 0 then
                begin
       }         max3 := 0;
                   for i := 1 to n do
                        if a[i] > max3 then
                                max3 := a[i];
        //        end;
        if sum <> 0 then
        writeln(max(sum + 2 * d, max(sum + max1 + max2 - 2 * d, sum + max1)))
       else
       writeln(max(max3, max1 + max2 - 2 * d));
       close(input);
       close(output);
end.
