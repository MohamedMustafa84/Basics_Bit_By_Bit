 
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


			--problem 18: get total vehicles per DriveTypeName Per Make And Order Them Per Make asc then Per Total Dec

				--sloution one 
				select  distinct Makes.Make ,DriveTypes.DriveTypeName ,Count(*) TotalVehicles
				from VehicleDetails 
						inner join Makes on VehicleDetails.MakeID =Makes.MakeID
						inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

				Group by Makes.Make ,DriveTypes.DriveTypeName
				Order by Makes.Make Asc ,TotalVehicles desc;


			--problem 19: get total vehicles per DriveTypeName Per Make And Order Them Per Make asc then Per Total Dec then filter only result  with total > 10000
				select  distinct Makes.Make ,DriveTypes.DriveTypeName ,Count(*) TotalVehicles
				from VehicleDetails 
						inner join Makes on VehicleDetails.MakeID =Makes.MakeID
						inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

				Group by Makes.Make ,DriveTypes.DriveTypeName
					having count(*) >10000
				Order by Makes.Make Asc ,TotalVehicles desc;

				
				--sloution two

				select * from 
				(
					select  distinct Makes.Make ,DriveTypes.DriveTypeName ,Count(*) TotalVehicles
				from VehicleDetails 
						inner join Makes on VehicleDetails.MakeID =Makes.MakeID
						inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

				Group by Makes.Make ,DriveTypes.DriveTypeName
				
				)R1 where TotalVehicles >10000;


				-- problem 20 : get all vehicles that number of doors is not specified
					
					select  * from VehicleDetails where NumDoors is null;
					


				-- problem 21 : get Total  vehicles that number of doors is not specified

				select  count(*) TotalWithNoSpecifiedDoorsNum from VehicleDetails where NumDoors is null;





				-- problem 22 : get Percentage of  vehicles that number of doors is not specified

				 
				 select  (
							cast ((select count(*) as TotalWithNoSpecifiedDoors from VehicleDetails where NumDoors is null) as float )
							/
							cast ((select count(*) as TotalVehicle from VehicleDetails)as float )
						) as PerOfNoSpecifiedDoors;
				 select count(*) TotalVehicle from VehicleDetails;



				 
			-- problem 23 : Get makeID ,Make  and submodelName for all vehicle that have submodelName 'Elite'


			select distinct  Makes.MakeID ,Makes.Make ,SubModels.SubModelName

			from VehicleDetails 
								inner join Makes on VehicleDetails.MakeID = Makes.MakeID
								inner join SubModels on VehicleDetails.SubModelID = SubModels.SubModelID

			where  SubModels.SubModelName ='Elite'
			group by Makes.MakeID, Makes.Make ,SubModels.SubModelName ;


			--problem 24 : get all vehicle that have Engines >3  liters and have only 2 doors

			select * from VehicleDetails
				where Engine_Liter_Display >3 and NumDoors =2;


			--probelm 25 : get make and vehicles that  the Engins  contains 'OHV' and have Cylinders =4

			select  Makes.Make , VehicleDetails.*
				from VehicleDetails 
								inner join Makes on VehicleDetails.MakeID =Makes.MakeID

				Where VehicleDetails.Engine like '%OHV%' and (VehicleDetails.Engine_Cylinders=4);


			--problem 26 : get all vehicle that their body  is sport Utility and year  > 2020
				
				select Bodies.BodyName ,VehicleDetails.*
					 from VehicleDetails
									inner join Bodies on VehicleDetails.BodyID = Bodies.BodyID
					 where Bodies.BodyName ='Sport Utility' and VehicleDetails.Year >2020;


			--problem 27 : get all vehicle that their body is 'Coupe' or 'Hatchback' or 'Sedan'
					
					select Bodies.BodyName ,VehicleDetails.*
					 from VehicleDetails
									inner join Bodies on VehicleDetails.BodyID = Bodies.BodyID
					 where Bodies.BodyName  in ('Coupe' ,'Hatchback' ,'Sedan');

			--problem 28: get all vehicle that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactures in year 2008 or 2020 or 2021

				select Bodies.BodyName ,VehicleDetails.*
					 from VehicleDetails
									inner join Bodies on VehicleDetails.BodyID = Bodies.BodyID
					 where (Bodies.BodyName  in ('Coupe' ,'Hatchback' ,'Sedan')) and (VehicleDetails.Year in (2008 ,2020,2022));

			
			
			--problem 29 : return found =1 if there is any vehicle made in year 1950

			select found =1
				where  
					exists(
								select top 1 * from vehicleDetails where Year =1950
							)


			--problem 30 : get all vehicle display name  num doors and add extra column  to describe number of dors by words and if door is null display not set 

			select VehicleDetails.Vehicle_Display_Name ,VehicleDetails.NumDoors ,
				CASE
						when NumDoors=0 then 'Zero Doors'
						when NumDoors=1 then 'One Door'
						when NumDoors =2 then 'Two Doors'
						when NumDoors=3 then 'Three Doors'
						when NumDoors=4 then 'Four Doors'
						when NumDoors= 5 then 'Five Doors'
						when NumDoors=6 then 'Six Doors'
						when NumDoors=8 then 'Eight Doors'
						when NumDoors is null then 'Not Set'
						else 'unknown'
			END as DoorDescription
				from VehicleDetails;

		

			-- probelm 31 : get all vehicle desplay name , year and add  extra column to calculate the Age of the Car then sort the results by the ag desc
				
				select VehicleDetails.Vehicle_Display_Name,VehicleDetails.Year ,Age = YEAR(GetDate()) - VehicleDetails.Year
					from VehicleDetails 
					order by Age desc;


			--probelm 32: get all vehicle desplay name , year and add  extra column to calculate the Age for the vehicles 

				--that their age between 15 and 25 year old

					select * from (
							select VehicleDetails.Vehicle_Display_Name,VehicleDetails.Year ,Age = YEAR(GetDate()) - VehicleDetails.Year
							from VehicleDetails  
					)R1
						where  Age =15 or Age =25;

			-- problem 33: get minimum EngineCC , Maximum Engine CC of all Vehicles

				select min(Engine_CC) as MinimumEngineCC , max(Engine_CC) as MaximumEngineCC, avg(Engine_CC) as AvarageEngineCC
				from VehicleDetails;



			-- problem 34: get all vehicles that have the Minimum Engine_CC

				Select  VehicleDetails.Vehicle_Display_Name   
					from VehicleDetails 
						where Engine_CC = (select min(Engine_CC) from VehicleDetails);
