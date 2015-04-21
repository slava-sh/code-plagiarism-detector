var res:char;
     a:array[0..4] of char;
     i,c:integer;
begin
randomize;
res := 'N';
a[0] := 'U';
a[1] := 'L';
a[2] := 'D';
a[3] := 'R';
c := 0;

while (res = 'N') do begin
      for i := 1 to c do begin
        writeln(a[c mod 4]);
        flush(output);
        readln(res);
        if (res <> 'N') then halt;
       end;
      inc(c);
       end;
end.