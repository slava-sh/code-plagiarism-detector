Uses MAth;
var n, m, l: longint;


begin
    assign(input, 'prizes.in');
    reset(input);
    assign(output, 'prizes.out');
    rewrite(output);
    readln(n, m);
    if (n = 2) or (m = 2)
    then begin
         writeln(0);
         halt;
         end;
 {   if (n = 1)  or (m = 1)
    then begin
         if n = 1
         then begin
              k : = (m + 1) div 4;
              end
         else if m = 1
              then begin
                   k := (n + 1) div 4;
                   end;
         writeln(k);
         halt;
         end;
    l := max(n, m);
    for i := 2 to l do
        begin
        if i = p
        then begin
             inc(k);
             p := p + 4;
             end;
        end;}
    l := max(n, m);
    writeln((l + 1) div 4);

end.