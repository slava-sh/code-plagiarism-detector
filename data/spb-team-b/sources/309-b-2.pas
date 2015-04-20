var f1,f2   : text;
    a,i,z,s : longint;


begin

assign(f1, 'chess.in');
assign(f2, 'chess.out');

reset(f1);
rewrite(f2);

read(f1,a);

 for i:=1 to a do begin
    read(f1,z);
    if z<i then begin      
      break;
    end
    else s:=i;    
 end;
 
 
writeln(f2,s);
 for i:=1 to s do begin
  writeln(f2,i, ' ',i);  
 end;
 
 close(f1);
 close(f2);
 
end.