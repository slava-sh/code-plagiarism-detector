uses math;
const
   MAX_N=100001;
type
   mas=array[1..MAX_N] of longint;
var
   n,k,i,x,l,r,sum:longint;
   a:mas;
procedure sort(var ar:mas; l,h:longint);
   var i,j,m,wsp:longint;
begin
   i := l;
   j := h;
   m := ar[random(j - i + 1) + i];
   repeat
        while ar[i] < m do inc(i);
        while ar[j] > m do dec(j);
        if i <= j then
                begin
                        wsp := ar[i];
                        ar[i] := ar[j];
                        ar[j] := wsp;
                        inc(i);
                        dec(j);
                end;
   until i > j;
   //write('BLAS');
   if l < j then sort(ar, l, j);
   if i < h then sort(ar, i, h);
end;
   begin
        assign(input, 'fence.in');
        assign(output, 'fence.out');
        reset(input);
        rewrite(output);
        randomize;
      read(n,k);
      for i:=1 to n do
         read(a[i]);
      sort(a,1,n);
      l:=0; r:=min(a[1], k div n) + 1;
      while (r-l)<>1 do
         begin
            x:=(l+r) div 2;
            sum:=0;
            for i:=1 to n do
               sum:=sum+max(a[i]-sum,x);
            if sum<=k then l:=x else r:=x;
         end;
      write(l);
      close(input);
      close(output);
   end.
