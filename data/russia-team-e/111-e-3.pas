var a:array[0..111]of ansistring;
    b:array[0..111,0..1111]of ansistring;
    m:array[0..111]of longint;
    aa,ans,qq,k,n,i,j,w,e:longint;f:boolean;q:ansistring;
Begin
 assign(input,'numbers.in');reset(input);
 assign(output,'numbers.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   readln(aa,m[i]);
   str(aa,a[i]);
   for j:=1 to m[i] do
    readln(b[i,j]);
  end;
 readln(k);
 for i:=1 to k do
  begin
   readln(q);
   for j:=1 to n do
    begin
     f:=true;
     for w:=1 to length(a[j]) do
      if a[j][w]<>q[w] then begin f:=false;break; end;
     if f then
      begin
       for w:=1 to m[j] do
        begin
         f:=true;
         for e:=length(a[j])+1 to length(a[j])+length(b[j,w]) do
          if q[e]<>b[j,w][e-length(a[j])] then begin f:=false;break; end;
         if f then
          begin
           if a[j][1]='0' then begin f:=false;break;end;
           if b[j][w][1]='0' then begin f:=false;break;end;
           if q[length(a[j])+length(b[j,w])+1]='0' then begin f:=false;break; end;
           write('+',a[j],'(',b[j,w],')');
           ans:=length(q)-length(a[j])-length(b[j,w]);
           if ans=3 then
            begin
             for e:=length(a[j])+length(b[j,w])+1 to length(q) do
              write(q[e]);
            end else
           if ans=4 then
            begin
             qq:=0;
             for e:=length(a[j])+length(b[j,w])+1 to length(q) do
              begin
               if qq=2 then write('-');
               write(q[e]);
               inc(qq);
              end;
            end else
           if ans=5 then
            begin
             qq:=0;
             for e:=length(a[j])+length(b[j,w])+1 to length(q) do
              begin
               if qq=3 then write('-');
               write(q[e]);
               inc(qq);
              end;
            end else
           if ans=6 then
            begin
             qq:=0;
             for e:=length(a[j])+length(b[j,w])+1 to length(q) do
              begin
               if (qq mod 2=0)and(qq<>0) then write('-');
               write(q[e]);
               inc(qq);
              end;
            end else
           if ans=7 then
            begin
             qq:=0;
             for e:=length(a[j])+length(b[j,w])+1 to length(q) do
              begin
               if qq=3 then write('-');
               if qq=5 then write('-');
               write(q[e]);
               inc(qq);
              end;
            end;
           writeln;
           break;
          end;
        end;
       if f then break;
      end;
    end;
   if f=false then writeln('Incorrect');
  end;
End.
