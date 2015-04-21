var
  prost:array[1..10000] of longint;
  pcou:longint;
  pow:array[1..10000] of longint;

  pn,n,k,i,j:longint;
  ans:longint;

  procedure search(prev,pos,pr,now,res,kn:longint);
  var
   i,j:longint;
  begin
   If (pos=k+1) and (kn=n) and (ans>res) then
   begin
    ans:=res;
   end
   else
   begin
    If pcou>=pr Then
    begin
     If pos<=k Then
     begin
      If (k-pos+1)*prev*kn>=n Then
      begin
       For i:=0 to pow[pr] do
       begin
        If now<=prev Then
        begin
         dec(pow[pr],i);
         search(prev,pos,pr+1,now,res,kn);
         search(now,pos+1,1,1,res*((now+1)div 2),kn*now);
         inc(pow[pr],i);
         now:=now*prost[pr];
        end
        else
        begin
         break;
        end;
       end;
      end;
     end;
    end;
   end;
  end;

begin
 read(n,k);
 pn:=n;
 i:=2;
 While i*i<=n do
 begin
  If n mod i = 0 then
  begin
   inc(pcou);
   prost[pcou]:=i;
  end;
  While n mod i = 0 do
  begin
   n:=n div i;
   inc(pow[pcou]);
  end;
  inc(i);
 end;
 If n<>1 then
 begin
  inc(pcou);
  prost[pcou]:=i;
  pow[pcou]:=1;
 end;
 n:=pn;
 ans:=n;
 search(n,1,1,1,1,1);
 writeln(ans);
 readln;
 readln;
end.
