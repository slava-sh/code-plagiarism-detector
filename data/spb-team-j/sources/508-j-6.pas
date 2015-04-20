Var a: array [1..200000] of longint;
    i, j, minsum, u, sum, n, h: int64;
Begin
  assign(input,'seq.in');
  assign(output,'seq.out');
  reset(input);
  rewrite(output);
  read(n, h);
  for i := 1 to n do read(a[i]);
  sum := 0;
  minsum := 40000000001;
  for i := 1 to n - h + 1 do
  begin
    u := 1;
    for j := 1 to h do 
    begin
      if a[j + i - 1] > j then 
      begin
        sum := 0;
        dec(u);  
        break; 
      end   
      else inc(sum,j-a[j+i-1]);
      
    end;
    if (u=1) and (minsum>sum) then if sum = 0 then 
        begin
          minsum := sum;
          break;
        end
        else minsum := sum;   
    sum := 0;
    dec(u);
  end;
  if minsum <> 40000000001 then writeln(minsum)
                           else writeln(-1);
  close(input);
  close(output);
End.