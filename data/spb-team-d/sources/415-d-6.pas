var
l,r,x,q,s:array [1..1000] of longint;
w,e,d,n,m,i,j:longint;
begin
  {assign(input,'dunes.in');
  assign(output,'dunes.out');
  reset(input);
  rewrite(output);}
  read(n,m);
  for i:=1 to n do begin
    read(l[i],r[i],x[i]);
  end;
  for i:=1 to m do begin
    read(q[i]);
  end;
  for i:=1 to m do begin
    for j:= 1 to m do begin
      if (q[j]<=r[i]) and (q[j]>=l[i]) then begin
        if (q[j]-l[i]) mod 2=0 then s[q[j]]:=s[q[j]]+x[i] else s[q[j]]:=s[q[j]]-x[i];
      end;
    end;
  end;  
  for i:=1 to m do begin
    writeln(s[q[i]]);
  end;  
  
  {close(input);
  close(output);} 
end.
     