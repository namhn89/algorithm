program ideone;
begconst h1: array[1..8] of integer = (1, -1, 0, 0, 1, -1, 1, -1);
      h2: array[1..8] of integer = (0, 0, 1, -1, 1, -1, -1, 1);
 
var a, res: array[0..201, 0..201] of byte;
    m, n: byte;
 
procedure init;
  var i, j: integer;
  begin
       fillchar(res, sizeof(res), 0);
       readln(m, n);
       for i:= 1 to m do
          begin
               for j:= 1 to n do read(a[i, j]);
               readln;
          end;
  end;
 
function count(i, j: byte): byte;
  var tmp, k: byte;
  begin
       tmp:= 0;
       for k:= 1 to 8 do
          if res[i + h1[k], j + h2[k]] = 1 then inc(tmp);
       exit(tmp);
  end;
 
function fill(i, j: byte): boolean;
  var t1, t2: integer;
  begin
       if (i = 1) or (j = 1) then exit(true);
       if (i > m) or (j > n) then exit(true);
       res[i, j]:= 0;
 
       t1:= a[i - 1, j - 1] - count(i - 1, j - 1);
       if t1 < 0 then exit(false);
       if t1 > 1 then exit(false);
 
       {if j = n then
         begin
              t2:= a[i - 1, j] - count(i - 1, j);
              if t2 <> t1 then exit(false);
         end;
 
       if i = m then
         begin
              t2:= a[i, j - 1] - count(i, j - 1);
              if t2 <> t1 then exit(false);
         end;}
 
       res[i, j]:= t1;
       exit(true);
  end;
 
procedure printres;
  var i, j: byte;
  begin
       for i:= 1 to m do
          begin
               for j:= 1 to n do write(res[i, j],' ');
               writeln;
          end;
       halt;
  end;
 
procedure attempt(i: byte);
  var p, q, u: byte;
      ok: boolean;
  begin
       for p:= 0 to 1 do
          for q:= 0 to 1 do
             begin
                  res[i, 1]:= p;
                  res[1, i]:= q;
                  ok:= true;
                  for u:= 1 to i do
                     if (not fill(u, i)) or (not fill(i, u)) then
                       begin
                            ok:= false;
                            break;
                       end;
                  if not ok then continue;
                  if (i >= m) and (i >= n) then printres;
                  attempt(i + 1);
             end;
  end;
 
begin
     init;
     attempt(1);
end.in
	(* your code goes here *)
end.