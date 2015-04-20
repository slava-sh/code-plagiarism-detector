var
 n,m,l:int64;
 r.w:text;
begin
  assign(r,'prizes.in'); reset(r);
  assign(w,'prizes.out'); rewrtite(w);
  readln(r,n,m);
  dec(m);
  if m>=2 then inc(l);
  m:=m-2;
  l:=l+m div 4;
  writeln(w,l);
  close(r);
  close(w);
end.
