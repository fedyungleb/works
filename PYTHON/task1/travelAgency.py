class Customer:
    def __init__(self, id, name, age):
     self.id = id
     self.name = name
     self.age = age 
    def printCustomer(self, id, name, age) :
        print ("ID:", self.id, "Name:", self.name, "Age:", self.age)

class Ticket:
    def __init__(self, dateOfDeparture, dateOfArival, airport):
        self.dateOfDeparture = dateOfDeparture
        self.dateOfArival = dateOfArival
        self.airport = airport         

class Airport:
    def __init__(self, country, code):
        self.country = country
        self.code = code

c1 = Customer.printCustomer(1, "Hlib", 19 )
t1 = Ticket ("17.08.2022", "17.09.2022", "Vilnius")
a1 = Airport("Lithuania", "VNO")

print("ID:",c1.id,'\n',"Name:", c1.name) 
print("Age:",c1.age)
print("Date of Arival:",t1.dateOfArival)
print("Date of Departure:",t1.dateOfDeparture)
print("Airport in:",t1.airport)
print("Country:", a1.country)
print("Airport code: ",a1.code)