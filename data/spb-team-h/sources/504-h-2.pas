type fio= record
        s1,s2,s3: string[20];
end;
var n,k: integer;
simv: char;
change1,change2,change3,dop,dop2,v1,v2: string[20];
i,j: integer;
pr: boolean;
name: array[1..1000] of fio;
        begin
                assign(input,'names.in');
                reset(input);
                readln(n);
                k:=0;
                for i:=1 to n do begin
                        k:=k+1;
                        name[k].s1:='';
                        name[k].s2:='';
                        name[k].s3:='';
                        repeat
                                read(simv);
                                if simv<>' ' then
                                        name[k].s1:=name[k].s1+simv;
                        until simv=' ';
                        v1:=name[k].s1;
                        repeat
                                read(simv);
                                if simv<>' ' then
                                        name[k].s2:=name[k].s2+simv;
                        until simv=' ';
                        readln(name[k].s3);
                        v2:=name[k].s2;
                        if k>1 then begin
                        pr:=false;
                                for j:=1 to k-1 do begin
                                        if (name[j].s1=v1) and (pr=false) then begin
                                                dop:=name[j].s1;
                                                dop2:=name[j].s2;
                                                name[j].s1:=name[j].s3;
                                                name[j].s2:=dop;
                                                name[j].s3:=dop2;
                                                dop:=name[k].s1;
                                                dop2:=name[k].s2;
                                                name[k].s1:=name[k].s3;
                                                name[k].s2:=dop;
                                                name[k].s3:=dop2;
                                                pr:=true;
                                        end;
                                        if (name[j].s2=v1) and (pr=false) then begin
                                                dop:=name[k].s1;
                                                dop2:=name[k].s2;
                                                name[k].s1:=name[k].s3;
                                                name[k].s2:=dop;
                                                name[k].s3:=dop2;
                                                pr:=true;
                                        end;
                                        if (name[j].s1=v2) and (pr=false) then begin
                                                dop:=name[j].s1;
                                                dop2:=name[j].s2;
                                                name[j].s1:=name[j].s3;
                                                name[j].s2:=dop;
                                                name[j].s3:=dop2;
                                                pr:=true;
                                        end;
                                end;
                        end;
                end;
                close(input);

                assign(output,'names.out');
                rewrite(output);
                for j:=1 to n-1 do
                        for i:=1 to n-j do begin
                                if name[i].s1>name[i+1].s1 then begin
                                        change1:=name[i].s1;
                                        change2:=name[i].s2;
                                        change3:=name[i].s3;
                                        name[i].s1:=name[i+1].s1;
                                        name[i].s2:=name[i+1].s2;
                                        name[i].s3:=name[i+1].s3;
                                        name[i+1].s1:=change1;
                                        name[i+1].s2:=change2;
                                        name[i+1].s3:=change3;
                                end;
                        end;
                for i:=1 to n do begin
                        write(name[i].s1,' ',name[i].s2,' ',name[i].s3);
                        writeln;
                end;
                close(output);
        end.


