program problemE;

type arr = array [1..10000] of boolean;

var i, o : text;
    n, m, j, y, l1, r1, l2, r2, sum1, sum2, k : int64;
    b : arr;
    r : array [1..10000] of int64;

begin
     assign(i,'game.in');
     assign(o,'game.out');
     reset(i);
     rewrite(o);
          sum1:=0;
          sum2:=0;
          readln(i, n, m);
          readln(i, l1, r1);
          readln(i, l2, r2);
          for j:=1 to n do
          begin
               read(i, r[j]);
          end;
          for j:=1 to m do
          begin
               if ((j mod 2) = 1) then for y:=1 to n do 
                                        begin
                                        if (not b[y]) then if (r[y] in [l1..r1]) and (r[y] in [l2..r2]) then begin b[y]:=true; inc(sum1); break; end;
                                        if y=n then for k:=1 to n do 
                                                     if (not b[k]) then if r[k] in [l1..r1] then begin b[k]:=true; inc(sum1); break; end;
                                                    
                                       end
                                  else  for y:=1 to n do
                                       begin
                                         if (not b[y]) then if (r[y] in [l1..r1]) and (r[y] in [l2..r2]) then begin b[y]:=true; inc(sum2); break; end;
                                         if y=n then for k:=1 to n do 
                                                     if (not b[k]) then if r[k] in [l2..r2] then begin b[k]:=true; inc(sum2); break; end;
                                                   
                                        end;     
               
          end;
          if sum1>sum2 then writeln(o,'Petya');
          if sum1<sum2 then writeln(o,'Vasya');
          if sum1=sum2 then writeln(o,'Draw');
          close(i);
     close(o);
end.