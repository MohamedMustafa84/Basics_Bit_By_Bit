
create Database CarsRental;

use CarsRental;



	create Table Maintanances (
		MaintananceID int primary key ,
		Description nvarchar(max) not null,
		MaintenanceDate date not null,
		MaintenanceCost smallmoney not null
	)

	select * from Maintanances;

	

	 create table FuleTypes(
	  FuleTypeID int primary key ,
	  FuleType nvarchar(20)
	  )

	  select * from FuleTypes;


	  create table VehiclesCategories(
			CategoryID int primary key ,
			CategoryName nvarchar(20) not null
		)

		select * from VehiclesCategories;


create Table Vehicles(
	vehicleID int primary key ,
	Make nvarchar(100) not null,
	VehicleModel nvarchar(50) not null,
	VehicleYear date not null,
	MaintenanceID int references Maintanances(MaintananceID),
	RentalPerDayAmount smallmoney not null,
	PlateNumber int unique not null ,
	Mailage int not null,
	RentalRate nvarchar(50),
	FuleType int references FuleTypes(FuleTypeID) not null,
	Category int references VehiclesCategories(CategoryID) not null,
	ISAvailableForRent bit not null

	)

	select * from Vehicles;



	 create table Customers(
		CustomerID  int primary key ,
		CustomerName  nvarchar(50) not null,
		ContactInfo nvarchar(50) not null,
		DriverLicenseNumber nvarchar(50) not null
	)

	select * from Customers;



 create table VehiclesBookings (
	BookingID int primary key ,
	VehicleID int references Vehicles (VehicleID),
	CustomerID int references  Customers(CustomerID) not null,
	StratRentalDate Date not null  ,
	EndRentalDate   Date not null,
	PickupLocation  nvarchar(50) not null,
	DropOfLocation nvarchar(50) not null,
	RentalPricePerDay  smallmoney not null,
	InitialRentalDays int not null,
	InitialVehicleCheckNotes  nvarchar(max) not null
)

  select * from VehiclesBookings;
	


	create table VehiclesReturn(
		ReturnVehicleID int primary key ,
		ActualReturnDate date not null,
		ActualRentalDays int not null,
		FinalVehicleCheckNotes nvarchar(max) not null,
		ActualTotalDueAmount smallmoney not null,
		AdditinalCharges smallmoney ,
		CurrentMailage int not null,
		ConsumedMailage  int not null
	)

	select * from VehiclesReturn;

	
	 create table RentalTransactions(
		TransactionID int primary key ,
		TransactionDate date not null,
		BookingID int references VehiclesBookings(BookingID) not null,
		ReturnVehicleID int references VehiclesReturn(ReturnVehicleID),
		TransactionDetails nvarchar(max) not null,
		InitailPaidAmount smallMoney not null,
		ActualTotalDueAmount smallmoney not null,
		TotalRemainingAmount smallmoney ,
		TotalRefund smallmoney not null,
		UpdatedTransactionDate date not null
	)

	select * from RentalTransactions;


	backup database CarsRental to disk ='F:\programing\ProgramingAdvices\course17_Database_Projects\CarsRentalProject\CarsRental.bac';