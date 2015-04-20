uses math;
var a:array[1..100000] of longint;
    i,j,k,l,m,n,d:longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
    assign(input,'sochi.in');
    reset(input);
    assign(output,'sochi.out');
    rewrite(output);
    read(n,d);
    for i:=1 to n do
        read(a[i]);
    sort(1,n);
    if n=1 then begin write(a[1]);halt;end;
    if n=2 then begin write(max(a[2],a[1]+a[2]-2*d));halt;end;
    k:=max(a[n],a[n]+a[n-1]-2*d);
    for i:=n-2 downto 1 do
    begin
        if a[i]-2*d >0 then inc(k,a[i]-2*d);
    end;
    write(k);

end.