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