var
 k,n,m,l:int64;
 r,w:text;
label 1;
begin
  assign(r,'prizes.in'); reset(r);
  assign(w,'prizes.out'); rewrite(w);
  readln(r,n,m);
  if (n=2) or (m=2) then begin l:=0; goto 1; end else
  if (n=1)then k:=m else
  if (m=1)then k:=n else
  if n>m then k:=m else k:=n;
  if k>=3 then l:=1;
  k:=k-3;
  l:=l+trunc(k/4);
  1:writeln(w,l);
  close(r);
  close(w);
end.
