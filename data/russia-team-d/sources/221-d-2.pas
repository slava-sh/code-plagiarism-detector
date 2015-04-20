uses math;
var a:array[1..100000] of longint;
    i,j,k,l,m,n,d:longint;
    sum:int64;
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
    assign(input,'fence.in');
    reset(input);
    assign(output,'fence.out');
    rewrite(output);
    read(n,k);
    for i:=1 to n do
    begin
        read(a[i]);
        inc(sum,a[i]);
    end;
    sort(1,n);
    l:=k-a[1];{
    if a[1] = k
    then begin
         writeln(0);
         halt;
         end;}
    if sum<=k then begin write(a[1]);halt;end;
    d:=k div n;
    d:=min(d,l);
    writeln(min(a[1], d));
end.
