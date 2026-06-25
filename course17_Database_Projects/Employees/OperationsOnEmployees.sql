
-- problem 51 : get all employees that have managers along with managers name 
--note : we used inner join on the same table  with different alliace

select Employees.Name,Employees.ManagerID,Employees.Salary ,Managers.Name as managerName
		from Employees inner join Employees as Managers on Employees.ManagerID = Managers.ManagerID;



		
-- problem 52 : get all employees that have managers or does not have manager  along with managers name  in case no manager name show null


select Employees.Name,Employees.ManagerID,Employees.Salary ,Managers.Name as ManagerName
		from Employees left join Employees as Managers on Employees.ManagerID = Managers.ManagerID
		
		

