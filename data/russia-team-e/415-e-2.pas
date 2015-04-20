var n,m,po:integer;
        posi,kst,kre,i,j,o:longint;
        s,s1,s2,s3,kstr,kreg,nom,l1,prov:string;
    c,k:array[1..100] of integer;
    t:array[1..100,1..1000] of longint;
begin
assign(input,'numbers.in');
reset(input);
assign(output,'numbers.out');
rewrite(output);
readln(n);
for i:=1 to n do begin
        readln(c[i],k[i]);
        for j:=1 to k[i] do read(t[i,j]);
        end;
readln(m);
for i:=1 to m do begin
        kstr:='';
        l1:='';
        nom:='';
        kreg:='';
        s1:='';
        s2:='';
        s3:='';
        kre:=0;
        kst:=-2;
        readln(s);
        prov:=copy(s,1,1);
        if prov='0' then po:=-5;
        o:=0;
        for j:=1 to n do begin
                str(c[j],kstr);
                o:=pos(kstr,s);
                if o=1 then begin
                                      {write('+',kstr);   }
                                      l1:='+'+kstr;
                                      kst:=j;
                                      end;
                if kst<>-2 then break;
                kst:=-2;
                end;
        posi:=length(kstr);
     if (kst<>-2) and (po<>-5) then begin
        for j:=1 to k[kst] do begin
                str(t[kst,j],kreg);
                if pos(kreg,s)=posi+1 then  begin
                prov:=copy(kreg,1,1);
                if prov='0' then po:=-5;
                                      l1:=l1+'('+kreg+')';
                                      {write(l1,'(',kreg,')'); }
                                      kre:=j;
                                      end;
                if kre<>0 then break;
                end;
       posi:=posi+length(kreg);
     if (kre<>0) and (po<>-5) then begin
       nom:=copy(s,posi+1,length(s)-posi);
       prov:=copy(nom,1,1);
       if prov='0' then po:=-5 else write(l1);
       {writeln(nom);}
       if length(nom)=3 then begin
                                prov:=copy(nom,1,1);
                                if prov<>'0' then write(nom);
                                end;
       if length(nom)=4 then begin s1:=copy(nom,1,2);
                                   s2:=copy(nom,3,2);
                                   prov:=copy(s1,1,1);
                                   if (prov<>'0') then write(s1,'-',s2);
                                   end;
       if length(nom)=5 then begin s1:=copy(nom,1,3);
                                   s2:=copy(nom,4,2);
                                   prov:=copy(s1,1,1);
                                   if (prov<>'0') then write(s1,'-',s2);
                                   end;
       if length(nom)=6 then begin s1:=copy(nom,1,2);                                   s3:=copy(nom,5,2);
                                   s2:=copy(nom,3,2);
                                   s3:=copy(nom,5,2);
                                   prov:=copy(s1,1,1);
                                   if (prov<>'0') then write(s1,'-',s2,'-',s3);
                                   end;
      if length(nom)=7 then begin s1:=copy(nom,1,3);
                                   s2:=copy(nom,4,2);
                                   s3:=copy(nom,6,2);
                                   prov:=copy(s1,1,1);
                                   if (prov<>'0') then write(s1,'-',s2,'-',s3);
                                   end;
                end;
              end;
      if (kre=0) or (kst=-2) or (po=-5) then write('Incorrect');
      writeln;
      end;
end.