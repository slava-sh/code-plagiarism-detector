uses math;
type mas=array[0..100000] of longint;
var a,b:mas;
    n,i,k,kol,j,l,s:longint;
    f:boolean;

procedure sort(var a:mas;n:longint);
  var min,max,x,y,i,k,imin,imax:longint;
      f:boolean;
  begin
    x:=1;
    y:=n;
    f:=true;
    while y-x>0 do
    begin
      max:=0;
      min:=100001;
      for i:=x to y do
       begin
         if a[i]>= max then begin
                             max:=a[i];
                             imax:=i;
                           end;
         if a[i]<= min then begin
                             min:=a[i];
                             imin:=i;
                           end;
       end;
      k:=a[x];
      a[x]:=a[imin];
      a[imin]:=k;
      k:=a[y];
      a[y]:=a[imax];
      a[imax]:=k;
      x:=x+1;
      y:=y-1;
    end;
   end;

begin
  assign(input,'fence.in');
  assign(output,'fence.out');
  reset(input);
  rewrite(output);
  readln(n,l);
  for i:=1 to n do
   read(a[i]);
  sort(a,n);
 { for i:=1 to n do
    writeln(a[i]);}
  kol:=min(a[1],l div n);
  for i:=0 to a[n] do
    b[i]:=0;


  for i:=2 to n do
   b[a[i]-a[i-1]]:=b[a[i]-a[i-1]]+1;
  s:=a[n];
  f:=true;
  k:=0;

  while (f) and (k<=kol) do
   begin
    k:=k+1;
    for j:=0 to k-1 do
     begin
      s:=s+(k-j)*b[j];
      b[k]:=b[k]+b[j];
      b[j]:=0;
     end;
    if s>l then f:=false;
   end;
 writeln(k-1);
end.





