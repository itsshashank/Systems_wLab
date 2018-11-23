//packages
CREATE OR REPLACE PACKAGE BODY c_package AS 
      FUNCTION dissal(xid number)RETURN number
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere id = xid)
       LOop
            dbms_output.put_line('NAME ' || 'sal ');
            dbms_output.put_line( aRow.name ||' '|| aRow.sal);
            RETURN aRow.sal;
       end loop;
      end dissal;
      PROCEDURE display(xdno number)
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere dno = xdno)
       LOop
            dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
      end display;
end c_package;
/

create or replace package c_package AS

end package;
/
CREATE PACKAGE emp_stuff AS
   CURSOR c1 RETURN plemp%ROWTYPE;  -- declare cursor spec
END emp_stuff;
/
CREATE PACKAGE BODY emp_stuff AS
   CURSOR c1 RETURN plemp%ROWTYPE IS
      SELECT * FROM plemp WHERE sal > 2500;  -- define cursor body
END emp_stuff;
/

DECLARE   emp_rec plemp%ROWTYPE;BEGIN
   OPEN emp_stuff.c1;
   LOOP
      FETCH emp_stuff.c1 INTO emp_rec;
-- do processing here ...
      dbms_output.put_line(emp_rec.name||' '||emp_rec.sal);
      EXIT WHEN emp_stuff.c1%NOTFOUND;
   END LOOP;
   CLOSE emp_stuff.c1;
END;
/
//finally package 
create or replace package my_pac AS
      function dissal(xid number)RETURN NUMber;
      PROCEDURE display(xdno number);
end my_pac;
/
CREATE or replace PACKAGE body my_pac AS
      FUNCTION dissal(xid number)RETURN number
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere id = xid)
       LOop
            dbms_output.put_line('NAME ' || 'sal ');
            dbms_output.put_line( aRow.name ||' '|| aRow.sal);
            RETURN aRow.sal;
       end loop;
      end dissal;
      PROCEDURE display(xdno number)
      is
      BEGIN
       dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere did = xdno)
       LOop
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
      end;
end my_pac;
/
declare 
      id number;
      sal number;
      dno number;
BEGIN
      id := &id;
      sal:=my_pac.dissal(id);
      dno := &dno;
      my_pac.display(dno);
end;
/