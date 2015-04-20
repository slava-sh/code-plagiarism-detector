program qq; 
  
var
  f,f1 : text; 
  n, a, i, j, count: integer; 
  efgay: array [1..1001, 1..1001] of integer; 
  
begin
  assign(f, 'chess.in'); 
  assign(f1, 'chess.out'); 
  reset(f); 
  rewrite(f1); 
  readln(f,n); 
  for i := 1 to n do 
  begin
    read(f,a); 
    for j := a downto 1 do 
    begin
      efgay[j, i] := 1; 
    end; 
  end; 
  i := 1; 
  j := 1; 
  while efgay[i, j] <> 0 do begin
  count+=1; 
  i+=1; 
  j+=1; 
  end; 
  writeln(f1,count);
  for i:=1 to count do begin
  writeln(f1,i,' ',i); 
  end; 
  close(f);  
  close(f1); 
end.