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

      for i := 1 to c do begin
        writeln('U');
        flush(output);
        readln(res);
        if (res <> 'N') then halt;
       end;
       writeln('R');
       flush(output);
       inc(c);
     readln(res);
end;
end.