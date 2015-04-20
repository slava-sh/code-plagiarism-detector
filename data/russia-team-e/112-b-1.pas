var
  d: array [1..300000] of longint;
  r, n, i, j, k: longint;
  pairs: int64;

begin
 assign(input, 'che.in');
 reset(input);
 assign(output, 'che.out');
 rewrite(output);
 read(n, r);
 for i := 1 to n do
   read(d[i]);
 pairs := 0;
 for i := 1 to n do
   if d[n] - d[i] > r
     then
       begin
         j := i;
         k := n;
         while j < k - 1 do
           if d[(j + k) div 2] - d[i] > r
             then k := (j + k) div 2
             else j := (j + k) div 2;
         pairs := pairs + n - k + 1;
       end;
 writeln(pairs);
end.
