program E;
var
  n, m, l1, r1, l2, r2, i, both, p, v, pr, vr, x, y: cardinal;
  z: array [1..100000] of cardinal;
  f1,f2:text;
begin
  assign(f1, 'game.in');
  assign(f2, 'game.out');
  reset(f1);
  readln(f1,n,m);
  readln(f1,l1,r1);
  readln(f1,l2,r2);
  for i:=1 to n do begin
    read(f1,z[i]);
  end;
  close(f1);
  for i:=1 to n do begin
    if (z[i]>=l1) and (z[i]<=r1) and (z[i]>=l2) and (z[i]<=r2) then begin
      both+=1;
    end
    else
      if (z[i]>=l1) and (z[i]<=r1) then p+=1 else if (z[i]>=l2) and (z[i]<=r2) then v+=1;
  end;
  pr:=ceil(both/2); {+min(p,ceil(m/2)-ceil(both/2))}
  vr:=floor(both/2);{+min(v,floor(m/2)-floor(both/2))}
  x:=ceil(m/2)-ceil(both/2);
  y:=floor(m/2)-floor(both/2);
  pr+=min(p,x);
  vr+=min(v,y);
  i:=sign(pr-vr);
  rewrite(f2);
  case i of
    1: write(f2,'Petya');
    0: write(f2,'Draw');
    -1: write(f2,'Vasya');
  end;
  close(f2);
end.