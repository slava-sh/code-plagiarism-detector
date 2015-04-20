var n, h, k, i, j, t, p, sum, max, f, answer, d:longint;
a, b, c: array [1..200001] of integer;
f1, f2: text;
begin
assign(f1, 'seq.in');
assign(f2, 'seq.out');
reset(f1);
rewrite(f2);
readln(f1, n, h);
k:=1;
for i:=  1 to n do begin
                   read(f1, a[i]);
                   if ((a[i] = 1) and (i+h-1<=n))
                                 then begin
                                      b[k]:=i;
                                      inc(k);
                                      end
                    else if ((a[i] = 0) and (i+h-1<=n))
                                       then begin
                                            inc(f);
                                            c[f]:=i;
                                            end;
                   end;
dec(k);
for i:= 1 to k do begin
                  sum := 0;
                  for j:= b[i]+1 to b[i]+h-1 do begin
                                              if (a[j] > j-b[i]+1) then begin
                                                                        inc(t);
                                                                        break;
                                                                        end;
                                              sum := sum+a[j];
                                              end;
                  if (max < sum) then begin
                                      max := sum;
                                      end;
                  end;
p:=(1+h)*h div 2;
answer := p-1-max;
max:=0;
for i:= 1 to f do begin
                  sum := 0;
                  for j:= c[i]+1 to c[i]+h-1 do begin
                                              if (a[j] > j-c[i]+1) then begin
                                                                        inc(d);
                                                                        break;
                                                                        end;
                                              sum := sum+a[j];
                                              end;
                  if (max < sum) then begin
                                      max := sum;
                                      end;
                 end;
p:=(1+h)*h div 2;                 
if (answer > p-max) then answer := p-max;                                      
                                      


if ((t=k) and (d=k)) then 
              begin
              writeln(f2, -1);
              halt;
              end;
writeln(f2, answer);
close(f1);
close(f2);
end. 