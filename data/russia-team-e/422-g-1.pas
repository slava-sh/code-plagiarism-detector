uses math;
  var n , m : longint;

BEGIN

  assign(input , 'prizes.in'); assign(output , 'prizes.out');
  reset(input); rewrite(output);
  readln(n , m);
  if n = 1 then begin writeln((m - 1) div 2); halt; end;
  if m = 1 then begin writeln((n - 1) div 2); halt; end;
  writeln((min(n , m) - 1) div 2);
  close(input); close(output);

END.