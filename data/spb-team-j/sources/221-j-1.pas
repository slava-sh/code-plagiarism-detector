var
  mas:array[1..200000] of integer;
  n, h, max, count, i, j, d:integer;
  f1:text;
begin
  max:=-1;
  assign(f1,'seq.in');
  reset(f1);
  readln(f1, n, h);
  for i:=1 to n do 
    read(f1, mas[i]);
 close(f1);
 for i:=1 to n do
    if(mas[i]<=1) then begin
     count:=0;
     d:=1;
     j:=i;
      while(j<=h) do begin
       if(mas[j]<=d) then count:=count+d-mas[i]
       else begin count:=-1; break; end;
       j:=j+1;
       d:=d+1;
      end;
      if(count>=max) then max:=count; 
    end;
 assign(f1,'seq.out');
 rewrite(f1);
 writeln(f1, max);
 close(f1);
 end.