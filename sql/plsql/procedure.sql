//PROCEDURE run as EXECUTE greetings
CREATE OR REPLACE PROCEDURE greetings 
AS 
BEGIN 
   dbms_output.put_line('Welcome to plsql'); 
END; 
/
//PROCEDURE to display
DECLARE
      dno plemp.dno%type;
      PROCEDURE display(xdno number)
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere dno = xdno)
       LOop
            dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
      end;
BEGIN
      dno :=&dno;
      display(dno);
END;
/
//indepenent procedures
create or replace PROCEDURE display(xdno number)
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere dno = xdno)
       LOop
            dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
end;
/