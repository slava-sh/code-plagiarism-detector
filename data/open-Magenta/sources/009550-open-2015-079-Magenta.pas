var res:char;
     a:array[0..4] of char;
     i,c:integer;
begin
randomize;
res := 'N';
a[0] := 'R';
a[1] := 'L';
a[2] := 'D';
a[3] := 'U';
c := 1;

while (res = 'N') do begin

      for i := 1 to 59 do begin
        writeln('D');
        flush(output);
        readln(res);
        if (res <> 'N') then halt;
       end;

      for i := 1 to 37 do begin
        writeln('L');
        flush(output);
        readln(res);
        if (res <> 'N') then halt;
       end;

       end;
end.