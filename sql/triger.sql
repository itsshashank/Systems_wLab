CREATE TRIGGER TABLEB_UPDATE ON my_emp FOR  UPDATE 
AS 
Begin
UPDATE sal_update
Set 
A.id =  B.id,
A.old_sal =  B.basic_pay,
A.new_sal =  new.B.basic_pay,
FROM my_emp  AS A
JOIN  sal_update  AS B
      ON A.id = B.id

End

create or replace trigger error
before update of sal on plemp
for each row
begin
	if(:old.sal > :new.sal)
	then
		raise_application_error(-2000,'enter larger sal');
	end if;
end;
