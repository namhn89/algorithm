const   fi      ='';
        fo      ='';
 
var     f1, f2       :text;
        x       :longint;
        a, b, c :longint;
function get(a, b:longint):longint;
var     tmp     :longint;
begin
        if b = 0 then exit(1);
        if b mod 2 = 0 then exit(sqr(get(a, b div 2)) mod 29 )
        else exit( (sqr(get(a, b div 2))*a) mod 29 );
end;
 
BEGIN
        assign(f1, fi);
        reset(f1);
        assign(f2, fo);
        rewrite(f2);
        while not eof(f1) do
                begin
                        readln(f1, x);
                        if x = 0 then break;
                        a:=(get(2, 2*x + 1) - 1 ) mod 29;
                        b:=(get(3,   x + 1) - 1 ) mod 29;
                        c:=(get(167, x + 1) - 1 ) mod 29;
                        writeln(f2,(a*b*c*9) mod 29);
                end;
        close(f1);
        close(f2);
END.