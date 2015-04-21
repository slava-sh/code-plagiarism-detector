var
  pcou:longint;
  prost:array[1..100] of longint;
  pow:array[1..100] of longint;
  i,j:longint;
  n,pn,k:longint;
  ans:longint;

 procedure gen_ans(px,nx,kn,res,pos,ppos:longint);
 var
   i:longint;
 begin
  If (kn=n) then
  begin
   If res<=ans then ans:=res;
  end
  else
  begin
   If pos<=k Then
   begin
    If ppos<=pcou Then
    begin
     For i:=0 to pow[ppos] do
     begin
      If nx<=px Then
      begin
       dec(pow[ppos],i);
       gen_ans(px,nx,kn,res,pos,ppos+1);
       inc(pow[ppos],i);
       nx:=nx*prost[ppos];
      end
      else
      begin
       break;
      end;
     end;
    end
    else
    begin
     gen_ans(nx,1,kn*nx,res*((nx+1) div 2), pos+1,1);
    end;
   end;
  end;
 end;

begin
 read(n,k);
 i:=2;
 j:=n;
 While i*i <=j do
 begin
  if j mod i = 0 then
  begin
   inc(pcou);
   prost[pcou]:=i;
  end;
  While j mod i = 0 do
  begin
   j:=j div i;
   inc(pow[pcou]);
  end;
  inc(i);
 end;
 If j<>1 then
 begin
  inc(pcou);
  inc(pow[pcou]);
  prost[pcou]:=j;
 end;
 ans:=n;
 gen_ans(n,1,1,1,1,1);
 writeln(ans);
 readln;
 readln;
end.
