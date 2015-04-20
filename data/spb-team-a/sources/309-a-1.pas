var f1,f2: text;
    i,n,z: longint;
begin

assign(f1, 'abcd.in');
assign(f2, 'abcd.out');

reset(f1);
rewrite(f2);

read(f1,n);

for i:=1 to n do begin
  read(f1,z);
  if (sqr(z div 100)+sqr(z mod 100)) mod 7 = 1 then begin
    writeln(f2,'YES');
  end
  else writeln(f2,'NO');
end;

close(f1);
close(f2);

end. 