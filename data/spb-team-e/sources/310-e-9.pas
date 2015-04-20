program problemE;

type
     arr = array [1..10000] of boolean;

var
     i, o: text;
     n, m, j, y, l1, r1, l2, r2, sum1, sum2, k: int64;
     b: arr;
     r: array [1..10000] of int64;
     a1, a2, b1, b2: boolean;

begin
     assign(i, 'game.in');
     assign(o, 'game.out');
     reset(i);
     rewrite(o);
     a1 := true; a2 := true; b1 := true; b2 := true; 
     sum1 := 0;
     sum2 := 0;
     readln(i, n, m);
     readln(i, l1, r1);
     readln(i, l2, r2);
     for j := 1 to n do
     begin
          read(i, r[j]);
     end;
     for j := 1 to m do
     begin
          if ((j mod 2) = 1) then  
          begin
               if b1 then for y := 1 to n do if (not b[y]) and (r[y] in [l1..r1]) and (r[y] in [l2..r2]) then begin b[y] := true; inc(sum1); a1 := false; break; end;
               if a1 then  begin b1 := false;
                    for k := 1 to n do
                         if (not b[k]) then if r[k] in [l1..r1] then begin b[k] := true; inc(sum1); break; end;
                    
               end;
               a1 := true;
          end
          else 
          begin
               if b2 then for y := 1 to n do if (not b[y]) and (r[y] in [l1..r1]) and (r[y] in [l2..r2]) then begin b[y] := true; inc(sum2); a2 := false; break; end;
               if a2 then  begin b2 := false;
                    for k := 1 to n do
                         if (not b[k]) then if r[k] in [l2..r2] then begin b[k] := true; inc(sum2); break; end;  
                    
               end;
               a2 := true; 
          end;     
          
     end;
     if sum1 > sum2 then writeln(o, 'Petya');
     if sum1 < sum2 then writeln(o, 'Vasya');
     if sum1 = sum2 then writeln(o, 'Draw');
     close(i);
     close(o);
end.