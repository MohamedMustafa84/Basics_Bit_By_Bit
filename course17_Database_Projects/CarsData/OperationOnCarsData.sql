 
  use VehicleMakesDB;

  select * from VehicleDetails;

  select * from Bodies;

  select * from DriveTypes;

  select * from FuelTypes;

  select * from  Makes;

  select * from MakeModels;

  select * from  SubModels;

  select * from MasterView;

  --problem 1 : get all vehilce made between 1950 and 200
	select * from MasterVeiw where Year between 1950 and 2000;

--problem 2: get number of vehicle made beteen 1950 and 2000

 select count(*)  as NumberOfVehicles from MasterVeiw where  Year between 1950 and 2000;



 --problem 3: get number of vehicle made beteen 1950 and 2000 per make and order them by number of vehicles Descending

 select  Makes.Make ,count(*)  as NumberOfVehicles
	from MasterVeiw inner join Makes on Makes.MakeID = MasterVeiw.MakeID
	where ( Year between 1950 and 2000 )
	GROUP BY Makes.Make 
	order by NumberOfVehicles Desc;

	
	select Bodies.BodyName ,count (*) as NumberOFCarsBodies  
		from VehicleDetails inner join Bodies on VehicleDetails.BodyID =Bodies.BodyID

		group by Bodies.BodyName

		order BY NumberOFCarsBodies desc;


	-- problem 5 : get all makes that have manufactured more than 1200 vehicle in the years 1950 to 2000

	select  Makes.Make ,count(*)  as NumberOfVehicles
	from MasterVeiw inner join Makes on Makes.MakeID = MasterVeiw.MakeID
	where ( Year between 1950 and 2000 )
	GROUP BY Makes.Make 
	having count(*) >12000
	order by NumberOfVehicles Desc;
	
	

	-- solve  problem 5 without using Having 
	--Note : we use having on the result  and where on the data
			-- so we need to convert the resul to data we can do that by convert it to subquery as following

	select * from (
		select  Makes.Make ,count(*)  as NumberOfVehicles
		from MasterVeiw inner join Makes on Makes.MakeID = MasterVeiw.MakeID
		where ( Year between 1950 and 2000 )
		GROUP BY Makes.Make 
		--order by NumberOfVehicles Desc; we cannot use order by in the subquerey
	)R1 
	where  NumberOfVehicles>12000;
		


	-- Probelm 6:  get number of vehicles made between 1950 and 2000 per make and add Total Vehicle Column Beside
	
	-- note  you can add full query as Column

		select  Makes.Make ,count(*)  as NumberOfVehicles , (select count(*) from MasterVeiw) as TotalVehicles
		from MasterVeiw inner join Makes on Makes.MakeID = MasterVeiw.MakeID
		where ( Year between 1950 and 2000 )
		GROUP BY Makes.Make 
		order by NumberOfVehicles Desc 


		-- Probelm 7:  get number of vehicles made between 1950 and 2000 per make and add Total Vehicle Column Beside then Calculate the Persentage



		select * , CAST(NumberOfVehicles as float ) / CAST(TotalVehicles as float ) as perc from 
		(

			select  Makes.Make ,count(*)  as NumberOfVehicles , (select count(*) from MasterVeiw) as TotalVehicles
			from MasterVeiw inner join Makes on Makes.MakeID = MasterVeiw.MakeID
			where ( Year between 1950 and 2000 )
			GROUP BY Makes.Make 
		)R1
		order by NumberOfVehicles Desc;


		--  problem 8 :Get make , FuelTypeName  and Number of Vehicle per FueltypeName Per make

			select Makes.Make, FuelTypes.FuelTypeName ,count(*) NumberOFVehicle
			 from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
			 inner join  FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
			 where VehicleDetails.Year between 1950 and 2000
			 Group by Makes.Make,FuelTypes.FuelTypeName
			  order by Makes.Make;
			  
		--peoblem 9 : get all Vehicle that runs with GAS
		select VehicleDetails.* ,FuelTypes.FuelTypeName 
		from VehicleDetails
		inner join  FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
		where FuelTypes.FuelTypeName =N'GAS'; --we use N for the uniode



		
			  
		--peoblem 10 : get all Makes that runs with GAS
		select  distinct Makes.Make,FuelTypes.FuelTypeName
		from VehicleDetails
		inner join Makes on VehicleDetails.MakeID =Makes.MakeID
		inner join  FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
		where FuelTypes.FuelTypeName =N'GAS';


		--peoblem 11 : get Total Vehicle that runs with GAS
		
		
		select count(*)  AS TotalVehicleRunsOnGAS from
		(
			select  distinct Makes.Make,FuelTypes.FuelTypeName
		from VehicleDetails
		inner join Makes on VehicleDetails.MakeID =Makes.MakeID
		inner join  FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
		where FuelTypes.FuelTypeName =N'GAS'
		)R1;


		--peoblem 12 : count vehicle by makes and order them by  number of vehicles  frim high to low

		select Makes.Make,count(*) as NumberofVehicles
			 from VehicleDetails 
			 inner join Makes on VehicleDetails.MakeID = Makes.MakeID
			 
			 group by Makes.Make
			 Order by NumberofVehicles desc;



			 --peoblem 13 : Get all makes count of vehicles that manufactures more than 20k vehicles
		
		-- Sloution1
		select * from
		(

			select Makes.Make,count(*) as NumberofVehicles
				 from VehicleDetails 
				 inner join Makes on VehicleDetails.MakeID = Makes.MakeID
				 group by Makes.Make
		)R1
			  where NumberofVehicles > 20000
			Order by NumberofVehicles Desc;

		-- Sloution2
			
			select Makes.Make,count(*) as NumberofVehicles
			 from VehicleDetails 
			 inner join Makes on VehicleDetails.MakeID = Makes.MakeID
			 
			 group by Makes.Make
			 having Count(*) >20000
			 Order by NumberofVehicles desc;




			 --problem 14 : get all makes with makes that start with 'B'


			 Select Make from Makes 
				where Make like 'B%';

			 --problem 15: get all makes with makes that End with 'W'
				select Make from Makes
				where  Make like '%W';
		

		--problem 16: get all makes that manufactures  DriveTypeName =FWD

		select Makes.Make ,DriveTypes.DriveTypeName 
		from VehicleDetails 
				inner join Makes on VehicleDetails.MakeID =Makes.MakeID
				inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

		where DriveTypes.DriveTypeName ='FWD'
		Group by Makes.Make ,DriveTypes.DriveTypeName
		Order by Makes.Make ;


		--problem 17: get total makes that manufactures  DriveTypeName =FWD


	
			
			select count(*) as MakewithFWD
			 from 
			 (
					select Makes.Make ,DriveTypes.DriveTypeName 
				from VehicleDetails 
						inner join Makes on VehicleDetails.MakeID =Makes.MakeID
						inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

				where DriveTypes.DriveTypeName ='FWD'
				Group by Makes.Make ,DriveTypes.DriveTypeName
		
			)R1;


			
				




