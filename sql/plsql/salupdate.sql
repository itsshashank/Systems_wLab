CREATE OR REPLACE TRIGGER display_salary_changes 
BEFORE UPDATE ON emp1 
FOR EACH ROW 
BEGIN 
   insert into auditrial values (:old.id,:old.bs,:new.bs,sysdate);
END; 
/ 