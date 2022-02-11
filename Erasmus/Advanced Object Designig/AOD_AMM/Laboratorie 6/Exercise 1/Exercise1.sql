CREATE TABLE USER
(
    IdUser INTEGER NOT NULL AUTO_INCREMENT,
    Username VARCHAR(20),
    Name VARCHAR(30) NOT NULL,
    Surname VARCHAR(30) NOT NULL,
    Password VARCHAR(50) NOT NULL,
    Email VARCHAR(50) NOT NULL,
    DateOfRegistration VARCHAR(10) NOT NULL,  -- dd/mm/aaaa
    PhoneNumber VARCHAR(12) NOT NULL, -- +PPXXXXXXXXX 
    
    PRIMARY KEY (IdUser)
);

CREATE TABLE ADDRESS
(
    IdAddress INTEGER NOT NULL AUTO_INCREMENT,
    City VARCHAR(30) NOT NULL,
    Street VARCHAR(50) NOT NULL,
    HouseNumber INTEGER NOT NULL,
    ZipCODE VARCHAR(6) NOT NULL, -- XX-XXX
    
    PRIMARY KEY (IdAddress)
);

CREATE TABLE MEAL
(
    IdMeal INTEGER NOT NULL AUTO_INCREMENT,
    Name VARCHAR(30) NOT NULL,
    Price FLOAT NOT NULL,
    PossibleNumberOfOrders INTEGER NOT NULL,
    IsVegetarian BOOLEAN NOT NULL, -- True if vegetarian // False if not vegetarian
    
    PRIMARY KEY (IdMeal)
);

CREATE TABLE ORD3R 
(
    IdUser INTEGER NOT NULL AUTO_INCREMENT,
    NameMeal VARCHAR(30) NOT NULL,
    OrderDate VARCHAR(10) NOT NULL,
    OrderTime VARCHAR(5) NOT NULL, -- hh:mm
    IdOrder INTEGER NOT NULL,
    
    PRIMARY KEY (IdUser,IdOrder),
	CONSTRAINT FOREIGN KEY fk_customer_id (IdUser) REFERENCES USER(IdUser)
);

INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) 
			VALUES ("Adrian98","Adrian","Moreno","abc123","adrian@gmail.com","01/01/2021","+34608149234");
INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) 
			VALUES ("Pepito","Pepe","Garcia","123abc","pepe@gmail.com","01/01/2021","+34666000666");
INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) 
			VALUES ("Visumania","Larry","Katula","acb132","larry@gmail.com","01/01/2021","+42699699699");
INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) 
			VALUES ("Sandrana","Rosa","Melano","bca231","rosa@gmail.com","01/01/2021","+34987654321");
INSERT INTO USER (Username,Name,Surname,Password,Email,DateOfRegistration,PhoneNumber) 
			VALUES ("Hunter","Robert","Lewandowski","cba321","lewandowski@gmail.com","01/01/2021","+42999999999");

INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE) 
			VALUES ("Sosnowiec","Sucha7A",101,"41-200");
INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE) 
			VALUES ("Trigueros","Hermanas Carmelitas",77,"21-620");
INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE) 
			VALUES ("Krakow","Mikolowska",4,"31-137");
INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE) 
			VALUES ("Corrales","San Guillermo",18,"21-110");
INSERT INTO ADDRESS (City,Street,HouseNumber,ZipCODE) 
			VALUES ("Warszawa","Krucza",9,"00-509");

INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian)
			VALUES ("Pieroggi",7.5,50,true);
INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian)
			VALUES ("Pizza",10,50,true);
INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian)
			VALUES ("Kebab",6,50,false);
INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian)
			VALUES ("Chicken",6.5,50,false);
INSERT INTO MEAL(Name,Price,PossibleNumberOfOrders,IsVegetarian)
			VALUES ("Salat",8,50,true);

INSERT INTO ORD3R(IdOrder,NameMeal,OrderDate,OrderTime)
			VALUES(5,"Salat","05/01/2021","13:00");
INSERT INTO ORD3R (IdOrder,NameMeal,OrderDate,OrderTime)
			VALUES(4,"Chicken","06/01/2021","13:34");
INSERT INTO ORD3R (IdOrder,NameMeal,OrderDate,OrderTime)
			VALUES(3,"Kebab","07/01/2021","16:56");
INSERT INTO ORD3R (IdOrder,NameMeal,OrderDate,OrderTime)
			VALUES(2,"Pizza","08/01/2021","20:09");
INSERT INTO ORD3R (IdOrder,NameMeal,OrderDate,OrderTime)
			VALUES(1,"Pieroggi","09/01/2021","22:46");


