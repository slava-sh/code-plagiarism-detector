program prize;
    
{$APPTYPE CONSOLE}
    
uses
  SysUtils;

var
 k,n,m,l:int64;  
 r,w:text;  
label 1;
begin
  assign(r,'prizes.in'); reset(r);
  assign(w,'prizes.out'); rewrite(w);
  readln(r,n,m);
  l:=1;
  if (n=2) or (m=2) then begin l:=0; goto 1; end else
  if (n=1)then k:=m else
  if (m=1)then k:=n;
  if (m=1)or(n=1) then
  if k mod 4 = 3 then l:=1+k div 4 else l:=k div 4;
  1:writeln(w,l);
  close(r);
  close(w);
end. 
 

