uses math;
  var n , m : longint;

BEGIN

  assign(input , 'prizes.in'); assign(output , 'prizes.out');
  reset(input); rewrite(output);
  readln(n , m);
  dec(n); dec(m);
  if (n <= 1) and (m <= 1) then begin writeln(0); halt; end;
  if n = 0 then begin
     if m < 2 then begin writeln(0); halt; end
       else begin writeln((m - 2) div 4 + 1); halt;  end;
  end;
  if m = 0 then begin
    if n < 2 then begin writeln(0); halt; end
      else begin writeln((n - 2) div 4 + 1); halt; end;
  end;

  if (n = 1) or (m = 1) then begin writeln(0); halt; end;

  writeln((min(n , m) - 2) div 4 + 1);
  close(input); close(output);

END.
