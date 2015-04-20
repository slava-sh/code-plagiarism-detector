var i, j, n, m, w:int64;
l, r, x, q: array [1..1010] of int64;
f1,f2:text;
begin
assign(f1, 'dunes.in');
assign(f2, 'dunes.out');
reset(f1);
rewrite(f2);
readln(f1, n, m);
for i:= 1 to n do readln(f1, l[i], r[i], x[i]);
for i:= 1 to m do begin
                  readln(f1, q[i]);
                  end;
for i:= 1 to m do begin
                  w:=0;
                  for j:= 1 to n do begin 
                                    if ((q[i]>=l[j]) and (q[i]<=r[j])) then
                                        begin
                                        if (q[i] mod 2 = l[j] mod 2) then w:=w+x[j]
                                         else w:=w-x[j];
                                        end;
                                    end;
                  writeln(f2, w);
                  end;
close(f1);
close(f2);
end.
                  