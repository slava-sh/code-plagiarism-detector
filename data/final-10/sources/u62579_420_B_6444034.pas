const
        finp = '';
        fout = '';
        maxN = 100010;
type    meeting = record
                check, val : longint;
                end;
var     f, g : text;
        bool, info : array [0 .. maxN] of longint;
        id : array [0 .. maxN] of meeting;
        n, m, code, res, i, count, checkin, fi, t, onl : longint;
        s : string;
begin
        assign(f, finp); reset(f);
        assign(g, fout); rewrite(g);
        readln(f, m, n); bool[0] := m; checkin := 0;
        for i := 1 to m do bool[i] := 1;
        for i := 1 to n do
                begin
                        readln(f, s);
                        if s[1] = '+' then id[i].check := 1;
                        delete(s, 1, 2);
                        val(s, id[i].val, code);
                        if info[id[i].val] = 0 then
                                begin
                                        info[id[i].val] := 1;
                                        if id[i].check = 0 then
                                                count := count + 1
                                        else
                                                if checkin = 0 then
                                                        begin
                                                                checkin := 1;
                                                                fi := id[i].val;
                                                        end
                                                else
                                                        bool[id[i].val] := 0;
                                end;
                end;
        t := count;
        for i := 1 to n do
                if id[i].check = 1 then
                        begin
                                if count > 0 then bool[id[i].val] := 0;
                                count := count + 1;
                        end
                else
                        begin
                                if count - 1 > 0 then bool[id[i].val] := 0;
                                count := count - 1;
                        end;
        count := t;
        for i := 1 to n do
                begin
                        if (onl = 0) and (count > 0) then bool[fi] := 0;
                        if id[i].val = fi then onl := 1 - onl;
                        if id[i].check = 1 then count := count + 1
                        else count := count - 1;
                end;
        for i := 1 to n - 1 do
                if id[i].check = 0 then
                        if id[i].val <> id[i + 1].val then
                                bool[id[i].val] := 0;
        for i := 1 to m do
                res := res + bool[i];
        writeln(g, res);
        for i := 1 to m do
                if bool[i] = 1 then write(g, i, ' ');
        close(f); close(g);
end.
