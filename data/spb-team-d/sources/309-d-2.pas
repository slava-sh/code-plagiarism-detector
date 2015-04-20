var f1,f2   : text;
    i,j,n,l,m,r,x,t   : longint;
    q       : array[1..1000] of int64;

begin

assign(f1, 'dunes.in');
assign(f2, 'dunes.out');

reset(f1);
rewrite(f2);

read(f1,n,m);

for i:=1 to n do begin
  read(f1,l,r,x);
  if (l div 2)=(l/2) then begin
    for j:=l to r do begin
      if (j/2)=(j div 2) then 
      begin
      q[j]:=q[j]+x;
      end
      else q[j]:=q[j]-x;
    end;
  end;  
  
  if (l div 2)<>(l/2) then begin
    for j:=l to r do begin
      if (j/2)=(j div 2) then 
      begin
      q[j]:=q[j]-x;
      end
      else q[j]:=q[j]+x;
    end;
  end;   
end; 

for i:=1 to m do begin
  read(f1,t);
  writeln(f2,q[t]);
end;
 
close(f1);
close(f2);
 
end.

