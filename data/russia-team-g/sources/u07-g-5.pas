var
 k,n,m,l:int64;
 r,w:text;
begin
  assign(r,'prizes.in'); reset(r);
  assign(w,'prizes.out'); rewrite(w);
  readln(r,n,m);
  k:=m;
  if n<m then k:=n else k:=m;
  dec(k);
  if k>=2 then inc(l);
  k:=k-2;
  l:=l+k div 4;
  writeln(w,l);
  close(r);
  close(w);
end.