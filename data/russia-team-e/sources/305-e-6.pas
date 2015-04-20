program project1;

{$mode objfpc}{$H+}

Var
  st:array[0..1000] of longint;
  kreg:array[0..1000] of longint;
  reg:array[0..1000,0..1000] of longint;
  o,q,r,l,m,g,n,i:longint;
  p,k1,k2,k3,y,u1,u2,u3,t,tel,k:int64;
  ans1,s,ans:string;
begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read (st[i],kreg[i]);
    for g:=1 to kreg[i] do
      read(reg[i,g]);
  end;
  read(m);
  for l:=1 to m do
  begin
    ans:='';
    read(t);
    for i:=1 to n do
    begin
      if (t div 1000000000) mod 10 = 0 then begin  ans:=''; continue; end;
      tel:=t;
      if (tel div 10000000000=st[i]) then
      begin
        tel:=tel mod 10000000000;
        str(st[i],s);
        ans:=ans+'+'+s;
      end
        else
        if (tel div 1000000000=st[i]) then
        begin
          tel:=tel mod 1000000000;
          str(st[i],s);
          ans:=ans+'+'+s;
        end
        else
        if (tel div 100000000=st[i]) then
        begin
          tel:=tel mod 100000000;
          str(st[i],s);
          ans:=ans+'+'+s;
        end
        else begin ans:=''; continue; end;
        ans1:=ans;
        u1:=tel;
        u2:=tel;
        u3:=tel;
        k1:=1;
        k2:=1;
        k3:=1;
        while u1>999 do begin u1:=u1 div 10; k1:=k1*10; end;
        while u2>9999 do begin u2:=u2 div 10; k2:=k2*10; end;
        while u3>99999 do begin u3:=u3 div 10; k3:=k3*10; end;
        for g:=1 to kreg[i] do
        begin
          if u1=reg[i,g] then begin if (tel div (k1 div 10)) mod 10=0 then continue; tel:=tel mod k1; str(u1,s); ans:=ans+'('+s+')'end else
          if u2=reg[i,g] then begin if (tel div (k2 div 10)) mod 10=0 then continue; tel:=tel mod k2; str(u2,s); ans:=ans+'('+s+')'end else
          if u3=reg[i,g] then begin if (tel div (k3 div 10)) mod 10=0 then continue; tel:=tel mod k3; str(u3,s); ans:=ans+'('+s+')'end else
          continue;
        end;
        if ans=ans1 then begin ans:='';  continue; end;
        y:=tel;
        k:=1;
        while y>0 do begin if y<10 then r:=y; y:=y div 10; k:=k*10; end;
        if k=10000000 then
        begin
          str(tel div 10000,s);
          ans:=ans+s+'-';
          str((tel div 100) mod 100,s);
          p:=(tel div 100) mod 100;
          o:=0;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s+'-';
          str(tel mod 100,s);
          o:=0;
          p:=tel mod 100;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s;
        end;

        if k=1000000 then
        begin
          str(tel div 10000,s);
          ans:=ans+s+'-';
          str((tel div 100) mod 100,s);
          o:=0;
          p:=(tel div 100) mod 100;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s+'-';
          str(tel mod 100,s);
          o:=0;
          p:=tel mod 100;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s;
        end;

        if k=100000 then
        begin
          str(tel div 100,s);
          ans:=ans+s+'-';
          str(tel mod 100,s);
          o:=0;
          p:=tel mod 100;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s;
        end;

        if k=10000 then
        begin
          str(tel div 100,s);
          ans:=ans+s+'-';
          str(tel mod 100,s);
          o:=0;
          p:=tel mod 100;
          while p>0 do begin p:=p div 10; o:=o+1; end;
          for q:=1 to (2-o) do ans:=ans+'0';
          ans:=ans+s;
        end;

        if k=1000 then
        begin
          str(tel,s);
          ans:=ans+s;
        end;
    if length(ans)>=16 then break;
    end;
    if ans='' then writeln('Incorrect') else writeln(ans);
  end;
close(input);
close(output);
end.
