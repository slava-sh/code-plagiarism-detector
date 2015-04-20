var n,d,i,a,s:longint;
 begin
    
    assign(input,'sochi.in'); reset(input);
    assign(output,'sochi.out'); rewrite(output);
    read(n,d);
     for i:=1 to n do begin 
      read(a);
        if (i<>1) and (i<>n) then
         s:=s+a-2*d else
         s:=s+a - d;
         end;
         write(s);
    close(input);
    close(output);
 end.
