var n,m,l1,l2,r1,r2,kol1,kol2,kol3,l3,r3: longint;
        second,first,vs,i,j: longint;
begin
        assign(input, 'game.in');
        reset(input);
        readln(n,m);
        readln(l1,r1);
        readln(l2,r2);
        if l1>l2 then l3:=l1
        else l3:=l2;
        if r1<r2 then r3:=r1
        else r3:=r2;
        kol1:=0;
        kol2:=0;
        kol3:=0;
        for i:=1 to l3-1 do begin
                read(vs);
                kol1:=kol1+1;
        end;
        for i:=l3 to r3 do begin
                read(vs);
                kol2:=kol2+1;
        end;
        for i:=(r3+1) to n do begin
                read(vs);
                kol3:=kol3+1;
        end;
        close(input);
        assign(output,'game.out');
        rewrite(output);
        if (l1=l2) and (r1=r2) then begin
                if (kol2 mod 2=0) then write('Draw')
                else  write('Petya');
        end
        else begin
                if l1=l2 then begin
                        if r1<r2 then write('Vasya')
                        else write('Petya');
                end;
                if r1=r2 then begin
                        if l1>l2 then write('Vasya')
                        else write('Petya');
                end;
                if (l1<>l2) and (r1<>r2) then begin
                if kol2>=m then begin
                        if (m mod 2=0) then write('Draw')
                        else write('Petya');
                end
                else begin
                        if (kol2 mod 2=0) then begin
                                if l1<>l3 then first:=kol1
                                else first:=kol3;
                                if l2<>l3 then second:=kol1
                                else second:=kol3;
                                if second>first then write('Vasya');
                                if first>second then write('Petya');
                                if second=first then write('Draw');
                        end
                        else write('Petya');
                end;
                end;

        end;
        close(output);

end.
